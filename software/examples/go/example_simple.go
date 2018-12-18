package main

import (
	"fmt"
	"github.com/Tinkerforge/go-api-bindings/ipconnection"
	"github.com/Tinkerforge/go-api-bindings/voltage_bricklet"
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

	// Get current voltage.
	voltage, _ := v.GetVoltage()
	fmt.Printf("Voltage: %f V\n", float64(voltage)/1000.0)

	fmt.Print("Press enter to exit.")
	fmt.Scanln()

}
