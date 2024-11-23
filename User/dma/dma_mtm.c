#include "dma_mtm.h"

const uint32_t aSRC_Const_Buffer[BUFFER_SIZE]= {
                                    0x01020304,0x05060708,0x090A0B0C,0x0D0E0F10,
                                    0x11121314,0x15161718,0x191A1B1C,0x1D1E1F20,
                                    0x21222324,0x25262728,0x292A2B2C,0x2D2E2F30,
                                    0x31323334,0x35363738,0x393A3B3C,0x3D3E3F40,
                                    0x41424344,0x45464748,0x494A4B4C,0x4D4E4F50,
                                    0x51525354,0x55565758,0x595A5B5C,0x5D5E5F60,
                                    0x61626364,0x65666768,0x696A6B6C,0x6D6E6F70,
                                    0x71727374,0x75767778,0x797A7B7C,0x7D7E7F80};

uint32_t aDST_Buffer[BUFFER_SIZE];
																		
																		
//typedef struct
//{
//  uint32_t DMA_PeripheralBaseAddr; /*!< Specifies the peripheral base address for DMAy Channelx. */
//  uint32_t DMA_MemoryBaseAddr;     /*!< Specifies the memory base address for DMAy Channelx. */
//  uint32_t DMA_DIR;                /*!< Specifies if the peripheral is the source or destination.
//                                        This parameter can be a value of @ref DMA_data_transfer_direction */
//  uint32_t DMA_BufferSize;         /*!< Specifies the buffer size, in data unit, of the specified Channel. 
//                                        The data unit is equal to the configuration set in DMA_PeripheralDataSize
//                                        or DMA_MemoryDataSize members depending in the transfer direction. */
//  uint32_t DMA_PeripheralInc;      /*!< Specifies whether the Peripheral address register is incremented or not.
//                                        This parameter can be a value of @ref DMA_peripheral_incremented_mode */
//  uint32_t DMA_MemoryInc;          /*!< Specifies whether the memory address register is incremented or not.
//                                        This parameter can be a value of @ref DMA_memory_incremented_mode */
//  uint32_t DMA_PeripheralDataSize; /*!< Specifies the Peripheral data width.
//                                        This parameter can be a value of @ref DMA_peripheral_data_size */
//  uint32_t DMA_MemoryDataSize;     /*!< Specifies the Memory data width.
//                                        This parameter can be a value of @ref DMA_memory_data_size */
//  uint32_t DMA_Mode;               /*!< Specifies the operation mode of the DMAy Channelx.
//                                        This parameter can be a value of @ref DMA_circular_normal_mode.
//                                        @note: The circular buffer mode cannot be used if the memory-to-memory
//                                              data transfer is configured on the selected Channel */
//  uint32_t DMA_Priority;           /*!< Specifies the software priority for the DMAy Channelx.
//                                        This parameter can be a value of @ref DMA_priority_level */
//  uint32_t DMA_M2M;                /*!< Specifies if the DMAy Channelx will be used in memory-to-memory transfer.
//                                        This parameter can be a value of @ref DMA_memory_to_memory */
//}DMA_InitTypeDef;

void MtM_DMA_Config(void)
{
	DMA_InitTypeDef DMA_InitStruct;
	
	RCC_AHBPeriphClockCmd(MtM_DMA_CLK, ENABLE);
	
	DMA_InitStruct.DMA_PeripheralBaseAddr = (uint32_t)aSRC_Const_Buffer;
	DMA_InitStruct.DMA_MemoryBaseAddr = (uint32_t)aDST_Buffer;
	DMA_InitStruct.DMA_DIR = DMA_DIR_PeripheralSRC;
	
	DMA_InitStruct.DMA_BufferSize = BUFFER_SIZE;
	DMA_InitStruct.DMA_PeripheralInc = DMA_PeripheralInc_Enable;
	DMA_InitStruct.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Word;
	
	DMA_InitStruct.DMA_MemoryInc = DMA_MemoryInc_Enable;
	DMA_InitStruct.DMA_MemoryDataSize = DMA_MemoryDataSize_Word;
	
	DMA_InitStruct.DMA_Mode = DMA_Mode_Normal;
	DMA_InitStruct.DMA_Priority = DMA_Priority_High;
	DMA_InitStruct.DMA_M2M = DMA_M2M_Enable;
	
	DMA_Init(MtM_DMA_CHANNEL, &DMA_InitStruct);
	DMA_ClearFlag(MtM_DMA_FLAG_TC);
	DMA_Cmd(MtM_DMA_CHANNEL, ENABLE);

}
