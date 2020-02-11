/*
 * registers.h
 *
 *  Created on: Oct 21, 2019
 *      Author: Sprints
 */

#ifndef REGISTERS_H_
#define REGISTERS_H_
#include "std_types.h"

/*
 * General Registers
 */
#define MCUCR			*(reg_type8_t)(0X55)	
#define MCUCSR			*(reg_type8_t)(0X54)
#define GICR			*(reg_type8_t)(0X5B)
#define GIFR			*(reg_type8_t)(0X5A)
#define SREG			*(reg_type8_t)(0X5F)

/*
 * PORTx registers
 */

#define PORTA_DATA 		*(reg_type8_t)(0X3B)
#define PORTA_DIR  		*(reg_type8_t)(0X3A)
#define PORTA_PIN		*(reg_type8_t)(0X39)

#define PORTB_DATA 		*(reg_type8_t)(0X38)
#define PORTB_DIR  		*(reg_type8_t)(0X37)
#define PORTB_PIN		*(reg_type8_t)(0X36)

#define PORTC_DATA 		*(reg_type8_t)(0X35)
#define PORTC_DIR  		*(reg_type8_t)(0X34)
#define PORTC_PIN		*(reg_type8_t)(0X33)
	

#define PORTD_DATA 		*(reg_type8_t)(0X32)
#define PORTD_DIR  		*(reg_type8_t)(0X31)
#define PORTD_PIN		*(reg_type8_t)(0X30)


/*
 * General Timer registers
 */
#define TIMSK			*(reg_type8_t)(0X59)
#define TIFR			*(reg_type8_t)(0X58)


/*
 * Timer 0 Registers
 */

#define TCCR0			*(reg_type8_t)(0X53)
#define TCNT0			*(reg_type8_t)(0X52)
#define OCR0			*(reg_type8_t)(0X5C)


/*
 * Timer 1 Registers
 */



///REMEBER TO CHECK FOR A B AND NONE
#define TCCR1A			*(reg_type8_t)(0X4F)
#define TCCR1B			*(reg_type8_t)(0X4E)
#define TCCR1			*(reg_type16_t)(0X4E)
#define TCNT1H			*(reg_type8_t)(0X4D)
#define TCNT1L			*(reg_type8_t)(0X4C)
#define TCNT1			*(reg_type16_t)(0X4C)
#define OCR1AH			*(reg_type8_t)(0X4B)
#define OCR1AL			*(reg_type8_t)(0X4A)
#define OCR1A			*(reg_type16_t)(0X4A)
#define OCR1BH			*(reg_type8_t)(0X49)
#define OCR1BL			*(reg_type8_t)(0X48)
#define OCR1B			*(reg_type16_t)(0X48)
#define ICR1H			*(reg_type8_t)(0X47)
#define ICR1L			*(reg_type8_t)(0X46)
#define ICR1			*(reg_type16_t)(0X46)
	

/*
 * Timer 2 Registers
 */
#define TCCR2			*(reg_type8_t)(0X45)	
#define TCNT2			*(reg_type8_t)(0X44)
#define OCR2			*(reg_type8_t)(0X43)
#define ASSR			*(reg_type8_t)(0X42)


/* SPI */
#define SPCR    *(reg_type8_t)(0x0D)
#define SPSR    *(reg_type8_t)(0x0E)
#define SPDR    *(reg_type8_t)(0x0F)






#endif /* REGISTERS_H_ */
