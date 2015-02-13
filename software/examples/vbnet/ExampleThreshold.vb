Imports Tinkerforge

Module ExampleThreshold
    Const HOST As String = "localhost"
    Const PORT As Integer = 4223
    Const UID As String = "aNt" ' Change to your UID

    ' Callback for voltage smaller than 5V
    Sub ReachedCB(ByVal sender As BrickletVoltage, ByVal voltage As Integer)
        System.Console.WriteLine("Voltage dopped below 5V: " + (voltage/1000.0).ToString() + "V")
    End Sub

    Sub Main()
        Dim ipcon As New IPConnection() ' Create IP connection
        Dim vol As New BrickletVoltage(UID, ipcon) ' Create device object

        ipcon.Connect(HOST, PORT) ' Connect to brickd
        ' Don't use device before ipcon is connected

        ' Get threshold callbacks with a debounce time of 10 seconds (10000ms)
        vol.SetDebouncePeriod(10000)

        ' Register threshold reached callback to function ReachedCB
        AddHandler vol.VoltageReached, AddressOf ReachedCB

        ' Configure threshold for "smaller than 5V" (unit is mV)
        vol.SetVoltageCallbackThreshold("<"C, 5*1000, 0)

        System.Console.WriteLine("Press key to exit")
        System.Console.ReadLine()
        ipcon.Disconnect()
    End Sub
End Module
