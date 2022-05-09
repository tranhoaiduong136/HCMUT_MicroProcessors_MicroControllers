/*
 * input_reading.c
 *
 *  Created on: Nov 21, 2021
 *      Author: Duong
 */


#include"input_reading.h"
#include"main.h"

static GPIO_PinState buttonBuffer[N0_OF_BUTTONS];

static GPIO_PinState debounceButtonBuffer1[N0_OF_BUTTONS] = {0};
static GPIO_PinState debounceButtonBuffer2[N0_OF_BUTTONS] = {0};

static uint16_t buttonPin[3] = {BUTTON_MODE,BUTTON_TIME,BUTTON_EXEC};

void reading_Init(void){
	for (int i=0; i < N0_OF_BUTTONS; i++){
		debounceButtonBuffer1[i]=BUTTON_IS_RELEASED;
		debounceButtonBuffer2[i]=BUTTON_IS_RELEASED;
		buttonBuffer[i]=BUTTON_IS_RELEASED;
	}
}
static uint8_t counterInterval=0;
void button_reading (void){
	if (counterInterval>=3){
		counterInterval=0;
		for (unsigned int i = 0; i < N0_OF_BUTTONS ; i ++){
			debounceButtonBuffer2[i] = debounceButtonBuffer1[i];
			debounceButtonBuffer1[i] = HAL_GPIO_ReadPin (BUTTON_1_GPIO_Port,buttonPin[i]);
			if( debounceButtonBuffer1[i] == debounceButtonBuffer2[i]){
				buttonBuffer[i] = debounceButtonBuffer1 [i];
			}
		}
	}
	else counterInterval++;
}
unsigned char is_button_pressed(unsigned char index){
	if( index >= N0_OF_BUTTONS ) return 0;
	if  ( buttonBuffer [index] == BUTTON_IS_PRESSED ){
		buttonBuffer[index]= BUTTON_IS_RELEASED;
		return 1;
	}
	else return 0;
}

