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

//-----------------------------
//Macros Configuration References
//-----------------------------


/*@ref
Module_REF_NAME_define
 */

//@ref GPIO_PINS_define
//shift
#define GPIO_PIN_0       ((uint16_t)0x0001)
#define GPIO_PIN_1       ((uint16_t)0x0002)
#define GPIO_PIN_2       ((uint16_t)0x0004)
#define GPIO_PIN_3       ((uint16_t)0x0008)
#define GPIO_PIN_4       ((uint16_t)0x0010)
#define GPIO_PIN_5       ((uint16_t)0x0020)
#define GPIO_PIN_6       ((uint16_t)0x0040)
#define GPIO_PIN_7       ((uint16_t)0x0080)
#define GPIO_PIN_8       ((uint16_t)0x0100)
#define GPIO_PIN_9       ((uint16_t)0x0200)
#define GPIO_PIN_10      ((uint16_t)0x0400)
#define GPIO_PIN_11      ((uint16_t)0x0800)
#define GPIO_PIN_12      ((uint16_t)0x1000)
#define GPIO_PIN_13      ((uint16_t)0x2000)
#define GPIO_PIN_14      ((uint16_t)0x4000)
#define GPIO_PIN_15      ((uint16_t)0x8000)
#define GPIO_ALL_PINS    ((uint16_t)0xFFFF)


//@ref GPIO_STATE_define

#define GPIO_STATE_HIGH      1
#define GPIO_STATE_LOW       0

//@ref GPIO_MODE_define

/*
 0: Analog mode
 1: Floating input (reset state)
 2: Input with pull-up
 3: Input with pull-down
 4: General purpose output push-pull
 5: General purpose output Open-drain
 6: Alternate function output Push-pull
 7: Alternate function output Open-drain
 8: Alternate function input
 */
//set value
#define GPIO_MODE_ANALOG            0x00000000u  // Analog mode
#define GPIO_MODE_INPUT_FLO         0x00000001u  // Floating mode
#define GPIO_MODE_INPUT_PU          0x00000002u  // Input with pull up
#define GPIO_MODE_INPUT_PD          0x00000002u  // Input with pull down
#define GPIO_MODE_OUTPUT_PP         0x00000000u  // General purpose output push-pull
#define GPIO_MODE_OUTPUT_OD         0x00000001u  // General purpose output Open-drain
#define GPIO_MODE_OUTPUT_AF_PP      0x00000002u  // Alternate function output Push-pull
#define GPIO_MODE_OUTPUT_AF_OD      0x00000003u  // Alternate function output Open-drain
#define GPIO_MODE_INPUT_AF          0x00000002u  // Alternate function input


//@ref GPIO_SPEED_define

/*
0: Input mode
1: Output mode, max speed 10 MHz.
2: Output mode, max speed 2 MHz.
3: Output mode, max speed 50 MHz.
 */
//set value
#define GPIO_SPEED_INPUT  0x00000000u  //Input mode
#define GPIO_SPEED_10M    0x00000001u  //Output mode, max speed 10 MHz.
#define GPIO_SPEED_2M     0x00000002u  //Output mode, max speed 2 MHz.
#define GPIO_SPEED_50M    0x00000003u  //Output mode, max speed 50 MHz.

