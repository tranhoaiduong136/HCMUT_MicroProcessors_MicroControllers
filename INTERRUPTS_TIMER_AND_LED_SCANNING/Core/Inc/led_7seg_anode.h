/*
 * led_7seg_anode.h
 *
 *  Created on: Oct 7, 2021
 *      Author: Duong
 */

#ifndef INC_LED_7SEG_ANODE_H_
#define INC_LED_7SEG_ANODE_H_
// Number of 7SEG
#define NUMS_7SEGS 2
#define GROUP_PIN GPIOB
// Gate
#define SEG0 GPIO_PIN_0
#define SEG1 GPIO_PIN_1
#define SEG2 GPIO_PIN_2
#define SEG3 GPIO_PIN_3
#define SEG4 GPIO_PIN_4
#define SEG5 GPIO_PIN_5
#define SEG6 GPIO_PIN_6

//#define SEG7 GPIO_PIN_7
//#define SEG8 GPIO_PIN_8
//#define SEG9 GPIO_PIN_9
//#define SEG10 GPIO_PIN_10
//#define SEG11 GPIO_PIN_11
//#define SEG12 GPIO_PIN_12
//#define SEG13 GPIO_PIN_13



// Main func
void sevenSegmentLEDInit(void);
void updatesevenSegmentLEDBuffer(uint8_t,int);
void sevenSegementLEDDriver(int);


#endif /* INC_LED_7SEG_ANODE_H_ */
