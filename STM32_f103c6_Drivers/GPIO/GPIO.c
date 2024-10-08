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

/**
 * @brief Initializes the specified GPIO pin(s).
 *
 * This function configures the mode and speed for the specified GPIO pin(s).
 *
 * @param[in] GPIOx Pointer to the GPIO peripheral (e.g., GPIOA, GPIOB,GPIOC).
 * @param[in] PinConfig Pointer to the configuration structure that contains the configuration information for the specified pin(s).
 */

void MCAL_GPIO_Init (GPIO_TypeDef * GPIOx, GPIO_PinConfig_t * PinConfig)
{
	if(PinConfig->GPIO_Pin_Number <= GPIO_PIN_7)
	{
		//Clear  CNF0[1:0] MODE0[1:0]
		GPIOx->CRL &= ~(0xf<< (Get_CRLH_Position(PinConfig->GPIO_Pin_Number)));

		//Set mode and Speed
		GPIOx->CRL |= (((PinConfig->GPIO_Mode <<2) | (PinConfig->GPIO_Output_Speed)) <<(Get_CRLH_Position(PinConfig->GPIO_Pin_Number)));
	}
	else if(PinConfig->GPIO_Pin_Number <= GPIO_PIN_15)
	{
		//Clear  CNF0[1:0] MODE0[1:0]
		GPIOx->CRH &= ~(0xf<< (Get_CRLH_Position(PinConfig->GPIO_Pin_Number)));

		//Set mode and Speed
		GPIOx->CRH |= (((PinConfig->GPIO_Mode <<2) | (PinConfig->GPIO_Output_Speed)) <<(Get_CRLH_Position(PinConfig->GPIO_Pin_Number)));
	}

	//If mode PullUp or PullDown
	if(PinConfig->GPIO_Mode == GPIO_MODE_INPUT_PU)
	{
		//0: No action on the corresponding ODRx bit
		//1: Set the corresponding ODRx bit
		GPIOx->BSRR = (uint32_t)Get_CRLH_Position(PinConfig->GPIO_Pin_Number);
	}
	else if(PinConfig->GPIO_Mode == GPIO_MODE_INPUT_PD)
	{
		//0: No action on the corresponding ODRx bit
		//1: Reset the corresponding ODRx bit
		GPIOx->BRR = (uint32_t)Get_CRLH_Position(PinConfig->GPIO_Pin_Number);
	}

}

/**
 * @brief Deinitializes the specified GPIO port.
 *
 * This function resets all pins of the specified GPIO port to their default values.
 *
 * @param[in] GPIOx Pointer to the GPIO peripheral (e.g., GPIOA, GPIOB).
 */

void MCAL_GPIO_DeInit(GPIO_TypeDef * GPIOx)
{
	if(GPIOx == GPIOA)
	{   // 0: No effect
		// 1: Reset IO port A
		RCC->APB2RSTR |= (2<<1);
		RCC->APB2RSTR &= ~(2<<1);
	}
	else if(GPIOx == GPIOB)
	{
		// 0: No effect
		// 1: Reset IO port B
		RCC->APB2RSTR |= (3<<1);
		RCC->APB2RSTR &= ~(3<<1);
	}
	else if(GPIOx == GPIOC)
	{
		// 0: No effect
		// 1: Reset IO port C
		RCC->APB2RSTR |= (4<<1);
		RCC->APB2RSTR &= ~(4<<1);
	}
	else if(GPIOx == GPIOD)
	{
		// 0: No effect
		// 1: Reset IO port D
		RCC->APB2RSTR |= (5<<1);
		RCC->APB2RSTR &= ~(5<<1);
	}
	else if(GPIOx == GPIOE)
	{
		// 0: No effect
		// 1: Reset IO port E
		RCC->APB2RSTR |= (6<<1);
		RCC->APB2RSTR &= ~(6<<1);
	}
}

/**
 * @brief Reads the state of the specified GPIO pin.
 *
 * This function reads the input data of the specified pin and returns its value (0 or 1).
 *
 * @param[in] GPIOx Pointer to the GPIO peripheral (e.g., GPIOA, GPIOB).
 * @param[in] PinNumber The number of the pin to read.
 * @return uint8_t The state of the pin (0 or 1).
 */

uint8_t MCAL_GPIO_ReadPin(GPIO_TypeDef * GPIOx,uint16_t PinNumber)
{

	uint8_t PinValue = GPIO_STATE_LOW;
    //I can't write this condition like (if((GPIOx->IDR & PinNumber) == (uint16_t)GPIO_STATE_HIGH))
	if((GPIOx->IDR & PinNumber) != (uint16_t)GPIO_STATE_LOW)
	{
		PinValue = GPIO_STATE_HIGH;
	}
	return PinValue;

}

/**
 * @brief Reads the state of all the pins in the specified GPIO port.
 *
 * This function reads the input data of the entire port and returns its value.
 *
 * @param[in] GPIOx Pointer to the GPIO peripheral (e.g., GPIOA, GPIOB).
 * @return uint16_t The state of the port.
 */

uint16_t MCAL_GPIO_ReadPort(GPIO_TypeDef * GPIOx)
{
	uint16_t PortValue = (uint16_t)(GPIOx->IDR);
	return PortValue;
}

/**
 * @brief Sets or clears the specified GPIO pin.
 *
 * This function writes the specified value (HIGH or LOW) to the specified pin.
 *
 * @param[in] GPIOx Pointer to the GPIO peripheral (e.g., GPIOA, GPIOB).
 * @param[in] PinNumber The number of the pin to write to.
 * @param[in] Value The value to write to the pin (0 for LOW, 1 for HIGH).
 */

void MCAL_GPIO_WritePin(GPIO_TypeDef * GPIOx,uint16_t PinNumber, uint8_t Value)
{
	if(Value != GPIO_STATE_LOW)
	{
		//0: No action on the corresponding ODRx bit
		//1: Set the corresponding ODRx bit

		GPIOx->BSRR = (uint32_t)PinNumber;
	}
	else
	{
		//0: No action on the corresponding ODRx bit
		//1: Reset the corresponding ODRx bit
		GPIOx->BRR = (uint32_t)PinNumber;
	}
}

/**
 * @brief Writes a value to the entire GPIO port.
 *
 * This function writes the specified value to all the pins in the specified port.
 *
 * @param[in] GPIOx Pointer to the GPIO peripheral (e.g., GPIOA, GPIOB).
 * @param[in] Value The value to write to the port.
 */

void MCAL_GPIO_WritePort(GPIO_TypeDef * GPIOx,uint16_t Value)
{
	GPIOx->ODR = (uint32_t)Value;
}

/**
 * @brief Toggles the state of the specified GPIO pin.
 *
 * This function inverts the state of the specified pin (from HIGH to LOW or vice versa).
 *
 * @param[in] GPIOx Pointer to the GPIO peripheral (e.g., GPIOA, GPIOB).
 * @param[in] PinNumber The number of the pin to toggle.
 */

void MCAL_GPIO_TogglePin(GPIO_TypeDef * GPIOx, uint16_t PinNumber)
{
	GPIOx->ODR ^= PinNumber;
}

