/* Concatenated header file */ 
#ifndef _FREESCALE_DRIVER_H_ 
#define _FREESCALE_DRIVER_H_ 
/*
 * IF_Gpio.h
 *
 *  Created on: 1 Mar 2017
 *      Author: Peter Goddard
 */

#ifndef INTERFACE_IF_GPIO_H_
#define INTERFACE_IF_GPIO_H_

typedef enum
{
	BLUE_LED_PORT_A_10 = 10,
	ORANGE_LED_PORT_A_11 = 11,
	YELLOW_LED_PORT_A_28 = 28,
	GREEN_LED_PORT_A_29 = 29
}
ledPortMap;

#endif /* INTERFACE_IF_GPIO_H_ */
/*
 * HAL_Gpio.h
 *
 *  Created on: 1 Mar 2017
 *      Author: Peter Goddard
 */

#ifndef HAL_HAL_GPIO_H_
#define HAL_HAL_GPIO_H_

#include <stdint.h>
#include <stdbool.h>

#define GPIO_PIN_MASK 0x1Fu
#define GPIO_PIN(x)   (((1)<<(x & GPIO_PIN_MASK)))

#define MUX_GPIO (1)

typedef enum
{
	PORT_A,
	PORT_B,
	PORT_C,
	PORT_D
}
portNo_t;

typedef enum
{
	GPIO_0,
	GPIO_1,
	GPIO_2,
	GPIO_3,
	GPIO_4,
	GPIO_5,
	GPIO_6,
	GPIO_7,
	GPIO_8,
	GPIO_9,
	GPIO_10,
	GPIO_11,
	GPIO_12,
	GPIO_13,
	GPIO_14,
	GPIO_15,
	GPIO_16,
	GPIO_17,
	GPIO_18,
	GPIO_19,
	GPIO_20,
	GPIO_21,
	GPIO_22,
	GPIO_23,
	GPIO_24,
	GPIO_25,
	GPIO_26,
	GPIO_27,
	GPIO_28,
	GPIO_29,
	GPIO_30,
	GPIO_31
}
gpioNo_t;

#define MAX_GPIO (GPIO_31)

typedef struct gpioInit
{
	uint32_t PortMask;
	uint32_t ActiveGpioList[MAX_GPIO];
	uint32_t ActiveGpioNo;
}
gpioInit_t;

void GPIO_Init(gpioInit_t * gpioInit);
bool GPIO_Set(portNo_t port, gpioNo_t gpioNo);
bool GPIO_Clear(portNo_t port, gpioNo_t gpioNo);

typedef struct gpio_driver_api
{
	void (*gpio_Init)(gpioInit_t * gpioInit);
	bool (*gpio_Set)(portNo_t port, gpioNo_t gpioNo);
	bool (*gpio_Clear)(portNo_t port, gpioNo_t gpioNo);
}
gpio_driver_api_t;

#endif /* HAL_HAL_GPIO_H_ */
/*
 * DVR_Led.h
 *
 *  Created on: 1 Mar 2017
 *      Author: Peter Goddard
 */

#ifndef DRIVERS_DVR_LED_H
#define DRIVERS_DVR_LED_H

#include <stdbool.h>

#if defined(COMPILE_LIBRARY)
#include "HAL/HAL_Gpio.h"
#endif

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

extern const led_driver_api_t freescale_m4_led_driver;

#endif /* DRIVERS_DVR_LED_H */
/*
 * INT_SysTick.h
 *
 *  Created on: 8 Mar 2017
 *      Author: Peter Goddard
 */

#ifndef INTERRUPTS_SYSTICK_INT_SYSTICK_H_
#define INTERRUPTS_SYSTICK_INT_SYSTICK_H_

typedef struct timer_driver_api{
	void (*dvr_SysTickInit)(void);
	void (*dvr_SysTickFunction)(void (*function)(void));
}
timer_driver_api_t;

#endif /* INTERRUPTS_SYSTICK_INT_SYSTICK_H_ */
#endif /* _FREESCALE_DRIVER_H_ */ 
