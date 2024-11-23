#ifndef __RCCCLKCONFIG_H
#define __RCCCLKCONFIG_H

#include "stm32f10x.h"

void HSE_SetClk(uint32_t RCC_PLLMul_x);
void HSI_SetClk(uint32_t RCC_PLLMul_x);
void MCO_GPIO_Config(void);

#endif






