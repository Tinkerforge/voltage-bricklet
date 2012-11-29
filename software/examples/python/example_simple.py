#!/usr/bin/env python
# -*- coding: utf-8 -*-  

HOST = "localhost"
PORT = 4223
UID = "ABC" # Change to your UID

from tinkerforge.ip_connection import IPConnection
from tinkerforge.bricklet_voltage import Voltage

if __name__ == "__main__":
    ipcon = IPConnection() # Create IP connection
    v = Voltage(UID, ipcon) # Create device object

    ipcon.connect(HOST, PORT) # Connect to brickd
    # Don't use device before ipcon is connected

    # Get current voltage (unit is mV)
    voltage = v.get_voltage()

    print('Voltage: ' + str(voltage/1000.0) + ' V')

    raw_input('Press key to exit\n') # Use input() in Python 3
