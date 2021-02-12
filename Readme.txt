1. separation data from file hex which you want bootloader
2. put it into a array and write into flash memory
3. Run bootloader

/**************** code blink led to get hex file **************************/

#include "main.h" 
void blink_led()
{
     RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
     GPIO_InitTypeDef GPIO_InitStructure;
     GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
     GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
     GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
     GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
     GPIO_Init(GPIOA, &GPIO_InitStructure);
}
int n = 16800000;
void main()
{ 
  SCB->VTOR = 0x08008000;
  __enable_irq ();
  blink_led();
  while(1){
      GPIO_ToggleBits(GPIOA, GPIO_Pin_0);
      delayms(1000);
  }
}
/***********************************************************************