#include "stm32f4xx.h"
#include "stm32f4xx_hal_cortex.h"
#include "DMA.h"
//#include "Gpio.h"


uint32_t SRC_Const_Buffer[9]= {123,1,3,5,6,7,8};
uint32_t DST_Buffer[9]= {0};
uint32_t ThirdTarget_Buffer[9] = {7};



volatile unsigned char _flag = 0;
volatile int data;
int i = 0;
TestStatus  TransferStatus = FAILED;

void DMA2_Stream7_IRQHandler(void){
	uint32_t statusHISR, statusCR_bef, statusCR_aft, satusHISR2;

	statusHISR = dma2->HISR;

	dma2->S7.CR &= ~(15 << 1);				// clear interrupt enable bit
	statusCR_aft = dma2->S7.CR;

	dma2->LISR &= 0x00000000;				// clear the interrupt status & flag
	dma2->HISR &= 0x00000000;

	dma2->HIFCR = (uint32_t)0x0f400000;		// clear any pending (old) DMA2 Stream 7 interrupts
	i++;

	unsigned int len = 9;					// start transfer to another memory
	dma2->S7.CR &= ~(0xffff);				// clear configure register
	configDMAM2M();							// everything setup but not enabled
	len = 9;
	DMA_memcpy8( ThirdTarget_Buffer, DST_Buffer, len);
	enableDMA();							// everything setup and enabled
	satusHISR2 = dma2->HISR;
	int Thirdptr2DST = ThirdTarget_Buffer[0];
	int Secondptr2SRC = DST_Buffer[0];

}




void main()
{
    unsigned int len;
    uint16_t Aftelem =0 ;
    int status = 0;
    len = 9;

    status = dma2->HISR;
    configDMAM2M();
    DMA_memcpy8( DST_Buffer, SRC_Const_Buffer, len );
    //DMA_memcpy8( ThirdTarget_Buffer, SRC_Const_Buffer, len );
    enableDMA();
    uint32_t status2 = 0;
    status2 = dma2->HISR;

    int ptr2DST = DST_Buffer[6];
    int ptr2SRC = SRC_Const_Buffer[6];


    HAL_NVIC_EnableIRQ(DMA2_Stream7_IRQn);

    while( 1 )
    {
    	uint32_t readInt ;//= 0;
    	readInt = dma2->HISR;
    	uint32_t read = ThirdTarget_Buffer[0];
    }
}




