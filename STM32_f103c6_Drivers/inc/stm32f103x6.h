/*
 * File: stm32f103X6.h
 * Description: This is the header file for STM32F103 drivers
 * Author: Manal Nabil
 */

#ifndef INC_STM32F103X6_H_
#define INC_STM32F103X6_H_


//-----------------------------
//Includes
//-----------------------------

#include<stdint.h>
#include<stdlib.h>

//-----------------------------
//Base addresses for Memories
//-----------------------------




#define  Flash_Memory_BASE	                     0x08000000UL
#define  SRAM_Memory_BASE      			     	 0x20000000UL
#define  System_Memory_BASE	                     0x1FFFF000UL

#define  Peripherals_BASE	                     0x40000000UL

#define  Cortex_M3_internal_peripherals_BASE	 0xE0000000UL


//--------------------------------------------------------------------

//-----------------------------
//Base addresses for AHB Peripherals
//-----------------------------



#define RCC_BASE   0x40021000UL

//-----------------------------
//Base addresses for APB2 Peripherals
//-----------------------------

//GPIO

//A,B fully included in LQFP48 Package
#define GPIOA_BASE             0x40010800UL
#define GPIOB_BASE             0x40010C00UL

//C,D Partial included in LQFP48 Package
#define GPIOC_BASE             0x40011000UL
#define GPIOD_BASE             0x40011400UL

//E not included in LQFP48 Package
#define GPIOE_BASE             0x40011800UL

//-------

//EXTI
#define EXTI_BASE              0x40010400UL

//-------

//AFIO
#define AFIO_BASE              0x40010000UL
//-------


//--------------------------------------------------------------------
