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

void configDMAM2M(void) {  // stream 7  channel 0
	dma2->DMA_S7CR &=  (000 << 25);
	dma2->DMA_S7CR |= (000 << 25);  	/* CHANNEL 0 */

	dma2->DMA_S7CR &= (00 << 6);
	dma2->DMA_S7CR |= (2 << 6 );      /* DIRECTION TRANSFER MODE M2M */

	dma2->DMA_S7CR &= (00 << 11); 	/* MEMORY data alignment : Word  */
	dma2->DMA_S7CR |= (2 << 11);

	dma2->DMA_S7CR &= (00 << 16);	/* priority level : high  */
	dma2->DMA->S7CR |= (2 <<16);

	dma2->DMA_S7CR &= (00 << 13);		/*Memory data size:word*/
	dma2->DMA_S7CR |= (2 << 13);

		/*DMA_Memory0BaseAddr = (uint32_t)&data;
		 *
		 *DMA_PeripheralBaseAddr = (uint32_t)&(SPI2->DR);*/

}

/*In my interrupt-handler i just clear the flag and shut down the dma controller:

void DMA1_Stream4_IRQHandler(void) {
if(DMA_GetITStatus(DMA1_Stream4, DMA_IT_TCIF4) == SET) {
toggleGPIO(GPIOD, GPIO_Pin_13);
DMA_Cmd(DMA1_Stream4, DISABLE);
DMA_ClearITPendingBit(DMA1_Stream4, DMA_IT_TCIF4);
}
}*/

void DMA2_STREAM7_IRQHandler(void) {
	int status;
	status = dma2->DMA_HISR;
	....
	if (dma2->DMA_HISR ==)
}

