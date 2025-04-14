#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "pwm.h"
#include "motor.h"
#include "serial.h"
#include "car.h"
#include "hcsr04.h"
#include "servo.h"
#include "track.h"
uint8_t distance;
int main(void)
{
	OLED_Init();
	pwm_init();
	motor_init();
	serial_init();
	car_init();
	hcsr04_init();
	servo_init();
	//track_init();
	while (1)
	{
		car_moveforward();
		uint16_t head=hcsr04_distance();
		serial_sendNumber(head,2);
		if(head<15)
		{
			car_stop();
			servo_setangle(0);
			Delay_ms(1000);
			uint16_t right=hcsr04_distance();
			serial_sendNumber(right,2);
			if(right>20)
			{
				servo_setangle(90);
				Delay_ms(1000);
				car_selfright();
				Delay_ms(1000);
				car_moveforward();
			}
			else
			{
				servo_setangle(180);
				Delay_ms(1000);
				uint16_t left=hcsr04_distance();
				serial_sendNumber(left,2);
				if(left>20)
				{
					servo_setangle(90);
					Delay_ms(1000);
					car_selfleft();
					Delay_ms(1000);
					car_moveforward();
				}
				else
				{
					servo_setangle(90);
					while(1);
				}
			}
		}
		
		Delay_ms(1000);
	}
}
