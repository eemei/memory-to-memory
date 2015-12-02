#include "stm32f4xx.h"
#include "stm32f4xx_hal_cortex.h"
#include "DMA.h"

//char src1[]="abcdefghijklmnopqrstuvwxyz\n";
//char dst1[]="00000000000000000000000000\n";
uint16_t src1[9] = {1,2,3,4,5,6,7,8,9,1};
uint16_t dst1[9];

volatile unsigned char _flag = 0;
volatile int data;


void DMA2_Stream7_IRQHandler(void){
	uint32_t status;

	int element;
	status = dma2->DMA_HISR;
	element = dst1[0];

	if(status == 1)
		toggleLED ();
	else
	dma2->DMA_HIFCR |= ( 1 << CTCIF7 ); 					// Clears the corresponding TCIFx flag
}



void transferDone_ISR() { 									//iv IVT_INT_DMA2_Stream7 ics ICS_AUTO
    dma2->DMA_HIFCR |= ( 1 << CTCIF7 ); 					// Clears the corresponding TCIFx flag
    _flag = 1;
}




void main()
{
    unsigned int len;
    int elem;

    //len = strlen( src1 );
    len = 9;

   elem= dst1[0];

    configDMAM2M();
    DMA_memcpy8( dst1, src1, len );
   HAL_NVIC_EnableIRQ(DMA2_Stream7_IRQn);
    //DMA2_Stream7_IRQHandler();
    transferDone_ISR();
    while( 1 )
    {
    	int status2 ;
    	status2 = dma2->DMA_HISR;
        if( _flag )
        {
            _flag = 0;
        }
    }

}


