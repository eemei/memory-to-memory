#include "stm32f4xx.h"
#include "stm32f4xx_hal_cortex.h"
#include "DMA.h"
//#include "Gpio.h"


uint32_t SRC_Const_Buffer[9]= {1,1,1,1,1,1,1,1,1,1};
uint32_t DST_Buffer[9]= {0,0,0,0,0,0,0,0,0,0};



volatile unsigned char _flag = 0;
volatile int data;
int i;
TestStatus  TransferStatus = FAILED;

void DMA2_Stream7_IRQHandler(void){
	uint32_t status;

	status = dma2->HISR;

	dma2->LISR &= 0x00000000;
	dma2->HISR &= 0x00000000;
	i++;
}


/*void transferDone_ISR() { 									//iv IVT_INT_DMA2_Stream7 ics ICS_AUTO
    dma2->DMA_HIFCR |= ( 1 << CTCIF7 ); 					// Clears the corresponding TCIFx flag
    _flag = 1;
}
*/


void main()
{
    unsigned int len;
    uint16_t Aftelem;// Befelem; //i;
    int status;
    len = 9;

    status = dma2->HISR;

    configDMAM2M();
    SRC_Const_Buffer[0]= 0xf;
    DMA_memcpy8( DST_Buffer, SRC_Const_Buffer, len );
    enableDMA();
    delay(100);
    uint32_t status2 = 0;
    status2 = dma2->HISR;
    int ptr2DST = DST_Buffer[0];
    int ptr2SRC = SRC_Const_Buffer[0];
    																/* Check if the transmitted and received data are equal */
    //TransferStatus = Buffercmp(SRC_Const_Buffer, DST_Buffer, 9);
    																/* TransferStatus = PASSED, if the transmitted and received data
       	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	  	  	  	are the same */
    																/* TransferStatus = FAILED, if the transmitted and received data
       	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	are different */
    HAL_NVIC_EnableIRQ(DMA2_Stream7_IRQn);

    while( 1 )
    {

    }
}



void _delay(int delay){
	while(delay != 0)
		delay--;
}



