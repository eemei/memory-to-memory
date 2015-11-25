#include "stm32f4xx.h"
//#include "stm32f4xx_hal_dma.h"




volatile int data;
volatile int entered;

void DMA2_Stream7_IRQHandler(){
	uint32_t status;
	status = dma2->DMA_HISR;
	if(status == 1)
		data = 123;
	else
		data =1;

	entered++;
}


void main(void){
	int i;
	DMAUnresetEnableClock();

	configDMAM2M();
	 /* Enable the transfer complete interrupt */
	  __HAL_DMA_ENABLE_IT(hdma, DMA_IT_TC);



}
