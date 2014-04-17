function octave_example_simple()
    more off;
    
    HOST = "localhost";
    PORT = 4223;
    UID = "abd2"; % Change to your UID

    ipcon = java_new("com.tinkerforge.IPConnection"); % Create IP connection
    v = java_new("com.tinkerforge.BrickletVoltage", UID, ipcon); % Create device object

    ipcon.connect(HOST, PORT); % Connect to brickd
    % Don't use device before ipcon is connected

    % Get current voltage (unit is mV)
    voltage = v.getVoltage();
    fprintf("Voltage: %g V\n", voltage/1000.0);

    input("Press any key to exit...\n", "s");
    ipcon.disconnect();
end
