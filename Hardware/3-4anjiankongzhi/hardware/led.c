#include "stm32f10x.h"                  // Device header

void led_init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	GPIO_InitTypeDef GPIOTypestructure;
	GPIOTypestructure.GPIO_Pin=GPIO_Pin_0|GPIO_Pin_1;
	GPIOTypestructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIOTypestructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_Init(GPIOA,&GPIOTypestructure);
	GPIO_SetBits(GPIOA,GPIO_Pin_0);
}
void led_0_on(void)
{
	GPIO_ResetBits(GPIOA,GPIO_Pin_0);
}
void led_1_on(void)
{
	GPIO_ResetBits(GPIOA,GPIO_Pin_1);
}
void led_0_off(void)
{
	GPIO_SetBits(GPIOA,GPIO_Pin_0);
}
void led_1_off(void)
{
	GPIO_SetBits(GPIOA,GPIO_Pin_1);
}
void led_0_turn(void)
{
	if(GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_0)==1)
	{
		GPIO_ResetBits(GPIOA,GPIO_Pin_0);
	}
	else
	{
		GPIO_SetBits(GPIOA,GPIO_Pin_0);
	}
}
void led_1_turn(void)
{
	if(GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_1)==1)
	{
		GPIO_ResetBits(GPIOA,GPIO_Pin_1);
	}
	else
	{
		GPIO_SetBits(GPIOA,GPIO_Pin_1);
	}
}
