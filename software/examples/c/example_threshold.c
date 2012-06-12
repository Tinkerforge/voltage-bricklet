
#include <stdio.h>

#include "ip_connection.h"
#include "bricklet_voltage.h"

#define HOST "localhost"
#define PORT 4223
#define UID "ABC" // Change to your UID

// Callback for voltage smaller than 5V
void cb_reached(uint16_t voltage) {
	printf("Voltage dropped below 5V: %f\n", voltage/1000.0);
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

	// Get threshold callbacks with a debounce time of 10 seconds (10000ms)
	voltage_set_debounce_period(&v, 10000);

	// Register threshold reached callback to function cb_reached
	voltage_register_callback(&v, VOLTAGE_CALLBACK_VOLTAGE_REACHED, cb_reached);

	// Configure threshold for "smaller than 5V" (unit is mV)
	voltage_set_voltage_callback_threshold(&v, '<', 5*1000, 0);

	printf("Press ctrl+c to close\n");
	ipcon_join_thread(&ipcon); // Join mainloop of IP connection
}
