import com.tinkerforge.BrickletVoltage;
import com.tinkerforge.IPConnection;

public class ExampleSimple {
	private static final String host = "localhost";
	private static final int port = 4223;
	private static final String UID = "ABC"; // Change to your UID
	
	// Note: To make the example code cleaner we do not handle exceptions. Exceptions you
	//       might normally want to catch are described in the commnents below
	public static void main(String args[]) throws Exception {
		// Create connection to brickd
		IPConnection ipcon = new IPConnection(host, port); // Can throw IOException
		BrickletVoltage vol = new BrickletVoltage(UID); // Create device object

		// Add device to IP connection
		ipcon.addDevice(vol); // Can throw IPConnection.TimeoutException
		// Don't use device before it is added to a connection

		// Get current voltage (unit is mV)
		int voltage = vol.getVoltage(); // Can throw IPConnection.TimeoutException

		System.out.println("Voltage: " + voltage/1000.0 + " V");

		System.console().readLine("Press key to exit\n");
		ipcon.destroy();
	}
}
