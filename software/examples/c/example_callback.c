
#include <stdio.h>

#include "ip_connection.h"
#include "bricklet_voltage.h"

#define HOST "localhost"
#define PORT 4223
#define UID "ABC" // Change to your UID

// Callback function for voltage callback (parameter has unit mV)
void cb_voltage(uint16_t voltage) {
	printf("Voltage: %f V\n", voltage/1000.0);
}

int main() {
	// Create IP connection to brickd
	IPConnection ipcon;
	if(ipcon_create(&ipcon, HOST, PORT) < 0) {
		fprintf(stderr, "Could not create connection\n");
		exit(1);
	}

	// Create device object
	Voltage v;
	voltage_create(&v, UID); 

	// Add device to IP connection
	if(ipcon_add_device(&ipcon, &v) < 0) {
		fprintf(stderr, "Could not connect to Bricklet\n");
		exit(1);
	}
	// Don't use device before it is added to a connection

	// Set Period for voltage callback to 1s (1000ms)
	// Note: The callback is only called every second if the 
	//       voltage has changed since the last call!
	voltage_set_voltage_callback_period(&v, 1000);

	// Register voltage callback to function cb_voltage
	voltage_register_callback(&v, VOLTAGE_CALLBACK_VOLTAGE, cb_voltage);

	printf("Press key to exit\n");
	getchar();
	ipcon_destroy(&ipcon);
}
