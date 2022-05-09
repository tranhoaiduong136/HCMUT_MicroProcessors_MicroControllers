/*
 * input_processing.h
 *
 *  Created on: Oct 18, 2021
 *      Author: Duong
 */

#ifndef INC_INPUT_PROCESSING_H_
#define INC_INPUT_PROCESSING_H_

#define NUMS_MODE 4
#define N0_OF_BUTTONS 3
#define BUTTON_1_GPIO_Port GPIOA
#define BUTTON_MODE GPIO_PIN_7
#define BUTTON_TIME GPIO_PIN_8
#define BUTTON_EXEC GPIO_PIN_9

# define DURATION_FOR_AUTO_INCREASING 100
# define BUTTON_IS_PRESSED GPIO_PIN_RESET
# define BUTTON_IS_RELEASED GPIO_PIN_SET


void button_reading (void);
unsigned char is_button_pressed(unsigned char);
unsigned char is_button_pressed_1s(unsigned char);


void fsm_for_input_processing(int index);
int getModevalue(void);
int getCurrentStatus(int);
void controlButton(void);

#endif /* INC_INPUT_PROCESSING_H_ */
