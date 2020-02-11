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


gstrSPI_spi_satus_t sp_status;

void slave(){
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
	uint8_t r;
	while(1){
		r = SPI_recieveByte();
		//PORTA_DATA = r;
		sevenSegWrite(SEG_0,r);
	}

}

void master(){
	sp_status.spi_mod			 = SPI_MASTER_MOD;
	sp_status.spi_opration_mod	 = SPI_NORMAL_MOD;
	sp_status.spi_prescaler		 = SPI_PRESCALER_4;
	sp_status.spi_speed_mod		 = SPI_NORMAL_MOD;
	sp_status.spi_sampling_mod	 = SPI_SAMPLING_MOD_0;
	sp_status.spi_data_order	 = SPI_DATA_ORDER_LSB;
	SPI_init(&sp_status);
	spi_enable();
	uint8_t i = 0;
	while(1){
		i%=10;
		SPI_sendByte(i);
		i++;
		timer0DelayMs(1000);
	}
	
}
int main(){
	
	//master();
	//slave();
}
