#include "stdio.h"
#include "math.h"
#include "stdint.h"

uint8_t value, cnt_buff, buff[10];
uint32_t data;

void get_data(char* Rx_data){
	if(47 < Rx_data[0] && Rx_data[0] < 58){
	   value = Rx_data[0] - 48;
	   buff[cnt_buff] = value;
	   cnt_buff++;
	}
	else if(96 < Rx_data[0] && Rx_data[0] < 103){
	   value = Rx_data[0] - 87;
	   buff[cnt_buff] = value;
	   cnt_buff++;
	}
	else if( Rx_data[0] == ','){
	   for(uint8_t i = 0 ; i < cnt_buff; i++){
	   data  |= (buff[cnt_buff-1-i]<<(4*i));
       }
	   //write data i flash
	   printf("%x \n",data);
	}
	else if( Rx_data[0] == 'x'){
	   cnt_buff = 0;
	   data = 0;
	   for(uint8_t i=0; i<10;i++)
	       buff[i] = 0;
	}
	else 
		value = 0;		
}

int main(){
	
	char dx[100] = {'0','x','2','0','0','0','0','a','1','0',',',' ',
	                '0','x','2','0','0','0','0','4','f','6',',',' ',
					'0','x','0',',',' '};
					
		
					
					
	for(int i = 0; i< 35; i++ )
          get_data(&dx[i]);
    
	while(1);
	return 0;
}
