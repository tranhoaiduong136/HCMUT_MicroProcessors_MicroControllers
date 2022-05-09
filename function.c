#include "function.h"

#include "main.h"
void runLed1(){
	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_1);
}
void runLed2(){
	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_2);
}
