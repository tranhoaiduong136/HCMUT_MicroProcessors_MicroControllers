/*
 * input_processing.c
 *
 *  Created on: Oct 18, 2021
 *      Author: Duong
 */
#include "main.h"
#include "input_processing.h"
#include "3Color_led.h"
static GPIO_PinState buttonBuffer[N0_OF_BUTTONS];
// we define two buffers for debouncing
static GPIO_PinState debounceButtonBuffer1[N0_OF_BUTTONS] = {0};
static GPIO_PinState debounceButtonBuffer2[N0_OF_BUTTONS] = {0};
// we define a flag for a button pressed more than 1 second .
static uint8_t flagForButtonPress1s[N0_OF_BUTTONS] = {0};
// we define counter for automatically increasing the value
// after the button is pressed more than 1 second .

enum ButtonName{MODE,TIME,EXEC};
static uint16_t counterForButtonPress1s[N0_OF_BUTTONS] = {0};

static uint16_t ButtonConfig[3] = {BUTTON_MODE,BUTTON_TIME,BUTTON_EXEC};

void button_reading (void){
	for (int i = 0;i < N0_OF_BUTTONS;i++){
		debounceButtonBuffer2[i] = debounceButtonBuffer1[i];
		debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(BUTTON_1_GPIO_Port,ButtonConfig[i]);

		if(debounceButtonBuffer1[i] == debounceButtonBuffer2[i]){
			buttonBuffer[i] = debounceButtonBuffer1[i];
		}
		if(buttonBuffer[i] == BUTTON_IS_PRESSED){
			// if a button is pressed , we start counting
			if(counterForButtonPress1s[i] < DURATION_FOR_AUTO_INCREASING) {
				++counterForButtonPress1s[i];
			}else {
				// the flag is turned on when 1 second has passed
				// since the button is pressed.
				flagForButtonPress1s[i] = 1;
			}
		}else {
			counterForButtonPress1s[i] = 0;
			flagForButtonPress1s[i] = 0;
		}
	}
}
unsigned char is_button_pressed (uint8_t index){
	return (buttonBuffer[index% N0_OF_BUTTONS] == BUTTON_IS_PRESSED);
}
unsigned char is_button_pressed_1s(unsigned char index) {
	if( index >= N0_OF_BUTTONS ){
		return 0xff ;
	}
	return ( flagForButtonPress1s[index ] == 1) ;
}
//########################################FSM##########################################///
enum ButtonState {BUTTON_RELEASED,BUTTON_PRESSED, BUTTON_PRESSED_MORE_THAN_1_SECOND};
// OFF at first
uint8_t buttonState[N0_OF_BUTTONS] = {BUTTON_RELEASED};

void fsm_for_input_processing(int index){
	switch(buttonState[index]){
		case BUTTON_RELEASED:
			if(is_button_pressed(index)){
				buttonState[index] = BUTTON_PRESSED;
				//INCREASE VALUE OF PORT A BY 1 UNIT

			}
			break;
		case BUTTON_PRESSED:
			if(!is_button_pressed(index)){
				buttonState[index] = BUTTON_RELEASED;
			}else{
				if(is_button_pressed_1s(0)){
					buttonState[index] = BUTTON_PRESSED_MORE_THAN_1_SECOND;
				}
			}
			break;
		case BUTTON_PRESSED_MORE_THAN_1_SECOND:
			if(!is_button_pressed(index)){
				buttonState[index] = BUTTON_RELEASED;
			}
			break;
	}
}
/////////////////////////////////MODE////////////////////////////////////////////////////
//Initial mode
enum statusName{MODE_CUR,RED_LIMIT,AMBER_LIMIT,GREEN_LIMIT};
static uint8_t status[NUMS_MODE] = {0};
static uint8_t limit[NUMS_MODE] = {4,100,100,100};

int getModevalue(void){
	return status[MODE_CUR];
}
int getCurrentStatus(int mode){
	return status[mode];
}

void controlButton(void){
	if(buttonState[MODE] == BUTTON_PRESSED || buttonState[MODE] == BUTTON_PRESSED_MORE_THAN_1_SECOND){
		status[MODE_CUR] = (status[MODE_CUR] + 1) % limit[MODE_CUR];
	}
	if(getModevalue() > 0){
		if(buttonState[TIME] == BUTTON_PRESSED || buttonState[TIME] == BUTTON_PRESSED_MORE_THAN_1_SECOND){
			status[getModevalue()] = (status[getModevalue()] + 1) % limit[getModevalue()];
		}
		if(buttonState[EXEC] == BUTTON_PRESSED || buttonState[EXEC] == BUTTON_PRESSED_MORE_THAN_1_SECOND){
			status[MODE_CUR] = 0;
			setLimitvalue(status[RED_LIMIT], status[AMBER_LIMIT], status[GREEN_LIMIT]);
		}
	}
}


