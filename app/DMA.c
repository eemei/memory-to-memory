#include "DMA.h"
#include "gpio.h"
#include "RCC.h"


void configDMAM2M(void) {  // stream 7  channel 0
	DMAUnresetEnableClock();

	dma2->S7.CR &= ~(1 << EN);						//Stream Disable
	uint32_t data = dma2->S7.CR; 	 	 	 	 	// *read-only ->stream (enabled) */

	dma2->S7.CR |= ( 1 << PINC ) | ( 1 << MINC ) | ( 1 << PL0 ) | ( 1 << PL1 ) ;//| ( 1 << TCIE );
	uint32_t data2 = dma2->S7.CR;

	dma2->S7.CR &=  ~(3 << 25);
	dma2->S7.CR |= (channel0 << 25);  				/* CHANNEL 0 */

	dma2->S7.CR &= ~(2 << 6);
	dma2->S7.CR |= (M2M << 6 );      				/* DIRECTION TRANSFER MODE M2M */

	//MEMORY & PERIPHERAL increment disable
	dma2->S7.CR &= ~(1 << MINC);
	dma2->S7.CR |= (DMA_MemoryInc_Enable << MINC);

	dma2->S7.CR &= ~(1 << PINC);
	dma2->S7.CR |= (DMA_PeripheralInc_Enable << PINC);

	//peripheral burst
	dma2->S7.CR &= ~(2 << 21);
	dma2->S7.CR |= (DMA_PeripheralBurst_Single << 21);


	dma2->S7.CR &= ~(15 << 1);
	dma2->S7.CR |= (15 << 1);					// enable all interrupt(TC, HT, TE) and EN bit
}

void DatasizeBurstFIFO (uint32_t MemorySize, uint32_t PeripheralSize, uint32_t Burst, uint32_t FIFO){

	//source and destination data size word=32bit
		dma2->S7.CR &= ~(2 << 13);
		dma2->S7.CR |= (MemorySize << 13);

		dma2->S7.CR &= ~(2 << 11);
		dma2->S7.CR |= (PeripheralSize << 11);

		//FIFO
		dma2->S7.FCR &= (11 << FTH);
		dma2->S7.FCR |= (FIFO << FTH);

		dma2->S7.CR &= ~(2 << 23);
		dma2->S7.CR |= (Burst << 23);
}

void DMA_memcpy8( uint32_t pDstAddr, uint32_t pSrcAddr, unsigned int uSize ){
/* As per page 233 this is how to configure a stream */
	if( ( dma2->S7.CR & ( 1 << EN ) ) == 1 ){
         dma2->S7.CR &= ~( 1 << EN );  					// 1. If stream is enabled, disable it
         while( ( dma2->S7.CR & ( 1 << EN ) == 1) );
    }
	dma2->S7.PAR =  (uint32_t)pSrcAddr;					/* source address */
	dma2->S7.M0AR = (uint32_t)pDstAddr; 				/* destination address */
    dma2->S7.NDTR = uSize;     							// Number of data items to transfer
}

void enableDMA(){
	dma2->S7.CR &= ~1;
	dma2->S7.CR |= 1;     						// Stream Enable
}







