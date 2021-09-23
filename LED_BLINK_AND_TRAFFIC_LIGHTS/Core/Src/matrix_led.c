/*
 * matrix_led.c
 *
 *  Created on: Sep 21, 2021
 *      Author: Duong
 */

#include "main.h"
#include "matrix_led.h"

static uint8_t matrixLEDBuffer[NUMS_MLED];
uint16_t colConversionGATE[COLS] = {CLK1,CLK2,CLK3,CLK4,CLK5};
uint16_t rowConversionGATE[ROWS] = {CLK6,CLK7,CLK8,CLK9,CLK10,CLK11,CLK12};
// NUmber Conversion Variable:
uint8_t number0Conversion[COLS] = {0x3E,0x41,0x41,0x41,0x3E};
uint8_t number1Conversion[COLS] = {0x11,0x21,0x7F,0x01,0x01};
uint8_t number2Conversion[COLS] = {0x43,0x45,0x49,0x51,0x61};
uint8_t number3Conversion[COLS] = {0x49,0x49,0x49,0x49,0x7F};
uint8_t number4Conversion[COLS] = {};
uint8_t number5Conversion[COLS] = {};
uint8_t number6Conversion[COLS] = {};
uint8_t number7Conversion[COLS] = {};
uint8_t number8Conversion[COLS] = {};
uint8_t number9Conversion[COLS] = {};


uint8_t (*numberConversion)[10] = {number0Conversion,number1Conversion,number2Conversion,number3Conversion,
		number3Conversion,number4Conversion,number5Conversion,number6Conversion,
		number7Conversion,number8Conversion,number9Conversion};

static uint8_t sevenbitConversion[ROWS] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40};


// Main func
void matrixLEDInit(void){
	//initial state
	int max = ROWS > COLS? ROWS : COLS;
	for(int i = 0;i < max;i++ ){
	if(i < ROWS){
		HAL_GPIO_WritePin(GROUP_PIN, rowConversionGATE[i], ON);
		}
	if(i < COLS){
		HAL_GPIO_WritePin(GROUP_PIN, colConversionGATE[i], OFF);
		}
	}
	//Number 0
	updatematrixLEDBuffer(0, 0);
	matrixLEDDriver(0);
}
void updatematrixLEDBuffer(uint8_t val,int idx){
	matrixLEDBuffer[idx] = val;
}

void matrixLEDDriver(int idx){
	for(int i = 0 ; i < COLS;i++){
	    // Led in 1 row is open
	    uint8_t temp = numberConversion[matrixLEDBuffer[idx]][i];
	      HAL_GPIO_WritePin(GROUP_PIN,colConversionGATE[i], ON);
	        for(int j = 0 ; j < ROWS;j++){
	          if(temp & sevenbitConversion[j]){
	            HAL_GPIO_WritePin(GROUP_PIN, rowConversionGATE[j], OFF);
	          }
	        }
	         HAL_Delay(SPEED);
	         for(int j = 0 ; j < ROWS;j++){
	            HAL_GPIO_WritePin(GROUP_PIN, rowConversionGATE[j], ON);
	          }
	         HAL_GPIO_WritePin(GROUP_PIN,colConversionGATE[i], OFF);
	         }
}
void clearAllClock(void){
	for(int i = 0;i < 7;i++){
		HAL_GPIO_WritePin(GROUP_PIN, rowConversionGATE[i], ON);
		if(i < 5){
			HAL_GPIO_WritePin(GROUP_PIN, colConversionGATE[i], OFF);
		}
	}
}
