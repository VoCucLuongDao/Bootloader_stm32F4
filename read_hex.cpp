/*
	* Tool phan tich data tu file hex
	* La ban nhap duoc viet cho vui nen chua duoc toi uu va chuan hoa
	* Nen tu viet lai can than khi nhung vao software
*/
#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "math.h"

char line[50]; // noi chua a line of file hex when it is read . no tao thanh 1 mang ki tu

struct Analysis_Hex    // cau truc cua mot line trong file hex
{
	uint8_t byte_count;  //1 byte
	uint16_t adress;     //2 byte
	uint8_t record_type; //1 byte
	uint32_t data[4];    //4*4 byte 
	uint8_t checksum;     //1 byte
};
typedef Analysis_Hex analysis_hex;

// tao 1 doi tuong chua cac thanh phan nhu struct Analysis_Hex sau khi phan tich mot line
analysis_hex *an_hex = (analysis_hex*) malloc(500*sizeof(analysis_hex));  x

uint8_t hex_number_to_int(char c){
	switch (c)
	{
		case '0': 
				return 0;
		case '1':
				return 1;
		case '2':
				return 2;
		case '3':
				return 3;
		case '4':
				return 4;
		case '5':
				return 5;
		case '6':
				return 6;
		case '7':
				return 7;
		case '8':
				return 8;
		case '9':
				return 9;
		case 'A':
				return 10;
		case 'B':
				return 11;
		case 'C':
				return 12;
		case 'D':
				return 13;
		case 'E':
				return 14;
		case 'F':
				return 15;
	}
	return 0;
}

int cont_an_hex = 0;

int main()
{
	FILE *file = fopen("blink.hex","r");
	
	if(fopen == NULL) 
	       printf("ERROR");
	else{
		
		int so_data = 0; // 2*byte_count data trong line                  
		cont_an_hex = 0; // dong cua file hex dang duoc doc
		
		while (!feof(file)){
			fgets(line,50*sizeof(char),file);  // read a line from file hex
			printf(" %s ", line);
			
			// ki tu 0/ duoc bo qua
			// ki tu 1/2/ la byte_count
			// ki tu 3/4/5/6/ la dia chi
			// ki tu 7/8/ la record_type
			// 2 ki tu cuoi la chek sum
			// ki tu con lai la data
			an_hex[cont_an_hex].byte_count = hex_number_to_int(line[1])*16 + hex_number_to_int(line[2]);
			an_hex[cont_an_hex].adress = hex_number_to_int(line[3])*pow(16,3) + hex_number_to_int(line[4])*pow(16,2) 
			                             +hex_number_to_int(line[5])*16 + hex_number_to_int(line[6]);
			an_hex[cont_an_hex].record_type =  hex_number_to_int(line[7])*16 + hex_number_to_int(line[8]);
			
		    so_data = 2*an_hex[cont_an_hex].byte_count;
		    
			an_hex[cont_an_hex].checksum =  hex_number_to_int(line[ 9 +so_data])*16 + hex_number_to_int(line[ 10 + so_data]);
			
			if(so_data > 0){
               int t_data[50]; // temp value of data thuo type int
               for(int i = 0; i < 50; i += 1){
			        if(i < so_data)
               	  		t_data[i] = hex_number_to_int(line[ 9 + i]); /* lay data bat dau tu ki tu 9/.../24/ */
               	  	else 
               	  	    t_data[i] = 0;
			   }
			    /* Mac dinh hex file STM32 phan data (00) se co 4 byte */
			    /* Ghep 4 byte thanh 1 so 32 bit. Tuong tu 4*4 byte */
			    /* Vi du '0','1','2','3' = 0x2301 */
				for(int j = 0; j < 4; j += 1){
			   		an_hex[cont_an_hex].data[j] = 0;
	                an_hex[cont_an_hex].data[j] += (t_data[8*j+0]*16 + t_data[8*j+1])*pow(16,0);
	                an_hex[cont_an_hex].data[j] += (t_data[8*j+2]*16 + t_data[8*j+3])*pow(16,2);
	                an_hex[cont_an_hex].data[j] += (t_data[8*j+4]*16 + t_data[8*j+5])*pow(16,4);
	                an_hex[cont_an_hex].data[j] += (t_data[8*j+6]*16 + t_data[8*j+7])*pow(16,6);
	            }
	        }
			cont_an_hex++;
		}
		
	}
	fclose(file);

    FILE* file_w = fopen("hex_blink.txt", "w");
    if(file_w == NULL)
     	printf("ERROR");
     	
    int number_line = 0; 
		
    fprintf(file_w, "{ \n");
    
    for(int i = 0; i < cont_an_hex; i++){
    	if(an_hex[i].record_type == 0)
    	{
		
    		fprintf(file_w, "0x%x, 0x%x, 0x%x, 0x%x,\n  ", an_hex[i].data[0], an_hex[i].data[1],
		                                          an_hex[i].data[2], an_hex[i].data[3]);
		    number_line++;
		}
	}
	
	fprintf(file_w, "}; \n");
	
	printf( "\n so phan tu mang: %d", number_line*4);	
	fprintf(file_w, "\n so phan tu mang: %d", number_line*4);	
    fclose(file_w);  
    
	return 0;
}
