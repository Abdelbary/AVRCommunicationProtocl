/*
 * sevenSeg_BCD.h
 *
 *  Created on: Oct 24, 2019
 *      Author: Sprints
 */

#ifndef SEVENSEG_H_
#define SEVENSEG_H_


#include "sevenSegConfig.h"
#include "gpio.h"

typedef enum En_SevenSegId_t{
	SEG_0,
	SEG_1,
}En_SevenSegId_t;

/**
 * Description: 
 * @param 
 */
void sevenSegInit(En_SevenSegId_t a_segment_id);

/**
 * Description: 
 * @param 
 */
void sevenSegEnable(En_SevenSegId_t en_segment_id);

/**
 * Description: 
 * @param 
 */
void sevenSegDisable(En_SevenSegId_t en_segment_id);

/**
 * Description: 
 * @param 
 */
void sevenSegWrite(En_SevenSegId_t en_segment_id, uint8_t u8_number);


#endif /* SEVENSEG_BCD_H_ */
