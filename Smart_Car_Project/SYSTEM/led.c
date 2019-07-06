#include "led.h"
#include "stm32f4xx.h"

//��ʼ��
void LED_Init(void)
{
	GPIO_InitTypeDef GPIOF_Struct; // ��������ָ��
	
	//1. ʹ��GPIOFʱ��
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE); //  
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);
	
	//2. ����GPIPF9�����ԣ���������졢�������������ٶ�
	GPIOF_Struct.GPIO_Pin   = GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_13|GPIO_Pin_14; // ��ʼ��13.14.9.10������
	GPIOF_Struct.GPIO_OType = GPIO_OType_PP;// ����
	GPIOF_Struct.GPIO_Mode  = GPIO_Mode_OUT; // ���
	GPIOF_Struct.GPIO_Speed = GPIO_Fast_Speed; // �ٶ�
	
	GPIO_Init(GPIOE, &GPIOF_Struct);
	GPIO_Init(GPIOF, &GPIOF_Struct);  

	//3.  �õ�Ϩ��: GPIOF9����ߵ�ƽ
	GPIO_SetBits(GPIOE, GPIO_Pin_13); 
	GPIO_SetBits(GPIOE, GPIO_Pin_14);
	GPIO_SetBits(GPIOF, GPIO_Pin_9);
	GPIO_SetBits(GPIOF, GPIO_Pin_10);
} 
void LED_Open() // ����
{
	GPIO_ResetBits(GPIOE, GPIO_Pin_13); 
	GPIO_ResetBits(GPIOE, GPIO_Pin_14);
	GPIO_ResetBits(GPIOF, GPIO_Pin_9);
	GPIO_ResetBits(GPIOF, GPIO_Pin_10);
}
void LED_Close() // �ص�
{
	GPIO_SetBits(GPIOE, GPIO_Pin_13); 
	GPIO_SetBits(GPIOE, GPIO_Pin_14);
	GPIO_SetBits(GPIOF, GPIO_Pin_9);
	GPIO_SetBits(GPIOF, GPIO_Pin_10);
}
