<?php

require_once('Tinkerforge/IPConnection.php');
require_once('Tinkerforge/BrickletVoltage.php');

use Tinkerforge\IPConnection;
use Tinkerforge\BrickletVoltage;

$host = 'localhost';
$port = 4223;
$uid = 'ABC'; // Change to your UID

$ipcon = new IPConnection($host, $port); // Create IP connection to brickd
$v = new BrickletVoltage($uid); // Create device object

$ipcon->addDevice($v); // Add device to IP connection
// Don't use device before it is added to a connection

// Get current voltage (unit is mV)
$voltage = $v->getVoltage() / 1000.0;

echo "Voltage: $voltage V\n";

echo "Press key to exit\n";
fgetc(fopen('php://stdin', 'r'));
$ipcon->destroy();

?>
