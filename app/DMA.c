#include "DMA.h"
#include "stm32f4xx.h"
#include "gpio.h"
#include "RCC.h"





void configDMAM2M(void) {  // stream 7  channel 0

	DMAUnresetEnableClock();

	dma2->DMA_LISR &= 0x00000000;
	dma2->DMA_HISR &= 0x00000000; 							// should be cleared before the stream can be re-enabled

	dma2->DMA_S7CR &= ~(1 << EN);							//Stream Disable

	//Configure the total number of data items to be transferred
	//dma2->DMA_S7NDTR = 0x00010000;							/*can be written->stream (disabled).
	 	 	 	 	 	  	 	 	 	 	 	 	 	 	// *read-only ->stream (enabled) */

	dma2->DMA_S7CR |= ( 1 << PINC ) | ( 1 << MINC ) | ( 1 << PL0 ) | ( 1 << PL1 ) | ( 1 << TCIE );

	//source and destination start addresses
	//dma2->DMA_S7PAR =  (uint32_t)dataAdressSource;			/* source address */
	//dma2->DMA_S7M0AR = (uint32_t)dataAdressDestination; 	/* destination address */


	dma2->DMA_S7CR &=  ~(000 << 25);
	dma2->DMA_S7CR |= (channel0 << 25);  					/* CHANNEL 0 */

	dma2->DMA_S7CR &= ~(00 << 6);
	dma2->DMA_S7CR |= (M2M << 6 );      					/* DIRECTION TRANSFER MODE M2M */


	//source and destination data size word=32bit
	dma2->DMA_S7CR &= ~(00 << 13);							/* DMA_MemoryDataSize_Word */
	dma2->DMA_S7CR |= (DMA_MemoryDataSize_Word << 13);

	dma2->DMA_S7CR &= ~(00 << 11);							/* DMA_PeripheralDataSize_Word */
	dma2->DMA_S7CR |= (DMA_PeripheralDataSize_Word << 11);

	//MEMORY AND PERIPHERAL increment disable
	dma2->DMA_S7CR &= ~(0 << 10);
	dma2->DMA_S7CR |= (DMA_MemoryInc_Disable << 10);

	dma2->DMA_S7CR &= ~(0 << 9);
	dma2->DMA_S7CR |= (DMA_PeripheralInc_Disable << 9);

	dma2->DMA_S7CR &= ~(00 << 23);
	dma2->DMA_S7CR |= (DMA_MemoryBurst_Single << 23);

	dma2->DMA_S7CR &= ~(00 << 23);
	dma2->DMA_S7CR |= (DMA_MemoryBurst_Single << 23);

	dma2->DMA_S7CR &= ~(00 << 21);
	dma2->DMA_S7CR |= (DMA_PeripheralBurst_Single << 21);

	dma2->DMA_HIFCR |= ( 1 << CTCIF7);						//clear transfer complete interrupt flag
	//dma2->DMA_HIFCR &= ~( 0 << CTCIF7);
	//dma2->DMA_S7CR |= ( 1 << EN );   		//12133454778889

}

void DMA_memcpy8( uint16_t pDstAddr, uint16_t pSrcAddr, unsigned int uSize ){
    /* As per page 233 this is how to configure a stream */
    if( ( dma2->DMA_S7CR & ( 1 << EN ) ) == 1 ){
         dma2->DMA_S7CR &= ~( 1 << EN );  					// 1. If stream is enabled, disable it
         while( ( dma2->DMA_S7CR & ( 1 << EN ) == 1) );
    }
	dma2->DMA_S7PAR =  (uint16_t)pSrcAddr;					/* source address */
	dma2->DMA_S7M0AR = (uint16_t)pDstAddr; 					/* destination address */
    dma2->DMA_S7NDTR = uSize;     							// Number of data items to transfer
    dma2->DMA_S7CR |= ( 1 << EN );     						// Stream Enable
}



void resetTransferCompleteError(){
	uint32_t status;
	status = dma2->DMA_HISR;
	//status &= 1;
	if(status == 1){
		dma2->DMA_HISR &= ~( 1 << 27 );
	}
}










