/*
 * Timer_interrupt.h
 *
 *  Created on: Nov 3, 2021
 *      Author: Duong
 */

#ifndef INC_TIMER_INTERRUPT_H_
#define INC_TIMER_INTERRUPT_H_


#define BLINK 0
#define DELAY 1
#define LED 2

#define BLINK_TIME 500
#define DELAY_TIME 300
#define LED_TIME 20

#define TIMER_CYCLE 10  // 10ms callback 1 times

int timer_run(int,int);
#endif /* INC_TIMER_INTERRUPT_H_ */
