#include "RCC.h"

void DMAUnresetEnableClock(){
	//only DMA2 streams are able to perform memory-to-memory transfers
	rcc->RCC_AHB1RSTR &= ~(1 << 22); 	//DMA2RST
	uint32_t data = rcc->RCC_AHB1RSTR;
	rcc->RCC_AHB1ENR &= 0;
	rcc->RCC_AHB1ENR  |= (1 << 22);		//DMA2EN	Clock the DMA2 for configuration change
	uint32_t data1 = rcc->RCC_AHB1ENR ;
	//DMA1 IS 21 POSITION
}

void gpioUnresetEnableClock(GPIO* port){
	int shift = ((int)port - (0x40020000))/(0x400);
	rcc->RCC_AHB1RSTR &= ~(1 << (shift));
	rcc->RCC_AHB1ENR |= (0x00100000 | ~(0 << (shift)));
}
