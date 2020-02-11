#include "spi.h"



void SPI_init(gstrSPI_spi_satus_t * spi_status){
	
	/************************************************************************
	*                     SPI INITIATION STEPS                            
	*	1-SET PINS DIRECTION DEPENDING ON MASTER OR SLAVE
	*	2-SET PRESCALER VALUE
	*	3-SET OPERATION MODE [INT NORMAL]
	*	4-SET SPEED MOD [NORMAL DOUBLE]
	*	5-SET SAMPLING AND SETUP MOD
	*	6-SET DATA DIRECTION
	************************************************************************/
	switch(spi_status->spi_mod)
	{
	case SPI_MASTER_MOD:
	  /******** Configure SPI Master Pins *********
	 * SS(PB4)   --> Output
	 * MOSI(PB5) --> Output 
	 * MISO(PB6) --> Input
	 * SCK(PB7) --> Output
	 ********************************************/
		 SET_BIT(SPI_DIR_PORT,SPI_SS);
		 SET_BIT(SPI_DIR_PORT,SPI_MOSI);
		 SET_BIT(SPI_DIR_PORT,SPI_SCK);
		 CLEAR_BIT(SPI_DIR_PORT,SPI_MISO);
		 
		 
	break;
	case SPI_SLAVE_MOD:
	/******** Configure SPI Slave Pins *********
	 * SS(PB4)   --> Input
	 * MOSI(PB5) --> Input
	 * MISO(PB6) --> Output
	 * SCK(PB7) --> Input
	 ********************************************/
		 CLEAR_BIT(SPI_DIR_PORT,SPI_SS);
		 CLEAR_BIT(SPI_DIR_PORT,SPI_MOSI);
		 CLEAR_BIT(SPI_DIR_PORT,SPI_SCK);
		 SET_BIT(SPI_DIR_PORT,SPI_MISO);
	
	break;
	}
	SET_MASK(SPCR,spi_status->spi_prescaler);
	SET_MASK(SPCR,spi_status->spi_sampling_mod);
	SET_MASK(SPCR,spi_status->spi_mod);
	SET_MASK(SPCR,spi_status->spi_data_order);
	SET_MASK(SPCR,spi_status->spi_opration_mod);
	SET_MASK(SPSR,spi_status->spi_speed_mod);
}


void spi_enable()
{
	SET_BIT(SPCR,SPE);
}


void SPI_sendByte(const uint8_t data) 
{
	 SPDR = data; //send data by SPI
	 while((SPSR& (1<<SPIF)) == 0); //wait until SPI interrupt flag=1 (data is sent correctly)
}

uint8_t SPI_recieveByte(void)
{
   while((SPSR& (1<<SPIF)) == 0);//wait until SPI interrupt flag=1(data is receive correctly)
   return SPDR; //return the received byte from SPI data register
}

