#include "stm32f10x.h"                  // Device header
void pwm_init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_1|GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	
	TIM_InternalClockConfig(TIM2);
	TIM_InternalClockConfig(TIM3);
	
	TIM_TimeBaseInitTypeDef TIM_TimBaseStructure;
	TIM_TimBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimBaseStructure.TIM_Period=100-1;
	TIM_TimBaseStructure.TIM_Prescaler=36-1;
	TIM_TimBaseStructure.TIM_RepetitionCounter=0;
	TIM_TimeBaseInit(TIM2,&TIM_TimBaseStructure);
	TIM_TimBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimBaseStructure.TIM_Period=20000-1;
	TIM_TimBaseStructure.TIM_Prescaler=72-1;
	TIM_TimBaseStructure.TIM_RepetitionCounter=0;
	TIM_TimeBaseInit(TIM3,&TIM_TimBaseStructure);
	
	TIM_OCInitTypeDef TIM_OCStructure;
	TIM_OCStructInit(&TIM_OCStructure);
	TIM_OCStructure.TIM_OCMode=TIM_OCMode_PWM1;
	TIM_OCStructure.TIM_OCPolarity=TIM_OCPolarity_High;
	TIM_OCStructure.TIM_OutputState=TIM_OutputState_Enable;
	TIM_OCStructure.TIM_Pulse=0;
	TIM_OC2Init(TIM2,&TIM_OCStructure);
	TIM_OC3Init(TIM2,&TIM_OCStructure);
	TIM_OC3Init(TIM3,&TIM_OCStructure);
	
	TIM_Cmd(TIM2,ENABLE);
	TIM_Cmd(TIM3,ENABLE);
}