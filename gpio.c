/*
 * CFile1.c
 *
 * Created: 1/17/2020 5:41:51 AM
 *  Author: mahmo
 */ 
#include "gpio.h"
void gpioPortDirection(uint8_t u8_port, uint8_t u8_direction)
{
	switch(u8_port){
		case GPIOA:
		PORTA_DIR = u8_direction;
		break;
		case GPIOB:
		PORTB_DIR = u8_direction;
		break;
		case GPIOC:
		PORTC_DIR = u8_direction;
		break;
		case GPIOD:
		PORTD_DIR = u8_direction;
		break;
	}	
}

void gpioPortWrite(uint8_t u8_port, uint8_t u8_value)
{
		switch(u8_port){
			case GPIOA:
			PORTA_DATA = u8_value;
			break;
			case GPIOB:
			PORTB_DATA = u8_value;
			break;
			case GPIOC:
			PORTC_DATA = u8_value;
			break;
			case GPIOD:
			PORTD_DATA = u8_value;
			break;
		}
}

void gpioPortToggle(uint8_t u8_port){
		switch(u8_port){
			case GPIOA:
			PORTA_DATA ^= HIGH;
			break;
			case GPIOB:
			PORTB_DATA ^= HIGH;
			break;
			case GPIOC:
			PORTC_DATA ^= HIGH;
			break;
			case GPIOD:
			PORTD_DATA ^= HIGH;
			break;
		}
}


uint8_t gpioPortRead(uint8_t u8_port){
	uint8_t ret = 0;
		switch(u8_port){
			case GPIOA:
			ret = PORTA_PIN;
			break;
			case GPIOB:
			ret = PORTB_PIN;
			break;
			case GPIOC:
			ret = PORTC_PIN;
			break;
			case GPIOD:
			ret = PORTD_PIN;
			break;
		}	
		return ret;
}

void gpioPinDirection(uint8_t u8_port, uint8_t u8_pins, uint8_t u8_direction)
{
	if(u8_direction == OUTPUT)
	{
			switch(u8_port){
				case GPIOA:
				PORTA_DIR |= u8_pins;
				break;
				case GPIOB:
				PORTB_DIR |= u8_pins;
				break;
				case GPIOC:
				PORTC_DIR |= u8_pins;
				break;
				case GPIOD:
				PORTD_DIR |= u8_pins;
				break;
			}
	}
	else
	{
			switch(u8_port){
				case GPIOA:
				PORTA_DIR &= ~(u8_pins);
				break;
				case GPIOB:
				PORTB_DIR &= ~(u8_pins);
				break;
				case GPIOC:
				PORTC_DIR &= ~(u8_pins);
				break;
				case GPIOD:
				PORTD_DIR &= ~(u8_pins);
				break;
			}
	}	
}

void gpioPinWrite(uint8_t u8_port, uint8_t u8_pins, uint8_t u8_value)
{
	
		if(u8_value == HIGH)
		{
			switch(u8_port){
				case GPIOA:
				PORTA_DATA |= u8_pins;
				break;
				case GPIOB:
				PORTB_DATA |= u8_pins;
				break;
				case GPIOC:
				PORTC_DATA |= u8_pins;
				break;
				case GPIOD:
				PORTD_DATA |= u8_pins;
				break;
			}
		}
		else
		{
			switch(u8_port){
				case GPIOA:
				PORTA_DATA &= ~(u8_pins);
				break;
				case GPIOB:
				PORTB_DATA &= ~(u8_pins);
				break;
				case GPIOC:
				PORTC_DATA &= ~(u8_pins);
				break;
				case GPIOD:
				PORTD_DATA &= ~(u8_pins);
				break;
			}
		}
}

void gpioPinToggle(uint8_t u8_port, uint8_t u8_pins)
{
	switch(u8_port){
		case GPIOA:
		PORTA_DATA ^= u8_pins;
		break;
		case GPIOB:
		PORTB_DATA ^= u8_pins;
		break;
		case GPIOC:
		PORTC_DATA ^= u8_pins;
		break;
		case GPIOD:
		PORTD_DATA ^= u8_pins;
		break;
	}
}

uint8_t gpioPinRead(uint8_t u8_port, uint8_t u8_pin)
{
	uint8_t ret = LOW;
	switch(u8_port){
		case GPIOA:
		ret = (PORTA_PIN & u8_pin);
		break;
		case GPIOB:
		ret = (PORTB_PIN & u8_pin);
		break;
		case GPIOC:
		ret = (PORTC_PIN & u8_pin);
		break;
		case GPIOD:
		ret = (PORTD_PIN & u8_pin);
		break;
	}
	if(ret == LOW)
	return FALSE;
	
	return TRUE;
}
