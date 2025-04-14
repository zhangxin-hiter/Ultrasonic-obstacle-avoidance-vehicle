#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "led.h"
#include "key.h"
uint8_t keyNum;
int main()
{
	led_init();
	key_init();
	while(1)
	{
		keyNum=key_getnum();
		if(keyNum==1)
		{
			led_0_turn();
		}
		if(keyNum==2)
		{
			led_1_turn();
		}
	}
}
