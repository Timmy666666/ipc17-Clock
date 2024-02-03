/*
 * @Author: IPC15-李天凯
 * @Date: 2023-11-1 20:55:18
 * @LastEditTime: 2023-11-1 20:55:18
 * @FilePath: \USER\main.c
 * @custom_steing_obkoro1:  Read only, do not modify place!!!
 */
#include "sys.h" //The <lwoopc.h> is already included here
#include "delay.h"
#include "usart.h"
//#include "usart2.h"	
#include "led.h"
#include "stdio.h"
#include "math.h"
#include "OLED.h"
#include "bee.h"  
#include "w25q128.h"
#include "HMC5883L.h"
#include "math.h"
#include "icm20602.h"
#include "bmi088.h"
#include "bmp280.h"
#include "clock.h"

extern uint8_t Count;



int main(void)
{  

	OLED_Init();
	TIM3_Init(10000,8400);
	pClock clock = Clock_CreateWithArgs(00,00,00);//从哪里开始计数

	

    while (1)
	{
		clock->pClock_Add();
		clock->pClock_Print();
		
		
		
	}
		
}

