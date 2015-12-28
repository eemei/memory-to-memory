#ifndef	__Registers_H__
#define	__Registers_H__

#include <stdint.h>
//#include "DMA.h"
//#include "Gpio.h"

#ifndef HOST



#define RCC_BASE_ADDRESS 0x40023800

#else
#include "HostRcc.h "
#define RCC_BASE_ADDRESS (&HostRcc)
//#error i am trying to be genius
#endif	// HOST

#endif	//__Registers_H__
