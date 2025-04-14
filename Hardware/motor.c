#include "stm32f10x.h"                  // Device header
void motor_init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
}
void leftmotor_speed(int16_t speed)
{
	if(speed>0)
	{
		GPIO_ResetBits(GPIOA,GPIO_Pin_4);
		GPIO_SetBits(GPIOA,GPIO_Pin_5);
		TIM_SetCompare2(TIM2,speed);
	}
	else if(speed==0)
	{
		GPIO_SetBits(GPIOA,GPIO_Pin_4);
		GPIO_SetBits(GPIOA,GPIO_Pin_5);
		TIM_SetCompare2(TIM2,speed);
	}
	else if(speed<0)
	{
		GPIO_SetBits(GPIOA,GPIO_Pin_4);
		GPIO_ResetBits(GPIOA,GPIO_Pin_5);
		TIM_SetCompare2(TIM2,-speed);
	}
}
void rightmotor_speed(int16_t speed)
{
	if(speed>0)
	{
		GPIO_ResetBits(GPIOA,GPIO_Pin_6);
		GPIO_SetBits(GPIOA,GPIO_Pin_7);
		TIM_SetCompare3(TIM2,speed);
	}
	else if(speed==0)
	{
		GPIO_SetBits(GPIOA,GPIO_Pin_6);
		GPIO_SetBits(GPIOA,GPIO_Pin_7);
		TIM_SetCompare3(TIM2,speed);
	}
	else if(speed<0)
	{
		GPIO_SetBits(GPIOA,GPIO_Pin_6);
		GPIO_ResetBits(GPIOA,GPIO_Pin_7);
		TIM_SetCompare3(TIM2,-speed);
	}
}