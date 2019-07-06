#include <stdio.h>
#include "stm32f4xx.h"
#include "run.h"
#include "delay.h"
#include "led.h"
#include "beep.h"
#include "uart.h"
#include "sys.h"
#include "tim.h"
#include "sr04.h"


void Run(void);
void Stop(void);
void Back(void);
void Left_Spin(void);
void Right_Spin(void);
void Left_Go(void);
void Right_Go(void);
void Left(void);


enum{ run = 0, back = 1, left_spin = 2, right_spin = 3, left_go = 4, right_go = 5, stop = 6};
u32 Action = stop;
int flag = 1;
u16 Res   = 0;
u8 u_flag = 0;



int main(void)
{
	
	LED_Init();     // LED ��ʼ��
	BEEP_Init();    // ��������ʼ��
	RUN_Init();     // �����ʼ��
	Uart1_Init();   // ���ڳ�ʼ��
	Uart_Open();		// ��������
	SR04_Init();    // ��ʼ���״�
	Tim3_PWM_Init();// ��ʼ����ʱ��
	Tim4_PWM_Init();// ��ʼ����ʱ��
	
	Stop();
	//Left_Spin();
	//Left();
	while (1)
  {
		u16 s_flag ;

		if(u_flag);
		{
			switch(Res)
			{
				
				
				case 0x30: Stop();        Action = stop;          break; 
				case 0x31: Run();         Action = run;           break;
				case 0x32: Back();        Action = back;          break;
				case 0x33: Left_Spin();   Action = left_spin;     break;
				
				case 0x34: Right_Spin();  Action = right_spin;    break;
					
				case 0x35: Left_Go();     Action = left_go;       break;
				case 0x36: Right_Go();    Action = right_go;      break;
				case 0x37: Back();        Action = back;          break;
				case 0x38: 	flag++;       
										s_flag = 1;
										if(flag > 4)
										{
										  flag = 4;
										}
										break;
										
				case 0x39: flag--;        
									 s_flag = 1;
									 if(flag < 0)
									 {
										 flag = 0;
									 }
										break;
									 
				case 0x40: BEEP_Open();                           break;
				case 0x41: BEEP_Close();   				                break;
			
				case 0x42: LED_Open();                            break;
			  case 0x43: LED_Close();                           break;
			}
			
			if(s_flag)
			{
				if(Action == run)
				{
					Run();
				}
				else if(Action == back)
				{
					Back();
				}
				else if(Action == left_spin)
				{
					Left_Spin();
				}
				else if(Action == right_spin)
				{
					Right_Spin();
				}
				else if(Action == left_go)
				{
					Left_Go();
				}
				else if(Action == right_go)
				{
					Right_Go();
				}
				else if(Action == stop)
				{
					Stop();
				}
				s_flag=0;
			}
			
			u_flag = 0;
			
			
		}
	}
	
		
	
}



// ֹͣ
void Stop(void)
{
	TIM_SetCompare1(TIM3, 199); // ���ñȽ�ֵ
	TIM_SetCompare1(TIM4, 199);
	PEout(5) = 0;
	PEout(6) = 0;

}	
// ����
void Run(void)
{
	TIM_SetCompare1(TIM3, 200-flag*50); // ���ñȽ�ֵ
	TIM_SetCompare1(TIM4, 200-flag*50);
	PEout(5) = 0;
	PEout(6) = 0;
}

void Back(void)
{
	TIM_SetCompare1(TIM3, flag*50); // ���ñȽ�ֵ
	TIM_SetCompare1(TIM4, flag*50);
	PEout(5) = 1;
	PEout(6) = 1;
}

void Left(void)
{
	TIM_SetCompare1(TIM3, 200); // ���ñȽ�ֵ //����
	TIM_SetCompare1(TIM4, 0);
	PEout(5) = 0;
	PEout(6) = 0;
}

void Left_Go(void)
{
	if(flag == 0)
	{
		TIM_SetCompare1(TIM3, 199); // ���ñȽ�ֵ
		TIM_SetCompare1(TIM4, 199);
		PEout(5) = 0;
		PEout(6) = 0;
	}
	else if(flag == 1)
	{
		TIM_SetCompare1(TIM3, 150); // ���ñȽ�ֵ
		TIM_SetCompare1(TIM4, 100);
		PEout(5) = 0;
		PEout(6) = 0;
	}
	else if(flag == 2)
	{
		TIM_SetCompare1(TIM3, 100); // ���ñȽ�ֵ
		TIM_SetCompare1(TIM4, 50);
		PEout(6) = 1;   // �ߵ�ƽ
		PEout(5) = 0;
	}
	else if(flag == 3)
	{
		TIM_SetCompare1(TIM3, 100); // ���ñȽ�ֵ
		TIM_SetCompare1(TIM4, 0);	
		PEout(5) = 0;
		PEout(6) = 0;
	}
	else if(flag == 4)
	{
		TIM_SetCompare1(TIM3, 50); // ���ñȽ�ֵ
		TIM_SetCompare1(TIM4, 0);	
		PEout(5) = 0;
		PEout(6) = 0;
	}
		
}

void Right_Go(void)
{
	if(flag == 0)
	{
		TIM_SetCompare1(TIM3, 199); // ���ñȽ�ֵ
		TIM_SetCompare1(TIM4, 199);
		PEout(5) = 0;
		PEout(6) = 0;
	}
	else if(flag == 1)
	{
		TIM_SetCompare1(TIM3, 100); // ���ñȽ�ֵ
		TIM_SetCompare1(TIM4, 150);
		PEout(5) = 0;
		PEout(6) = 0;
	}
	else if(flag == 2)
	{
		TIM_SetCompare1(TIM3, 50); // ���ñȽ�ֵ
		TIM_SetCompare1(TIM4, 100);
		PEout(6) = 0;   // �ߵ�ƽ
		PEout(5) = 1;
	}
	else if(flag == 3)
	{
		TIM_SetCompare1(TIM3, 0); // ���ñȽ�ֵ
		TIM_SetCompare1(TIM4, 100);	
		PEout(5) = 0;
		PEout(6) = 0;
	}
	else if(flag == 4)
	{
		TIM_SetCompare1(TIM3, 0); // ���ñȽ�ֵ
		TIM_SetCompare1(TIM4, 50);	
		PEout(5) = 0;
		PEout(6) = 0;
	}
}



void Left_Spin(void)
{
	
	TIM_SetCompare1(TIM3, flag*50); // ���ñȽ�ֵ
	TIM_SetCompare1(TIM4, 200-flag*50);
	PEout(6) = 1;   // �ߵ�ƽ
	PEout(5) = 0;
}
void Right_Spin(void)
{
	
	TIM_SetCompare1(TIM3, 200-flag*50); // ���ñȽ�ֵ
	TIM_SetCompare1(TIM4, flag*50);
	PEout(5) = 1;   // �ߵ�ƽ
	PEout(6) = 0;
}



void USART1_IRQHandler(void)
{
	// �ж��Ƿ�����˽����ж�
	if(USART_GetITStatus(USART1, USART_IT_RXNE) == SET)
	{
		// ����жϱ�־
		USART_ClearITPendingBit(USART1, USART_IT_RXNE);
		
		// ��������
		Res = USART_ReceiveData(USART1);
		u_flag = 1;
		
		printf("Res=%#x\n", Res);
	}
	
	
	
}
