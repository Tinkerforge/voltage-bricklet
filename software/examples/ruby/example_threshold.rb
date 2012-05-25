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

# Get threshold callbacks with a debounce time of 10 seconds (10000ms)
v.set_debounce_period 10000

# Register threshold reached callback for voltage smaller than 5V
v.register_callback BrickletVoltage::CALLBACK_VOLTAGE_REACHED, do |voltage|
  puts "Voltage dropped below 5V: #{voltage/1000.0}"
end

# Configure threshold for "smaller than 5V" (unit is mV)
v.set_voltage_callback_threshold '<', 5*1000, 0

puts 'Press key to exit'
$stdin.gets
ipcon.destroy
