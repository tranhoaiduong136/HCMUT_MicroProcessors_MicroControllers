/*
 * matrix_led.h
 *
 *  Created on: Oct 17, 2021
 *      Author: Duong
 */

#ifndef INC_MATRIX_LED_H_
#define INC_MATRIX_LED_H_

#define COL_GROUP GPIOA
#define ROW_GROUP GPIOB
#define ROWS 8
#define COLS 8
#define SPEED 10

#define ON RESET
#define OFF SET

void matrixLEDInit(void);
//Ex9:
void matrixLEDDisplay(void);
void startMatrixLedCOL(int);
void clearMatrixLedCOL(int);
//Ex10
void shiftingLEDDisplay(void);

#endif /* INC_MATRIX_LED_H_ */
