/*
 * led_7seg_anode.h
 *
 *  Created on: Sep 19, 2021
 *      Author: Duong
 */

#ifndef INC_LED_7SEG_ANODE_H_
#define INC_LED_7SEG_ANODE_H_
// Number of 7SEG
#define NUMS_7SEGS 1
// Gate
#define SEG0 GPIO_PIN_0
#define SEG1 GPIO_PIN_1
#define SEG2 GPIO_PIN_2
#define SEG3 GPIO_PIN_3
#define SEG4 GPIO_PIN_4
#define SEG5 GPIO_PIN_5
#define SEG6 GPIO_PIN_6

// Main func
void sevenSegmentLEDDriver(void);
void updatesevenSegmentLEDBuffer(uint8_t);


#endif /* INC_LED_7SEG_ANODE_H_ */
