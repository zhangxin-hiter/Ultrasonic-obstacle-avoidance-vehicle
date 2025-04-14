#include "stm32f10x.h"                  // Device header
#include "motor.h"
void car_init(void)
{
	motor_init();
}
void car_moveforward(void)
{
	leftmotor_speed(70);
	rightmotor_speed(70);
}
void car_movebackward(void)
{
	leftmotor_speed(-70);
	rightmotor_speed(-70);
}
void car_stop(void)
{
	leftmotor_speed(0);
	rightmotor_speed(0);
}
void car_turnleft(void)
{
	leftmotor_speed(0);
	rightmotor_speed(70);
}
void car_turnright(void)
{
	leftmotor_speed(70);
	rightmotor_speed(0);
}
void car_selfleft(void)
{
	leftmotor_speed(-80);
	rightmotor_speed(80);
}
void car_selfright(void)
{
	leftmotor_speed(80);
	rightmotor_speed(-80);
}