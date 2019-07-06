#include "run.h"
#include "sys.h"
//初始化
void RUN_Init(void)
{
	GPIO_InitTypeDef GPIO_Struct; // 不可以用指针
	
	//1. 使能GPIOF时钟
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE); //  
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
	
	//2. 设置GPIPF9的属性：输出、推挽、上拉、下拉、速度
	GPIO_Struct.GPIO_Pin   = GPIO_Pin_6; // 初始化13.14.9.10号引脚
	GPIO_Struct.GPIO_OType = GPIO_OType_PP;// 推挽
	GPIO_Struct.GPIO_Mode  = GPIO_Mode_OUT; // 输出
	GPIO_Struct.GPIO_Speed = GPIO_Fast_Speed; // 速度
	GPIO_Init(GPIOA, &GPIO_Struct);
	
	GPIO_Init(GPIOB, &GPIO_Struct);
	
	GPIO_Struct.GPIO_Pin   = GPIO_Pin_5 | GPIO_Pin_6;
	GPIO_Init(GPIOE, &GPIO_Struct); 
	//3.  停止
	Motor_Stop();
} 

 // 停止
void Motor_Stop(void)
{
	GPIO_ResetBits(GPIOB, GPIO_Pin_6); // 低电平
	GPIO_ResetBits(GPIOE, GPIO_Pin_5); // 低电平
	
	GPIO_ResetBits(GPIOE, GPIO_Pin_6); // 低电平
	GPIO_ResetBits(GPIOA, GPIO_Pin_6); // 低电平
}
  // 前进
void Motor_Start(void)
{
	GPIO_SetBits(GPIOB, GPIO_Pin_6);   // 高电平
	GPIO_ResetBits(GPIOE, GPIO_Pin_5); // 低电平
	
	GPIO_SetBits(GPIOE, GPIO_Pin_6);   // 高电平
	GPIO_ResetBits(GPIOA, GPIO_Pin_6); // 低电平
}
  // 倒退
void Motor_Back(void)
{
	GPIO_ResetBits(GPIOB, GPIO_Pin_6);   //低电平
	GPIO_SetBits(GPIOE, GPIO_Pin_5); 		 // 高电平
	
	GPIO_ResetBits(GPIOE, GPIO_Pin_6);   // 低电平
	GPIO_SetBits(GPIOA, GPIO_Pin_6);     // 高电平
}

 // 往左转
void Motor_Left(void)
{
	GPIO_SetBits(GPIOB, GPIO_Pin_6);   // 高电平
	GPIO_ResetBits(GPIOE, GPIO_Pin_5); // 低电平
	
	GPIO_ResetBits(GPIOE, GPIO_Pin_6);   // 低电平
	GPIO_SetBits(GPIOA, GPIO_Pin_6);    // 高电平
}

// 往右转
void Motor_Right(void)
{
	GPIO_ResetBits(GPIOB, GPIO_Pin_6); // 低电平
	GPIO_SetBits(GPIOE, GPIO_Pin_5); 	 // 高电平

	GPIO_SetBits(GPIOE, GPIO_Pin_6);   // 高电平
	GPIO_ResetBits(GPIOA, GPIO_Pin_6); // 低电平
}

//右轮停止
void Motor_RightStop(void)
{
	GPIO_ResetBits(GPIOB, GPIO_Pin_6); // 低电平
	GPIO_ResetBits(GPIOE, GPIO_Pin_5); 	 // 低电平

	GPIO_SetBits(GPIOE, GPIO_Pin_6);   // 高电平
	GPIO_ResetBits(GPIOA, GPIO_Pin_6); // 低电平
}
// 左轮停止
void Motor_LeftStop(void)
{
	GPIO_SetBits(GPIOB, GPIO_Pin_6); // 高电平
	GPIO_ResetBits(GPIOE, GPIO_Pin_5); 	 // 低电平

	GPIO_ResetBits(GPIOE, GPIO_Pin_6);   // 低电平
	GPIO_ResetBits(GPIOA, GPIO_Pin_6); // 低电平
}


