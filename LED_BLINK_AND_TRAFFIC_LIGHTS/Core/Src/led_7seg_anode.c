/*
 * led_7seg_anode.c
 *
 *  Created on: Sep 19, 2021
 *      Author: Duong
 */
#include "main.h"
#include "led_7seg_anode.h"

static uint8_t sevenSegmentLEDConversionAnode[10] = {
		// Convert from binary of anode led to hex
		0xC0, //0
		0xF9, //1
		0xA4, //2
		0xB0, //3
		0x99, //4
		0x92, //5
		0x82, //6
		0xF8, //7
		0x80, //8
		0x90  //9
};
// FOR Cathode if it is used

//static uint8_t sevenSegmentLEDConversionCathode[10] = {
//		0x3F, //0
//		0x06, //1
//		0x5B, //2
//		0x4F, //3
//		0x66, //4
//		0x6D, //5
//		0x7D, //6
//		0x07, //7
//		0x7F, //8
//		0x4F, //9
//};
static uint8_t sevenSegmentbitConversion[7] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40};
static uint8_t gate[7] = {SEG0,SEG1,SEG2,SEG3,SEG4,SEG5,SEG6};

static uint8_t sevenSegmentLEDBuffer[NUMS_7SEGS];


void updatesevenSegmentLEDBuffer(uint8_t val){
	uint8_t idx = NUMS_7SEGS - 1;
	sevenSegmentLEDBuffer[idx] = val;
}
void sevenSegementLEDDriver(void){
	uint8_t temp =sevenSegmentLEDConversionAnode[sevenSegmentLEDBuffer[0]];
	for(int i = 0; i < 7;i++){
		if(temp & sevenSegmentbitConversion[i]){
			HAL_GPIO_WritePin(GPIOB, gate[i], SET);
		}
		else{
			HAL_GPIO_WritePin(GPIOB, gate[i], RESET);
		}
	}
}

