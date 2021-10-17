/*
 * Timer_Interrupt.c
 *
 *  Created on: Oct 8, 2021
 *      Author: Duong
 */
#include "main.h"
#include "Timer_Interrupt.h"
//change state global variable
int stateflag = 0;
// Timer delay variable
int timer0_flag = 0;
int timer0_counter = 0;

void startDelay(void){
	timer0_flag = 1;
	timer0_counter = DELAY_TIME/TIMER_CYCLE;
}
int getDelayCounter(void){
	return timer0_counter;
}
int getDelayState(void){
	return timer0_flag;
}
void timerDELAY_run(void){
	timer0_counter--;
	if(timer0_counter <= 0){
		timer0_flag = 0;
	}
}

int setTimerDot(void){
	return DOT_TIME / TIMER_CYCLE;
}
int timerDot_run(int dot_count){
	dot_count--;
	if(dot_count <= 0){
		dot_count = DOT_TIME;
		HAL_GPIO_TogglePin(GPIOA, DOT);
		return setTimerDot();
	}
	return dot_count;
}
int getChangeStateLED(void){
	return stateflag;
}
int setTimerLED(void){
	return LED_TIME/ TIMER_CYCLE; // 500ms
}
int timerLED_run(int led_counter){
	led_counter--;
	if(led_counter <= 0){
		stateflag = 1;
		return setTimerLED();
	}
	// Normal
	stateflag = 0;
	return led_counter;
}

int timerWord_run(int word_counter){
	return word_counter <= 0? WORD_TIME/TIMER_CYCLE : (--word_counter);
}

