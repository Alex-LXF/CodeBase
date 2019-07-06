#include "tim.h"
#include "run.h"

void Tim3_Init(void)
{
	NVIC_InitTypeDef NVIC_InitStruct;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	
	// 1.ʹ��ʱ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	
	// 2.��ʱ���ĳ�ʼ��
	TIM_TimeBaseStructure.TIM_Period = 399; // �Զ�����ֵ
	TIM_TimeBaseStructure.TIM_Prescaler = 4199; // ��Ƶϵ��
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; // ����Ƶ
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; // ���ϼ���
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);

	// ��ʼ��NVIC
	NVIC_InitStruct.NVIC_IRQChannel = TIM3_IRQn; // ������
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 3; //��ռ���ȼ� 3
	NVIC_InitStruct.NVIC_IRQChannelSubPriority =3;  
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;

	NVIC_Init(&NVIC_InitStruct);  
	
	// ���ø����ж� 
	TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);
	
	// ʹ�ܶ�ʱ��
	TIM_Cmd(TIM3, ENABLE);
}

void Tim3_PWM_Init(void)
{
	TIM_OCInitTypeDef  TIM_OCInitStructure; 
	GPIO_InitTypeDef GPIO_InitStruct;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	
	// 1.ʹ��ʱ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA|RCC_AHB1Periph_GPIOB|RCC_AHB1Periph_GPIOE, ENABLE);
	
	
	
	// 2.����GPIPF9�����ԣ���������졢�ٶȡ�����
	GPIO_InitStruct.GPIO_Pin 		= GPIO_Pin_6; // ��ʼ����5\6������
	GPIO_InitStruct.GPIO_Mode 	= GPIO_Mode_AF; // ���
	GPIO_InitStruct.GPIO_Speed 	= GPIO_Fast_Speed; // �ٶ�
	GPIO_InitStruct.GPIO_OType 	= GPIO_OType_PP; // ����
	
	GPIO_Init(GPIOB, &GPIO_InitStruct);
	
	GPIO_PinAFConfig(GPIOB,GPIO_PinSource6,GPIO_AF_TIM3); // ��������Ϊ����
	
	// 2.��ʱ���ĳ�ʼ��
	TIM_TimeBaseStructure.TIM_Period = 199; // �Զ�����ֵ
	TIM_TimeBaseStructure.TIM_Prescaler = 419; // ��Ƶϵ��
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; // ����Ƶ
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; // ���ϼ���
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);
	
	// ���ò���PWM��ͨ������
	//��ʱһ���ýṹ��
	//ѡ��PWM��ģʽ��ѡ��PWMģʽ1
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 
	//�������������ʹ�ܣ�ʹ��PWM������˿�
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; 
	//����ļ��ԣ�����Ǹߵ�ƽ���ǵ͵�ƽ������ѡ��͡�
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low; 
	//�����趨��Ϣ����TIM14 OC1
	TIM_OC1Init(TIM3, &TIM_OCInitStructure); 
	
	// ʹ��Ԥװ�ؼĴ���
	TIM_OC1PreloadConfig(TIM3, 	TIM_OCPreload_Enable);
	
	TIM_SetCompare1(TIM3, 100); // ���ñȽ�ֵ
	
	// ʹ�ܶ�ʱ��
	TIM_Cmd(TIM3, ENABLE);
}

void Tim4_PWM_Init(void)
{
	TIM_OCInitTypeDef  TIM_OCInitStructure; 
	GPIO_InitTypeDef GPIO_InitStruct;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	
	// 1.ʹ��ʱ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA|RCC_AHB1Periph_GPIOB|RCC_AHB1Periph_GPIOE, ENABLE);
	
	
	
	// 2.����GPIPF9�����ԣ���������졢�ٶȡ�����
	GPIO_InitStruct.GPIO_Pin 		= GPIO_Pin_6; // ��ʼ����5\6������
	GPIO_InitStruct.GPIO_Mode 	= GPIO_Mode_AF; // ���
	GPIO_InitStruct.GPIO_Speed 	= GPIO_Fast_Speed; // �ٶ�
	GPIO_InitStruct.GPIO_OType 	= GPIO_OType_PP; // ����
	
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource6,GPIO_AF_TIM4); // ��������Ϊ����
	
	// 2.��ʱ���ĳ�ʼ��
	TIM_TimeBaseStructure.TIM_Period = 199; // �Զ�����ֵ
	TIM_TimeBaseStructure.TIM_Prescaler = 419; // ��Ƶϵ��
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; // ����Ƶ
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; // ���ϼ���
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);
	
	// ���ò���PWM��ͨ������
	//��ʱһ���ýṹ��
	//ѡ��PWM��ģʽ��ѡ��PWMģʽ1
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 
	//�������������ʹ�ܣ�ʹ��PWM������˿�
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; 
	//����ļ��ԣ�����Ǹߵ�ƽ���ǵ͵�ƽ������ѡ��͡�
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low; 
	//�����趨��Ϣ����TIM14 OC1
	TIM_OC1Init(TIM4, &TIM_OCInitStructure); 
	
	// ʹ��Ԥװ�ؼĴ���
	TIM_OC1PreloadConfig(TIM4, 	TIM_OCPreload_Enable);
	
	TIM_SetCompare1(TIM4, 100); // ���ñȽ�ֵ
	
	// ʹ�ܶ�ʱ��
	TIM_Cmd(TIM4, ENABLE);
}

void TIM3_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM3, TIM_IT_Update) == SET)
	{
		// ����жϱ�־
		TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
		
		PFout(8) = ~PFout(8);
		PBout(6) = ~PBout(6);
		
	}
	
}
