#include "uart.h"
#include "stdio.h"

// 关闭半主机模式，为了printf能够直接输出
#pragma import(__use_no_semihosting)             
//标准库需要的支持函数                 
struct __FILE 
{  
	int handle; 
}; 

FILE __stdout;       
//定义_sys_exit()以避免使用半主机模式    
void _sys_exit(int x) 
{ 
	x = x; 
} 

//重定义fputc函数 
int fputc(int ch, FILE *f)
{ 	
	USART_SendData(USART1,ch);
	while(USART_GetFlagStatus(USART1,USART_FLAG_TXE)==RESET);      
	return ch;
}

void Send_Str(u8 *str)
{
	while(str && *str)
	{
		USART_SendData(USART1, *str++);
		while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
	}
}

void Uart1_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	USART_InitTypeDef USART_InitStruct;
	NVIC_InitTypeDef NVIC_InitStruct;
	
	// 使能时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	
	// 设置引脚复用绑定
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_USART1);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_USART1);
	
	// 2.设置GPIPF9的属性：输出、推挽、速度、上拉
	GPIO_InitStruct.GPIO_Pin 		= GPIO_Pin_9|GPIO_Pin_10; // 初始化第9个引脚
	GPIO_InitStruct.GPIO_Mode 	= GPIO_Mode_AF; // 复用
	GPIO_InitStruct.GPIO_Speed 	= GPIO_Fast_Speed; // 速度
	GPIO_InitStruct.GPIO_OType 	= GPIO_OType_PP; // 推挽
	
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	// 设置串口的参数：波特率、数据位、停止位……
	USART_InitStruct.USART_BaudRate = 38400; // 波特率
	USART_InitStruct.USART_WordLength = USART_WordLength_8b; // 数据位 8位
	USART_InitStruct.USART_StopBits   =  USART_StopBits_1;   // 停止位 1位      
	USART_InitStruct.USART_Parity = USART_Parity_No; // 无奇偶校验
	USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None; // 无硬件流控
  USART_InitStruct.USART_Mode = USART_Mode_Rx | USART_Mode_Tx; // 支持接收数据和发送数据

	USART_Init(USART1, &USART_InitStruct);
	
	 
	
	// 初始化NVIC
	NVIC_InitStruct.NVIC_IRQChannel = USART1_IRQn; // 向量号
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 3; //抢占优先级 3
	NVIC_InitStruct.NVIC_IRQChannelSubPriority =3;  
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;

	NVIC_Init(&NVIC_InitStruct);  
	
	// 开启接收中断
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
  
	// 串口使能
	USART_Cmd(USART1, ENABLE);
}                           

void Uart_Open(void) // 启动Uart
{
	GPIO_ResetBits(GPIOF, GPIO_Pin_9); // 输出低电平
}
