/**
  ******************************************************************************
  * @file    main
  * @author  XQ
  * @version V1.0
  * @date    2024-10-30
  * @brief   基于野火指南者开发板，所制作的固件库DEMO，实现移植方便。
  ******************************************************************************
  * 
	* @attention
  * 可移植固件：LED，KEY，RCC，EXTI，SYSTICK，USART，DMA
  * 持续更新中..................................
	
  ******************************************************************************
  */

/******************************************************头文件区****************************************************************/
#include "stm32f10x.h"   // 相当于51单片机中的  #include <reg51.h>
#include "led.h"
#include "key.h"
#include "rccclkconfig.h"
#include "exti.h"
#include "systick.h"
#include "usart.h"
#include "launch_config.h"//启动配置文件，自定义
#include "dma_mtm.h"
/******************************************************头文件区****************************************************************/

/******************************************************宏定义区****************************************************************/
//GPIOx(A,B,C)基地址
#define GPIOB_ODR_Addr (GPIOB_BASE+0X0C)
#define GPIOA_IDR_Addr (GPIOA_BASE+0X08)
#define GPIOC_IDR_Addr (GPIOC_BASE+0X08)

//位带操作计算总公式
#define PBout(bitnum) *(unsigned int*)((GPIOB_ODR_Addr & 0xF0000000)+0x02000000+((GPIOB_ODR_Addr & 0x00FFFFFF)<<5)+(bitnum<<2))
#define PAin(bitnum) *(unsigned int*)((GPIOA_IDR_Addr & 0xF0000000)+0x02000000+((GPIOA_IDR_Addr & 0x00FFFFFF)<<5)+(bitnum<<2))
#define PCin(bitnum) *(unsigned int*)((GPIOC_IDR_Addr & 0xF0000000)+0x02000000+((GPIOC_IDR_Addr & 0x00FFFFFF)<<5)+(bitnum<<2))
		
/******************************************************宏定义区****************************************************************/


int main(void)
{
/******************************************************配置函数区**************************************************************/
#if IsLaunch_RCC_HSE
	HSE_SetClk(RCC_PLLMul_9);/* 外部高速时钟，配置时钟为8M*9 = 72M */
	
#elif IsLaunch_RCC_HIE
	HSI_SetClk(RCC_PLLMul_16);/* 内部高速时钟，配置时钟为4M*16 = 64M */
	
#elif IsLaunch_RCC_MCO
	MCO_GPIO_Config();/*MCO配置，用于配置时钟的输出检测 */
	RCC_MCOConfig(RCC_MCO_SYSCLK);/*选择输出检测的对象来源于哪——系统时钟RCC_MCO_SYSCLK*/
	//RCC_MCOConfig(RCC_MCO_HSI);
#elif IsLaunch_KEY
	KEY1_GPIO_Config();/* 按键配置KEY1 */
	
#elif IsLaunch_LED
	LED_GPIO_Config();/* LED灯配置 */

#elif IsLaunch_EXTI
	EXTI_Key1_Config();/* 按键中断配置KEY1 */

#elif IsLaunch_USART/* 串口配置 */
	USART_Config();
	//Usart_SendByte(DEBUG_USARTx,100);
	printf("这是一个测试发送");
	
#elif IdLaunch_DMA_MtM/* DMA配置（M TO M） */
	MtM_DMA_Config();
	while(DMA_GetFlagStatus(uint32_t DMAy_FLAG) == RESET);/* 判断M TO M 是否传递完 */
	
#endif

/******************************************************配置函数区**************************************************************/


/******************************************************执行函数区**************************************************************/
#if 0
	while(1)
	{
		//GPIO_SetBits(LED_G_GPIO_PORT, LED_G_GPIO_PIN);
		//LED_G(ON);
		PBout(0) = 1; // 位带操作
		
		SysTick_Delay_ms(1000); //系统定时器
		//GPIO_ResetBits(LED_G_GPIO_PORT, LED_G_GPIO_PIN);
		//LED_G(OFF);
		PBout(0) = 0; //位带操作
		
		SysTick_Delay_ms(1000); //系统定时器
	}
	
#elif 0
	while(1)
	{
		if(PAin(0) == KEY_ON)
		{
			while(PAin(0) == KEY_ON);
			LED_G_TOGGLE;
		}
		if(PCin(13) == KEY_ON)
		{
			while(PCin(0) == KEY_ON);
			LED_G_TOGGLE;
		}
	}
#elif 1
	while(1)
	{
	
	}
	
#endif


/******************************************************执行函数区**************************************************************/
	
}




