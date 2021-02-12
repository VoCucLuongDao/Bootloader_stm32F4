#include "SPI_Config.h"

uint16_t  DAC_value[255] = {2047 ,3499 ,4094 ,3481 ,2022 ,577 ,0 ,631 ,2097 ,3534 ,4093 ,3445 ,1971 ,543 ,2 ,668 ,2148 ,3568 ,4091 ,3407 ,1921 ,509 ,5 ,706 ,2198 ,3602 ,4087 ,3369 ,1871 ,476 ,9 ,744 ,2248 ,3634 ,4083 ,3330 ,1820 ,444 ,14 ,783 ,2299 ,3665 ,4077 ,3291 ,1770 ,413 ,21 ,823 ,2349 ,3696 ,4070 ,3250 ,1721 ,384 ,28 ,864 ,2398 ,3725 ,4061 ,3209 ,1671 ,355 ,37 ,906 ,2448 ,3753 ,4052 ,3167 ,1621 ,327 ,47 ,948 ,2497 ,3781 ,4041 ,3125 ,1572 ,300 ,59 ,991 ,2546 ,3807 ,4029 ,3081 ,1523 ,274 ,71 ,1034 ,2595 ,3832 ,4016 ,3038 ,1475 ,250 ,85 ,1079 ,2643 ,3856 ,4001 ,2993 ,1426 ,226 ,100 ,1123 ,2692 ,3879 ,3986 ,2948 ,1379 ,203 ,116 ,1169 ,2739 ,3901 ,3969 ,2903 ,1331 ,182 ,134 ,1214 ,2786 ,3922 ,3951 ,2856 ,1284 ,162 ,152 ,1261 ,2833 ,3942 ,3932 ,2810 ,1238 ,143 ,172 ,1308 ,2880 ,3960 ,3912 ,2763 ,1191 ,125 ,193 ,1355 ,2925 ,3978 ,3891 ,2715 ,1146 ,108 ,215 ,1402 ,2971 ,3994 ,3868 ,2668 ,1101 ,93 ,238 ,1451 ,3015 ,4009 ,3844 ,2619 ,1056 ,78 ,262 ,1499 ,3060 ,4023 ,3820 ,2571 ,1013 ,65 ,287 ,1548 ,3103 ,4035 ,3794 ,2522 ,969 ,53 ,313 ,1597 ,3146 ,4047 ,3767 ,2473 ,927 ,42 ,341 ,1646 ,3188 ,4057 ,3739 ,2423 ,885 ,33 ,369 ,1696 ,3230 ,4066 ,3710 ,2373 ,844 ,24 ,398 ,1745 ,3271 ,4073 ,3681 ,2324 ,803 ,17 ,429 ,1795 ,3311 ,4080 ,3650 ,2274 ,764 ,11 ,460 ,1846 ,3350 ,4085 ,3618 ,2223 ,725 ,7 ,492 ,1896 ,3388 ,4089 ,3585 ,2173 ,687 ,3 ,526 ,1946 ,3426 ,4092 ,3551 ,2123 ,649 ,1 ,560 ,1997 ,3463 ,4094 ,3517 ,2072 ,613 ,0 ,595};

void SPI1_Config()
{
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA ,ENABLE);
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;
    GPIO_Init(GPIOA,&GPIO_InitStructure);
 
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource4, GPIO_AF_SPI1);
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource5, GPIO_AF_SPI1);
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource6, GPIO_AF_SPI1);    
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource7, GPIO_AF_SPI1);
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1 ,ENABLE);
    SPI_InitTypeDef SPI_InitStructure;
    SPI_InitStructure.SPI_Mode = SPI_Mode_Slave;
    SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_256;
    SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge;
    SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;
    SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
    SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
    SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
    SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;
    SPI_InitStructure.SPI_CRCPolynomial = 0;
    SPI_Init(SPI1, &SPI_InitStructure);
    SPI_Cmd(SPI1, ENABLE);
    
     NVIC_InitTypeDef NVIC_InitStructure;
     NVIC_InitStructure.NVIC_IRQChannel = SPI1_IRQn; 
     NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
     NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
     NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
     NVIC_Init( &NVIC_InitStructure );
     SPI_I2S_ITConfig(SPI1,SPI_I2S_IT_RXNE, ENABLE);      // enable RXNE interrup
    
}
uint8_t spi1_recive[500],cky = 0;
void SPI1_IRQHandler(void)
 {
   if (SPI_I2S_GetITStatus(SPI1, SPI_I2S_IT_RXNE) != RESET)
   { 
      spi1_recive[cky] =  SPI1->DR;
      cky++;
   }
 }

void SPI2_Config()
{
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB ,ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI2 ,ENABLE);
 
    GPIO_InitTypeDef   GPIO_InitStructure;
    
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;
    GPIO_Init(GPIOB,&GPIO_InitStructure);
   
    GPIO_PinAFConfig(GPIOB, GPIO_PinSource13, GPIO_AF_SPI2);    
    GPIO_PinAFConfig(GPIOB, GPIO_PinSource14, GPIO_AF_SPI2);
    GPIO_PinAFConfig(GPIOB, GPIO_PinSource15, GPIO_AF_SPI2);    
    
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
    GPIO_Init(GPIOB,&GPIO_InitStructure);
    
    SPI_InitTypeDef SPI_InitStructure;
    SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
    SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_4;
    SPI_InitStructure.SPI_CPHA = SPI_CPHA_2Edge;
    SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;
    SPI_InitStructure.SPI_DataSize = SPI_DataSize_16b;
    SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
    SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
    SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;
    SPI_InitStructure.SPI_CRCPolynomial = 0;
    SPI_Init(SPI2, &SPI_InitStructure);
    
    SPI_SSOutputCmd(SPI2, ENABLE);
    
     NVIC_InitTypeDef   NVIC_InitStructure;
     NVIC_InitStructure.NVIC_IRQChannel = SPI2_IRQn; 
     NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
     NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
     NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
     NVIC_Init( &NVIC_InitStructure );      // enable RXNE interrup   
     SPI_I2S_ITConfig(SPI2,SPI_I2S_IT_TXE, ENABLE);      // enable RXNE interrup   
     
     SPI_Cmd(SPI2, ENABLE);
}

uint8_t cnt;

void SPI2_IRQHandler(void)
 {
   if (SPI_I2S_GetITStatus(SPI2, SPI_I2S_IT_TXE) != RESET)
   {    
          while(SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_BSY));
          SS_H();
          cnt++;
          SS_L();  
          SPI2->DR = (DAC_value[cnt]|0x3000); 
   }
 }

void SS_H(){
     GPIO_SetBits(GPIOB, GPIO_Pin_12);
}

void SS_L(){
    GPIO_ResetBits(GPIOB, GPIO_Pin_12);
}
