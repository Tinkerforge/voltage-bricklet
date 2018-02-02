function octave_example_simple()
    more off;

    HOST = "localhost";
    PORT = 4223;
    UID = "XYZ"; % Change XYZ to the UID of your Voltage Bricklet

    ipcon = javaObject("com.tinkerforge.IPConnection"); % Create IP connection
    v = javaObject("com.tinkerforge.BrickletVoltage", UID, ipcon); % Create device object

    ipcon.connect(HOST, PORT); % Connect to brickd
    % Don't use device before ipcon is connected

    % Get current voltage
    voltage = v.getVoltage();
    fprintf("Voltage: %g V\n", voltage/1000.0);

    input("Press key to exit\n", "s");
    ipcon.disconnect();
end
