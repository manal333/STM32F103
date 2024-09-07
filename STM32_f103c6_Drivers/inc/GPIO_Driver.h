/*
 * File: goio.h
 * Description: This is the header file of GPIO driver for STM32F103
 * Author: Manal Nabil
 */

#ifndef INC_GPIO_DRIVER_H_
#define INC_GPIO_DRIVER_H_

//-----------------------------
//Includes
//-----------------------------

#include<stm32f103x6.h>

//-----------------------------
//User type definitions (structures)
//-----------------------------

typedef struct
{
	uint16_t GPIO_Pin_Number  ;	//Specifics the GPIO pins to be configured .
	                            // This parameter can be a value of @ref GPIO_PINS_define
	uint8_t GPIO_Mode         ; //Specifics the GPIO mode to be configured .
	                            // This parameter can be a value of @ref GPIO_MODE_define
	uint8_t GPIO_Output_Speed ; //Specifics the speed for the selected pins .
	                            // This parameter can be a value of @ref GPIO_SPEED_define
}GPIO_PinConfig_t;

