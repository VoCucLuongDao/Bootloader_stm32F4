#ifndef _DAC_CONFIG_H_
#define _DAC_CONFIG_H_
#include "stm32f4xx_dac.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_dma.h"
#include "timer_config.h"

#define DAC_DHR12R1_ADDR   (uint32_t)0x40007408
#define DAC_DHR12R2_ADDR   (uint32_t)0x40007414
#define SIN_RES  32
#define RCOSIN_RES 3200

void DAC2_DMA_init();
void DMA11_init();
void DAC1_DMA_init();
void DMA12_init();
void DAC2_init();

#endif