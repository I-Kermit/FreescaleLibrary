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
