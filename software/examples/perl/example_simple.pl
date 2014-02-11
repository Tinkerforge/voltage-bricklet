#!/usr/bin/perl  

use Tinkerforge::IPConnection;
use Tinkerforge::BrickletVoltage;

use constant HOST => 'localhost';
use constant PORT => 4223;
use constant UID => 'abd2'; # Change to your UID

my $ipcon = Tinkerforge::IPConnection->new(); # Create IP connection
my $v = Tinkerforge::BrickletVoltage->new(&UID, $ipcon); # Create device object

$ipcon->connect(&HOST, &PORT); # Connect to brickd
# Don't use device before ipcon is connected

# Get current voltage (unit is mV)
my $voltage = $v->get_voltage();

print "\nVoltage: ".$voltage/1000.0." V\n";

print "\nPress any key to exit...\n";
<STDIN>;
$ipcon->disconnect();
