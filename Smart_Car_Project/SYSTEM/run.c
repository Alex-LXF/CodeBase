#include "run.h"
#include "sys.h"
//��ʼ��
void RUN_Init(void)
{
	GPIO_InitTypeDef GPIO_Struct; // ��������ָ��
	
	//1. ʹ��GPIOFʱ��
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE); //  
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
	
	//2. ����GPIPF9�����ԣ���������졢�������������ٶ�
	GPIO_Struct.GPIO_Pin   = GPIO_Pin_6; // ��ʼ��13.14.9.10������
	GPIO_Struct.GPIO_OType = GPIO_OType_PP;// ����
	GPIO_Struct.GPIO_Mode  = GPIO_Mode_OUT; // ���
	GPIO_Struct.GPIO_Speed = GPIO_Fast_Speed; // �ٶ�
	GPIO_Init(GPIOA, &GPIO_Struct);
	
	GPIO_Init(GPIOB, &GPIO_Struct);
	
	GPIO_Struct.GPIO_Pin   = GPIO_Pin_5 | GPIO_Pin_6;
	GPIO_Init(GPIOE, &GPIO_Struct); 
	//3.  ֹͣ
	Motor_Stop();
} 

 // ֹͣ
void Motor_Stop(void)
{
	GPIO_ResetBits(GPIOB, GPIO_Pin_6); // �͵�ƽ
	GPIO_ResetBits(GPIOE, GPIO_Pin_5); // �͵�ƽ
	
	GPIO_ResetBits(GPIOE, GPIO_Pin_6); // �͵�ƽ
	GPIO_ResetBits(GPIOA, GPIO_Pin_6); // �͵�ƽ
}
  // ǰ��
void Motor_Start(void)
{
	GPIO_SetBits(GPIOB, GPIO_Pin_6);   // �ߵ�ƽ
	GPIO_ResetBits(GPIOE, GPIO_Pin_5); // �͵�ƽ
	
	GPIO_SetBits(GPIOE, GPIO_Pin_6);   // �ߵ�ƽ
	GPIO_ResetBits(GPIOA, GPIO_Pin_6); // �͵�ƽ
}
  // ����
void Motor_Back(void)
{
	GPIO_ResetBits(GPIOB, GPIO_Pin_6);   //�͵�ƽ
	GPIO_SetBits(GPIOE, GPIO_Pin_5); 		 // �ߵ�ƽ
	
	GPIO_ResetBits(GPIOE, GPIO_Pin_6);   // �͵�ƽ
	GPIO_SetBits(GPIOA, GPIO_Pin_6);     // �ߵ�ƽ
}

 // ����ת
void Motor_Left(void)
{
	GPIO_SetBits(GPIOB, GPIO_Pin_6);   // �ߵ�ƽ
	GPIO_ResetBits(GPIOE, GPIO_Pin_5); // �͵�ƽ
	
	GPIO_ResetBits(GPIOE, GPIO_Pin_6);   // �͵�ƽ
	GPIO_SetBits(GPIOA, GPIO_Pin_6);    // �ߵ�ƽ
}

// ����ת
void Motor_Right(void)
{
	GPIO_ResetBits(GPIOB, GPIO_Pin_6); // �͵�ƽ
	GPIO_SetBits(GPIOE, GPIO_Pin_5); 	 // �ߵ�ƽ

	GPIO_SetBits(GPIOE, GPIO_Pin_6);   // �ߵ�ƽ
	GPIO_ResetBits(GPIOA, GPIO_Pin_6); // �͵�ƽ
}

//����ֹͣ
void Motor_RightStop(void)
{
	GPIO_ResetBits(GPIOB, GPIO_Pin_6); // �͵�ƽ
	GPIO_ResetBits(GPIOE, GPIO_Pin_5); 	 // �͵�ƽ

	GPIO_SetBits(GPIOE, GPIO_Pin_6);   // �ߵ�ƽ
	GPIO_ResetBits(GPIOA, GPIO_Pin_6); // �͵�ƽ
}
// ����ֹͣ
void Motor_LeftStop(void)
{
	GPIO_SetBits(GPIOB, GPIO_Pin_6); // �ߵ�ƽ
	GPIO_ResetBits(GPIOE, GPIO_Pin_5); 	 // �͵�ƽ

	GPIO_ResetBits(GPIOE, GPIO_Pin_6);   // �͵�ƽ
	GPIO_ResetBits(GPIOA, GPIO_Pin_6); // �͵�ƽ
}


