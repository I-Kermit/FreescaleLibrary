/*
 * INT_SysTick.c
 *
 *  Created on: 8 Mar 2017
 *      Author: Peter Goddard
 */
#include <stddef.h>

#include "mcu.h"
#include "INT_SysTick.h"

static void DVR_SysTickInit(void);
static void DVR_SetFunction(void (*function)(void));

timer_driver_api_t freescale_m4_timer_driver =
{
	DVR_SysTickInit,
	DVR_SetFunction
};

static void DVR_SysTickInit(void)
{
	SysTick_Config(0x7FFFFF);
}

static void (*ptr_function)(void) = NULL;

static void DVR_SetFunction(void (*function)(void))
{
	ptr_function = function;
}

__attribute__((interrupt ("IRQ"))) void SysTick_Handler()
{
	if( ptr_function != NULL )
	{
		ptr_function();
	}
}
