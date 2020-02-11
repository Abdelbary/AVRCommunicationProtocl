/*
 * pushButton.c
 *
 * Created: 1/17/2020 9:21:54 AM
 *  Author: mahmo
 */ 
#include "pushButton.h"
void pushButtonInit(En_buttonId_t en_butotn_id)
{
	switch(en_butotn_id)
	{
		case BTN_0:
		gpioPinDirection(BTN_0_GPIO,BTN_0_BIT,INPUT);
		break;
		case BTN_1:
		gpioPinDirection(BTN_1_GPIO,BTN_1_BIT,INPUT);
		break;
		case BTN_2:
		gpioPinDirection(BTN_2_GPIO,BTN_2_BIT,INPUT);
		break;
		case BTN_3:
		gpioPinDirection(BTN_3_GPIO,BTN_3_BIT,INPUT);
		break;
	}
}

En_buttonStatus_t pushButtonGetStatus(En_buttonId_t en_butotn_id)
{
	En_buttonStatus_t ret = Released ;
	switch(en_butotn_id)
	{
		case BTN_0:
		ret = gpioPinRead(BTN_0_GPIO,BTN_0_BIT);
		if(ret == Pressed)
		{
			softwareDelayMs(50);
			if(gpioPinRead(BTN_0_GPIO,BTN_0_BIT) == Pressed)
				ret = Pressed;
		}
		break;
		case BTN_1:
		ret = gpioPinRead(BTN_1_GPIO,BTN_1_BIT);
		if(ret == Pressed)
		{
			softwareDelayMs(50);
			if(gpioPinRead(BTN_1_GPIO,BTN_1_BIT) == Pressed)
			ret = Pressed;
		}
		break;
		case BTN_2:
		ret = gpioPinRead(BTN_2_GPIO,BTN_2_BIT);
		if(ret == Pressed)
		{
			softwareDelayMs(50);
			if(gpioPinRead(BTN_2_GPIO,BTN_2_BIT) == Pressed)
			ret = Pressed;
		}
		break;
		case BTN_3:
		ret = gpioPinRead(BTN_3_GPIO,BTN_3_BIT);
		if(ret == Pressed)
		{
			softwareDelayMs(50);
			if(gpioPinRead(BTN_3_GPIO,BTN_3_BIT) == Pressed)
			ret = Pressed;
		}
		break;
	}	
	return ret;
}