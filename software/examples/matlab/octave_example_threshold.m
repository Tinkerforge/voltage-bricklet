function octave_example_threshold()
    more off;

    HOST = "localhost";
    PORT = 4223;
    UID = "XYZ"; % Change to your UID

    ipcon = java_new("com.tinkerforge.IPConnection"); % Create IP connection
    v = java_new("com.tinkerforge.BrickletVoltage", UID, ipcon); % Create device object

    ipcon.connect(HOST, PORT); % Connect to brickd
    % Don't use device before ipcon is connected

    % Get threshold callbacks with a debounce time of 10 seconds (10000ms)
    v.setDebouncePeriod(10000);

    % Register voltage reached callback to function cb_voltage_reached
    v.addVoltageReachedCallback(@cb_voltage_reached);

    % Configure threshold for voltage "greater than 5 V" (unit is mV)
    v.setVoltageCallbackThreshold(">", 5*1000, 0);

    input("Press key to exit\n", "s");
    ipcon.disconnect();
end

% Callback function for voltage reached callback (parameter has unit mV)
function cb_voltage_reached(e)
    fprintf("Voltage: %g V\n", e.voltage/1000.0);
end
