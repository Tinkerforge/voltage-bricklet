<?php

require_once('Tinkerforge/IPConnection.php');
require_once('Tinkerforge/BrickletVoltage.php');

use Tinkerforge\IPConnection;
use Tinkerforge\BrickletVoltage;

const HOST = 'localhost';
const PORT = 4223;
const UID = 'XYZ'; // Change XYZ to the UID of your Voltage Bricklet

// Callback function for voltage reached callback
function cb_voltageReached($voltage)
{
    echo "Voltage: " . $voltage/1000.0 . " V\n";
}

$ipcon = new IPConnection(); // Create IP connection
$v = new BrickletVoltage(UID, $ipcon); // Create device object

$ipcon->connect(HOST, PORT); // Connect to brickd
// Don't use device before ipcon is connected

// Get threshold callbacks with a debounce time of 10 seconds (10000ms)
$v->setDebouncePeriod(10000);

// Register voltage reached callback to function cb_voltageReached
$v->registerCallback(BrickletVoltage::CALLBACK_VOLTAGE_REACHED, 'cb_voltageReached');

// Configure threshold for voltage "greater than 5 V"
$v->setVoltageCallbackThreshold('>', 5*1000, 0);

echo "Press ctrl+c to exit\n";
$ipcon->dispatchCallbacks(-1); // Dispatch callbacks forever

?>
