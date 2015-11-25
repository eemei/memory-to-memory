#include "DMA.h"

/**
  * @brief  Configure the DMA controller according to the Stream parameters
  *         defined in 	DMA.h file
  * @note  This function is used to :
  *        -1- Enable DMA2 clock
  *        -2- Select the DMA functional Parameters
  *        -3- Select the DMA instance to be used for the transfer
  *        -4- Select Callbacks functions called after Transfer complete and
               Transfer error interrupt detection
  *        -5- Initialize the DMA stream
  *        -6- Configure NVIC for DMA transfer complete/error interrupts
  *        -7- Start the DMA transfer using the interrupt mode
  *
  */

void configDMAM2M() {  // stream 7  channel 0

	dma2->DMA_LISR &= 0x00000000;
	dma2->DMA_HISR &= 0x00000000; 				// should be cleared before the stream can be re-enabled

	dma2->DMA_S7CR &= (0 << 0);					/*	clear STREAM FLAG */

	//Configure the total number of data items to be transferred
	dma2->DMA_S7NDTR = 0x00010000;				/*can be written->stream (disabled).
	 	 	 	 	 	  	 	 	 	 	 	 *read-only ->stream (enabled) */


	//source and destination start addresses
	dma2->DMA_S7PAR =  (uint32_t)dataAdressSource;			/* source address */
	dma2->DMA_S7M0AR = (uint32_t)dataAdressDestination; 	/* destination address */


	dma2->DMA_S7CR &=  ~(000 << 25);
	dma2->DMA_S7CR |= (channel0 << 25);  					/* CHANNEL 0 */

	dma2->DMA_S7CR &= ~(00 << 6);
	dma2->DMA_S7CR |= (M2M << 6 );      					/* DIRECTION TRANSFER MODE M2M */


	dma2->DMA_S7CR &= ~(00 << 16);							/* priority level : high  */
	dma2->DMA_S7CR |= (Priority_High <<16);


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

	// Enable DMA Interrupt on complete transfer
	//enable CONTROL bit
	dma2->DMA_S7CR &= ~(0 << 4);
	dma2->DMA_S7CR |= (TC_interrupt_enabled << 4);
	//Event flag Transfer complete interrupt
	dma2->DMA_HISR &= (0 << 27);
	//dma2->DMA_HISR |= (1 << 27);


	dma2->DMA_S7CR |= (1 << 0);					/*	ENABLE STREAM FLAG */

}


void resetTransferCompleteError(){
	uint32_t status;
	status = dma2->DMA_HISR;
	//status &= 1;
	if(status == 1){
		dma2->DMA_HISR &= ~( 1 << 27 );
	}
}

int getStatus(){
	uint32_t status;
	int data;
	status = dma2->DMA_HISR;
	status &= 1;

	if(status == 1)
		data = 123;

	return data;
}



//void DMA2_Stream7_IRQHandler() {
  //Test on DMA2 Channel0 Transfer Complete interrupt
  //if(DMA_GetITStatus(DMA2_IT_TC1))
  //{
      //status=1;
      //LEDToggle(LEDG);
   //Clear DMA1 Channel1 Half Transfer, Transfer Complete and Global interrupt pending bits
    //DMA_ClearITPendingBit(DMA1_IT_GL1);
 // }
//}











/*In my interrupt-handler i just clear the flag and shut down the dma controller:

void DMA1_Stream4_IRQHandler(void) {
if(DMA_GetITStatus(DMA1_Stream4, DMA_IT_TCIF4) == SET) {
toggleGPIO(GPIOD, GPIO_Pin_13);
DMA_Cmd(DMA1_Stream4, DISABLE);
DMA_ClearITPendingBit(DMA1_Stream4, DMA_IT_TCIF4);
}


//wait for DMA transfer to be finished
while(status==0) {};
    LEDToggle(LEDB);
    for (i=0; i<ARRAYSIZE;i++)
    {
        destination[i]=source[i];
    }
}*/


