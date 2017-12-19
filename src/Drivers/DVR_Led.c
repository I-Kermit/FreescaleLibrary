#include <stdbool.h>

#include "Drivers/DVR_Led.h"
#include "HAL/HAL_Gpio.h"
#include "Interface/IF_Gpio.h"

const led_driver_api_t freescale_m4_led_driver =
{
		LedInit,
		LedOn,
		LedOff
};

void LedInit(gpioInit_t * ledGpio)
{
	GPIO_Init(ledGpio);
}

bool LedOn(LedColour colour)
{
	bool failed = true;

	switch (colour) {
		case ORANGE_LED:
			failed = GPIO_Set(PORT_A, ORANGE_LED_PORT_A_11);
			break;
		case YELLOW_LED:
			failed = GPIO_Set(PORT_A, YELLOW_LED_PORT_A_28);
			break;
		case GREEN_LED:
			failed = GPIO_Set(PORT_A, GREEN_LED_PORT_A_29);
			break;
		case BLUE_LED:
			failed = GPIO_Set(PORT_A, BLUE_LED_PORT_A_10);
			break;
		default:
			break;
	}

	return (failed);
}

bool LedOff(LedColour colour)
{
	switch (colour) {
		case ORANGE_LED:
			GPIO_Clear(PORT_A, ORANGE_LED_PORT_A_11);
			break;
		case YELLOW_LED:
			GPIO_Clear(PORT_A, YELLOW_LED_PORT_A_28);
			break;
		case GREEN_LED:
			GPIO_Clear(PORT_A, GREEN_LED_PORT_A_29);
			break;
		case BLUE_LED:
			GPIO_Clear(PORT_A, BLUE_LED_PORT_A_10);
			break;
		default:
			break;
	}

	return (true);
}
