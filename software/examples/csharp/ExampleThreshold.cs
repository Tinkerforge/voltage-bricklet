using Tinkerforge;

class Example
{
	private static string HOST = "localhost";
	private static int PORT = 4223;
	private static string UID = "ABC"; // Change to your UID

	// Callback for voltage smaller than 5V
	static void ReachedCB(BrickletVoltage sender, int voltage)
	{
		System.Console.WriteLine("Voltage dopped below 5V: " + voltage/1000.0 + "V");
	}

	static void Main() 
	{
		IPConnection ipcon = new IPConnection(); // Create IP connection
		BrickletVoltage vol = new BrickletVoltage(UID, ipcon); // Create device object

		ipcon.Connect(HOST, PORT); // Connect to brickd
		// Don't use device before ipcon is connected

		// Get threshold callbacks with a debounce time of 10 seconds (10000ms)
		vol.SetDebouncePeriod(10000);

		// Register threshold reached callback to function ReachedCB
		vol.VoltageReached += ReachedCB;

		// Configure threshold for "smaller than 5V" (unit is mV)
		vol.SetVoltageCallbackThreshold('<', 5*1000, 0);

		System.Console.WriteLine("Press enter to exit");
		System.Console.ReadLine();
		ipcon.Disconnect();
	}
}
