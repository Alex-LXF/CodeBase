#include "delay.h"

u32 delay_us(u32 nus)
{
	u32 temp = 0;
	
	if ((nus*21 - 1) > SysTick_LOAD_RELOAD_Msk)  return (1);      /* Reload value impossible */
  SysTick->LOAD  = nus*21 - 1;                                  /* set reload register */
  SysTick->VAL   = 0x00;                                          /* Load the SysTick Counter Value */
  SysTick->CTRL  |= SysTick_CTRL_ENABLE_Msk; // 使能定时器                     /* Enable SysTick IRQ and SysTick Timer */
	
	do
	{
		temp = SysTick->CTRL;
	}while(!(temp & (1<<16)));
	
	SysTick->CTRL  &= ~SysTick_CTRL_ENABLE_Msk; // 关闭定时器   
	SysTick->VAL   = 0x00;
	
	return 0;
}


u32 delay_ms(u32 nms)
{
	u32 temp = 0;
	
	if ((nms*21000 - 1) > SysTick_LOAD_RELOAD_Msk)  return (1);      /* Reload value impossible */
  SysTick->LOAD  = nms*21000 - 1;                                  /* set reload register */
  SysTick->VAL   = 0x00;                                          /* Load the SysTick Counter Value */
  SysTick->CTRL  |= SysTick_CTRL_ENABLE_Msk; // 使能定时器                     /* Enable SysTick IRQ and SysTick Timer */
	
	do
	{
		temp = SysTick->CTRL;
	}while(!(temp & (1<<16)));
	
	SysTick->CTRL  &= ~SysTick_CTRL_ENABLE_Msk; // 使能定时器   
	SysTick->VAL   = 0x00;
	
	return 0;
}

u32 delay_s(u32 ns)
{
	while(ns--)
	{
		delay_ms(500);
		delay_ms(500);
	}
	
	return 0;
}

