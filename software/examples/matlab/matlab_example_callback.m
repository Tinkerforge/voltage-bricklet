function matlab_example_callback()
    import com.tinkerforge.IPConnection;
    import com.tinkerforge.BrickletVoltage;

    HOST = 'localhost';
    PORT = 4223;
    UID = 'XYZ'; % Change to your UID

    ipcon = IPConnection(); % Create IP connection
    v = BrickletVoltage(UID, ipcon); % Create device object

    ipcon.connect(HOST, PORT); % Connect to brickd
    % Don't use device before ipcon is connected

    % Register voltage callback to function cb_voltage
    set(v, 'VoltageCallback', @(h, e) cb_voltage(e));

    % Set period for voltage callback to 1s (1000ms)
    % Note: The voltage callback is only called every second
    %       if the voltage has changed since the last call!
    v.setVoltageCallbackPeriod(1000);

    input('Press key to exit\n', 's');
    ipcon.disconnect();
end

% Callback function for voltage callback (parameter has unit mV)
function cb_voltage(e)
    fprintf('Voltage: %g V\n', e.voltage/1000.0);
end
