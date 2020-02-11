/*
 * led.c
 *
 * Created: 1/17/2020 7:29:29 AM
 *  Author: mahmo
 */ 
#include "led.h"

void Led_Init(En_LedNumber_t en_led_id)
{
	switch(en_led_id){
		case LED_0:
		gpioPinDirection(LED_0_GPIO,LED_0_BIT,OUTPUT);
		break;
		case LED_1:
		gpioPinDirection(LED_1_GPIO,LED_1_BIT,OUTPUT);
		break;
		case LED_2:
		gpioPinDirection(LED_2_GPIO,LED_2_BIT,OUTPUT);
		break;
		case LED_3:
		gpioPinDirection(LED_3_GPIO,LED_3_BIT,OUTPUT);
		break;
	}
	
}


void Led_On(En_LedNumber_t en_led_id)
{
	switch(en_led_id){
	case LED_0:
	gpioPinWrite(LED_0_GPIO,LED_0_BIT,HIGH);
	break;
	case LED_1:
	gpioPinWrite(LED_1_GPIO,LED_1_BIT,HIGH);
	break;
	case LED_2:
	gpioPinWrite(LED_2_GPIO,LED_2_BIT,HIGH);
	break;
	case LED_3:
	gpioPinWrite(LED_3_GPIO,LED_3_BIT,HIGH);
	break;
	}	
}

void Led_Off(En_LedNumber_t en_led_id)
{
	switch(en_led_id){
	case LED_0:
	gpioPinWrite(LED_0_GPIO,LED_0_BIT,LOW);
	break;
	case LED_1:
	gpioPinWrite(LED_1_GPIO,LED_1_BIT,LOW);
	break;
	case LED_2:
	gpioPinWrite(LED_2_GPIO,LED_2_BIT,LOW);
	break;
	case LED_3:
	gpioPinWrite(LED_3_GPIO,LED_3_BIT,LOW);
	break;
	}
	
}

void Led_Toggle(En_LedNumber_t en_led_id)
{
	switch(en_led_id){
	case LED_0:
	gpioPinToggle(LED_0_GPIO,LED_0_BIT);
	break;
	case LED_1:
	gpioPinToggle(LED_1_GPIO,LED_1_BIT);
	break;
	case LED_2:
	gpioPinToggle(LED_2_GPIO,LED_2_BIT);
	break;
	case LED_3:
	gpioPinToggle(LED_3_GPIO,LED_3_BIT);
	break;
	}
}


