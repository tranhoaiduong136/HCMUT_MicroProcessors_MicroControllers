/*
 * Timer_Interrupt.h
 *
 *  Created on: Oct 8, 2021
 *      Author: Duong
 */

#ifndef INC_TIMER_INTERRUPT_H_
#define INC_TIMER_INTERRUPT_H_

#define DOT GPIO_PIN_4
#define DOT_TIME 400
#define LED_TIME 200
#define DELAY_TIME 200
#define WORD_TIME 200
#define TIMER_CYCLE 10  // 10ms callback 1 times


// Delay time
void startDelay(void);
int getDelayState(void);
int getDelayCounter(void);
void timerDELAY_run(void);

//DOT time
int setTimerDot(void);
int timerDot_run(int);
//LED_7SEG time
int getChangeStateLED(void);
int setTimerLED(void);
int timerLED_run(int);

//Word shift:
int timerWord_run(int);
#endif /* INC_TIMER_INTERRUPT_H_ */
