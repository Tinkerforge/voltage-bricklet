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

    //Create listener for voltage events.
    let voltage_listener = voltage_bricklet.get_voltage_receiver();
    // Spawn thread to handle received events. This thread ends when the voltage_bricklet
    // is dropped, so there is no need for manual cleanup.
    thread::spawn(move || {
        for event in voltage_listener {
            println!("Voltage: {}{}", event as f32 / 1000.0, " V");
        }
    });

    // Set period for voltage listener to 1s (1000ms)
    // Note: The voltage callback is only called every second
    //       if the voltage has changed since the last call!
    voltage_bricklet.set_voltage_callback_period(1000);

    println!("Press enter to exit.");
    let mut _input = String::new();
    io::stdin().read_line(&mut _input)?;
    ipcon.disconnect();
    Ok(())
}
