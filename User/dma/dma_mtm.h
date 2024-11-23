#ifndef __DMA_MTM_H
#define __DMA_MTM_H
//变量一般不在头文件中定义，容易产生重复定义。可加extern
//在c中可以重复声明，但不可重复定义

/* extern  int ival=10; //虽然ival声明为extern，但是它初始化了，代表这是个定义。
   double fica_rate;  //fica_rate虽然没有初始化，但是没有extern。所以仍是定义。*/

#include "stm32f10x.h"
#define MtM_DMA_CLK 		RCC_AHBPeriph_DMA1
#define MtM_DMA_CHANNEL DMA1_Channel6
#define MtM_DMA_FLAG_TC		DMA1_FLAG_TC6



// 要发送的数据大小
#define BUFFER_SIZE     32


																		
void MtM_DMA_Config(void);

#endif




