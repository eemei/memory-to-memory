#include "stm32f4xx.h"
#include "stm32f4xx_hal_cortex.h"
#include "DMA.h"
#include "Gpio.h"


const uint32_t SRC_Const_Buffer[9]= {4,4,4,4,4,4,4,4,4,4};
uint32_t DST_Buffer[9]= {0,0,0,0,0,0,0,0,0,0};



volatile unsigned char _flag = 0;
volatile int data;
int i;
TestStatus  TransferStatus = FAILED;

void DMA2_Stream7_IRQHandler(void){
	uint32_t status;

	status = dma2->DMA_HISR;

	dma2->DMA_LISR &= 0x00000000;
	dma2->DMA_HISR &= 0x00000000;
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
    uint32_t status;
    //len = 9;

    status = dma2->DMA_HISR;

    configDMAM2M();
    //DMA_memcpy8( dst1, src1, len );

    DST_Buffer[8] = * getSourceData();
    Aftelem = DST_Buffer[8];

    /* Check if the transmitted and received data are equal */
    TransferStatus = Buffercmp(Aftelem, DST_Buffer, 9);
    /* TransferStatus = PASSED, if the transmitted and received data
       are the same */
    /* TransferStatus = FAILED, if the transmitted and received data
       are different */


  //  HAL_NVIC_EnableIRQ(DMA2_Stream7_IRQn);


   /* AddrD[5] = * getDestinationData();
    Aftelem = AddrD[5];*/



    while( 1 )
    {
    	//uint16_t Befelem;
        //Addr[5] = * getSourceData();
       // Befelem = Addr[5];
    //	writeOne(PIN_13, PORTG);
    //	writeZero(PIN_14, PORTG);
    //	_delay(100000);
    }

}

void _delay(int delay){
	while(delay != 0)
		delay--;
}









//element = dst1[0];
//if(status == 1)
//	toggleLED ();
//else
//dma2->DMA_HIFCR |= ( 1 << CTCIF7 ); 					// Clears the corresponding TCIFx flag
