#include "stm32f10x.h"                  // Device header
#include "Delay.h"
void hcsr04_init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_14;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPD;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	
	TIM_InternalClockConfig(TIM1);
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseStructure.TIM_Period=65535-1;
	TIM_TimeBaseStructure.TIM_Prescaler=72-1;
	TIM_TimeBaseStructure.TIM_RepetitionCounter=0;
	TIM_TimeBaseInit(TIM1,&TIM_TimeBaseStructure);
}
float hcsr04_distance(void)
{
	GPIO_ResetBits(GPIOB,GPIO_Pin_14);
	GPIO_SetBits(GPIOB,GPIO_Pin_14);
	Delay_us(20);
	GPIO_ResetBits(GPIOB,GPIO_Pin_14);
	
	while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_15)==RESET);
	TIM_SetCounter(TIM1,0);
	TIM_Cmd(TIM1,ENABLE);
	while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_15)==SET);
	TIM_Cmd(TIM1,DISABLE);
	uint16_t num;
	num=TIM_GetCounter(TIM1);
	float distance=(num*0.034)/2;
	return distance;
}
	
	
	
	
	