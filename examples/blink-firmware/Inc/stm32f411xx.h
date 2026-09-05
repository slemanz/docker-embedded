#ifndef INC_STM32F411XX_H_
#define INC_STM32F411XX_H_

// this header file describes the microcontroller
// only what a blink needs: RCC + GPIO
#include <stdint.h>

#define __vo volatile


/*
 * base addresses of Flash and SRAM memories
 */

#define FLASH_BASEADDR						0x08000000U
#define SRAM1_BASEADDR						0x20000000U

/*
 * AHBx and APBx Bus Peripheral base addresses
 */

#define PERIPH_BASE							0x40000000U
#define AHB1PERIPH_BASE						0x40020000U

/*
 * Base addresses of peripherals which are hanging on AHB1 bus
 */

#define GPIOA_BASEADDR						(AHB1PERIPH_BASE + 0x0000U)
#define GPIOB_BASEADDR						(AHB1PERIPH_BASE + 0x0400U)
#define GPIOC_BASEADDR						(AHB1PERIPH_BASE + 0x0800U)

#define RCC_BASEADDR						(AHB1PERIPH_BASE + 0x3800U)


/*******************peripheral register definition structures*******************/

typedef struct
{
	__vo uint32_t MODER;		/* configure the mode of pin 			address offset: 0x00 */
	__vo uint32_t OTYPER;		/* output type (push-pull/open drain) 	address offset: 0x04 */
	__vo uint32_t OSPEEDR;
	__vo uint32_t PUPDR;
	__vo uint32_t IDR;
	__vo uint32_t ODR;
	__vo uint32_t BSRR;
	__vo uint32_t LCKR;
	__vo uint32_t AFR[2];
}GPIO_RegDef_t;

typedef struct
{
	__vo uint32_t CR;			// 0x00
	__vo uint32_t PLLCFGR;		// 0x04
	__vo uint32_t CFGR;			// 0x08
	__vo uint32_t CIR;			// 0x0C
	__vo uint32_t AHB1RSTR;		// 0x10
	__vo uint32_t AHB2RSTR;		// 0x14
	__vo uint32_t reserved[2];
	__vo uint32_t APB1RSTR;		// 0x20
	__vo uint32_t APB2RSTR;		// 0x24
	__vo uint32_t reserved1[2];
	__vo uint32_t AHB1ENR;		// 0x30
	__vo uint32_t AHB2ENR;		// 0x34
	__vo uint32_t reserved2[2];
	__vo uint32_t APB1ENR;		// 0x40
	__vo uint32_t APB2ENR;		// 0x44
}RCC_RegDef_t;


/*
 * peripheral definitions (peripheral base addresses typecasted to xxx_RegDef_t)
 */

#define GPIOA			((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB			((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC			((GPIO_RegDef_t*)GPIOC_BASEADDR)

#define RCC				((RCC_RegDef_t*)RCC_BASEADDR)


/*
 * Clock enable macros for GPIOx peripherals
 */

#define GPIOA_PCLK_EN()		(RCC->AHB1ENR |= (1 << 0))
#define GPIOB_PCLK_EN()		(RCC->AHB1ENR |= (1 << 1))
#define GPIOC_PCLK_EN()		(RCC->AHB1ENR |= (1 << 2))


/*
 * some generic macros
 */

#define ENABLE				1
#define DISABLE				0
#define _SET				ENABLE
#define _RESET				DISABLE
#define GPIO_PIN_SET		_SET
#define GPIO_PIN_RESET		_RESET


#endif /* INC_STM32F411XX_H_ */