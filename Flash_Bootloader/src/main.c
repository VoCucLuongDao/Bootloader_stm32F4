#include "main.h" 

uint32_t PROGRAM_START_ADDRESS = FLASH_USER_START_ADDR; //tinh dia chi cua page
void Bootloader()
{   
          SysTick->CTRL = 0;
          SysTick->LOAD = 0;
          
          /* Clear Pending Interrupt Request, turn  off System Tick*/
           SCB->SHCSR &= ~( SCB_SHCSR_USGFAULTENA_Msk |\
                            SCB_SHCSR_BUSFAULTENA_Msk |\
                            SCB_SHCSR_MEMFAULTENA_Msk ) ;
          __disable_irq ();
          
           /* Set Main Stack Pointer*/
           __set_MSP(*((volatile uint32_t*) PROGRAM_START_ADDRESS));
          /* Set Program Counter to Blink LED Apptication Address*/
          void (*reset_handler)(void) = (void (*)(void))(*((volatile uint32_t *) (PROGRAM_START_ADDRESS + 4)));
          reset_handler();
          while(1);
}

void main()
{ 
        Flash_write();
        Bootloader();
       
        while(1);
        
}

