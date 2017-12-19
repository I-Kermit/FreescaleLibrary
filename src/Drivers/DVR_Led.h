/*
 * LedDriver.h
 *
 *  Created on: 1 Mar 2017
 *      Author: Peter Goddard
 */

#ifndef DRIVERS_DVR_LED_H_
#define DRIVERS_DVR_LED_H_

#include <stdbool.h>

#include "HAL/HAL_Gpio.h"

typedef enum{
	ORANGE_LED,
	YELLOW_LED,
	GREEN_LED,
	BLUE_LED,
	NO_OF_LEDS
} LedColour;

void LedInit(gpioInit_t * ledInit);
bool LedOn(LedColour colour);
bool LedOff(LedColour colour);

typedef struct led_driver_api
{
	void (*ledInit)(gpioInit_t * ledInit);
	bool (*ledOn)(LedColour colour);
	bool (*ledOff)(LedColour colour);
}
led_driver_api_t;

#endif /* DRIVERS_DVR_LED_H_ */
