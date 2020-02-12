/*
 * DIO.c
 *
 * Created: 1/17/2020 4:09:01 AM
 * Author : mahmo
 */ 

#include "gpio.h"
#include "pushButton.h"
#include "led.h"
#include "timers.h"
#include "interrupt.h"
#include "registers.h"
#include "spi.h"
#include "util/delay.h"
#include "sevenSeg.h"
#include "Usart/usart.h"

#define  ZERO_CHAR '0'
uint8_t test_c = 0;
volatile int Timer0OverflowCounter = ZERO;
volatile uint8_t * c = &test_c;
volatile uint8_t u8_udr_empty;

ISR(TIMER0_OVF_vect){
	Timer0OverflowCounter++;
}


gstrSPI_spi_satus_t sp_status;

void slave(){
	Usart_Init();
	pushButtonInit(BTN_0);
	pushButtonInit(BTN_1);
	sp_status.spi_mod			 = SPI_SLAVE_MOD;
	sp_status.spi_opration_mod	 = SPI_NORMAL_MOD;
	sp_status.spi_prescaler		 = SPI_PRESCALER_4;
	sp_status.spi_speed_mod		 = SPI_NORMAL_MOD;
	sp_status.spi_sampling_mod	 = SPI_SAMPLING_MOD_0;
	sp_status.spi_data_order	 = SPI_DATA_ORDER_LSB;
	SPI_init(&sp_status);
	spi_enable();
	sevenSegInit(SEG_0);
	sevenSegEnable(SEG_0);
	//PORTA_DIR = 0xff;
	u8_udr_empty = TRUE;
	uint8_t spi_value;
	uint8_t start_flag = FALSE;
	uint8_t btn0Status;
	uint8_t btn1Status;
	uint8_t pushbutton_block = FALSE;
	uint64_t distant = 0;
	while(1){
		btn0Status = pushButtonGetStatus(BTN_0);
		btn1Status = pushButtonGetStatus(BTN_1);
		if (btn0Status == Pressed && !pushbutton_block )
		{
			start_flag = TRUE;
			pushbutton_block = TRUE;
			//Led_Toggle(LED_0);
		}
		if (btn1Status == Pressed && !pushbutton_block )
		{
			/*	send data to pc 
			*	release pushbutton block state
			*	zero accumulated distance 
			*	zero start flag	
			*/
			//send data to PC via UART
				/* you can write */
			UsartWriteTx(*c);			      
			pushbutton_block = FALSE;
			start_flag = FALSE;
			distant = ZERO;
			//Led_Toggle(LED_0);
		}
		spi_value = SPI_recieveByte();
		//PORTA_DATA = r;
		if(start_flag)
		{
			distant += spi_value;
		} 
		sevenSegWrite(SEG_0,spi_value);
	
	}

}

void master(){
	Usart_Init();
	pushButtonInit(BTN_0);
	pushButtonInit(BTN_1);
	Led_Init(LED_0);
	Led_On(LED_0);
	timer0Init(T0_NORMAL_MODE,T0_OC0_DIS,
	T0_PRESCALER_1024,247,ZERO,T0_INTERRUPT_NORMAL);
	timer0Start();
	sp_status.spi_mod			 = SPI_MASTER_MOD;
	sp_status.spi_opration_mod	 = SPI_NORMAL_MOD;
	sp_status.spi_prescaler		 = SPI_PRESCALER_4;
	sp_status.spi_speed_mod		 = SPI_NORMAL_MOD;
	sp_status.spi_sampling_mod	 = SPI_SAMPLING_MOD_0;
	sp_status.spi_data_order	 = SPI_DATA_ORDER_LSB;
	SPI_init(&sp_status);
	spi_enable();
	uint8_t btn0Status;
	uint8_t btn1Status;
	uint8_t pushbutton_block = FALSE;
	//while(u8_udr_empty);
	/*you can read */
	//sint8_t speed = (sint8_t) (UsartReadRx()- ZERO_CHAR);
	timer2DelayMs(1000);
	sint8_t speed = 5;
	while(1){
		btn0Status = pushButtonGetStatus(BTN_0);
		btn1Status = pushButtonGetStatus(BTN_1);
		
		if (btn0Status == Pressed && !pushbutton_block )
		{
			speed+= (speed == 100)? 0 : 1;
			pushbutton_block = TRUE;
			//Led_Toggle(LED_0);
		}
		if (btn1Status == Pressed && !pushbutton_block )
		{
			speed-= (speed == 0)? 0 : 1;
			pushbutton_block = TRUE;

			//Led_Toggle(LED_0);
		}

		
		if(Timer0OverflowCounter >= 61){
			Timer0OverflowCounter=ZERO;
			timer0Init(T0_NORMAL_MODE,T0_OC0_DIS,
			T0_PRESCALER_1024,247,ZERO
			,T0_INTERRUPT_NORMAL);
			timer0Start();
			SPI_sendByte(speed);
			pushbutton_block = FALSE;
			//Led_Toggle(LED_0);
		}

	}
}
int main(){



	//master();
	//slave();
}
