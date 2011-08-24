/*************************************************************
 * This file was automatically generated on 23.08.2011.      *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generator git on tinkerforge.com                   *
 *************************************************************/

#ifndef BRICKLET_VOLTAGE_H
#define BRICKLET_VOLTAGE_H

#include "ip_connection.h"

typedef Device Voltage;

#define VOLTAGE_CALLBACK_VOLTAGE 13
#define VOLTAGE_CALLBACK_ANALOG_VALUE 14
#define VOLTAGE_CALLBACK_VOLTAGE_REACHED 15
#define VOLTAGE_CALLBACK_ANALOG_VALUE_REACHED 16

void voltage_create(Voltage *voltage, const char *uid);

int voltage_get_voltage(Voltage *voltage, uint16_t *ret_voltage);
int voltage_get_analog_value(Voltage *voltage, uint16_t *ret_value);
int voltage_set_voltage_callback_period(Voltage *voltage, uint32_t period);
int voltage_get_voltage_callback_period(Voltage *voltage, uint32_t *ret_period);
int voltage_set_analog_value_callback_period(Voltage *voltage, uint32_t period);
int voltage_get_analog_value_callback_period(Voltage *voltage, uint32_t *ret_period);
int voltage_set_voltage_callback_threshold(Voltage *voltage, char option, int16_t min, int16_t max);
int voltage_get_voltage_callback_threshold(Voltage *voltage, char *ret_option, int16_t *ret_min, int16_t *ret_max);
int voltage_set_analog_value_callback_threshold(Voltage *voltage, char option, uint16_t min, uint16_t max);
int voltage_get_analog_value_callback_threshold(Voltage *voltage, char *ret_option, uint16_t *ret_min, uint16_t *ret_max);
int voltage_set_debounce_period(Voltage *voltage, uint32_t debounce);
int voltage_get_debounce_period(Voltage *voltage, uint32_t *ret_debounce);
int voltage_voltage(Voltage *voltage, uint16_t *ret_voltage);
int voltage_analog_value(Voltage *voltage, uint16_t *ret_value);
int voltage_voltage_reached(Voltage *voltage, uint16_t *ret_voltage);
int voltage_analog_value_reached(Voltage *voltage, uint16_t *ret_value);

void voltage_register_callback(Voltage *voltage, uint8_t cb, void *func);

#endif