import com.tinkerforge.IPConnection;
import com.tinkerforge.BrickletVoltage;

public class ExampleThreshold {
	private static final String HOST = "localhost";
	private static final int PORT = 4223;

	// Change XYZ to the UID of your Voltage Bricklet
	private static final String UID = "XYZ";

	// Note: To make the example code cleaner we do not handle exceptions. Exceptions
	//       you might normally want to catch are described in the documentation
	public static void main(String args[]) throws Exception {
		IPConnection ipcon = new IPConnection(); // Create IP connection
		BrickletVoltage v = new BrickletVoltage(UID, ipcon); // Create device object

		ipcon.connect(HOST, PORT); // Connect to brickd
		// Don't use device before ipcon is connected

		// Get threshold callbacks with a debounce time of 10 seconds (10000ms)
		v.setDebouncePeriod(10000);

		// Add voltage reached listener (parameter has unit mV)
		v.addVoltageReachedListener(new BrickletVoltage.VoltageReachedListener() {
			public void voltageReached(int voltage) {
				System.out.println("Voltage: " + voltage/1000.0 + " V");
			}
		});

		// Configure threshold for voltage "greater than 5 V" (unit is mV)
		v.setVoltageCallbackThreshold('>', 5*1000, 0);

		System.out.println("Press key to exit"); System.in.read();
		ipcon.disconnect();
	}
}
