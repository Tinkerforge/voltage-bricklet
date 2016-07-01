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
        // Set period for voltage callback to 1s (1000ms)
        // Note: The voltage callback is only called every second
        //       if the voltage has changed since the last call!
        v.setVoltageCallbackPeriod(1000);
    }
);

// Register voltage callback
v.on(Tinkerforge.BrickletVoltage.CALLBACK_VOLTAGE,
    // Callback function for voltage callback (parameter has unit mV)
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
