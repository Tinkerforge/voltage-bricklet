#!/bin/sh
# Connects to localhost:4223 by default, use --host and --port to change this

uid=XYZ # Change XYZ to the UID of your Voltage Bricklet

# Get current voltage (unit is mV)
tinkerforge call voltage-bricklet $uid get-voltage
