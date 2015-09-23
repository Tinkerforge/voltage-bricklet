#!/usr/bin/perl

use Tinkerforge::IPConnection;
use Tinkerforge::BrickletVoltage;

use constant HOST => 'localhost';
use constant PORT => 4223;
use constant UID => 'XYZ'; # Change to your UID

# Callback subroutine for voltage reached callback (parameter has unit mV)
sub cb_voltage_reached
{
    my ($voltage) = @_;

    print "Voltage: " . $voltage/1000.0 . " V\n";
}

my $ipcon = Tinkerforge::IPConnection->new(); # Create IP connection
my $v = Tinkerforge::BrickletVoltage->new(&UID, $ipcon); # Create device object

$ipcon->connect(&HOST, &PORT); # Connect to brickd
# Don't use device before ipcon is connected

# Get threshold callbacks with a debounce time of 10 seconds (10000ms)
$v->set_debounce_period(10000);

# Register voltage reached callback to subroutine cb_voltage_reached
$v->register_callback($v->CALLBACK_VOLTAGE_REACHED, 'cb_voltage_reached');

# Configure threshold for voltage "greater than 5 V" (unit is mV)
$v->set_voltage_callback_threshold('>', 5*1000, 0);

print "Press key to exit\n";
<STDIN>;
$ipcon->disconnect();
