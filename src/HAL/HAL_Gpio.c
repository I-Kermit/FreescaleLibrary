/*
 * GPIO.c
 *
 *  Created on: 1 Mar 2017
 *      Author: Peter Goddard
 */

#include <stdint.h>
#include <stdbool.h>

#include "mcu.h"

#include "HAL/HAL_Gpio.h"

const gpio_driver_api_t freescale_m4_gpio_driver =
{
		GPIO_Init,
		GPIO_Set,
		GPIO_Clear
};

void GPIO_Init(gpioInit_t * gpioInit)
{
	uint16_t portCount;

	/* Turn on port A clock */
	SIM->SCGC5 = gpioInit->PortMask;

	/* Reset PORT A */
	PTA->PDDR = 0;
	for(portCount=0;portCount<gpioInit->ActiveGpioNo;portCount++)
	{
		/* Set PORT A (connected to LED's) for GPIO functionality */
		PORTA->PCR[gpioInit->ActiveGpioList[portCount]] = PORT_PCR_MUX(MUX_GPIO);
		/* Change PORT A to outputs */
		PTA->PDDR |= GPIO_PDDR_PDD(GPIO_PIN(gpioInit->ActiveGpioList[portCount]));
		/* Switch off LED */
		GPIO_Clear(PORT_A, gpioInit->ActiveGpioList[portCount]);
	}
}

bool GPIO_Set(portNo_t port, gpioNo_t gpioNo)
{
	bool failed = true;

	switch(port)
	{
		case PORT_A:
			PTA->PDOR &= ~GPIO_PDOR_PDO(GPIO_PIN(gpioNo));
			failed = false;
			break;
		case PORT_B:
			PTB->PDOR &= ~GPIO_PDOR_PDO(GPIO_PIN(gpioNo));
			failed = false;
			break;
		case PORT_C:
			PTC->PDOR &= ~GPIO_PDOR_PDO(GPIO_PIN(gpioNo));
			failed = false;
			break;
		case PORT_D:
			PTD->PDOR &= ~GPIO_PDOR_PDO(GPIO_PIN(gpioNo));
			failed = false;
			break;
		default:
			break;
	}

	return (failed);
}

bool GPIO_Clear(portNo_t port, gpioNo_t gpioNo)
{
	bool failed = true;

	switch(port)
	{
		case PORT_A:
			PTA->PDOR |= GPIO_PDOR_PDO(GPIO_PIN(gpioNo));
			failed = false;
			break;
		case PORT_B:
			PTB->PDOR |= GPIO_PDOR_PDO(GPIO_PIN(gpioNo));
			failed = false;
			break;
		case PORT_C:
			PTC->PDOR |= GPIO_PDOR_PDO(GPIO_PIN(gpioNo));
			failed = false;
			break;
		case PORT_D:
			PTD->PDOR |= GPIO_PDOR_PDO(GPIO_PIN(gpioNo));
			failed = false;
			break;
		default:
			break;
	}

	return (failed);
}
