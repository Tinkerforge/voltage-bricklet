#!/bin/sh
# Connects to localhost:4223 by default, use --host and --port to change this

uid=XYZ # Change XYZ to the UID of your Voltage Bricklet

# Handle incoming voltage callbacks
tinkerforge dispatch voltage-bricklet $uid voltage &

# Set period for voltage callback to 1s (1000ms)
# Note: The voltage callback is only called every second
#       if the voltage has changed since the last call!
tinkerforge call voltage-bricklet $uid set-voltage-callback-period 1000

echo "Press key to exit"; read dummy

kill -- -$$ # Stop callback dispatch in background
