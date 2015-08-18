Imports Tinkerforge

Module ExampleThreshold
    Const HOST As String = "localhost"
    Const PORT As Integer = 4223
    Const UID As String = "XYZ" ' Change to your UID

    ' Callback function for voltage greater than 5 V (parameter has unit mV)
    Sub VoltageReachedCB(ByVal sender As BrickletVoltage, ByVal voltage As Integer)
        System.Console.WriteLine("Voltage: " + (voltage/1000.0).ToString() + " V")
    End Sub

    Sub Main()
        Dim ipcon As New IPConnection() ' Create IP connection
        Dim v As New BrickletVoltage(UID, ipcon) ' Create device object

        ipcon.Connect(HOST, PORT) ' Connect to brickd
        ' Don't use device before ipcon is connected

        ' Get threshold callbacks with a debounce time of 10 seconds (10000ms)
        v.SetDebouncePeriod(10000)

        ' Register threshold reached callback to function VoltageReachedCB
        AddHandler v.VoltageReached, AddressOf VoltageReachedCB

        ' Configure threshold for "greater than 5 V" (unit is mV)
        v.SetVoltageCallbackThreshold(">"C, 5*1000, 0)

        System.Console.WriteLine("Press key to exit")
        System.Console.ReadLine()
        ipcon.Disconnect()
    End Sub
End Module
