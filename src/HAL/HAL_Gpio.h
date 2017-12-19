/*
 * GPIO.h
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
