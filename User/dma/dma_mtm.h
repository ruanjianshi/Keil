#ifndef __DMA_MTM_H
#define __DMA_MTM_H
//����һ�㲻��ͷ�ļ��ж��壬���ײ����ظ����塣�ɼ�extern
//��c�п����ظ��������������ظ�����

/* extern  int ival=10; //��Ȼival����Ϊextern����������ʼ���ˣ��������Ǹ����塣
   double fica_rate;  //fica_rate��Ȼû�г�ʼ��������û��extern���������Ƕ��塣*/

#include "stm32f10x.h"
#define MtM_DMA_CLK 		RCC_AHBPeriph_DMA1
#define MtM_DMA_CHANNEL DMA1_Channel6
#define MtM_DMA_FLAG_TC		DMA1_FLAG_TC6



// Ҫ���͵����ݴ�С
#define BUFFER_SIZE     32


																		
void MtM_DMA_Config(void);

#endif




