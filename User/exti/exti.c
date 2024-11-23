#include "exti.h"
//static 锁死于该文件，其他不可调用
static void EXTI_NVIC_Config(void)
{
	NVIC_InitTypeDef NVIC_InitConfig;
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	
	NVIC_InitConfig.NVIC_IRQChannel = EXTI0_IRQn;
	NVIC_InitConfig.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitConfig.NVIC_IRQChannelSubPriority = 1;
	NVIC_InitConfig.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitConfig);


}

void EXTI_Key1_Config(void)
{

  GPIO_InitTypeDef GPIO_InitStruct;
	EXTI_InitTypeDef EXTI_InitStruct;
	
	//配置中断优先级
	EXTI_NVIC_Config();
	
	RCC_APB2PeriphClockCmd(KEY1_INT_GPIO_CLK, ENABLE);
	GPIO_InitStruct.GPIO_Pin = KEY1_INT_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(KEY1_INT_GPIO_PORT, &GPIO_InitStruct);
	
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource0);
	
	EXTI_InitStruct.EXTI_Line = EXTI_Line0;
	EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Rising;
	EXTI_InitStruct.EXTI_LineCmd = ENABLE;
	
	EXTI_Init(&EXTI_InitStruct);


}


