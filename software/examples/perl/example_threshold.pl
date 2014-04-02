#!/usr/bin/perl  

use Tinkerforge::IPConnection;
use Tinkerforge::BrickletVoltage;

use constant HOST => 'localhost';
use constant PORT => 4223;
use constant UID => 'abd2'; # Change to your UID

my $ipcon = Tinkerforge::IPConnection->new(); # Create IP connection
my $v = Tinkerforge::BrickletVoltage->new(&UID, $ipcon); # Create device object

# Callback for voltage smaller than 5V
sub cb_reached
{
    my ($voltage) = @_;

    print "Voltage dropped below 5V: ".$voltage/1000.0." \n";
}

$ipcon->connect(&HOST, &PORT); # Connect to brickd
# Don't use device before ipcon is connected

# Get threshold callbacks with a debounce time of 10 seconds (10000ms)
$v->set_debounce_period(1000);

# Register threshold reached callback to function cb_reached
$v->register_callback($v->CALLBACK_VOLTAGE_REACHED, 'cb_reached');

# Configure threshold for "smaller than 5V" (unit is mV)
$v->set_voltage_callback_threshold('<', 5*1000, 0);

print "Press any key to exit...\n";
<STDIN>;
$ipcon->disconnect();
