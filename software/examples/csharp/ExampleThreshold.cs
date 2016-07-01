using System;
using Tinkerforge;

class Example
{
	private static string HOST = "localhost";
	private static int PORT = 4223;
	private static string UID = "XYZ"; // Change XYZ to the UID of your Voltage Bricklet

	// Callback function for voltage reached callback (parameter has unit mV)
	static void VoltageReachedCB(BrickletVoltage sender, int voltage)
	{
		Console.WriteLine("Voltage: " + voltage/1000.0 + " V");
	}

	static void Main()
	{
		IPConnection ipcon = new IPConnection(); // Create IP connection
		BrickletVoltage v = new BrickletVoltage(UID, ipcon); // Create device object

		ipcon.Connect(HOST, PORT); // Connect to brickd
		// Don't use device before ipcon is connected

		// Get threshold callbacks with a debounce time of 10 seconds (10000ms)
		v.SetDebouncePeriod(10000);

		// Register voltage reached callback to function VoltageReachedCB
		v.VoltageReached += VoltageReachedCB;

		// Configure threshold for voltage "greater than 5 V" (unit is mV)
		v.SetVoltageCallbackThreshold('>', 5*1000, 0);

		Console.WriteLine("Press enter to exit");
		Console.ReadLine();
		ipcon.Disconnect();
	}
}
