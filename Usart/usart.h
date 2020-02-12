#ifndef __USART_H__
#define __USART_H__
/*---------------------------------------- #includes ----------------------------------------*/
#include "../gpio.h"
#include "../registers.h"
#include "usart_Cfg.h"
#include "../std_types.h"
/*---------------------------------------- #defines -----------------------------------------*/
#define BAUDE_RATE 103 /* this value generates baude rate of 9600 at Fosc = 16MHz */

/*
*  Description : Initializes USART.
*
*  @param void
*  @return void
*/
void Usart_Init(void);

/*
*  Description : Read a character from RXB.
*
*  @param void
*  @return uint8_t
*/
uint8_t UsartReadRx(void);

/*
*  Description : Write a character to TXB
*
*  @param uint8_t  ch
*  @return void
*/
void UsartWriteTx(uint8_t ch);

/*
*  Description : Read a character from RXB.
*
*  @param void
*  @return uint8_t
*/
uint8_t UsartReadRxPolling(void);


/*
*  Description : Write a character to TXB
*
*  @param uint8_t ch
*  @return void
*/
void UsartWriteTxPolling(uint8_t ch);

#endif /* END OF __USART_H__ */