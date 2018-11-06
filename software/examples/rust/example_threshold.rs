use std::{error::Error, io, thread};
use tinkerforge::{ipconnection::IpConnection, voltage_bricklet::*};

const HOST: &str = "127.0.0.1";
const PORT: u16 = 4223;
const UID: &str = "XYZ"; // Change XYZ to the UID of your Voltage Bricklet

fn main() -> Result<(), Box<dyn Error>> {
    let ipcon = IpConnection::new(); // Create IP connection
    let voltage_bricklet = VoltageBricklet::new(UID, &ipcon); // Create device object

    ipcon.connect(HOST, PORT).recv()??; // Connect to brickd
                                        // Don't use device before ipcon is connected

    // Get threshold listeners with a debounce time of 10 seconds (10000ms)
    voltage_bricklet.set_debounce_period(10000);

    //Create listener for voltage reached events.
    let voltage_reached_listener = voltage_bricklet.get_voltage_reached_receiver();
    // Spawn thread to handle received events. This thread ends when the voltage_bricklet
    // is dropped, so there is no need for manual cleanup.
    thread::spawn(move || {
        for event in voltage_reached_listener {
            println!("Voltage: {}{}", event as f32 / 1000.0, " V");
        }
    });

    // Configure threshold for voltage "greater than 5 V"
    voltage_bricklet.set_voltage_callback_threshold('>', 5 * 1000, 0);

    println!("Press enter to exit.");
    let mut _input = String::new();
    io::stdin().read_line(&mut _input)?;
    ipcon.disconnect();
    Ok(())
}
