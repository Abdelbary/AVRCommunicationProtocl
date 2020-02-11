/*
 * SwICU.h
 *
 *  Created on: Oct 27, 2019
 *      Author: Sprints
 */

#ifndef HWICU_H_
#define HWICU_H_

#include "interrupt.h"
#include "timers.h"

typedef enum EN_HwICU_Edge_t{
	HwICU_EdgeFalling = 2,
	HwICU_EdgeRisiging = 3
}EN_HwICU_Edge_t;

void HwICU_Init(EN_HwICU_Edge_t a_en_inputCaptureEdge);
EN_HwICU_Edge_t HwICU_GetCfgEdge(void);
void HwICU_SetCfgEdge(EN_HwICU_Edge_t a_en_inputCaptureEdge);
void HwICU_Read(volatile uint8_t * a_pu8_capture);
void HwICU_Stop(void);
void HwICU_Start(void);
void HwICU_Enable(void);
void HwICU_Disable(void);

#endif /* SWICU_H_ */
