/*
 * matrix_led.c
 *
 *  Created on: Oct 17, 2021
 *      Author: Duong
 */

#include "main.h"
#include "matrix_led.h"

static uint16_t ROW[ROWS]={
		GPIO_PIN_8,GPIO_PIN_9,GPIO_PIN_10,GPIO_PIN_11,GPIO_PIN_12,GPIO_PIN_13,GPIO_PIN_14,GPIO_PIN_15
};
static uint16_t COL[COLS]={
		GPIO_PIN_2,GPIO_PIN_3,GPIO_PIN_10,GPIO_PIN_11,GPIO_PIN_12,GPIO_PIN_13,GPIO_PIN_14,GPIO_PIN_15
};
static uint8_t wordAConversion[8] = {
		0xF0,0xF8,0xFC,0x33,0x33,0xFC,0xF8,0xF0
};
static uint8_t rowConversion[8] = {
		0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80
};
void matrixLEDInit(void){
	//initial state
	int max = ROWS > COLS? ROWS : COLS;
	for(int i = 0;i < max;i++ ){
		if(i < ROWS){
			HAL_GPIO_WritePin(ROW_GROUP, ROW[i], OFF);
		}
		if(i < COLS){
			HAL_GPIO_WritePin(COL_GROUP,COL[i], OFF);
		}
	}
}


void matrixLEDDisplay(void){
	for(int i = 0;i < COLS;i++){
		startMatrixLedCOL(i);
		HAL_Delay(SPEED);
		clearMatrixLedCOL(i);
	}
}

uint8_t buffer_row[8] = {0};
int count_row = 0;
void startMatrixLedCOL(int col){
	HAL_GPIO_WritePin(COL_GROUP,COL[col],ON);
	uint8_t temp = wordAConversion[col];
	for(int j = 0;j < ROWS;j++){
		if(temp & rowConversion[j]){
			HAL_GPIO_WritePin(ROW_GROUP,ROW[j],ON);
			buffer_row[count_row] = j;
			++count_row;
		}
	}
}
void clearMatrixLedCOL(int col){
	HAL_GPIO_WritePin(COL_GROUP,COL[col],OFF);
	for(int i = 0; i < count_row;i++){
		HAL_GPIO_WritePin(ROW_GROUP,ROW[buffer_row[i]],OFF);
		buffer_row[i] = 0;
	}
	count_row = 0;
}
void shiftingLEDDisplay(void){
	uint8_t temp = wordAConversion[0];
	for(int i = 0; i < COLS-1;i++){
		wordAConversion[i] = wordAConversion[i+1];
	}
	wordAConversion[COLS-1] = temp;
}


