#ifndef	__DMA_H__
#define	__DMA_H__
#include <stdint.h>


typedef struct DMA_t DMA_reg;
struct DMA_t{
	volatile uint32_t DMA_LISR;
	volatile uint32_t DMA_HISR;
	volatile uint32_t DMA_LIFCR;
	volatile uint32_t DMA_HIFCR;
	volatile uint32_t DMA_S0CR;
	volatile uint32_t DMA_S0NDTR;
	volatile uint32_t DMA_S0PAR;
	volatile uint32_t DMA_S0M0AR;
	volatile uint32_t DMA_S0M1AR;
	volatile uint32_t DMA_S0FCR;
	volatile uint32_t DMA_S1CR;
	volatile uint32_t DMA_S1NDTR;
	volatile uint32_t DMA_S1PAR;
	volatile uint32_t DMA_S1M0AR;
	volatile uint32_t DMA_S1M1AR;
	volatile uint32_t DMA_S1FCR;
	volatile uint32_t DMA_S2CR;
	volatile uint32_t DMA_S2NDTR;
	volatile uint32_t DMA_S2PAR;
	volatile uint32_t DMA_S2M0AR;
	volatile uint32_t DMA_S2M1AR;
	volatile uint32_t DMA_S2FCR;
	volatile uint32_t DMA_S3CR;
	volatile uint32_t DMA_S3NDTR;
	volatile uint32_t DMA_S3PAR;
	volatile uint32_t DMA_S3M0AR;
	volatile uint32_t DMA_S3M1AR;
	volatile uint32_t DMA_S3FCR;
	volatile uint32_t DMA_S4CR;
	volatile uint32_t DMA_S4NDTR;
	volatile uint32_t DMA_S4PAR;
	volatile uint32_t DMA_S4M0AR;
	volatile uint32_t DMA_S4M1AR;
	volatile uint32_t DMA_S4FCR;
	volatile uint32_t DMA_S5CR;
	volatile uint32_t DMA_S5NDTR;
	volatile uint32_t DMA_S5PAR;
	volatile uint32_t DMA_S5M0AR;
	volatile uint32_t DMA_S5M1AR;
	volatile uint32_t DMA_S5FCR;
	volatile uint32_t DMA_S6CR;
	volatile uint32_t DMA_S6NDTR;
	volatile uint32_t DMA_S6PAR;
	volatile uint32_t DMA_S6M0AR;
	volatile uint32_t DMA_S6M1AR;
	volatile uint32_t DMA_S6FCR;
	volatile uint32_t DMA_S7CR;
	volatile uint32_t DMA_S7NDTR;
	volatile uint32_t DMA_S7PAR;
	volatile uint32_t DMA_S7M0AR;
	volatile uint32_t DMA_S7M1AR;
	volatile uint32_t DMA_S7FCR;

};


#define dma2 ((DMA_reg*)0x40026400)

#define channel0	0
#define channel1	1
#define channel2	2
#define channel3	3
#define channel4	4
#define channel5	5
#define channel6	6
#define channel7	7

#define P2M	0
#define M2P	1
#define M2M	2

#define Priority_Low		0
#define Priority_Medium		1
#define Priority_High		2
#define Priority_VeryHigh	3

#define DMA_PeripheralInc_Enable	1
#define DMA_PeripheralInc_Disable	0

#define DMA_MemoryInc_Enable		1
#define DMA_MemoryInc_Disable		0

#define DMA_MemoryBurst_Single	0
#define DMA_MemoryBurst_Incr4	1
#define DMA_MemoryBurst_Incr8	2
#define DMA_MemoryBurst_Incr16	3

#define DMA_PeripheralBurst_Single	0
#define DMA_PeripheralBurst_Incr4	1
#define DMA_PeripheralBurst_Incr8	2
#define DMA_PeripheralBurst_Incr16	3


#define dataAdressSource		0xAAAAAAAA			///????? address ?
#define dataAdressDestination	0xFFFFFFFF			///?????

#define DMA_MemoryDataSize_byte 	0
#define DMA_MemoryDataSize_halfword 1
#define DMA_MemoryDataSize_Word 	2
#define DMA_MemoryDataSize_reserved 3

#define DMA_PeripheralDataSize_byte		0
#define DMA_PeripheralDataSize_halfword	1
#define DMA_PeripheralDataSize_Word 	2
#define DMA_PeripheralDataSize_reserved	3

#define TC_interrupt_disabled 0
#define TC_interrupt_enabled  1


#define EN		0
#define PINC	9
#define MINC	10
#define PL0		16
#define PL1		17
#define TCIE	4
#define CTCIF7	27


#define ARRAYSIZE 800
#define DMA_STREAM_IRQHANDLER    DMA2_Stream0_IRQHandler

void configDMAM2M();
void DMA_memcpy8( uint16_t pDstAddr, uint16_t pSrcAddr, unsigned int uSize );
int* getADC1Data();
//int getAddrSrc();
void resetTransferCompleteError();
int getStatus();

#endif	//__DMA_H__
