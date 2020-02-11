/*
 * dcMotor.c
 *
 * Created: 1/27/2020 2:48:07 AM
 *  Author: mahmo
 */ 
#include "dcMotor.h"
#include "timers.h"

/**
 * Description: 
 * @param
 */
void MotorDC_Init(En_motorType_t en_motor_number)
{
	/* for motor 1 /2 :
	*					-initalize EN pin as output.
	*					-initalize direction pins as output
	*/
	gpioPinDirection(MOTOR_EN_1_GPIO,MOTOR_EN_1_BIT,OUTPUT);
	gpioPinDirection(MOTOR_OUT_1A_GPIO,MOTOR_OUT_1A_BIT,OUTPUT);
	gpioPinDirection(MOTOR_OUT_1B_GPIO,MOTOR_OUT_1B_BIT,OUTPUT);

	gpioPinDirection(MOTOR_EN_2_GPIO,MOTOR_EN_2_BIT,OUTPUT);
	gpioPinDirection(MOTOR_OUT_2A_GPIO,MOTOR_OUT_2A_BIT,OUTPUT);
	gpioPinDirection(MOTOR_OUT_2B_GPIO,MOTOR_OUT_2B_BIT,OUTPUT);
}

/**
 * Description: 
 * @param 
 * @param 
 */
void MotorDC_Dir(En_motorType_t en_motor_number, En_motorDir_t en_motor_dir)
{
	switch(en_motor_number)
	{
		case MOT_1:
			switch(en_motor_dir)
			{
				case FORWARD:
				gpioPinWrite(MOTOR_OUT_1A_GPIO,MOTOR_OUT_1A_BIT,HIGH);
				gpioPinWrite(MOTOR_OUT_1B_GPIO,MOTOR_OUT_1B_BIT,LOW);
				break;
				case BACKWARD:
				gpioPinWrite(MOTOR_OUT_1A_GPIO,MOTOR_OUT_1A_BIT,LOW);
				gpioPinWrite(MOTOR_OUT_1B_GPIO,MOTOR_OUT_1B_BIT,HIGH);
				break;
				case STOP:
				gpioPinWrite(MOTOR_OUT_1A_GPIO,MOTOR_OUT_1A_BIT,LOW);
				gpioPinWrite(MOTOR_OUT_1B_GPIO,MOTOR_OUT_1B_BIT,LOW);
				break;
			}
		break;
		case MOT_2:
			switch(en_motor_dir)
			{
				case FORWARD:
				gpioPinWrite(MOTOR_OUT_2A_GPIO,MOTOR_OUT_2A_BIT,HIGH);
				gpioPinWrite(MOTOR_OUT_2B_GPIO,MOTOR_OUT_2B_BIT,LOW);
				break;
				case BACKWARD:
				gpioPinWrite(MOTOR_OUT_2A_GPIO,MOTOR_OUT_2A_BIT,LOW);
				gpioPinWrite(MOTOR_OUT_2B_GPIO,MOTOR_OUT_2B_BIT,HIGH);
				break;
				case STOP:
				gpioPinWrite(MOTOR_OUT_2A_GPIO,MOTOR_OUT_2A_BIT,LOW);
				gpioPinWrite(MOTOR_OUT_2B_GPIO,MOTOR_OUT_2B_BIT,LOW);
				break;	
			}
		break;
	}
}
/**
 * Description: 
 * @param 
 */
void MotorDC_Speed_PollingWithT0(uint8_t u8_motor_speed)
{
	timer1SwPWM(u8_motor_speed,u8_motor_speed,FREQ1);
}

/**
 * Description: set the port value (which is PORT register)
 * @param 
 */
void MotorDC_Speed_HwPWM(uint8_t u8_motor_speed);
