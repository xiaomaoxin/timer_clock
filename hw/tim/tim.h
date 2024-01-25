#ifndef __TIM_H
#define __TIM_H

#include "sys.h"

typedef uint16_t u16;
	 
void TIM3_Init(u16 arr,u16 psc);//arr自动重装载值，psc预分频值

void TIM4_Init(u16 arr,u16 psc);

void Second_goes(void);

#endif
