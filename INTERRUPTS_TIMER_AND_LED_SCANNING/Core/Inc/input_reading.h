/*
 * input_reading.h
 *
 *  Created on: Nov 21, 2021
 *      Author: Duong
 */

#ifndef INC_INPUT_READING_H_
#define INC_INPUT_READING_H_

#define N0_OF_BUTTONS 3
#define BUTTON_1_GPIO_Port GPIOA
#define BUTTON_MODE GPIO_PIN_10
#define BUTTON_TIME GPIO_PIN_9
#define BUTTON_EXEC GPIO_PIN_8

# define DURATION_FOR_AUTO_INCREASING 100
# define BUTTON_IS_PRESSED GPIO_PIN_RESET
# define BUTTON_IS_RELEASED GPIO_PIN_SET

void reading_Init(void);
void button_reading (void);
unsigned char is_button_pressed(unsigned char);


#endif /* INC_INPUT_READING_H_ */
