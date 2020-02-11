
/*
 * Sevenseg.c
 *
 * Created: 1/17/2020 9:22:00 PM
 *  Author: hazem
 */ 
#include "sevenSeg.h"

/*implementation of seven segment display */
void sevenSegInit(En_SevenSegId_t a_segment_id){
	switch (a_segment_id){
		case  SEG_0:
		           gpioPinDirection(SEG_BCD_GPIO,SEG_BCD_BITS,OUTPUT);
				   gpioPinDirection(SEG_EN1_GPIO,SEG_EN1_BIT,OUTPUT);
				   break;
		case  SEG_1:
		            gpioPinDirection(SEG_BCD_GPIO,SEG_BCD_BITS,OUTPUT);
		            gpioPinDirection(SEG_EN2_GPIO,SEG_EN2_BIT,OUTPUT);
		            break;
	}
}

/*implementation of seven segment ENABLE*/

void sevenSegEnable(En_SevenSegId_t en_segment_id){
	switch(en_segment_id){
		case SEG_0:
		          gpioPinWrite(SEG_EN1_GPIO,SEG_EN1_BIT,HIGH);
				  break;
		case SEG_1:
		          gpioPinWrite(SEG_EN2_GPIO,SEG_EN2_BIT,HIGH);
		          break;
		default:
		        break;		  			
	}
}

/*implementation of seven segment DISENABLE*/

void sevenSegDisable(En_SevenSegId_t en_segment_id){
	switch(en_segment_id){
		case SEG_0:
		           gpioPinWrite(SEG_EN1_GPIO,SEG_EN1_BIT,LOW);
					break;
		case SEG_1:
			      gpioPinWrite(SEG_EN2_GPIO,SEG_EN2_BIT,LOW);
					break;
		default:
					break;
	}
	
	
}
/*IMPLEMENTATION OF SEVENSEGEMENT WRITE*/
void sevenSegWrite(En_SevenSegId_t en_segment_id, uint8_t u8_number){
	
	
	gpioPinWrite(SEG_BCD_GPIO,SEG_BCD_BITS,LOW);
	gpioPinWrite(SEG_BCD_GPIO,u8_number,HIGH);
	
	
	
	
}