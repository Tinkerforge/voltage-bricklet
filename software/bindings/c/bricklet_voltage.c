/*************************************************************
 * This file was automatically generated on 2011-08-23.      *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generator git on tinkerforge.com                   *
 *************************************************************/

#include "bricklet_voltage.h"

#include <string.h>

#define TYPE_GET_VOLTAGE 1
#define TYPE_GET_ANALOG_VALUE 2
#define TYPE_SET_VOLTAGE_CALLBACK_PERIOD 3
#define TYPE_GET_VOLTAGE_CALLBACK_PERIOD 4
#define TYPE_SET_ANALOG_VALUE_CALLBACK_PERIOD 5
#define TYPE_GET_ANALOG_VALUE_CALLBACK_PERIOD 6
#define TYPE_SET_VOLTAGE_CALLBACK_THRESHOLD 7
#define TYPE_GET_VOLTAGE_CALLBACK_THRESHOLD 8
#define TYPE_SET_ANALOG_VALUE_CALLBACK_THRESHOLD 9
#define TYPE_GET_ANALOG_VALUE_CALLBACK_THRESHOLD 10
#define TYPE_SET_DEBOUNCE_PERIOD 11
#define TYPE_GET_DEBOUNCE_PERIOD 12
#define TYPE_VOLTAGE 13
#define TYPE_ANALOG_VALUE 14
#define TYPE_VOLTAGE_REACHED 15
#define TYPE_ANALOG_VALUE_REACHED 16

typedef void (*voltage_func_t)(uint16_t);
typedef void (*analog_value_func_t)(uint16_t);
typedef void (*voltage_reached_func_t)(uint16_t);
typedef void (*analog_value_reached_func_t)(uint16_t);

#ifdef _MSC_VER
	#pragma pack(push)
	#pragma pack(1)

	#define PACKED
#else
	#define PACKED __attribute__((packed))
#endif

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED GetVoltage;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint16_t voltage;
} PACKED GetVoltageReturn;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED GetAnalogValue;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint16_t value;
} PACKED GetAnalogValueReturn;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint32_t period;
} PACKED SetVoltageCallbackPeriod;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED GetVoltageCallbackPeriod;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint32_t period;
} PACKED GetVoltageCallbackPeriodReturn;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint32_t period;
} PACKED SetAnalogValueCallbackPeriod;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED GetAnalogValueCallbackPeriod;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint32_t period;
} PACKED GetAnalogValueCallbackPeriodReturn;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	char option;
	int16_t min;
	int16_t max;
} PACKED SetVoltageCallbackThreshold;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED GetVoltageCallbackThreshold;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	char option;
	int16_t min;
	int16_t max;
} PACKED GetVoltageCallbackThresholdReturn;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	char option;
	uint16_t min;
	uint16_t max;
} PACKED SetAnalogValueCallbackThreshold;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED GetAnalogValueCallbackThreshold;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	char option;
	uint16_t min;
	uint16_t max;
} PACKED GetAnalogValueCallbackThresholdReturn;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint32_t debounce;
} PACKED SetDebouncePeriod;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED GetDebouncePeriod;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint32_t debounce;
} PACKED GetDebouncePeriodReturn;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint16_t voltage;
} PACKED VoltageCallback;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint16_t value;
} PACKED AnalogValueCallback;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint16_t voltage;
} PACKED VoltageReachedCallback;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint16_t value;
} PACKED AnalogValueReachedCallback;

#ifdef _MSC_VER
	#pragma pack(pop)
#endif

int voltage_get_voltage(Voltage *voltage, uint16_t *ret_voltage) {
	if(voltage->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(voltage);

	voltage->answer.type = TYPE_GET_VOLTAGE;
	voltage->answer.length = sizeof(GetVoltageReturn);
	GetVoltage gv;
	gv.stack_id = voltage->stack_id;
	gv.type = TYPE_GET_VOLTAGE;
	gv.length = sizeof(GetVoltage);

	ipcon_device_write(voltage, (char *)&gv, sizeof(GetVoltage));

	if(ipcon_answer_sem_wait_timeout(voltage) != 0) {
		ipcon_sem_post_write(voltage);
		return E_TIMEOUT;
	}

	GetVoltageReturn *gvr = (GetVoltageReturn *)voltage->answer.buffer;
	*ret_voltage = gvr->voltage;

	ipcon_sem_post_write(voltage);

	return E_OK;
}

int voltage_get_analog_value(Voltage *voltage, uint16_t *ret_value) {
	if(voltage->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(voltage);

	voltage->answer.type = TYPE_GET_ANALOG_VALUE;
	voltage->answer.length = sizeof(GetAnalogValueReturn);
	GetAnalogValue gav;
	gav.stack_id = voltage->stack_id;
	gav.type = TYPE_GET_ANALOG_VALUE;
	gav.length = sizeof(GetAnalogValue);

	ipcon_device_write(voltage, (char *)&gav, sizeof(GetAnalogValue));

	if(ipcon_answer_sem_wait_timeout(voltage) != 0) {
		ipcon_sem_post_write(voltage);
		return E_TIMEOUT;
	}

	GetAnalogValueReturn *gavr = (GetAnalogValueReturn *)voltage->answer.buffer;
	*ret_value = gavr->value;

	ipcon_sem_post_write(voltage);

	return E_OK;
}

int voltage_set_voltage_callback_period(Voltage *voltage, uint32_t period) {
	if(voltage->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(voltage);

	SetVoltageCallbackPeriod svcp;
	svcp.stack_id = voltage->stack_id;
	svcp.type = TYPE_SET_VOLTAGE_CALLBACK_PERIOD;
	svcp.length = sizeof(SetVoltageCallbackPeriod);
	svcp.period = period;

	ipcon_device_write(voltage, (char *)&svcp, sizeof(SetVoltageCallbackPeriod));

	ipcon_sem_post_write(voltage);

	return E_OK;
}

int voltage_get_voltage_callback_period(Voltage *voltage, uint32_t *ret_period) {
	if(voltage->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(voltage);

	voltage->answer.type = TYPE_GET_VOLTAGE_CALLBACK_PERIOD;
	voltage->answer.length = sizeof(GetVoltageCallbackPeriodReturn);
	GetVoltageCallbackPeriod gvcp;
	gvcp.stack_id = voltage->stack_id;
	gvcp.type = TYPE_GET_VOLTAGE_CALLBACK_PERIOD;
	gvcp.length = sizeof(GetVoltageCallbackPeriod);

	ipcon_device_write(voltage, (char *)&gvcp, sizeof(GetVoltageCallbackPeriod));

	if(ipcon_answer_sem_wait_timeout(voltage) != 0) {
		ipcon_sem_post_write(voltage);
		return E_TIMEOUT;
	}

	GetVoltageCallbackPeriodReturn *gvcpr = (GetVoltageCallbackPeriodReturn *)voltage->answer.buffer;
	*ret_period = gvcpr->period;

	ipcon_sem_post_write(voltage);

	return E_OK;
}

int voltage_set_analog_value_callback_period(Voltage *voltage, uint32_t period) {
	if(voltage->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(voltage);

	SetAnalogValueCallbackPeriod savcp;
	savcp.stack_id = voltage->stack_id;
	savcp.type = TYPE_SET_ANALOG_VALUE_CALLBACK_PERIOD;
	savcp.length = sizeof(SetAnalogValueCallbackPeriod);
	savcp.period = period;

	ipcon_device_write(voltage, (char *)&savcp, sizeof(SetAnalogValueCallbackPeriod));

	ipcon_sem_post_write(voltage);

	return E_OK;
}

int voltage_get_analog_value_callback_period(Voltage *voltage, uint32_t *ret_period) {
	if(voltage->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(voltage);

	voltage->answer.type = TYPE_GET_ANALOG_VALUE_CALLBACK_PERIOD;
	voltage->answer.length = sizeof(GetAnalogValueCallbackPeriodReturn);
	GetAnalogValueCallbackPeriod gavcp;
	gavcp.stack_id = voltage->stack_id;
	gavcp.type = TYPE_GET_ANALOG_VALUE_CALLBACK_PERIOD;
	gavcp.length = sizeof(GetAnalogValueCallbackPeriod);

	ipcon_device_write(voltage, (char *)&gavcp, sizeof(GetAnalogValueCallbackPeriod));

	if(ipcon_answer_sem_wait_timeout(voltage) != 0) {
		ipcon_sem_post_write(voltage);
		return E_TIMEOUT;
	}

	GetAnalogValueCallbackPeriodReturn *gavcpr = (GetAnalogValueCallbackPeriodReturn *)voltage->answer.buffer;
	*ret_period = gavcpr->period;

	ipcon_sem_post_write(voltage);

	return E_OK;
}

int voltage_set_voltage_callback_threshold(Voltage *voltage, char option, int16_t min, int16_t max) {
	if(voltage->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(voltage);

	SetVoltageCallbackThreshold svct;
	svct.stack_id = voltage->stack_id;
	svct.type = TYPE_SET_VOLTAGE_CALLBACK_THRESHOLD;
	svct.length = sizeof(SetVoltageCallbackThreshold);
	svct.option = option;
	svct.min = min;
	svct.max = max;

	ipcon_device_write(voltage, (char *)&svct, sizeof(SetVoltageCallbackThreshold));

	ipcon_sem_post_write(voltage);

	return E_OK;
}

int voltage_get_voltage_callback_threshold(Voltage *voltage, char *ret_option, int16_t *ret_min, int16_t *ret_max) {
	if(voltage->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(voltage);

	voltage->answer.type = TYPE_GET_VOLTAGE_CALLBACK_THRESHOLD;
	voltage->answer.length = sizeof(GetVoltageCallbackThresholdReturn);
	GetVoltageCallbackThreshold gvct;
	gvct.stack_id = voltage->stack_id;
	gvct.type = TYPE_GET_VOLTAGE_CALLBACK_THRESHOLD;
	gvct.length = sizeof(GetVoltageCallbackThreshold);

	ipcon_device_write(voltage, (char *)&gvct, sizeof(GetVoltageCallbackThreshold));

	if(ipcon_answer_sem_wait_timeout(voltage) != 0) {
		ipcon_sem_post_write(voltage);
		return E_TIMEOUT;
	}

	GetVoltageCallbackThresholdReturn *gvctr = (GetVoltageCallbackThresholdReturn *)voltage->answer.buffer;
	*ret_option = gvctr->option;
	*ret_min = gvctr->min;
	*ret_max = gvctr->max;

	ipcon_sem_post_write(voltage);

	return E_OK;
}

int voltage_set_analog_value_callback_threshold(Voltage *voltage, char option, uint16_t min, uint16_t max) {
	if(voltage->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(voltage);

	SetAnalogValueCallbackThreshold savct;
	savct.stack_id = voltage->stack_id;
	savct.type = TYPE_SET_ANALOG_VALUE_CALLBACK_THRESHOLD;
	savct.length = sizeof(SetAnalogValueCallbackThreshold);
	savct.option = option;
	savct.min = min;
	savct.max = max;

	ipcon_device_write(voltage, (char *)&savct, sizeof(SetAnalogValueCallbackThreshold));

	ipcon_sem_post_write(voltage);

	return E_OK;
}

int voltage_get_analog_value_callback_threshold(Voltage *voltage, char *ret_option, uint16_t *ret_min, uint16_t *ret_max) {
	if(voltage->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(voltage);

	voltage->answer.type = TYPE_GET_ANALOG_VALUE_CALLBACK_THRESHOLD;
	voltage->answer.length = sizeof(GetAnalogValueCallbackThresholdReturn);
	GetAnalogValueCallbackThreshold gavct;
	gavct.stack_id = voltage->stack_id;
	gavct.type = TYPE_GET_ANALOG_VALUE_CALLBACK_THRESHOLD;
	gavct.length = sizeof(GetAnalogValueCallbackThreshold);

	ipcon_device_write(voltage, (char *)&gavct, sizeof(GetAnalogValueCallbackThreshold));

	if(ipcon_answer_sem_wait_timeout(voltage) != 0) {
		ipcon_sem_post_write(voltage);
		return E_TIMEOUT;
	}

	GetAnalogValueCallbackThresholdReturn *gavctr = (GetAnalogValueCallbackThresholdReturn *)voltage->answer.buffer;
	*ret_option = gavctr->option;
	*ret_min = gavctr->min;
	*ret_max = gavctr->max;

	ipcon_sem_post_write(voltage);

	return E_OK;
}

int voltage_set_debounce_period(Voltage *voltage, uint32_t debounce) {
	if(voltage->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(voltage);

	SetDebouncePeriod sdp;
	sdp.stack_id = voltage->stack_id;
	sdp.type = TYPE_SET_DEBOUNCE_PERIOD;
	sdp.length = sizeof(SetDebouncePeriod);
	sdp.debounce = debounce;

	ipcon_device_write(voltage, (char *)&sdp, sizeof(SetDebouncePeriod));

	ipcon_sem_post_write(voltage);

	return E_OK;
}

int voltage_get_debounce_period(Voltage *voltage, uint32_t *ret_debounce) {
	if(voltage->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(voltage);

	voltage->answer.type = TYPE_GET_DEBOUNCE_PERIOD;
	voltage->answer.length = sizeof(GetDebouncePeriodReturn);
	GetDebouncePeriod gdp;
	gdp.stack_id = voltage->stack_id;
	gdp.type = TYPE_GET_DEBOUNCE_PERIOD;
	gdp.length = sizeof(GetDebouncePeriod);

	ipcon_device_write(voltage, (char *)&gdp, sizeof(GetDebouncePeriod));

	if(ipcon_answer_sem_wait_timeout(voltage) != 0) {
		ipcon_sem_post_write(voltage);
		return E_TIMEOUT;
	}

	GetDebouncePeriodReturn *gdpr = (GetDebouncePeriodReturn *)voltage->answer.buffer;
	*ret_debounce = gdpr->debounce;

	ipcon_sem_post_write(voltage);

	return E_OK;
}

int voltage_callback_voltage(Voltage *voltage, const unsigned char *buffer) {
	VoltageCallback *vc = (VoltageCallback *)buffer;
	((voltage_func_t)voltage->callbacks[vc->type])(vc->voltage);
	return sizeof(VoltageCallback);
}

int voltage_callback_analog_value(Voltage *voltage, const unsigned char *buffer) {
	AnalogValueCallback *avc = (AnalogValueCallback *)buffer;
	((analog_value_func_t)voltage->callbacks[avc->type])(avc->value);
	return sizeof(AnalogValueCallback);
}

int voltage_callback_voltage_reached(Voltage *voltage, const unsigned char *buffer) {
	VoltageReachedCallback *vrc = (VoltageReachedCallback *)buffer;
	((voltage_reached_func_t)voltage->callbacks[vrc->type])(vrc->voltage);
	return sizeof(VoltageReachedCallback);
}

int voltage_callback_analog_value_reached(Voltage *voltage, const unsigned char *buffer) {
	AnalogValueReachedCallback *avrc = (AnalogValueReachedCallback *)buffer;
	((analog_value_reached_func_t)voltage->callbacks[avrc->type])(avrc->value);
	return sizeof(AnalogValueReachedCallback);
}

void voltage_register_callback(Voltage *voltage, uint8_t cb, void *func) {
    voltage->callbacks[cb] = func;
}

void voltage_create(Voltage *voltage, const char *uid) {
	ipcon_device_create(voltage, uid);

	voltage->device_callbacks[TYPE_VOLTAGE] = voltage_callback_voltage;
	voltage->device_callbacks[TYPE_ANALOG_VALUE] = voltage_callback_analog_value;
	voltage->device_callbacks[TYPE_VOLTAGE_REACHED] = voltage_callback_voltage_reached;
	voltage->device_callbacks[TYPE_ANALOG_VALUE_REACHED] = voltage_callback_analog_value_reached;
}
