#include "led.h"
#include "stm32f4xx.h"

//初始化
void LED_Init(void)
{
	GPIO_InitTypeDef GPIOF_Struct; // 不可以用指针
	
	//1. 使能GPIOF时钟
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE); //  
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);
	
	//2. 设置GPIPF9的属性：输出、推挽、上拉、下拉、速度
	GPIOF_Struct.GPIO_Pin   = GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_13|GPIO_Pin_14; // 初始化13.14.9.10号引脚
	GPIOF_Struct.GPIO_OType = GPIO_OType_PP;// 推挽
	GPIOF_Struct.GPIO_Mode  = GPIO_Mode_OUT; // 输出
	GPIOF_Struct.GPIO_Speed = GPIO_Fast_Speed; // 速度
	
	GPIO_Init(GPIOE, &GPIOF_Struct);
	GPIO_Init(GPIOF, &GPIOF_Struct);  

	//3.  让灯熄灭: GPIOF9输出高电平
	GPIO_SetBits(GPIOE, GPIO_Pin_13); 
	GPIO_SetBits(GPIOE, GPIO_Pin_14);
	GPIO_SetBits(GPIOF, GPIO_Pin_9);
	GPIO_SetBits(GPIOF, GPIO_Pin_10);
} 
void LED_Open() // 开灯
{
	GPIO_ResetBits(GPIOE, GPIO_Pin_13); 
	GPIO_ResetBits(GPIOE, GPIO_Pin_14);
	GPIO_ResetBits(GPIOF, GPIO_Pin_9);
	GPIO_ResetBits(GPIOF, GPIO_Pin_10);
}
void LED_Close() // 关灯
{
	GPIO_SetBits(GPIOE, GPIO_Pin_13); 
	GPIO_SetBits(GPIOE, GPIO_Pin_14);
	GPIO_SetBits(GPIOF, GPIO_Pin_9);
	GPIO_SetBits(GPIOF, GPIO_Pin_10);
}
