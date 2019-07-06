#include "sr04.h"
#include "stdio.h"
#define TRIG PEout(4)
#define ECHO PCin(9)

void SR04_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	
	// 1.使能GPIOF时钟
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE|RCC_AHB1Periph_GPIOC, ENABLE);
	
	// 2.设置GPIPF9的属性：输出、推挽、速度、上拉
	GPIO_InitStruct.GPIO_Pin 		= GPIO_Pin_4; // 初始化第9个引脚
	GPIO_InitStruct.GPIO_Mode 	= GPIO_Mode_OUT; // 输出
	GPIO_InitStruct.GPIO_Speed 	= GPIO_Fast_Speed; // 速度
	GPIO_InitStruct.GPIO_OType 	= GPIO_OType_PP; // 推挽
	
	GPIO_Init(GPIOE, &GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin 		= GPIO_Pin_9; // 初始化第9个引脚
	GPIO_InitStruct.GPIO_Mode 	= GPIO_Mode_IN; // 输出
	GPIO_InitStruct.GPIO_OType 	= GPIO_OType_OD; // 下拉
	GPIO_Init(GPIOC, &GPIO_InitStruct);
	
	// 3.让灯熄灭：GPIOF9输出高电平
	PEout(4) = 0;
}

void Get_SR04(u32 *data)
{
	u32 t = 0;
	
	// TRIG 引脚输出高电平，持续10us
	TRIG = 1;
	delay_us(20);
	TRIG = 0;
	
	//printf("ECHO=%d\n",ECHO);
	//判断ECHO是否为高电平
	while(!ECHO); // 渡过低电平
	//printf("t2\n");
	while(ECHO)
	{
		delay_us(8); // 约等于3mm
		t++;
		//printf("ECHO=%d\n",ECHO);
	}
	//printf("t3\n");
	*data = t*3/2;

}
	
	

