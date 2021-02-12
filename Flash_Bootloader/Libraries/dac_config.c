#include "dac_config.h"
#include "main.h"

uint16_t  rcosin[350]= {2048 , 2767 , 3395 , 3851 , 4076 , 4044 , 3756 , 3251 , 2592 , 1864 , 1159 , 568 , 165 , 2 , 100 , 447 , 997 , 1682 , 2413 , 3098 , 3648 , 3995 , 4093 , 3930 , 3527 , 2936 , 2231 , 1503 , 844 , 339 , 51 , 19 , 244 , 700 , 1328 , 2048 , 2767 , 3395 , 3851 , 4076 , 4044 , 3756 , 3251 , 2592 , 1864 , 1159 , 568 , 165 , 2 , 100 , 447 , 997 , 1682 , 2413 , 3098 , 3648 , 3995 , 4093 , 3930 , 3527 , 2936 , 2231 , 1503 , 844 , 339 , 51 , 19 , 244 , 700 , 1328 , 2048 , 2767 , 3395 , 3851 , 4076 , 4044 , 3756 , 3251 , 2592 , 1864 , 1159 , 568 , 165 , 2 , 100 , 447 , 997 , 1682 , 2413 , 3098 , 3648 , 3995 , 4093 , 3930 , 3527 , 2936 , 2231 , 1503 , 844 , 339 , 51 , 19 , 244 , 700 , 1328 , 2047 , 2767 , 3395 , 3851 , 4076 , 4044 , 3756 , 3251 , 2592 , 1864 , 1159 , 568 , 165 , 2 , 100 , 447 , 997 , 1682 , 2413 , 3098 , 3648 , 3995 , 4093 , 3930 , 3527 , 2936 , 2231 , 1503 , 844 , 339 , 51 , 19 , 244 , 700 , 1328 , 2047 , 2767 , 3395 , 3851 , 4076 , 4044 , 3756 , 3251 , 2592 , 1864 , 1159 , 568 , 165 , 2 , 100 , 447 , 997 , 1682 , 2413 , 3098 , 3648 , 3995 , 4093 , 3930 , 3527 , 2936 , 2231 , 1503 , 844 , 339 , 51 , 19 , 244 , 700 , 1328 , 2048 , 2767 , 3395 , 3851 , 4076 , 4044 , 3756 , 3251 , 2592 , 1864 , 1159 , 568 , 165 , 2 , 100 , 447 , 997 , 1682 , 2413 , 3098 , 3648 , 3995 , 4093 , 3930 , 3527 , 2936 , 2231 , 1503 , 844 , 339 , 51 , 19 , 244 , 700 , 1328 , 2048 , 2767 , 3395 , 3851 , 4076 , 4044 , 3756 , 3251 , 2592 , 1864 , 1159 , 568 , 165 , 2 , 100 , 447 , 997 , 1682 , 2413 , 3098 , 3648 , 3995 , 4093 , 3930 , 3527 , 2936 , 2231 , 1503 , 844 , 339 , 51 , 19 , 244 , 700 , 1328 , 2048 , 2767 , 3395 , 3851 , 4076 , 4044 , 3756 , 3251 , 2592 , 1864 , 1159 , 568 , 165 , 2 , 100 , 447 , 997 , 1682 , 2413 , 3098 , 3648 , 3995 , 4093 , 3930 , 3527 , 2936 , 2231 , 1503 , 844 , 339 , 51 , 19 , 244 , 700 , 1328 , 2047 , 2767 , 3395 , 3851 , 4076 , 4044 , 3756 , 3251 , 2592 , 1864 , 1159 , 568 , 165 , 2 , 100 , 447 , 997 , 1682 , 2413 , 3098 , 3648 , 3995 , 4093 , 3930 , 3527 , 2936 , 2231 , 1503 , 844 , 339 , 51 , 19 , 244 , 700 , 1328 , 2047 , 2767 , 3395 , 3851 , 4076 , 4044 , 3756 , 3251 , 2592 , 1864 , 1159 , 568 , 165 , 2 , 100 , 447 , 997 , 1682 , 2413 , 3098 , 3648 , 3995 , 4093 , 3930 , 3527 , 2936 , 2231 , 1503 , 844 , 339 , 51 , 19 , 244 , 700 , 1328};
uint16_t  source[350]= {2047 , 1359 , 930 , 911 , 1284 , 1869 , 2398 , 2627 , 2438 , 1884 , 1173 , 578 , 323 , 495 , 1004 , 1622 , 2076 , 2164 , 1835 , 1215 , 549 , 104 , 58 , 423 , 1044 , 1662 , 2020 , 1970 , 1535 , 900 , 334 , 78 , 247 , 782 , 1473 , 2048 , 2282 , 2096 , 1583 , 976 , 544 , 489 , 853 , 1511 , 2211 , 2690 , 2772 , 2450 , 1882 , 1331 , 1049 , 1182 , 1699 , 2413 , 3055 , 3383 , 3289 , 2834 , 2233 , 1757 , 1627 , 1917 , 2529 , 3230 , 3746 , 3883 , 3599 , 3027 , 2418 , 2035 , 2048 , 2460 , 3108 , 3730 , 4071 , 3994 , 3530 , 2871 , 2288 , 2018 , 2167 , 2666 , 3299 , 3794 , 3934 , 3647 , 3037 , 2341 , 1830 , 1696 , 1976 , 2532 , 3112 , 3454 , 3392 , 2928 , 2229 , 1559 , 1170 , 1198 , 1603 , 2193 , 2696 , 2878 , 2637 , 2048 , 1328 , 752 , 534 , 740 , 1263 , 1864 , 2273 , 2301 , 1918 , 1265 , 596 , 174 , 160 , 547 , 1166 , 1750 , 2051 , 1938 , 1453 , 796 , 237 , 9 , 208 , 757 , 1434 , 1965 , 2140 , 1897 , 1348 , 734 , 325 , 305 , 701 , 1367 , 2047 , 2481 , 2510 , 2145 , 1561 , 1024 , 781 , 959 , 1508 , 2229 , 2848 , 3135 , 2999 , 2521 , 1925 , 1485 , 1408 , 1750 , 2394 , 3097 , 3591 , 3692 , 3379 , 2803 , 2220 , 1889 , 1963 , 2427 , 3102 , 3720 , 4036 , 3927 , 3447 , 2800 , 2258 , 2048 , 2258 , 2800 , 3447 , 3927 , 4036 , 3720 , 3102 , 2427 , 1963 , 1889 , 2220 , 2803 , 3379 , 3692 , 3591 , 3097 , 2394 , 1750 , 1408 , 1485 , 1925 , 2521 , 2999 , 3135 , 2848 , 2229 , 1508 , 959 , 781 , 1024 , 1561 , 2145 , 2510 , 2481 , 2047 , 1367 , 701 , 305 , 325 , 734 , 1348 , 1897 , 2140 , 1965 , 1434 , 757 , 208 , 9 , 237 , 796 , 1453 , 1938 , 2051 , 1750 , 1166 , 547 , 160 , 174 , 596 , 1265 , 1918 , 2301 , 2273 , 1864 , 1263 , 740 , 534 , 752 , 1328 , 2048 , 2637 , 2878 , 2696 , 2193 , 1603 , 1198 , 1170 , 1559 , 2229 , 2928 , 3392 , 3454 , 3112 , 2532 , 1976 , 1696 , 1830 , 2341 , 3037 , 3647 , 3934 , 3794 , 3299 , 2666 , 2167 , 2018 , 2288 , 2871 , 3530 , 3994 , 4071 , 3730 , 3108 , 2460 , 2048 , 2035 , 2418 , 3027 , 3599 , 3883 , 3746 , 3230 , 2529 , 1917 , 1627 , 1757 , 2233 , 2834 , 3289 , 3383 , 3055 , 2413 , 1699 , 1182 , 1049 , 1331 , 1882 , 2450 , 2772 , 2690 , 2211 , 1511 , 853 , 489 , 544 , 976 , 1583 , 2096 , 2282 , 2048 , 1473 , 782 , 247 , 78 , 334 , 900 , 1535 , 1970 , 2020 , 1662 , 1044 , 423 , 58 , 104 , 549 , 1215 , 1835 , 2164 , 2076 , 1622 , 1004 , 495 , 323 , 578 , 1173 , 1884 , 2438 , 2627 , 2398 , 1869 , 1284 , 911 , 930 , 1359};
void DMA11_init()
{
      RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA1, ENABLE);
      DMA_DeInit(DMA1_Stream5);
      DMA_InitTypeDef DMA_InitStructure;
      DMA_InitStructure.DMA_Channel = DMA_Channel_7;
      DMA_InitStructure.DMA_PeripheralBaseAddr =(uint32_t) DAC_DHR12R1_ADDR;
      DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t) &source;
      DMA_InitStructure.DMA_DIR = DMA_DIR_MemoryToPeripheral;
      DMA_InitStructure.DMA_BufferSize = 320;
      DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
      DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
      DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
      DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;
      DMA_InitStructure.DMA_MemoryBurst =  DMA_MemoryBurst_Single;
      DMA_InitStructure.DMA_Priority = DMA_Priority_High;
      DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
      DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
      DMA_InitStructure.DMA_FIFOMode =DMA_FIFOMode_Disable;  
      DMA_InitStructure.DMA_FIFOThreshold= DMA_FIFOThreshold_HalfFull;
      DMA_Init(DMA1_Stream5, &DMA_InitStructure);
      DMA_Cmd(DMA1_Stream5, ENABLE);

}
void DAC1_DMA_init()
{
         TIM6_Init();
         DMA11_init();
	/* Initialize proper GPIO pin */
         GPIO_InitTypeDef GPIO_InitStruct;
         RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
         GPIO_InitStruct.GPIO_Pin = GPIO_Pin_4;
         GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AN;
         GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
         GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
         GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
         GPIO_Init(GPIOA,&GPIO_InitStruct);
	/* Enable DAC clock */
	RCC->APB1ENR |= RCC_APB1ENR_DACEN;
	
	/* Set DAC options */
        DAC_InitTypeDef DAC_InitStruct;
	DAC_InitStruct.DAC_Trigger = DAC_Trigger_T6_TRGO;//thay bang timer 6
	DAC_InitStruct.DAC_WaveGeneration = DAC_WaveGeneration_None;
        DAC_InitStruct.DAC_LFSRUnmask_TriangleAmplitude=DAC_LFSRUnmask_Bits2_0;
	DAC_InitStruct.DAC_OutputBuffer = DAC_OutputBuffer_Enable;
	
	/* Init and enable proper DAC */
	
	DAC_Init(DAC_Channel_1, &DAC_InitStruct);
	/* Enable DAC channel 1 */
	DAC->CR |= DAC_CR_EN1;
        DAC_Cmd(DAC_Channel_1, ENABLE);
        DAC_SoftwareTriggerCmd(DAC_Channel_1, ENABLE);
        DAC_DMACmd( DAC_Channel_1, ENABLE);
}

void DMA12_init()
{
      RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA1, ENABLE);
      DMA_DeInit(DMA1_Stream6);
      DMA_InitTypeDef DMA_InitStructure;
      DMA_InitStructure.DMA_Channel = DMA_Channel_7;
      DMA_InitStructure.DMA_PeripheralBaseAddr =(uint32_t) DAC_DHR12R2_ADDR;
      DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t) &rcosin;
      DMA_InitStructure.DMA_DIR = DMA_DIR_MemoryToPeripheral;
      DMA_InitStructure.DMA_BufferSize = 320;
      DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
      DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
      DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
      DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;
      DMA_InitStructure.DMA_MemoryBurst =  DMA_MemoryBurst_Single;
      DMA_InitStructure.DMA_Priority = DMA_Priority_High;
      DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;
      DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
      DMA_InitStructure.DMA_FIFOMode =DMA_FIFOMode_Disable;  
      DMA_InitStructure.DMA_FIFOThreshold= DMA_FIFOThreshold_HalfFull;
      DMA_Init(DMA1_Stream6, &DMA_InitStructure);
      DMA_Cmd(DMA1_Stream6, ENABLE);

}
void DAC2_DMA_init()
{
         TIM6_Init();
         DMA12_init();
	/* Initialize proper GPIO pin */
         GPIO_InitTypeDef GPIO_InitStruct;
         RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
         GPIO_InitStruct.GPIO_Pin = GPIO_Pin_5;
         GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AN;
         GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
         GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
         GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
         GPIO_Init(GPIOA,&GPIO_InitStruct);
	/* Enable DAC clock */
        RCC_APB1PeriphClockCmd(RCC_APB1Periph_DAC, ENABLE);
	
	/* Set DAC options */
        DAC_InitTypeDef DAC_InitStruct;
	DAC_InitStruct.DAC_Trigger = DAC_Trigger_T6_TRGO;//thay bang timer 7
	DAC_InitStruct.DAC_WaveGeneration = DAC_WaveGeneration_None;
        DAC_InitStruct.DAC_LFSRUnmask_TriangleAmplitude=DAC_LFSRUnmask_Bits2_0;
	DAC_InitStruct.DAC_OutputBuffer = DAC_OutputBuffer_Enable;
	
	/* Init and enable proper DAC */
	DAC_Init(DAC_Channel_2, &DAC_InitStruct);
	/* Enable DAC channel 2 */
	DAC->CR |= DAC_CR_EN2;
        DAC_Cmd(DAC_Channel_2, ENABLE);
        DAC_SoftwareTriggerCmd(DAC_Channel_2, ENABLE);
        DAC_DMACmd( DAC_Channel_2, ENABLE);
}


void DAC2_init()
{
	/* Initialize proper GPIO pin */
         GPIO_InitTypeDef GPIO_InitStruct;
         RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
         GPIO_InitStruct.GPIO_Pin = GPIO_Pin_5;
         GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AN;
         GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
         GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
         GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
         GPIO_Init(GPIOA,&GPIO_InitStruct);
	/* Enable DAC clock */
	RCC->APB1ENR |= RCC_APB1ENR_DACEN;
	
	/* Set DAC options */
        DAC_InitTypeDef DAC_InitStruct;
	DAC_InitStruct.DAC_Trigger = DAC_Trigger_None;
	DAC_InitStruct.DAC_WaveGeneration = DAC_WaveGeneration_None;
	DAC_InitStruct.DAC_OutputBuffer = DAC_OutputBuffer_Enable;
        DAC_InitStruct.DAC_LFSRUnmask_TriangleAmplitude=DAC_LFSRUnmask_Bits2_0;
	
	/* Init and enable proper DAC */
	DAC_Init(DAC_Channel_2, &DAC_InitStruct);
	/* Enable DAC channel 2 */
	DAC->CR |= DAC_CR_EN2;
        DAC_Cmd(DAC_Channel_2, ENABLE);
        DAC_SoftwareTriggerCmd(DAC_Channel_2, ENABLE);

}
