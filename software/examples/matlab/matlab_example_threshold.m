function matlab_example_threshold()
    import com.tinkerforge.IPConnection;
    import com.tinkerforge.BrickletVoltage;

    HOST = 'localhost';
    PORT = 4223;
    UID = 'abd2'; % Change to your UID

    ipcon = IPConnection(); % Create IP connection
    v = BrickletVoltage(UID, ipcon); % Create device object

    ipcon.connect(HOST, PORT); % Connect to brickd
    % Don't use device before ipcon is connected

    % Set threshold callbacks with a debounce time of 10 seconds (10000ms)
    v.setDebouncePeriod(10000);

    % Register threshold reached callback to function cb_reached
    set(v, 'VoltageReachedCallback', @(h, e) cb_reached(e));

    % Configure threshold for "smaller than 5V" (unit is mV)
    v.setVoltageCallbackThreshold('<', 5*1000, 0);

    input('Press any key to exit...\n', 's');
    ipcon.disconnect();
end

% Callback for voltage greater than 5V
function cb_reached(e)
    fprintf('Voltage dropped below 5V: %g\n', e.voltage/1000.0);
end
