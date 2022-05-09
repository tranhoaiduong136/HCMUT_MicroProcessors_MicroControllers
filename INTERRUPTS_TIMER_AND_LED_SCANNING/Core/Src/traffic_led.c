/*
 * traffic_led.c
 *
 *  Created on: Nov 21, 2021
 *      Author: Duong
 */
#include"main.h"
#include"traffic_led.h"
static uint16_t RedLED[2] = {RED1,RED2};
static uint16_t YellowLED[2] = {YELLOW1,YELLOW2};
static uint16_t GreenLED[2] = {GREEN1,GREEN2};
static uint16_t *typeLED[3] = {RedLED,YellowLED,GreenLED};
static uint8_t counterBuffer[3] = {5,2,3};
enum {RED,YELLOW,GREEN};
int color1 = RED;
int color2 = YELLOW;
int limit1 = 0;
int limit2 = 0;
void initLED(void){
	HAL_GPIO_WritePin(GPIOA, RED1, OFF);
	HAL_GPIO_WritePin(GPIOA, YELLOW1, OFF);
	HAL_GPIO_WritePin(GPIOA, GREEN1, OFF);
	HAL_GPIO_WritePin(GPIOA, RED2, OFF);
	HAL_GPIO_WritePin(GPIOA, YELLOW2, OFF);
	HAL_GPIO_WritePin(GPIOA, GREEN2, OFF);
	 // Set first limit
	 limit1 = counterBuffer[color1];
	 limit2 = counterBuffer[color2];
	 int color1 = RED;
	 int color2 = YELLOW;
}
void trafficLIGHTStart(int led,int idx){
	  HAL_GPIO_WritePin(GPIOA, typeLED[led][idx], ON);
}
void trafficLIGHTChangeColor(int led,int idx){
	HAL_GPIO_WritePin(GPIOA, typeLED[(led)%3][idx], OFF);
	HAL_GPIO_WritePin(GPIOA, typeLED[(led+1)%3][idx], ON);
}




int	updateColor(int limit,int color,int index){
	if(limit == -1)trafficLIGHTChangeColor(color,index);
	return limit == -1 ? ++color%3 : color;
}
int updateLimit(int limit,int color){
	return limit == -1 ? counterBuffer[color %3] : --limit;
}
int getLimit1Value(void){
	return limit1;
}
int getLimit2Value(void){
	return limit2;
}

void setLimitvalue(int color,int value){
	counterBuffer[color] =  value;
}
void blinkLED2Hz(int color){
	HAL_GPIO_TogglePin(LED_PIN, typeLED[color-1][0]);
	HAL_GPIO_TogglePin(LED_PIN, typeLED[color-1][1]);
}
void countLEDBuffer(void){
	color1 = updateColor(limit1, color1,0);
	color2 = updateColor(limit2, color2,1);
	limit1 = updateLimit(limit1, color1);
	limit2 = updateLimit(limit2, color2);
}
