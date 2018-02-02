var Tinkerforge = require('tinkerforge');

var HOST = 'localhost';
var PORT = 4223;
var UID = 'XYZ'; // Change XYZ to the UID of your Voltage Bricklet

var ipcon = new Tinkerforge.IPConnection(); // Create IP connection
var v = new Tinkerforge.BrickletVoltage(UID, ipcon); // Create device object

ipcon.connect(HOST, PORT,
    function (error) {
        console.log('Error: ' + error);
    }
); // Connect to brickd
// Don't use device before ipcon is connected

ipcon.on(Tinkerforge.IPConnection.CALLBACK_CONNECTED,
    function (connectReason) {
        // Get threshold callbacks with a debounce time of 10 seconds (10000ms)
        v.setDebouncePeriod(10000);

        // Configure threshold for voltage "greater than 5 V"
        v.setVoltageCallbackThreshold('>', 5*1000, 0);
    }
);

// Register voltage reached callback
v.on(Tinkerforge.BrickletVoltage.CALLBACK_VOLTAGE_REACHED,
    // Callback function for voltage reached callback
    function (voltage) {
        console.log('Voltage: ' + voltage/1000.0 + ' V');
    }
);

console.log('Press key to exit');
process.stdin.on('data',
    function (data) {
        ipcon.disconnect();
        process.exit(0);
    }
);
