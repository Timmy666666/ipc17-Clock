#include "exti.h"  
#include "led.h"
#include "bee.h" 
volatile unsigned char count,count1;
void exti_Init(void)
{
	RCC_APB2PeriphClockCmd (RCC_APB2Periph_SYSCFG ,ENABLE);
	RCC_AHB1PeriphClockCmd (RCC_AHB1Periph_GPIOD ,ENABLE);

	
	GPIO_InitTypeDef GPIO_InitStructure;
	EXTI_InitTypeDef EXTI_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3|GPIO_Pin_4;
	GPIO_InitStructure.GPIO_PuPd =GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Mode =GPIO_Mode_IN;
	GPIO_Init(GPIOD,&GPIO_InitStructure);
	
	SYSCFG_EXTILineConfig (EXTI_PortSourceGPIOD,EXTI_PinSource3);//配置exti3线的中断
	
	EXTI_InitStructure.EXTI_Line =EXTI_Line3;
	EXTI_InitStructure.EXTI_Mode =EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger =EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_LineCmd =ENABLE;
	EXTI_Init(&EXTI_InitStructure);
	
	SYSCFG_EXTILineConfig (EXTI_PortSourceGPIOD,EXTI_PinSource4);//配置exti4线的中断
	
	EXTI_InitStructure.EXTI_Line =EXTI_Line4;
	EXTI_InitStructure.EXTI_Mode =EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger =EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_LineCmd =ENABLE;
	EXTI_Init(&EXTI_InitStructure);
	
	NVIC_InitStructure.NVIC_IRQChannel =EXTI3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd =ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority =0x00;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority =0x00;
	NVIC_Init (&NVIC_InitStructure);
	
	NVIC_InitStructure.NVIC_IRQChannel =EXTI4_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd =ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority =0x00;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority =0x00;
	NVIC_Init (&NVIC_InitStructure);
	
}

//void EXTI3_IRQHandler(void)
//{
//	if(EXTI_GetITStatus(EXTI_Line3 )!=RESET )
//	{
//		 green_toggle();
//	}
//	
//	EXTI_ClearITPendingBit(EXTI_Line3);
//}
void EXTI3_IRQHandler(void)
{
	while(EXTI_GetITStatus(EXTI_Line3 )!=RESET)
	
		{
		Bee_ON
		delay_ms(5);		
		Bee_OFF 
		delay_ms(5);
			
		if(GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_3)==1)
		Reset_Function();//复位
		
		}
	
	EXTI_ClearITPendingBit(EXTI_Line3);
}
void Reset_Function(void)
{
    NVIC_SystemReset();
}

void EXTI4_IRQHandler(void)
{
	
	if(EXTI_GetITStatus(EXTI_Line4 )!=RESET)
	{	delay_ms(10);
		if(EXTI_GetITStatus(EXTI_Line4 )!=RESET)
			{
			count++;
			count1++;
		
		}}
		
			
	EXTI_ClearITPendingBit(EXTI_Line4);
}





