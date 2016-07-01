#!/usr/bin/perl

use Tinkerforge::IPConnection;
use Tinkerforge::BrickletVoltage;

use constant HOST => 'localhost';
use constant PORT => 4223;
use constant UID => 'XYZ'; # Change XYZ to the UID of your Voltage Bricklet

my $ipcon = Tinkerforge::IPConnection->new(); # Create IP connection
my $v = Tinkerforge::BrickletVoltage->new(&UID, $ipcon); # Create device object

$ipcon->connect(&HOST, &PORT); # Connect to brickd
# Don't use device before ipcon is connected

# Get current voltage (unit is mV)
my $voltage = $v->get_voltage();
print "Voltage: " . $voltage/1000.0 . " V\n";

print "Press key to exit\n";
<STDIN>;
$ipcon->disconnect();
