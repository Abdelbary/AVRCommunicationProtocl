/*
 * SwICU.c
 *
 * Created: 1/29/2020 4:33:50 AM
 *  Author: mahmo
 */ 

#include "SwICU.h"

volatile uint16_t gu16SwICU_timer0_Overflow_Counts = ZERO;
volatile uint8_t  gu8SwICU_INT2_vec_enteranceFlag = ZERO;
volatile uint8_t  gu8SwICU_Timer0_Stop_Flag = FALSE;



/*			CONFIGIRE EXTERNAL INT
*	REGISTERS : GIFR  [INTF1 INTF0 INTF2]
*				GICR  [INT1 INT0 INT2]
*				MCUCR [ISC11 ISC10 ISC01 ISC00]
*				MCUCSR [ISCR2]
*/
void external_Int_Enable(En_externalInt_t en_externalInt
,EN_SwICU_Edge_t swICU_Edge)
{
	switch (en_externalInt)
	{
		case EN_INT0:
			switch(swICU_Edge)
			{
				case SwICU_EdgeRisiging:
				break;
				case SwICU_EdgeFalling:
				break;
			}
		break;
		case EN_INT1:
			switch(swICU_Edge)
			{
				case SwICU_EdgeRisiging:
				break;
				case SwICU_EdgeFalling:
				break;
			}
		break;
		case EN_INT2:
			switch(swICU_Edge)
			{
				case SwICU_EdgeRisiging:
				/*			 CONFIGRE EXTERNAL INT2
				*  1-disable INT2 in GUCR.INT2
				*  2-Configure raising or falling edge MCUCSR.IISC2
				*  3-clear INT2 flag in GIFR.INTF2
				*  4-enable INT2 in GUCR.INT2
				*  5-make pin direction input POTTB.PIN2
				*  6-enbale global int sei()
				*/
				CLEAR_BIT(GICR,INT2);
				SET_BIT(MCUCSR,ISC2);
				SET_BIT(GIFR,INTF2);/*CLEAR INT FLAG BY SET IT'S BIT TO 1*/
				SET_BIT(GICR,INT2);
				gpioPinDirection(GPIOB,BIT2,INPUT);
				sei();
				break;
				case SwICU_EdgeFalling:
				break;
			}
		break;
		
	}
}

void external_Int_Change_Edge(En_externalInt_t en_externalInt
,EN_SwICU_Edge_t swICU_Edge)
{
	switch (en_externalInt)
	{
		case EN_INT0:
			switch(swICU_Edge)
			{
				case SwICU_EdgeRisiging:
				break;
				case SwICU_EdgeFalling:
				break;
			}
		break;
		case EN_INT1:
			switch(swICU_Edge)
			{
				case SwICU_EdgeRisiging:
				break;
				case SwICU_EdgeFalling:
				break;
			}
		break;
		case EN_INT2:
			switch(swICU_Edge)
			{
				case SwICU_EdgeRisiging:
					
					SET_BIT(MCUCSR,ISC2);

				break;
				case SwICU_EdgeFalling:
					CLEAR_BIT(MCUCSR,ISC2);
				break;
			}
		break;
		
	}
}

void SwICU_Init(EN_SwICU_Edge_t a_en_inputCaptureEdge)
{
	
	/*initialize external int
	* initialize timer0 and
	*
	*
	*/



	external_Int_Enable(EN_INT2,SwICU_EdgeRisiging);
	timer0Init(T0_NORMAL_MODE,T0_OC0_DIS,T0_PRESCALER_64,
	ZERO,ZERO,T0_INTERRUPT_NORMAL);
	gu16SwICU_timer0_Overflow_Counts = ZERO;
	gu8SwICU_INT2_vec_enteranceFlag = ZERO;
	gu8SwICU_Timer0_Stop_Flag = FALSE;

}





void SwICU_SetCfgEdge(EN_SwICU_Edge_t a_en_inputCaptureEdgeedge){
	/*change the config of the ext pin 
	* rasing failling
	*/
	external_Int_Change_Edge(EN_INT2,a_en_inputCaptureEdgeedge);
	
}


void SwICU_Read(uint64_t * a_pu8_capt)
{
	/*
	* poll for timer0stop flag then read value
	* read ticks value 
	* set Timer0_Stop_Flag t0 false  
	* zero the number of overflow
	* reinitalize timer0 to reset it
	*/
	while(gu8SwICU_Timer0_Stop_Flag == FALSE);
	*a_pu8_capt = (gu16SwICU_timer0_Overflow_Counts*(uint64_t)TIMER0_RESLUTION)+timer0Read();
	gu16SwICU_timer0_Overflow_Counts = ZERO;
	gu8SwICU_Timer0_Stop_Flag = FALSE;
	

	/*	
	timer0Init(T0_NORMAL_MODE,T0_OC0_DIS,T0_PRESCALER_64,
	ZERO,ZERO,T0_INTERRUPT_NORMAL);
	*/
}


void SwICU_Stop(void){
	/*stop timer */
	timer0Stop();
}


void SwICU_Start(void)
{
	/*start timer*/
	timer0Start();
}


