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

//-*-*-*-*-*-*-*-*-*-*-*
//Peripheral register:
//-*-*-*-*-*-*-*-*-*-*-*

//-*-*-*-*-*-*-*-*-*-*-*
//RCC register:
//-*-*-*-*-*-*-*-*-*-*-*






typedef struct {
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;


}RCC_TypeDef;

//-*-*-*-*-*-*-*-*-*-*-*
//GPIO register:
//-*-*-*-*-*-*-*-*-*-*-*

typedef struct {
	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;

}GPIO_TypeDef;

//-*-*-*-*-*-*-*-*-*-*-*
//EXIT register:
//-*-*-*-*-*-*-*-*-*-*-*

typedef struct {
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;

}EXTI_TypeDef;

//-*-*-*-*-*-*-*-*-*-*-*
//AFIO register:
//-*-*-*-*-*-*-*-*-*-*-*

typedef struct {
	volatile uint32_t EVCR;
	volatile uint32_t MAPR;
	volatile uint32_t EXTICR1;
	volatile uint32_t EXTICR2;
	volatile uint32_t EXTICR3;
	volatile uint32_t EXTICR4;
	uint32_t reserved;
	volatile uint32_t MAPR2;

}AFIO_TypeDef;

//--------------------------------------------------------------------

//-*-*-*-*-*-*-*-*-*-*-*
//Peripheral Instants:
 //-*-*-*-*-*-*-*-*-*-*-*


#define GPIOA   ((GPIO_TypeDef * )GPIOA_BASE)
#define GPIOB   ((GPIO_TypeDef * )GPIOB_BASE)
#define GPIOC   ((GPIO_TypeDef * )GPIOC_BASE)
#define GPIOD   ((GPIO_TypeDef * )GPIOD_BASE)
#define GPIOE   ((GPIO_TypeDef * )GPIOE_BASE)


#define RCC     ((RCC_TypeDef * )RCC_BASE)

#define EXTI    ((EXTI_TypeDef * )EXTI_BASE)

#define AFIO    ((AFIO_TypeDef * )AFIO_BASE)

//-----------------------------------------------------------------

//-*-*-*-*-*-*-*-*-*-*-*
//clock enable Macros:
 //-*-*-*-*-*-*-*-*-*-*-*





#define RCC_GPIOA_CLK_EN()  (RCC->APB2ENR |= 1<<2)
#define RCC_GPIOB_CLK_EN()  (RCC->APB2ENR |= 1<<3)
#define RCC_GPIOC_CLK_EN()  (RCC->APB2ENR |= 1<<4)
#define RCC_GPIOD_CLK_EN()  (RCC->APB2ENR |= 1<<5)
#define RCC_GPIOE_CLK_EN()  (RCC->APB2ENR |= 1<<6)

#define RCC_AFIO_CLK_EN()   (RCC->APB2ENR |= 1<<0)



//-*-*-*-*-*-*-*-*-*-*-*
//IVT_IQR
//-*-*-*-*-*-*-*-*-*-*-*

#define EXTI0_IQR    6
#define EXTI1_IQR    7
#define EXTI2_IQR    8
#define EXTI3_IQR    9
#define EXTI4_IQR    10
#define EXTI5_IQR    23
#define EXTI6_IQR    23
#define EXTI7_IQR    23
#define EXTI8_IQR    23
#define EXTI9_IQR    23
#define EXTI10_IQR   40
#define EXTI11_IQR   40
#define EXTI12_IQR   40
#define EXTI13_IQR   40
#define EXTI14_IQR   40
#define EXTI15_IQR   40


#endif /* INC_STM32F103X6_H_ */
