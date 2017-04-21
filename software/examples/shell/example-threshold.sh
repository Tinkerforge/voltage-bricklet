#!/bin/sh
# Connects to localhost:4223 by default, use --host and --port to change this

uid=XYZ # Change XYZ to the UID of your Voltage Bricklet

# Get threshold callbacks with a debounce time of 10 seconds (10000ms)
tinkerforge call voltage-bricklet $uid set-debounce-period 10000

# Handle incoming voltage reached callbacks (parameter has unit mV)
tinkerforge dispatch voltage-bricklet $uid voltage-reached &

# Configure threshold for voltage "greater than 5 V" (unit is mV)
tinkerforge call voltage-bricklet $uid set-voltage-callback-threshold threshold-option-greater 5000 0

echo "Press key to exit"; read dummy

kill -- -$$ # Stop callback dispatch in background
