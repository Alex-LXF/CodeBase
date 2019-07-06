#include "sr04.h"
#include "stdio.h"
#define TRIG PEout(4)
#define ECHO PCin(9)

void SR04_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	
	// 1.ʹ��GPIOFʱ��
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE|RCC_AHB1Periph_GPIOC, ENABLE);
	
	// 2.����GPIPF9�����ԣ���������졢�ٶȡ�����
	GPIO_InitStruct.GPIO_Pin 		= GPIO_Pin_4; // ��ʼ����9������
	GPIO_InitStruct.GPIO_Mode 	= GPIO_Mode_OUT; // ���
	GPIO_InitStruct.GPIO_Speed 	= GPIO_Fast_Speed; // �ٶ�
	GPIO_InitStruct.GPIO_OType 	= GPIO_OType_PP; // ����
	
	GPIO_Init(GPIOE, &GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin 		= GPIO_Pin_9; // ��ʼ����9������
	GPIO_InitStruct.GPIO_Mode 	= GPIO_Mode_IN; // ���
	GPIO_InitStruct.GPIO_OType 	= GPIO_OType_OD; // ����
	GPIO_Init(GPIOC, &GPIO_InitStruct);
	
	// 3.�õ�Ϩ��GPIOF9����ߵ�ƽ
	PEout(4) = 0;
}

void Get_SR04(u32 *data)
{
	u32 t = 0;
	
	// TRIG ��������ߵ�ƽ������10us
	TRIG = 1;
	delay_us(20);
	TRIG = 0;
	
	//printf("ECHO=%d\n",ECHO);
	//�ж�ECHO�Ƿ�Ϊ�ߵ�ƽ
	while(!ECHO); // �ɹ��͵�ƽ
	//printf("t2\n");
	while(ECHO)
	{
		delay_us(8); // Լ����3mm
		t++;
		//printf("ECHO=%d\n",ECHO);
	}
	//printf("t3\n");
	*data = t*3/2;

}
	
	

