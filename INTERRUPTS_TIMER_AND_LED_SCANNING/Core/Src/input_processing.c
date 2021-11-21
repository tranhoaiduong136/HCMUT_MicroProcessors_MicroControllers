/*
 * input_processing.c
 *
 *  Created on: Oct 18, 2021
 *      Author: Duong
 */
#include "main.h"
#include "input_processing.h"
#include "input_reading.h"
#include "Timer_Interrupt.h"
#include"traffic_led.h"
enum ButtonName{MODE,TIME,EXEC};

/////////////////////////////////MODE////////////////////////////////////////////////////
//Initial mode
static int status[NUMS_MODE] = {0,0,0,0};

void initStatus(void){
	for(int i =0 ;i < NUMS_MODE;i++){
		status[i] = 0;
	}
}
int getModeValue(){
	return status[0];
}
//########################################FSM##########################################///
enum ButtonState { MODE_0, MODE_1, MODE_2, MODE_3};
enum ButtonState buttonState = MODE_3;
uint8_t normalMode = 0;
void fsm_for_input_processing(void){
	switch(buttonState){
	case MODE_0:
		status[0] = 0;
		if(normalMode == 0){ // Start led
			normalMode = 1;
			trafficLIGHTStart(0,0);
			trafficLIGHTStart(1,1);
		}
		if(getDelayCounter() <= 0){
			countLEDBuffer();
			updateClockBuffer(getLimit1Value(),getLimit2Value());
			startDelay(700);
		}
		if(is_button_pressed(0)){
			buttonState = MODE_1;
			InitTimer();
			stopDelay();
			initLED();
		}
		break;
	case MODE_1:
		status[0] = 1;
		if(getDelayCounter() < 0){
			updateClockBuffer(1,status[1]);
			startDelay(100);
		}
		if(is_button_pressed(0)){
			buttonState = MODE_2;
			InitTimer();
			stopDelay();
			initLED();
		}
		if (is_button_pressed(1)){
			status[1]=(status[1]+1)%100;
			stopDelay();
		}
		if (is_button_pressed(2)){
			setLimitvalue(0, status[1]);
		}
		break;
	case MODE_2:
		status[0] = 2;
		if(getDelayCounter() < 0){
			updateClockBuffer(2,status[2]);
			startDelay(100);
		}
		if(is_button_pressed(0)){
			buttonState = MODE_3;
			InitTimer();
			stopDelay();
			initLED();
		}
		if (is_button_pressed(1)){
			status[2]=(status[2]+1)%100;
			stopDelay();
		}
		if (is_button_pressed(2)){
			setLimitvalue(1, status[2]);
		}
		break;
	case MODE_3:
		status[0] =3;
		if(getDelayCounter() < 0){
			updateClockBuffer(3,status[3]);
			startDelay(100);
		}
		if(is_button_pressed(0)){
			buttonState = MODE_0;
			InitTimer();
			stopDelay();
			initLED();
			normalMode = 0;
		}
		if (is_button_pressed(1)){
			status[3]=(status[3]+1)%100;
			stopDelay();
		}
		if (is_button_pressed(2)){
			setLimitvalue(2, status[3]);
		}
		break;
	default:
		buttonState = MODE_0;
	}
}
