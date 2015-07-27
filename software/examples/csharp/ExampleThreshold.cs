using Tinkerforge;

class Example
{
	private static string HOST = "localhost";
	private static int PORT = 4223;
	private static string UID = "XYZ"; // Change to your UID

	// Callback function for voltage greater than 5 V (parameter has unit mV)
	static void VoltageReachedCB(BrickletVoltage sender, int voltage)
	{
		System.Console.WriteLine("Voltage: " + voltage/1000.0 + " V");
	}

	static void Main()
	{
		IPConnection ipcon = new IPConnection(); // Create IP connection
		BrickletVoltage v = new BrickletVoltage(UID, ipcon); // Create device object

		ipcon.Connect(HOST, PORT); // Connect to brickd
		// Don't use device before ipcon is connected

		// Get threshold callbacks with a debounce time of 10 seconds (10000ms)
		v.SetDebouncePeriod(10000);

		// Register threshold reached callback to function VoltageReachedCB
		v.VoltageReached += VoltageReachedCB;

		// Configure threshold for "greater than 5 V" (unit is mV)
		v.SetVoltageCallbackThreshold('>', 5*1000, 0);

		System.Console.WriteLine("Press enter to exit");
		System.Console.ReadLine();
		ipcon.Disconnect();
	}
}
