 /*---------------------------------------- #Include & #Define ---------------------------------*/
#include "usart.h"
#include "../interrupt.h"
/* Create a new Usart instance in the main -Dont forget - */
//Usart s ={/*put your initial params here and then s will be passed to functions*/};
extern volatile uint8_t * c;  
volatile uint8_t u8_udr_is_empty = 0; // you cannot read 

/*
*  Description : Intializes USART.
*
*  @param void
*  @return void
*/
void Usart_Init(void)
{
   /*----------------- initializing (UCSRC) -----------------*/   
   UCSRC |= (usart_init_config.usart_mode_sel|usart_init_config.stop_bit_sel|usart_init_config.reg_sel_mode|0x06); /*0x05 becuase we want UCSZ0:1 to be set to 1 1 ---> in order to obtain 8-bit width character*/
   //UCSRC |= 0x85; /*works fine*/
   /*----------------- initializing (UCSRB) -----------------*/
   UCSRB |= ((usart_init_config.interrupt_mode_sel | usart_init_config.usart_dir_sel) & (~(0x04)) & (~(0x03)));
   //UCSRB  |= 0xB8;
   /*----------------- initializing (UCSRA) -----------------*/
   //UCSRA &= ~(0x1C); /* Check that FE & DOR & PE is set to zero*/
   UCSRA |= (usart_init_config.double_speed_select & ~(0x1C));
   /*------------------ initialize baude rate ---------------*/
   UBRRL = BAUDE_RATE;
   /*------------------ Character size select  ---------------*/
   /*---- setting it to 8-bit -----*/
   //UCSRC |= 0x05;
   //UCSRB &= ~(0x04); /* ----> check this if it will work or not */
   /*----- clear RXB8 and TXB8 ----*/
   //UCSRB &= ~(0x03);
}

/*
*  Description : Read a character from RXB.
*
*  @param void
*  @return uint8_t
*/
uint8_t UsartReadRxPolling(void)
{
   while (!(UCSRA & (0x80))) ; /* while RXC == 0 */
   return (uint8_t)UDR;
}

/*
*  Description : Write a character to TXB
*
*  @param uint8_t ch
*  @return void
*/
void UsartWriteTxPolling(uint8_t ch)
{
   while (!(UCSRA & (0x20))) ; /* check UDRE is empty through URDE flag */
   //UCSRC |= 0x80;
   UDR = (uint8_t)ch;
   
}

/*
*  Description : Read a character from RXB.
*
*  @param void
*  @return uint8_t
*/
uint8_t UsartReadRx(void)
{
   //while (!(UCSRA & (0x80))) ; /* while RXC == 0 */
   return (uint8_t)UDR;
}

/*
*  Description : Write a character to TXB
*
*  @param uint8_t ch
*  @return void
*/
void UsartWriteTx(uint8_t ch)
{
   //while (!(UCSRA & (0x20))) ; /* check UDRE is empty through URDE flag */
   UDR = ch;
   
}

/*------------------------------------- Interrupt handlers  -----------------------------------*/

/*
* Usart on successful character receive completion interrupt handler 
*/
ISR(USART_RXC_vect)
{
   /*
   * on successful character reception ..> write the new character
   */   
   //UsartReadRx();
    //*c = UDR;    
    u8_udr_is_empty = FALSE;    
}

/*
* Usart when data register is empty
*/
ISR(USART_UDRE_vect)
{
   /*
   * when data register is empty ..> read the new character 
   */
   //UDR = (*c);
   u8_udr_is_empty = TRUE;          
}