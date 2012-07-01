<?php

require_once('Tinkerforge/IPConnection.php');
require_once('Tinkerforge/BrickletVoltage.php');

use Tinkerforge\IPConnection;
use Tinkerforge\BrickletVoltage;

$host = 'localhost';
$port = 4223;
$uid = 'ABC'; // Change to your UID

// Callback for voltage smaller than 5V
function cb_reached($voltage)
{
    echo "Voltage dropped below 5V: " . $voltage / 10.0 . "\n";
}

$ipcon = new IPConnection($host, $port); // Create IP connection to brickd
$v = new BrickletVoltage($uid); // Create device object

$ipcon->addDevice($v); // Add device to IP connection
// Don't use device before it is added to a connection

// Get threshold callbacks with a debounce time of 10 seconds (10000ms)
$v->setDebouncePeriod(10000);

// Register threshold reached callback to function cb_reached
$v->registerCallback(BrickletVoltage::CALLBACK_VOLTAGE_REACHED, 'cb_reached');

// Configure threshold for "smaller than 5V" (unit is mV)
$v->setVoltageCallbackThreshold('<', 5*1000, 0);

echo "Press ctrl+c to exit\n";
$ipcon->dispatchCallbacks(-1); // Dispatch callbacks forever

?>