use std::{io, error::Error};
use std::thread;
use tinkerforge::{ip_connection::IpConnection, 
                  voltage_bricklet::*};


const HOST: &str = "localhost";
const PORT: u16 = 4223;
const UID: &str = "XYZ"; // Change XYZ to the UID of your Voltage Bricklet.

fn main() -> Result<(), Box<dyn Error>> {
    let ipcon = IpConnection::new(); // Create IP connection.
    let v = VoltageBricklet::new(UID, &ipcon); // Create device object.

    ipcon.connect((HOST, PORT)).recv()??; // Connect to brickd.
    // Don't use device before ipcon is connected.

     let voltage_receiver = v.get_voltage_callback_receiver();

        // Spawn thread to handle received callback messages. 
        // This thread ends when the `v` object
        // is dropped, so there is no need for manual cleanup.
        thread::spawn(move || {
            for voltage in voltage_receiver {           
                		println!("Voltage: {} V", voltage as f32 /1000.0);
            }
        });

		// Set period for voltage receiver to 1s (1000ms).
		// Note: The voltage callback is only called every second
		//       if the voltage has changed since the last call!
		v.set_voltage_callback_period(1000);

    println!("Press enter to exit.");
    let mut _input = String::new();
    io::stdin().read_line(&mut _input)?;
    ipcon.disconnect();
    Ok(())
}
