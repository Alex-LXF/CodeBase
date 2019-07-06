#include "beep.h"
#include "stm32f4xx.h"

//��ʼ��
void BEEP_Init(void)
{
	GPIO_InitTypeDef GPIOF_Struct; // ��������ָ��
	
	//1. ʹ��GPIOFʱ�� 
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);
	
	//2. ����GPIPF9�����ԣ���������졢�������������ٶ�
	GPIOF_Struct.GPIO_Pin   = GPIO_Pin_8; // ��ʼ��8������
	GPIOF_Struct.GPIO_OType = GPIO_OType_PP;// ����
	GPIOF_Struct.GPIO_Mode  = GPIO_Mode_OUT; // ���
	GPIOF_Struct.GPIO_Speed = GPIO_Fast_Speed; // �ٶ�
	
	GPIO_Init(GPIOF, &GPIOF_Struct);  

	//3. �������ر�
	GPIO_ResetBits(GPIOF, GPIO_Pin_8); //  GPIOF9����ߵ�ƽ
} 

// ����������
void BEEP_Open(void)
{
	GPIO_SetBits(GPIOF, GPIO_Pin_8);
}

//�������ر�
void BEEP_Close(void)
{
	GPIO_ResetBits(GPIOF, GPIO_Pin_8);
}
