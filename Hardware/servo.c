#include "stm32f10x.h"                  // Device header
#include "pwm.h"
void servo_init(void)
{
	pwm_init();
}
void servo_setangle(float angle)
{
	TIM_SetCompare3(TIM3,angle/180*2000+500);
}
