#include "tim.h"
#include "run.h"

void Tim3_Init(void)
{
	NVIC_InitTypeDef NVIC_InitStruct;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	
	// 1.使能时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	
	// 2.定时器的初始化
	TIM_TimeBaseStructure.TIM_Period = 399; // 自动重载值
	TIM_TimeBaseStructure.TIM_Prescaler = 4199; // 分频系数
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; // 不分频
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; // 向上计数
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);

	// 初始化NVIC
	NVIC_InitStruct.NVIC_IRQChannel = TIM3_IRQn; // 向量号
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 3; //抢占优先级 3
	NVIC_InitStruct.NVIC_IRQChannelSubPriority =3;  
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;

	NVIC_Init(&NVIC_InitStruct);  
	
	// 配置更新中断 
	TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);
	
	// 使能定时器
	TIM_Cmd(TIM3, ENABLE);
}

void Tim3_PWM_Init(void)
{
	TIM_OCInitTypeDef  TIM_OCInitStructure; 
	GPIO_InitTypeDef GPIO_InitStruct;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	
	// 1.使能时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA|RCC_AHB1Periph_GPIOB|RCC_AHB1Periph_GPIOE, ENABLE);
	
	
	
	// 2.设置GPIPF9的属性：输出、推挽、速度、上拉
	GPIO_InitStruct.GPIO_Pin 		= GPIO_Pin_6; // 初始化第5\6个引脚
	GPIO_InitStruct.GPIO_Mode 	= GPIO_Mode_AF; // 输出
	GPIO_InitStruct.GPIO_Speed 	= GPIO_Fast_Speed; // 速度
	GPIO_InitStruct.GPIO_OType 	= GPIO_OType_PP; // 推挽
	
	GPIO_Init(GPIOB, &GPIO_InitStruct);
	
	GPIO_PinAFConfig(GPIOB,GPIO_PinSource6,GPIO_AF_TIM3); // 设置引脚为复用
	
	// 2.定时器的初始化
	TIM_TimeBaseStructure.TIM_Period = 199; // 自动重载值
	TIM_TimeBaseStructure.TIM_Prescaler = 419; // 分频系数
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; // 不分频
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; // 向上计数
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);
	
	// 配置产生PWM的通道参数
	//定时一个该结构体
	//选择PWM的模式，选择PWM模式1
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 
	//用于设置输出的使能，使能PWM输出到端口
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; 
	//输出的极性，输出是高电平还是低电平，这里选择低。
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low; 
	//根据设定信息配置TIM14 OC1
	TIM_OC1Init(TIM3, &TIM_OCInitStructure); 
	
	// 使能预装载寄存器
	TIM_OC1PreloadConfig(TIM3, 	TIM_OCPreload_Enable);
	
	TIM_SetCompare1(TIM3, 100); // 设置比较值
	
	// 使能定时器
	TIM_Cmd(TIM3, ENABLE);
}

void Tim4_PWM_Init(void)
{
	TIM_OCInitTypeDef  TIM_OCInitStructure; 
	GPIO_InitTypeDef GPIO_InitStruct;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	
	// 1.使能时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA|RCC_AHB1Periph_GPIOB|RCC_AHB1Periph_GPIOE, ENABLE);
	
	
	
	// 2.设置GPIPF9的属性：输出、推挽、速度、上拉
	GPIO_InitStruct.GPIO_Pin 		= GPIO_Pin_6; // 初始化第5\6个引脚
	GPIO_InitStruct.GPIO_Mode 	= GPIO_Mode_AF; // 输出
	GPIO_InitStruct.GPIO_Speed 	= GPIO_Fast_Speed; // 速度
	GPIO_InitStruct.GPIO_OType 	= GPIO_OType_PP; // 推挽
	
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource6,GPIO_AF_TIM4); // 设置引脚为复用
	
	// 2.定时器的初始化
	TIM_TimeBaseStructure.TIM_Period = 199; // 自动重载值
	TIM_TimeBaseStructure.TIM_Prescaler = 419; // 分频系数
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; // 不分频
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; // 向上计数
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);
	
	// 配置产生PWM的通道参数
	//定时一个该结构体
	//选择PWM的模式，选择PWM模式1
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 
	//用于设置输出的使能，使能PWM输出到端口
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; 
	//输出的极性，输出是高电平还是低电平，这里选择低。
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low; 
	//根据设定信息配置TIM14 OC1
	TIM_OC1Init(TIM4, &TIM_OCInitStructure); 
	
	// 使能预装载寄存器
	TIM_OC1PreloadConfig(TIM4, 	TIM_OCPreload_Enable);
	
	TIM_SetCompare1(TIM4, 100); // 设置比较值
	
	// 使能定时器
	TIM_Cmd(TIM4, ENABLE);
}

void TIM3_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM3, TIM_IT_Update) == SET)
	{
		// 清除中断标志
		TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
		
		PFout(8) = ~PFout(8);
		PBout(6) = ~PBout(6);
		
	}
	
}
