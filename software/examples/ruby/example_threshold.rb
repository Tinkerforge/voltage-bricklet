#!/usr/bin/env ruby
# -*- ruby encoding: utf-8 -*-

require 'tinkerforge/ip_connection'
require 'tinkerforge/bricklet_voltage'

include Tinkerforge

HOST = 'localhost'
PORT = 4223
UID = 'XYZ' # Change XYZ to the UID of your Voltage Bricklet

ipcon = IPConnection.new # Create IP connection
v = BrickletVoltage.new UID, ipcon # Create device object

ipcon.connect HOST, PORT # Connect to brickd
# Don't use device before ipcon is connected

# Get threshold callbacks with a debounce time of 10 seconds (10000ms)
v.set_debounce_period 10000

# Register voltage reached callback
v.register_callback(BrickletVoltage::CALLBACK_VOLTAGE_REACHED) do |voltage|
  puts "Voltage: #{voltage/1000.0} V"
end

# Configure threshold for voltage "greater than 5 V"
v.set_voltage_callback_threshold '>', 5*1000, 0

puts 'Press key to exit'
$stdin.gets
ipcon.disconnect
