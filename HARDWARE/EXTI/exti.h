#ifndef __EXTI_H
#define __EXTI_H

#include "stm32f4xx.h"
#include "delay.h"

	void exti_Init(void);
	void EXTI3_IRQHandler(void);
	void Reset_Function(void);
	void EXTI4_IRQHandler(void);
#endif

