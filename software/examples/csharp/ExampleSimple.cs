using Tinkerforge;

class Example
{
	private static string HOST = "localhost";
	private static int PORT = 4223;
	private static string UID = "ABC"; // Change to your UID

	static void Main() 
	{
		IPConnection ipcon = new IPConnection(HOST, PORT); // Create connection to brickd
		BrickletVoltage vol = new BrickletVoltage(UID); // Create device object
		ipcon.AddDevice(vol); // Add device to IP connection
		// Don't use device before it is added to a connection

		// Get current voltage (unit is mV)
		ushort voltage = vol.GetVoltage();

		System.Console.WriteLine("Voltage: " + voltage/1000.0 + " V");

		System.Console.WriteLine("Press ctrl+c to exit");
		ipcon.JoinThread();
	}
}
