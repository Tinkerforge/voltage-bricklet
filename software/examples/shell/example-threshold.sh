#!/bin/sh
# connects to localhost:4223 by default, use --host and --port to change it

# change to your UID
uid=XYZ

# get threshold callbacks with a debounce time of 10 seconds (10000ms)
tinkerforge call voltage-bricklet $uid set-debounce-period 10000

# configure threshold for "smaller than 5V" (unit is mV)
tinkerforge call voltage-bricklet $uid set-voltage-callback-threshold smaller 5000 0

# handle incoming voltage-reached callbacks (unit is Lux/10)
tinkerforge dispatch voltage-bricklet $uid voltage-reached\
 --execute "echo Voltage dropped below 5V: {voltage} mV"
