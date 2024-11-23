/**
  ******************************************************************************
  * @file    main
  * @author  XQ
  * @version V1.0
  * @date    2024-10-30
  * @brief   ����Ұ��ָ���߿����壬�������Ĺ̼���DEMO��ʵ����ֲ���㡣
  ******************************************************************************
  * 
	* @attention
  * ����ֲ�̼���LED��KEY��RCC��EXTI��SYSTICK��USART��DMA
  * ����������..................................
	
  ******************************************************************************
  */

/******************************************************ͷ�ļ���****************************************************************/
#include "stm32f10x.h"   // �൱��51��Ƭ���е�  #include <reg51.h>
#include "led.h"
#include "key.h"
#include "rccclkconfig.h"
#include "exti.h"
#include "systick.h"
#include "usart.h"
#include "launch_config.h"//���������ļ����Զ���
#include "dma_mtm.h"
/******************************************************ͷ�ļ���****************************************************************/

/******************************************************�궨����****************************************************************/
//GPIOx(A,B,C)����ַ
#define GPIOB_ODR_Addr (GPIOB_BASE+0X0C)
#define GPIOA_IDR_Addr (GPIOA_BASE+0X08)
#define GPIOC_IDR_Addr (GPIOC_BASE+0X08)

//λ�����������ܹ�ʽ
#define PBout(bitnum) *(unsigned int*)((GPIOB_ODR_Addr & 0xF0000000)+0x02000000+((GPIOB_ODR_Addr & 0x00FFFFFF)<<5)+(bitnum<<2))
#define PAin(bitnum) *(unsigned int*)((GPIOA_IDR_Addr & 0xF0000000)+0x02000000+((GPIOA_IDR_Addr & 0x00FFFFFF)<<5)+(bitnum<<2))
#define PCin(bitnum) *(unsigned int*)((GPIOC_IDR_Addr & 0xF0000000)+0x02000000+((GPIOC_IDR_Addr & 0x00FFFFFF)<<5)+(bitnum<<2))
		
/******************************************************�궨����****************************************************************/


int main(void)
{
/******************************************************���ú�����**************************************************************/
#if IsLaunch_RCC_HSE
	HSE_SetClk(RCC_PLLMul_9);/* �ⲿ����ʱ�ӣ�����ʱ��Ϊ8M*9 = 72M */
	
#elif IsLaunch_RCC_HIE
	HSI_SetClk(RCC_PLLMul_16);/* �ڲ�����ʱ�ӣ�����ʱ��Ϊ4M*16 = 64M */
	
#elif IsLaunch_RCC_MCO
	MCO_GPIO_Config();/*MCO���ã���������ʱ�ӵ������� */
	RCC_MCOConfig(RCC_MCO_SYSCLK);/*ѡ��������Ķ�����Դ���ġ���ϵͳʱ��RCC_MCO_SYSCLK*/
	//RCC_MCOConfig(RCC_MCO_HSI);
#elif IsLaunch_KEY
	KEY1_GPIO_Config();/* ��������KEY1 */
	
#elif IsLaunch_LED
	LED_GPIO_Config();/* LED������ */

#elif IsLaunch_EXTI
	EXTI_Key1_Config();/* �����ж�����KEY1 */

#elif IsLaunch_USART/* �������� */
	USART_Config();
	//Usart_SendByte(DEBUG_USARTx,100);
	printf("����һ�����Է���");
	
#elif IdLaunch_DMA_MtM/* DMA���ã�M TO M�� */
	MtM_DMA_Config();
	while(DMA_GetFlagStatus(uint32_t DMAy_FLAG) == RESET);/* �ж�M TO M �Ƿ񴫵��� */
	
#endif

/******************************************************���ú�����**************************************************************/


/******************************************************ִ�к�����**************************************************************/
#if 0
	while(1)
	{
		//GPIO_SetBits(LED_G_GPIO_PORT, LED_G_GPIO_PIN);
		//LED_G(ON);
		PBout(0) = 1; // λ������
		
		SysTick_Delay_ms(1000); //ϵͳ��ʱ��
		//GPIO_ResetBits(LED_G_GPIO_PORT, LED_G_GPIO_PIN);
		//LED_G(OFF);
		PBout(0) = 0; //λ������
		
		SysTick_Delay_ms(1000); //ϵͳ��ʱ��
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


/******************************************************ִ�к�����**************************************************************/
	
}




