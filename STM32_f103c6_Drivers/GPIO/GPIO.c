/*
 * File: gpio.c
 * Description: This file contains the implementation of GPIO driver for STM32F103
 * Author: Manal Nabil
 */


#include<GPIO_Driver.h>


uint8_t Get_CRLH_Position(uint16_t PinNumber)
{
	if(PinNumber == GPIO_PIN_0 || PinNumber == GPIO_PIN_8)
		return 0;
	if(PinNumber == GPIO_PIN_1 || PinNumber == GPIO_PIN_9)
		return 4;
	if(PinNumber == GPIO_PIN_2 || PinNumber == GPIO_PIN_10)
		return 8;
	if(PinNumber == GPIO_PIN_3 || PinNumber == GPIO_PIN_11)
		return 12;
	if(PinNumber == GPIO_PIN_4 || PinNumber == GPIO_PIN_12)
		return 16;
	if(PinNumber == GPIO_PIN_5 || PinNumber == GPIO_PIN_13)
		return 20;
	if(PinNumber == GPIO_PIN_6 || PinNumber == GPIO_PIN_14)
		return 24;
	if(PinNumber == GPIO_PIN_7 || PinNumber == GPIO_PIN_15)
		return 28;
}

