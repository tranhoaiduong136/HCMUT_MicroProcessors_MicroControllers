/*
 * Timer_interrupt.c
 *
 *  Created on: Nov 3, 2021
 *      Author: Duong
 */
#include "main.h"
#include "Timer_Interrupt.h"

static int TimeRun[3]= {BLINK_TIME,DELAY_TIME,LED_TIME};

int timer_run(int time,int mode){
	return time < 0? TimeRun[mode]/TIMER_CYCLE : (--time);
}
