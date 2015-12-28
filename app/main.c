#include "stm32f4xx.h"
//#include "stm32f4xx_hal_cortex.h"
#include "DMA.h"
//#include "Gpio.h"


uint32_t SRC_Const_Buffer[]= {0x12345678, 0xdeadbeef, 0xc0ffee45, 0x0badface, 0x789abcde, 0x2a3b4c5d, 0x6b3cde42,0xcade2917,0xbcd6745a,
								0xfadd1257,0xdef37846,0x12785abc,0x92837465, 0xa7b80919, 0x4726fabe, 0xbd87af91, 0xa3cde978};
uint32_t DST_Buffer[]= {0x00000000, 0x11111111, 0x22222222, 0x333333333, 0x4444444444, 0x55555555, 0x66666666, 0x77777777, 0x888888888,
						0x999999999, 0x00001111, 0x22223333, 0x44445555, 0x66667777, 0x999991111, 0x55552222};
uint32_t ThirdTarget_Buffer[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};



volatile unsigned char _flag = 0;
volatile int data;
TestStatus  TransferStatus = FAILED;

void DMA2_Stream7_IRQHandler(void){
	uint32_t statusHISR, statusCR_bef, statusCR_aft, satusHISR2;

	dma2->S7.CR &= ~(15 << 1);				// clear interrupt enable bit

	dma2->LISR &= 0x00000000;				// clear the interrupt status & flag
	dma2->HISR &= 0x00000000;

	dma2->HIFCR = (uint32_t)0x0f400000;		// clear any pending (old) DMA2 Stream 7 interrupts

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
    unsigned int len = 0;
    uint16_t Aftelem =0 ;
    int status = 0;
    len = 18;

    status = dma2->HISR;
    configDMAM2M();
    DMA_memcpy8( DST_Buffer, SRC_Const_Buffer, len );
    enableDMA();
    uint32_t status2 = 0;
    status2 = dma2->HISR;

    int ptr2DST = DST_Buffer[7];
    int ptr2SRC = SRC_Const_Buffer[7];


    HAL_NVIC_EnableIRQ(DMA2_Stream7_IRQn);

    while( 1 )
    {
    	uint32_t readInt ;//= 0;
    	readInt = dma2->HISR;
    	uint32_t read = ThirdTarget_Buffer[0];
    }
}




