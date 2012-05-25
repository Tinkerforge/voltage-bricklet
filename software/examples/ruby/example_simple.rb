#!/usr/bin/env ruby
# -*- ruby encoding: utf-8 -*-

require 'tinkerforge/ip_connection'
require 'tinkerforge/bricklet_voltage'

include Tinkerforge

HOST = 'localhost'
PORT = 4223
UID = 'ABC' # Change to your UID

ipcon = IPConnection.new HOST, PORT # Create IP connection to brickd
v = BrickletVoltage.new UID # Create device object
ipcon.add_device v # Add device to IP connection
# Don't use device before it is added to a connection

# Get current voltage (unit is mV)
voltage = v.get_voltage / 1000.0
puts "Voltage: #{voltage} V"

puts 'Press key to exit'
$stdin.gets
ipcon.destroy
