/*
 * 3Color_led.h
 *
 *  Created on: Nov 3, 2021
 *      Author: Duong
 */

#ifndef INC_3COLOR_LED_H_
#define INC_3COLOR_LED_H_

#define LED_PIN GPIOA
#define RED1 GPIO_PIN_1
#define YELLOW1 GPIO_PIN_2
#define GREEN1 GPIO_PIN_3
#define RED2 GPIO_PIN_4
#define YELLOW2 GPIO_PIN_5
#define GREEN2 GPIO_PIN_6
// define sign
#define ON RESET
#define OFF SET

#define LED_DELAY 500

void initLED(void);
void trafficLIGHTStart(int led,int idx);
void trafficLIGHTChangeColor(int led,int idx);

int getLimit1Value(void);
int getLimit2Value(void);
void countLEDBuffer(void);
// can be use
int CurrentModetrafficLIGHT(void);
void setLimitvalue(int,int,int);
void blinkLED2Hz(int color);
void fsm_for_trafficLIGHT(int mode);

#endif /* INC_3COLOR_LED_H_ */
