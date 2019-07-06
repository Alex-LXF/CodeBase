#include "uart.h"
#include "stdio.h"

// �رհ�����ģʽ��Ϊ��printf�ܹ�ֱ�����
#pragma import(__use_no_semihosting)             
//��׼����Ҫ��֧�ֺ���                 
struct __FILE 
{  
	int handle; 
}; 

FILE __stdout;       
//����_sys_exit()�Ա���ʹ�ð�����ģʽ    
void _sys_exit(int x) 
{ 
	x = x; 
} 

//�ض���fputc���� 
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
	
	// ʹ��ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	
	// �������Ÿ��ð�
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_USART1);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_USART1);
	
	// 2.����GPIPF9�����ԣ���������졢�ٶȡ�����
	GPIO_InitStruct.GPIO_Pin 		= GPIO_Pin_9|GPIO_Pin_10; // ��ʼ����9������
	GPIO_InitStruct.GPIO_Mode 	= GPIO_Mode_AF; // ����
	GPIO_InitStruct.GPIO_Speed 	= GPIO_Fast_Speed; // �ٶ�
	GPIO_InitStruct.GPIO_OType 	= GPIO_OType_PP; // ����
	
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	// ���ô��ڵĲ����������ʡ�����λ��ֹͣλ����
	USART_InitStruct.USART_BaudRate = 38400; // ������
	USART_InitStruct.USART_WordLength = USART_WordLength_8b; // ����λ 8λ
	USART_InitStruct.USART_StopBits   =  USART_StopBits_1;   // ֹͣλ 1λ      
	USART_InitStruct.USART_Parity = USART_Parity_No; // ����żУ��
	USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None; // ��Ӳ������
  USART_InitStruct.USART_Mode = USART_Mode_Rx | USART_Mode_Tx; // ֧�ֽ������ݺͷ�������

	USART_Init(USART1, &USART_InitStruct);
	
	 
	
	// ��ʼ��NVIC
	NVIC_InitStruct.NVIC_IRQChannel = USART1_IRQn; // ������
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 3; //��ռ���ȼ� 3
	NVIC_InitStruct.NVIC_IRQChannelSubPriority =3;  
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;

	NVIC_Init(&NVIC_InitStruct);  
	
	// ���������ж�
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
  
	// ����ʹ��
	USART_Cmd(USART1, ENABLE);
}                           

void Uart_Open(void) // ����Uart
{
	GPIO_ResetBits(GPIOF, GPIO_Pin_9); // ����͵�ƽ
}
