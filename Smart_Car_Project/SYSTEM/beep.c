#include "beep.h"
#include "stm32f4xx.h"

//初始化
void BEEP_Init(void)
{
	GPIO_InitTypeDef GPIOF_Struct; // 不可以用指针
	
	//1. 使能GPIOF时钟 
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);
	
	//2. 设置GPIPF9的属性：输出、推挽、上拉、下拉、速度
	GPIOF_Struct.GPIO_Pin   = GPIO_Pin_8; // 初始化8号引脚
	GPIOF_Struct.GPIO_OType = GPIO_OType_PP;// 推挽
	GPIOF_Struct.GPIO_Mode  = GPIO_Mode_OUT; // 输出
	GPIOF_Struct.GPIO_Speed = GPIO_Fast_Speed; // 速度
	
	GPIO_Init(GPIOF, &GPIOF_Struct);  

	//3. 蜂鸣器关闭
	GPIO_ResetBits(GPIOF, GPIO_Pin_8); //  GPIOF9输出高电平
} 

// 蜂鸣器启动
void BEEP_Open(void)
{
	GPIO_SetBits(GPIOF, GPIO_Pin_8);
}

//蜂鸣器关闭
void BEEP_Close(void)
{
	GPIO_ResetBits(GPIOF, GPIO_Pin_8);
}
