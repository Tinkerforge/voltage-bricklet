package main

import (
	"fmt"
	"tinkerforge/ipconnection"
	"tinkerforge/voltage_bricklet"
)

const ADDR string = "localhost:4223"
const UID string = "XYZ" // Change XYZ to the UID of your Voltage Bricklet.

func main() {
	ipcon := ipconnection.New()
	defer ipcon.Close()
	v, _ := voltage_bricklet.New(UID, &ipcon) // Create device object.

	ipcon.Connect(ADDR) // Connect to brickd.
	defer ipcon.Disconnect()
	// Don't use device before ipcon is connected.

	// Get threshold receivers with a debounce time of 10 seconds (10000ms).
	v.SetDebouncePeriod(10000)

	v.RegisterVoltageReachedCallback(func(voltage uint16) {
		fmt.Printf("Voltage: %d V\n", float64(voltage)/1000.0)
	})

	// Configure threshold for voltage "greater than 5 V".
	v.SetVoltageCallbackThreshold('>', 5*1000, 0)

	fmt.Print("Press enter to exit.")
	fmt.Scanln()

}
