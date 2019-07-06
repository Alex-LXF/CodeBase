#ifndef _RUN_H
#define _RUN_H

#include "stm32f4xx.h"

void RUN_Init(void);
void Motor_Stop(void);
void Motor_Start(void);
void Motor_Back(void);
void Motor_Left(void);
void Motor_Right(void);
void Motor_LeftStop(void);
void Motor_RightStop(void);
#endif
