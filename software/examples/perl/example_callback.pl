#!/usr/bin/perl  

use Tinkerforge::IPConnection;
use Tinkerforge::BrickletVoltage;

use constant HOST => 'localhost';
use constant PORT => 4223;
use constant UID => 'abd2'; # Change to your UID

my $ipcon = Tinkerforge::IPConnection->new(); # Create IP connection
my $v = Tinkerforge::BrickletVoltage->new(&UID, $ipcon); # Create device object

# Callback function for voltage callback (parameter has unit mV)
sub cb_voltage
{
    my ($voltage) = @_;

    print "Voltage: ".$voltage/1000.0." V\n";
}

$ipcon->connect(&HOST, &PORT); # Connect to brickd
# Don't use device before ipcon is connected

# Set Period for voltage callback to 1s (1000ms)
# Note: The callback is only called every second if the 
#       voltage has changed since the last call!
$v->set_voltage_callback_period(1000);

# Register voltage callback to function cb_voltage
$v->register_callback($v->CALLBACK_VOLTAGE, 'cb_voltage');

print "Press any key to exit...\n";
<STDIN>;
$ipcon->disconnect();
