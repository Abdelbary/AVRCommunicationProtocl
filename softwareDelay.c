/*
 * softwareDelay.c
 *
 * Created: 1/17/2020 8:58:23 AM
 *  Author: mahmo
 */ 
#include "std_types.h"
#define  MSECTICKS 1400
void softwareDelayMs(uint32_t u32_delay_in_ms)
{
	uint64_t tick;
	while (u32_delay_in_ms--)
	for(tick = FALSE ; tick < MSECTICKS ; ++tick);	
}