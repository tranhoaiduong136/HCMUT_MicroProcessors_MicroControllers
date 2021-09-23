/*
 * matrix_led.h
 *
 *  Created on: Sep 21, 2021
 *      Author: Duong
 */

#ifndef INC_MATRIX_LED_H_
#define INC_MATRIX_LED_H_
// Numbers of matrix led
#define NUMS_MLED 1
// Define gate
#define GROUP_PIN GPIOA
#define COLS 5
#define ROWS 7

#define CLK1 GPIO_PIN_2
#define CLK2 GPIO_PIN_3
#define CLK3 GPIO_PIN_4
#define CLK4 GPIO_PIN_5
#define CLK5 GPIO_PIN_6
#define CLK6 GPIO_PIN_13
#define CLK7 GPIO_PIN_12
#define CLK8 GPIO_PIN_11
#define CLK9 GPIO_PIN_10
#define CLK10 GPIO_PIN_9
#define CLK11 GPIO_PIN_8
#define CLK12 GPIO_PIN_7
// Define sign
#define ON SET
#define OFF RESET
#define SPEED 100
//Main functions
void matrixLEDInit(void);
void updatematrixLEDBuffer(uint8_t,int);
void matrixLEDDriver(int);



void clearAllClock(void);
#endif /* INC_MATRIX_LED_H_ */
