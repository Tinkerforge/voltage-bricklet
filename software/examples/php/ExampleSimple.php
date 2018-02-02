<?php

require_once('Tinkerforge/IPConnection.php');
require_once('Tinkerforge/BrickletVoltage.php');

use Tinkerforge\IPConnection;
use Tinkerforge\BrickletVoltage;

const HOST = 'localhost';
const PORT = 4223;
const UID = 'XYZ'; // Change XYZ to the UID of your Voltage Bricklet

$ipcon = new IPConnection(); // Create IP connection
$v = new BrickletVoltage(UID, $ipcon); // Create device object

$ipcon->connect(HOST, PORT); // Connect to brickd
// Don't use device before ipcon is connected

// Get current voltage
$voltage = $v->getVoltage();
echo "Voltage: " . $voltage/1000.0 . " V\n";

echo "Press key to exit\n";
fgetc(fopen('php://stdin', 'r'));
$ipcon->disconnect();

?>
