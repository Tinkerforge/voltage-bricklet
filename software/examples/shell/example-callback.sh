#!/bin/sh
# connects to localhost:4223 by default, use --host and --port to change it

# change to your UID
uid=XYZ

# set period for voltage callback to 1s (1000ms)
# note: the voltage callback is only called every second if the
#       voltage has changed since the last call!
tinkerforge call voltage-bricklet $uid set-voltage-callback-period 1000

# handle incoming voltage callbacks (unit is mV)
tinkerforge dispatch voltage-bricklet $uid voltage
