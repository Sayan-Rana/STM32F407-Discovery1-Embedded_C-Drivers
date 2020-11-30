/*
 * stm32f407xx.h
 *
 *  Created on: Nov 28, 2020
 *      Author: Sayan Rana
 */

#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_

#include <stdint.h>

#define __vo				volatile

/*
 * BAse address of Flash and SRAM memories
 */

#define FLASH_BASEADDR					0x08000000U							// Base address of flash memory
#define SRAM1_BASEADDR					0x20000000U							// Base address of SRAM1
#define SRAM1_SIZE						(112 * 1024)U						// SRAM1 size is 112KB
#define SRAM2_BASEADDR					(SRAM1_BASEADDR + SRAM1_SIZE)		// SRAM2 base address and it's size is 16KB
#define ROM_BASEADDR					0x1FFF0000U							// System memory(ROM) base address


/*
 * AHBx and APBx Bus peripheral base addresses
 */

#define PERIPH_BASEADDR						0x40000000U
#define APB1PERIPH_BASEADDR					PERIPH_BASEADDR					// Base address of APB1 bus related peripherals
#define APB2PERIPH_BASEADDR					0x40010000U						// Base address of APB2 bus related peripherals
#define AHB1PERIPH_BASEADDR					0x40020000U						// Base address of AHB1 bus related peripherals
#define AHB2PERIPH_BASEADDR					0x50000000U						// Base address of AHB2 bus related peripherals


/*
 * Base addresses of peripherals which are hanging on AHB1 Bus
 */

#define GPIOA_BASEADDR					(AHB1PERIPH_BASEADDR + 0x0000)		// GPIOA is hanging on the 1st position of AHB1 Bus (AHB1 Bus peripheral base address + ofFset)
#define GPIOB_BASEADDR					(AHB1PERIPH_BASEADDR + 0x0400)		// GPIOB is hanging on the 2nd position of AHB1 Bus (AHB1 Bus peripheral base address + ofFset)
#define GPIOC_BASEADDR					(AHB1PERIPH_BASEADDR + 0x0800)		// GPIOC is hanging on the 3rd position of AHB1 Bus (AHB1 Bus peripheral base address + ofFset)
#define GPIOD_BASEADDR					(AHB1PERIPH_BASEADDR + 0x0C00)		// GPIOD is hanging on the 4th position of AHB1 Bus (AHB1 Bus peripheral base address + ofFset)
#define GPIOE_BASEADDR					(AHB1PERIPH_BASEADDR + 0x1000)		// GPIOE is hanging on the 5th position of AHB1 Bus (AHB1 Bus peripheral base address + ofFset)
#define GPIOF_BASEADDR					(AHB1PERIPH_BASEADDR + 0x1400)		// GPIOF is hanging on the 6th position of AHB1 Bus (AHB1 Bus peripheral base address + ofFset)
#define GPIOG_BASEADDR					(AHB1PERIPH_BASEADDR + 0x1800)		// GPIOG is hanging on the 7th position of AHB1 Bus (AHB1 Bus peripheral base address + ofFset)
#define GPIOH_BASEADDR					(AHB1PERIPH_BASEADDR + 0x1C00)		// GPIOH is hanging on the 8th position of AHB1 Bus (AHB1 Bus peripheral base address + ofFset)
#define GPIOI_BASEADDR					(AHB1PERIPH_BASEADDR + 0x2000)		// GPIOI is hanging on the 9th position of AHB1 Bus (AHB1 Bus peripheral base address + ofFset)

#define RCC_BASEADDR					(AHB1PERIPH_BASEADDR + 0x3800)		// RCC is hanging on the 13th position of AHB1 Bus (AHB1 Bus peripheral base address + ofFset)

/*
 * Base addresses of peripherals which are hanging on APB1 Bus
 */

#define I2C1_BASEADDR					(APB1PERIPH_BASEADDR + 0x5400)		// Base address of APB1 bus peripherals + offset I2C1
#define I2C2_BASEADDR					(APB1PERIPH_BASEADDR + 0x5800)		// Base address of APB1 bus peripherals + offset I2C2
#define I2C3_BASEADDR					(APB1PERIPH_BASEADDR + 0x5C00)		// Base address of APB1 bus peripherals + offset I2C3
#define SPI2_BASEADDR					(APB1PERIPH_BASEADDR + 0x3800)		// Base address of APB1 bus peripherals + offset SPI2
#define SPI3_BASEADDR					(APB1PERIPH_BASEADDR + 0x3C00)		// Base address of APB1 bus peripherals + offset SPI3
#define USART2_BASEADDR					(APB1PERIPH_BASEADDR + 0x4400)		// Base address of APB1 bus peripherals + offset USART2
#define USART3_BASEADDR					(APB1PERIPH_BASEADDR + 0x4800)		// Base address of APB1 bus peripherals + offset USART3
#define UART4_BASEADDR					(APB1PERIPH_BASEADDR + 0x4C00)		// Base address of APB1 bus peripherals + offset UART4
#define UART5_BASEADDR					(APB1PERIPH_BASEADDR + 0x5000)		// Base address of APB1 bus peripherals + offset UART5


/*
 * Base addresses of peripherals which are hanging on APB2 Bus
 */

#define SPI1_BASEADDR					(APB2PERIPH_BASEADDR + 0x3000)		// Base address of APB2 bus peripherals + offset SPI1
#define USART1_BASEADDR					(APB2PERIPH_BASEADDR + 0x1000)		// Base address of APB2 bus peripherals + offset USART1
#define USART6_BASEADDR					(APB2PERIPH_BASEADDR + 0x1400)		// Base address of APB2 bus peripherals + offset USART6
#define EXTI_BASEADDR					(APB2PERIPH_BASEADDR + 0x3C00)		// Base address of APB2 bus peripherals + offset EXT Interrupt
#define	SYSCFG_BASEADDR					(APB2PERIPH_BASEADDR + 0x3800)		// Base address of APB2 bus peripherals + offset SYS Configuration


/************************************Peripheral registers definition structure******************************************/
/*
 * This structure is only for STM32F407VG microcontroller AHB1 Bus GPIO peripheral
 */

typedef struct
{
	__vo uint32_t MODER;				/* GPIO port mode register,																					 Address offset : 0x00 */
	__vo uint32_t OTYPER;				/* GPIO port output type register,																			 Address offset : 0x04 */
	__vo uint32_t OSPEEDR;				/* GPIO port output speed register,																			 Address offset : 0x08 */
	__vo uint32_t PUPDR;				/* GPIO port pull-up/pull-down register																		 Address offset : 0x0C */
	__vo uint32_t IDR;					/* GPIO port input data register,																			 Address offset : 0x10 */
	__vo uint32_t ODR;					/* GPIO port output data register,																			 Address offset : 0x14 */
	__vo uint32_t BSRR;					/* GPIO port bit set/reset register,																	   	 Address offset : 0x18 */
	__vo uint32_t LCKR;					/* GPIO port configuration lock register,																	 Address offset : 0x1C */
	__vo uint32_t AFR[2];				/* AFR[0] : GPIO alternate function low register, AFR[1] : GPIO alternate function high register,			 Address offset: 0x20 and 0x24 */
}GPIO_RegDef_t;


/*
 * This structure is only for STM32F407VG microcontroller AHB1 Bus RCC peripheral
 */

typedef struct
{
	__vo uint32_t CR;					/* RCC clock control register,					Address offset : 0x00 */
	__vo uint32_t PLLCFGR;				/* RCC PLL configuration register,				Address offset : 0x04 */
	__vo uint32_t CFGR;					/* RCC clock configuration register,			Address offset : 0x08 */
	__vo uint32_t CIR;					/* RCC clock interrupt register,				Address offset : 0x0C */
	__vo uint32_t AHB1RSTR;				/* RCC AHB1 peripheral reset register,			Address offset : 0x10 */
	__vo uint32_t AHB2RSTR;				/* RCC AHB2 peripheral reset register,			Address offset : 0x14 */
	__vo uint32_t AHB3RSTR;				/* RCC AHB3 peripheral reset register,			Address offset : 0x18 */
	__vo uint32_t Reserved0;			/* Reserved 4 Byte*/
	__vo uint32_t APB1RSTR;				/* RCC APB1 peripheral reset register,			Address offset : 0x20 */
	__vo uint32_t APB2RSTR;				/* RCC APB2 peripheral reset register,			Address offset : 0x24 */
	__vo uint32_t Reserved1[2];			/* Reserved 8 Byte */
	__vo uint32_t AHB1ENR;				/* RCC AHB1 peripheral clock enable register,	Address offset : 0x30 */
	__vo uint32_t AHB2ENR;				/* RCC AHB2 peripheral clock enable register,	Address offset : 0x34 */
	__vo uint32_t AHB3ENR;				/* RCC AHB3 peripheral clock enable register,	Address offset : 0x38 */
	__vo uint32_t Reserved2;			/* Reserved 4 Byte */
	__vo uint32_t APB1ENR;				/* RCC APB1 peripheral clock enable register,	Address offset : 0x40 */
	__vo uint32_t APB2ENR;				/* RCC APB2 peripheral clock enable register,	Address offset : 0x44 */
	__vo uint32_t Reserved3[2];			/* Reserved 8 Byte */
	__vo uint32_t AHB1LPENR;			/* RCC AHB1 peripheral clock enable in low power mode register,		Address offset : 0x50 */
	__vo uint32_t AHB2LPENR;			/* RCC AHB2 peripheral clock enable in low power mode register,		Address offset : 0x54 */
	__vo uint32_t AHB3LPENR;			/* RCC AHB3 peripheral clock enable in low power mode register,		Address offset : 0x58 */
	__vo uint32_t Reserved4;			/* Reserved  4 Byte */
	__vo uint32_t APB1LPENR;			/* RCC APB1 peripheral clock enable in low power mode register,		Address offset : 0x60 */
	__vo uint32_t APB2LPENR;			/* RCC APB2 peripheral clock enable in low power mode register,		Address offset : 0x64 */
	__vo uint32_t Reserved5[2];			/* Reserved 8 Byte */
	__vo uint32_t BDCR;					/* RCC Backup domain control register,			Address offset : 0x70 */
	__vo uint32_t CSR;					/* RCC clock control & status register,			Address offset : 0x74 */
	__vo uint32_t Reserved6[2];			/* Reserved  8 Byte */
	__vo uint32_t SSCGR;				/* RCC spread spectrum clock generation register,					Address offset : 0x80 */
	__vo uint32_t PLLI2SCFGR;			/* RCC PLLI2S configuration register,			Address offset : 0x84 */
}RCC_RegDef_t;



/*
 * Peripheral definition (Peripheral base addresses tpyecasted to xxx_RegDef_t)
 */

//GPIO
#define GPIOA							((GPIO_RegDef_t*) GPIOA_BASEADDR)
#define GPIOB							((GPIO_RegDef_t*) GPIOB_BASEADDR)
#define GPIOC							((GPIO_RegDef_t*) GPIOC_BASEADDR)
#define GPIOD							((GPIO_RegDef_t*) GPIOD_BASEADDR)
#define GPIOE							((GPIO_RegDef_t*) GPIOE_BASEADDR)
#define GPIOF							((GPIO_RegDef_t*) GPIOF_BASEADDR)
#define GPIOG							((GPIO_RegDef_t*) GPIOG_BASEADDR)
#define GPIOH							((GPIO_RegDef_t*) GPIOH_BASEADDR)
#define GPIOI							((GPIO_RegDef_t*) GPIOI_BASEADDR)

//RCC
#define RCC								((RCC_RegDef_t*) RCC_BASEADDR)


/*
 * Clock Enable Macros for GPIOx peripherals
 */

#define GPIOA_PCLK_EN()					(RCC->AHB1ENR |= (1 << 0))
#define GPIOB_PCLK_EN()					(RCC->AHB1ENR |= (1 << 1))
#define GPIOC_PCLK_EN()					(RCC->AHB1ENR |= (1 << 2))
#define GPIOD_PCLK_EN()					(RCC->AHB1ENR |= (1 << 3))
#define GPIOE_PCLK_EN()					(RCC->AHB1ENR |= (1 << 4))
#define GPIOF_PCLK_EN()					(RCC->AHB1ENR |= (1 << 5))
#define GPIOG_PCLK_EN()					(RCC->AHB1ENR |= (1 << 6))
#define GPIOH_PCLK_EN()					(RCC->AHB1ENR |= (1 << 7))
#define GPIOI_PCLK_EN()					(RCC->AHB1ENR |= (1 << 8))


/*
 * Clock Enable Macro for I2Cx peripheral
 */

#define I2C1_PCLK_EN()					(RCC->APB1ENR |= (1 << 21))
#define I2C2_PCLK_EN()					(RCC->APB1ENR |= (1 << 22))
#define I2C3_PCLK_EN()					(RCC->APB1ENR |= (1 << 23))


/*
 * Clock Enable Macro for SPIx peripheral
 */

#define SPI1_PCLK_EN()					(RCC->APB2ENR |= (1 << 12))
#define SPI2_PCLK_EN()					(RCC->APB1ENR |= (1 << 14))
#define SPI3_PCLK_EN()					(RCC->APB1ENR |= (1 << 15))


/*
 * Clock Enable Macro for USARTx peripheral
 */

#define USART1_PCLK_EN()				(RCC->APB2ENR |= (1 << 4))
#define USART2_PCLK_EN()				(RCC->APB1ENR |= (1 << 17))
#define USART3_PCLK_EN()				(RCC->APB1ENR |= (1 << 18))
#define USART6_PCLK_EN()				(RCC->APB2ENR |= (1 << 5))


/*
 * Clock Enable Macro for SYSCNFG peripheral
 */

#define SYSCFG_PCLK_EN()				(RCC->APB2ENR |= (1 << 14))


/*
 * Clock Disable Macro for GPIOx peripheral
 */

#define GPIOA_PCLK_DI()					(RCC->AHB1ENR &= ~(1 << 0))
#define GPIOB_PCLK_DI()					(RCC->AHB1ENR &= ~(1 << 1))
#define GPIOC_PCLK_DI()					(RCC->AHB1ENR &= ~(1 << 2))
#define GPIOD_PCLK_DI()					(RCC->AHB1ENR &= ~(1 << 3))
#define GPIOE_PCLK_DI()					(RCC->AHB1ENR &= ~(1 << 4))
#define GPIOF_PCLK_DI()					(RCC->AHB1ENR &= ~(1 << 5))
#define GPIOG_PCLK_DI()					(RCC->AHB1ENR &= ~(1 << 6))
#define GPIOH_PCLK_DI()					(RCC->AHB1ENR &= ~(1 << 7))
#define GPIOI_PCLK_DI()					(RCC->AHB1ENR &= ~(1 << 8))


/*
 * Clock Disable Macro for I2Cx peripheral
 */

#define I2C1_PCLK_DI()					(RCC->APB1ENR &= ~(1 << 21))
#define I2C2_PCLK_DI()					(RCC->APB1ENR &= ~(1 << 22))
#define I2C3_PCLK_DI()					(RCC->APB1ENR &= ~(1 << 23))


/*
 * Clock Disable Macro for SPIx peripheral
 */

#define SPI1_PCLK_DI()					(RCC->APB2ENR &= ~(1 << 12))
#define SPI2_PCLK_DI()					(RCC->APB1ENR &= ~(1 << 14))
#define SPI3_PCLK_DI()					(RCC->APB1ENR &= ~(1 << 15))


/*
 * Clock Disable Macro for USARTx peripheral
 */

#define USART1_PCLK_DI()				(RCC->APB2ENR &= ~(1 << 4))
#define USART2_PCLK_DI()				(RCC->APB1ENR &= ~(1 << 17))
#define USART3_PCLK_DI()				(RCC->APB1ENR &= ~(1 << 18))
#define USART6_PCLK_DI()				(RCC->APB2ENR &= ~(1 << 5))


/*
 * Clock Disable Macro for SYSCNFG peripheral
 */

#define SYSCFG_PCLK_DI()				(RCC->APB2ENR &= ~(1 << 14))


/*
 * Macros to reset GPIOx peripherals
 */
#define GPIOA_REG_RESET()	do{	RCC->AHB1RSTR |= (1 << 0);	RCC->AHB1RSTR &= ~(1 << 0);	}while(0)			/*Do while condition zero loop*/
#define GPIOB_REG_RESET()	do{	RCC->AHB1RSTR |= (1 << 1);	RCC->AHB1RSTR &= ~(1 << 1);	}while(0)			/*Do while condition zero loop*/
#define GPIOC_REG_RESET()	do{	RCC->AHB1RSTR |= (1 << 2);	RCC->AHB1RSTR &= ~(1 << 2);	}while(0)			/*Do while condition zero loop*/
#define GPIOD_REG_RESET()	do{	RCC->AHB1RSTR |= (1 << 3);	RCC->AHB1RSTR &= ~(1 << 3);	}while(0)			/*Do while condition zero loop*/
#define GPIOE_REG_RESET()	do{	RCC->AHB1RSTR |= (1 << 4);	RCC->AHB1RSTR &= ~(1 << 4);	}while(0)			/*Do while condition zero loop*/
#define GPIOF_REG_RESET()	do{	RCC->AHB1RSTR |= (1 << 5);	RCC->AHB1RSTR &= ~(1 << 5);	}while(0)			/*Do while condition zero loop*/
#define GPIOG_REG_RESET()	do{	RCC->AHB1RSTR |= (1 << 6);	RCC->AHB1RSTR &= ~(1 << 6);	}while(0)			/*Do while condition zero loop*/
#define GPIOH_REG_RESET()	do{	RCC->AHB1RSTR |= (1 << 7);	RCC->AHB1RSTR &= ~(1 << 7);	}while(0)			/*Do while condition zero loop*/
#define GPIOI_REG_RESET()	do{	RCC->AHB1RSTR |= (1 << 8);	RCC->AHB1RSTR &= ~(1 << 8);	}while(0)			/*Do while condition zero loop*/



/*
 * Some generic macros
 */

#define ENABLE						1
#define DISABLE						0
#define SET							ENABLE
#define RESET						DISABLE
#define GPIO_PIN_SET				SET
#define GPIO_PIN_RESET				RESET

#include "stm32f407xx_GPIO_driver.h"


#endif /* INC_STM32F407XX_H_ */







