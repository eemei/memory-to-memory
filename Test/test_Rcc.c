#include "unity.h"
#include "RCC.h"
#include "Registers.h"
#include "HostRcc.h"

void setUp(void)
{
   rcc->RCC_AHB1ENR = 0;
  rcc->RCC_AHB1RSTR = 0xffffffff; 
}

void tearDown(void)
{
}

void test_RCC_not_reset_and_clock_GpioA(void)
{

  
	rcc->RCC_AHB1ENR |= 1;
  rcc->RCC_AHB1RSTR &= ~1;
}

void test_notResetAndClockGpioA(void){
  TEST_ASSERT_EQUAL (1, rcc->RCC_AHB1ENR & 1);
  TEST_ASSERT_EQUAL (0, rcc->RCC_AHB1RSTR & 1);
}
