import com.tinkerforge.BrickletVoltage;
import com.tinkerforge.IPConnection;

public class ExampleCallback {
	private static final String host = new String("localhost");
	private static final int port = 4223;
	private static final String UID = new String("ABC"); // Change to your UID
	
	// Note: To make the example code cleaner we do not handle exceptions. Exceptions you
	//       might normally want to catch are described in the commnents below
	public static void main(String args[]) throws Exception {
		// Create connection to brickd
		IPConnection ipcon = new IPConnection(host, port); // Can throw IOException

		BrickletVoltage vol = new BrickletVoltage(UID); // Create device object

		// Add device to ip connection
		ipcon.addDevice(vol); // Can throw IPConnection.TimeoutException
		// Don't use device before it is added to a connection
		

		// Set Period for voltage callback to 1s (1000ms)
		// Note: The voltage callback is only called every second if the 
		//       voltage has changed since the last call!
		vol.setVoltageCallbackPeriod(1000);

		// Add and implement voltage listener (called if voltage changes)
		vol.addListener(new BrickletVoltage.VoltageListener() {
			public void voltage(int voltage) {
				System.out.println("Voltage: " + voltage/1000.0 + " V");
			}
		});
		
		System.out.println("Press ctrl+c to exit");
		ipcon.joinThread();
	}
}
