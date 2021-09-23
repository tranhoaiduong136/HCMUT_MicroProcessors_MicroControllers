/*
 * matrix_led.c
 *
 *  Created on: Sep 21, 2021
 *      Author: Duong
 */

#include "main.h"
#include "matrix_led.h"

int matrixLEDBuffer[NUMS_MLED];

static uint16_t colConversionGATE[COLS] = {CLK1,CLK2,CLK3,CLK4,CLK5};
static uint16_t rowConversionGATE[ROWS] = {CLK6,CLK7,CLK8,CLK9,CLK10,CLK11,CLK12};
// NUmber Conversion Variable:
uint8_t initialState[COLS] = {0x3E,0x41,0x41,0x41,0x3E};

uint8_t number0Conversion[COLS] = {0x00,0x00,0x01,0x00,0x00};
uint8_t number1Conversion[COLS] = {0x00,0x00,0x00,0x01,0x00};
uint8_t number2Conversion[COLS] = {0x00,0x00,0x00,0x00,0x04};
uint8_t number3Conversion[COLS] = {0x00,0x00,0x00,0x00,0x08};
uint8_t number4Conversion[COLS] = {0x00,0x00,0x00,0x00,0x10};
uint8_t number5Conversion[COLS] = {0x00,0x00,0x00,0x40,0x00};
uint8_t number6Conversion[COLS] = {0x00,0x00,0x40,0x00,0x00};
uint8_t number7Conversion[COLS] = {0x00,0x40,0x00,0x00,0x00};
uint8_t number8Conversion[COLS] = {0x10,0x00,0x00,0x00,0x00};
uint8_t number9Conversion[COLS] = {0x08,0x00,0x00,0x00,0x00};
uint8_t number10Conversion[COLS] = {0x04,0x00,0x00,0x00,0x00};
uint8_t number11Conversion[COLS] = {0x00,0x01,0x00,0x00,0x00};

static uint8_t sevenbitConversion[ROWS] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40};

// Will try this later
// uint8_t  (*numberConversion)[13] = {number0Conversion,number1Conversion,number2Conversion,number3Conversion,number4Conversion,
// number5Conversion,number6Conversion,number7Conversion,number8Conversion,number9Conversion,number10Conversion,
// number11Conversion};

uint8_t *typeFunc(int num){
	switch(num){
	case 0:
		return number0Conversion;
	case 1:
		return number1Conversion;
	case 2:
		return number2Conversion;
	case 3:
		return number3Conversion;
	case 4:
		return number4Conversion;
	case 5:
		return number5Conversion;
	case 6:
		return number6Conversion;
	case 7:
		return number7Conversion;
	case 8:
		return number8Conversion;
	case 9:
		return number9Conversion;
	case 10:
		return number10Conversion;
	case 11:
		return number11Conversion;
	default:
		break;
	}
	return NULL;
}


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
	for(int i = 0 ; i < COLS;i++){
		 	 uint8_t temp = initialState[i];
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
void updatematrixLEDBuffer(int val,int idx){
	matrixLEDBuffer[idx] = val;
}
void setNumberOnClock(int num){
	uint8_t *temp1 = typeFunc(matrixLEDBuffer[0]);
	for(int i = 0 ; i < COLS;i++){
			 	 uint8_t temp = temp1[i];
			     for(int j = 0 ; j < ROWS;j++){
			          if(temp & sevenbitConversion[j]){
			        	HAL_GPIO_WritePin(GROUP_PIN,colConversionGATE[i], ON);
			            HAL_GPIO_WritePin(GROUP_PIN, rowConversionGATE[j], OFF);

			          }
			     }
			}
}
void clearNumberOnClock(int num){
	uint8_t *temp1 = typeFunc(matrixLEDBuffer[0]);
	for(int i = 0 ; i < COLS;i++){
		 	 uint8_t temp = temp1[i];
		     for(int j = 0 ; j < ROWS;j++){
		          if(temp & sevenbitConversion[j]){
		            HAL_GPIO_WritePin(GROUP_PIN, rowConversionGATE[j], ON);
		            HAL_GPIO_WritePin(GROUP_PIN,colConversionGATE[i], OFF);
		          }
		     }
		}
}
void matrixLEDDriver(int idx){
	// Nothing yet
}
void clearAllClock(void){
	for(int i = 0;i < 7;i++){
		HAL_GPIO_WritePin(GROUP_PIN, rowConversionGATE[i], ON);
		if(i < 5){
			HAL_GPIO_WritePin(GROUP_PIN, colConversionGATE[i], OFF);
		}
	}
}
