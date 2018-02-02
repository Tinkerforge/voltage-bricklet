Imports System
Imports Tinkerforge

Module ExampleCallback
    Const HOST As String = "localhost"
    Const PORT As Integer = 4223
    Const UID As String = "XYZ" ' Change XYZ to the UID of your Voltage Bricklet

    ' Callback subroutine for voltage callback
    Sub VoltageCB(ByVal sender As BrickletVoltage, ByVal voltage As Integer)
        Console.WriteLine("Voltage: " + (voltage/1000.0).ToString() + " V")
    End Sub

    Sub Main()
        Dim ipcon As New IPConnection() ' Create IP connection
        Dim v As New BrickletVoltage(UID, ipcon) ' Create device object

        ipcon.Connect(HOST, PORT) ' Connect to brickd
        ' Don't use device before ipcon is connected

        ' Register voltage callback to subroutine VoltageCB
        AddHandler v.VoltageCallback, AddressOf VoltageCB

        ' Set period for voltage callback to 1s (1000ms)
        ' Note: The voltage callback is only called every second
        '       if the voltage has changed since the last call!
        v.SetVoltageCallbackPeriod(1000)

        Console.WriteLine("Press key to exit")
        Console.ReadLine()
        ipcon.Disconnect()
    End Sub
End Module
