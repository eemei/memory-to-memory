#ifndef	__RCC_H__
#define	__RCC_H__

#include <stdint.h>
#include "DMA.h"
#include "Gpio.h"


typedef struct RCC_Type RCC_t;
struct RCC_Type{
	volatile uint32_t RCC_CR;
	volatile uint32_t RCC_PLLCFGR;
	volatile uint32_t RCC_CFGR;
	volatile uint32_t RCC_CIR;
	volatile uint32_t RCC_AHB1RSTR;
	volatile uint32_t RCC_AHB2RSTR;
	volatile uint32_t RCC_AHB3RSTR;
	volatile uint32_t RESERVE_0;
	volatile uint32_t RCC_APB1RSTR;
	volatile uint32_t RCC_APB2RSTR;
	volatile uint32_t RESERVE_1;
	volatile uint32_t RESERVE_2;
	volatile uint32_t RCC_AHB1ENR;
	volatile uint32_t RCC_AHB2ENR;
	volatile uint32_t RCC_AHB3ENR;
	volatile uint32_t RESERVE_3;
	volatile uint32_t RCC_APB1ENR;
	volatile uint32_t RCC_APB2ENR;
	volatile uint32_t RESERVE_4;
	volatile uint32_t RESERVE_5;
	volatile uint32_t RCC_AHB1LPENR;
	volatile uint32_t RCC_AHB2LPENR;
	volatile uint32_t RCC_AHB3LPENR;
	volatile uint32_t RESERVE_6;
	volatile uint32_t RCC_APB1LPENR;
	volatile uint32_t RCC_APB2LPENR;
	volatile uint32_t RESERVE_7;
	volatile uint32_t RESERVE_8;
	volatile uint32_t RCC_BDCR;
	volatile uint32_t RCC_CSR;
	volatile uint32_t RESERVE_9;
	volatile uint32_t RESERVE_10;
	volatile uint32_t RCC_SSCGR;
	volatile uint32_t RCC_PLLI2SCFGR;
	volatile uint32_t RCC_PLLSAICFGR;
	volatile uint32_t RCC_DCKCFGR;
};
//#define rcc	((RCC_t*)0x40023800)
//#define RCC_BASE_ADDRESS 0x40023800
#define rcc	((RCC_t*)RCC_BASE_ADDRESS)


void DMAUnresetEnableClock();
void gpioUnresetEnableClock(GPIO* port);

#include "Registers.h"
#endif	//__RCC_H__
