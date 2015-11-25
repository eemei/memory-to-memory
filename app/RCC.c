#include "RCC.h"

void DMAUnresetEnableClock(){
	//only DMA2 streams are able to perform memory-to-memory transfers

	rcc->RCC_AHB1RSTR &= (1 << 22); 	//DMA2RST
	rcc->RCC_AHB1ENR  |= (1 << 22);		//DMA2EN


}


//rcc->RCC_AHB1RSTR &= (1 << 21);		//DMA1RST
		//rcc->RCC_AHB1ENR  |= (1 << 21);		//DMA1EN
		// interrupt
		//rcc->RCC_AHB1LPENR &= (1 << 22);	//DMA2LPEN
		//..
		//rcc->RCC_AHB1LPENR &= (1 << 21);	//DMA1LPEN
		//..
