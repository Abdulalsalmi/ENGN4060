#include <stdio.h>
#include "system.h"
#include "alt_types.h"
#include "altera_avalon_pio_regs.h"
#include "altera_up_avalon_video_pixel_buffer_dma.h"
#include "altera_up_avalon_rs232.h"
#include <unistd.h>

unsigned char __attribute__ ((section (".bss"))) ICON00 [32*32];
unsigned char __attribute__ ((section (".bss"))) ICON01 [32*32];
unsigned char __attribute__ ((section (".bss"))) ICON02 [32*32];
unsigned char __attribute__ ((section (".bss"))) ICON03 [32*32];
unsigned char __attribute__ ((section (".bss"))) ICON04 [32*32];
unsigned char __attribute__ ((section (".bss"))) ICON05 [32*32];
unsigned char __attribute__ ((section (".bss"))) ICON06 [32*32];
unsigned char __attribute__ ((section (".bss"))) ICON07 [32*32];
unsigned char __attribute__ ((section (".bss"))) ICON08 [32*32];
unsigned char __attribute__ ((section (".bss"))) ICON09 [32*32];
unsigned char __attribute__ ((section (".bss"))) ZERO [24*16];
unsigned char __attribute__ ((section (".bss"))) ONE [24*16];
unsigned char __attribute__ ((section (".bss"))) TWO [24*16];
unsigned char __attribute__ ((section (".bss"))) THREE [24*16];
unsigned char __attribute__ ((section (".bss"))) FOUR [24*16];
unsigned char __attribute__ ((section (".bss"))) FIVE [24*16];
unsigned char __attribute__ ((section (".bss"))) SIX [24*16];
unsigned char __attribute__ ((section (".bss"))) SEVEN [24*16];
unsigned char __attribute__ ((section (".bss"))) EIGHT [24*16];
unsigned char __attribute__ ((section (".bss"))) NINE [24*16];
unsigned char __attribute__ ((section (".bss"))) ALPHA [24*16];
unsigned char __attribute__ ((section (".bss"))) BRAVO [24*16];
unsigned char __attribute__ ((section (".bss"))) CHARLIE [24*16];
unsigned char __attribute__ ((section (".bss"))) DELTA [24*16];
unsigned char __attribute__ ((section (".bss"))) ECHO [24*16];
unsigned char __attribute__ ((section (".bss"))) FOXTROT [24*16];
unsigned char __attribute__ ((section (".bss"))) GOLF [24*16];
unsigned char __attribute__ ((section (".bss"))) HOTEL [24*16];
unsigned char __attribute__ ((section (".bss"))) INDIA [24*16];
unsigned char __attribute__ ((section (".bss"))) JULIETT [24*16];
unsigned char __attribute__ ((section (".bss"))) KILO [24*16];
unsigned char __attribute__ ((section (".bss"))) LIMA [24*16];
unsigned char __attribute__ ((section (".bss"))) MIKE [24*16];
unsigned char __attribute__ ((section (".bss"))) NOVEMBER [24*16];
unsigned char __attribute__ ((section (".bss"))) OSCAR [24*16];
unsigned char __attribute__ ((section (".bss"))) PAPA [24*16];
unsigned char __attribute__ ((section (".bss"))) QUEBEC [24*16];
unsigned char __attribute__ ((section (".bss"))) ROMEO [24*16];
unsigned char __attribute__ ((section (".bss"))) SIERRA [24*16];
unsigned char __attribute__ ((section (".bss"))) TANGO [24*16];
unsigned char __attribute__ ((section (".bss"))) UNIFORM [24*16];
unsigned char __attribute__ ((section (".bss"))) VICTOR [24*16];
unsigned char __attribute__ ((section (".bss"))) WHISKEY [24*16];
unsigned char __attribute__ ((section (".bss"))) XRAY [24*16];
unsigned char __attribute__ ((section (".bss"))) YANKEE [24*16];
unsigned char __attribute__ ((section (".bss"))) ZULU [24*16];
#define  UART_OK             0
#define  UART_ERROR         -1
#define  UART_DATA_COUNT     1

void Delay_Medium   () {volatile int d = 0; for (d = 0; d <  10000; d++) {}}
void Delay_short   () {volatile int d = 0; for (d = 0; d <  2500; d++) {}}

int main ()
{

	alt_up_pixel_buffer_dma_dev* hPB = NULL;
		    	        hPB = alt_up_pixel_buffer_dma_open_dev (VGA_PIXEL_DMA_NAME);
		    	        if (hPB == NULL)
		    	        {

		    	            while (1);
		    	        }
		    		else {
		    			alt_up_pixel_buffer_dma_clear_screen (hPB, 0);
		    			alt_up_pixel_buffer_dma_clear_screen (hPB, 1);
		    		}

	int x,y;
	int count = 0;
	unsigned int temp;
	for(int i = 0x0; i<= 0x5E00; i+=4){ // 0x5E00
	temp = *((volatile unsigned int*) (OC_FLASH_DATA_SECTOR1_START_ADDR + i));
	if(i<1024){
		ICON00[count]=temp>>24 ;
		ICON00[count+1]= ((temp>>(17-1))&((1<<8)-1));
		ICON00[count+2]= ((temp>>(9-1))&((1<<8)-1));
		ICON00[count+3]= ((temp>>(1-1))&((1<<8)-1)); ;
		count = count+4;
		 }
	 if(i==1024){
		 count=0;
	 }
	if(i>=1024&& i < 2048){
		ICON01[count]=temp>>24 ;
		ICON01[count+1]= ((temp>>(17-1))&((1<<8)-1));
		ICON01[count+2]= ((temp>>(9-1))&((1<<8)-1));
		ICON01[count+3]= ((temp>>(1-1))&((1<<8)-1)); ;
		count = count+4;
			}
	if(i==2048){
		count=0;
		}
	if(i>=2048&& i < 3072){
		ICON02[count]=temp>>24 ;
		ICON02[count+1]= ((temp>>(17-1))&((1<<8)-1));
		ICON02[count+2]= ((temp>>(9-1))&((1<<8)-1));
		ICON02[count+3]= ((temp>>(1-1))&((1<<8)-1)); ;
		count = count+4;
		}
	if(i==3072){
		count=0;
		 }
	if(i>=3072&& i < 4096){
		ICON03[count]=temp>>24 ;
		ICON03[count+1]= ((temp>>(17-1))&((1<<8)-1));
		ICON03[count+2]= ((temp>>(9-1))&((1<<8)-1));
		ICON03[count+3]= ((temp>>(1-1))&((1<<8)-1)); ;
		count = count+4;
				}
	if(i==4096){
		count=0;
			}
	if(i>=4096&& i < 5120){
		ICON04[count]=temp>>24 ;
		ICON04[count+1]= ((temp>>(17-1))&((1<<8)-1));
		ICON04[count+2]= ((temp>>(9-1))&((1<<8)-1));
		ICON04[count+3]= ((temp>>(1-1))&((1<<8)-1)); ;
		count = count+4;
				 }
	if(i==5120){
		count=0;
			 }
	if(i>=5120&& i < 6144){
		ICON05[count]=temp>>24 ;
		ICON05[count+1]= ((temp>>(17-1))&((1<<8)-1));
		ICON05[count+2]= ((temp>>(9-1))&((1<<8)-1));
		ICON05[count+3]= ((temp>>(1-1))&((1<<8)-1)); ;
		count = count+4;
					}
	if(i==6144){
		count=0;
				}
	if(i>=6144&& i < 7168){
		ICON06[count]=temp>>24 ;
		ICON06[count+1]= ((temp>>(17-1))&((1<<8)-1));
		ICON06[count+2]= ((temp>>(9-1))&((1<<8)-1));
		ICON06[count+3]= ((temp>>(1-1))&((1<<8)-1)); ;
		count = count+4;
					}
	if(i==7168){
		 count=0;
				 }
	if(i>=7168&& i < 8192){
		ICON07[count]=temp>>24 ;
		ICON07[count+1]= ((temp>>(17-1))&((1<<8)-1));
		ICON07[count+2]= ((temp>>(9-1))&((1<<8)-1));
		ICON07[count+3]= ((temp>>(1-1))&((1<<8)-1)); ;
		count = count+4;
					}
	if(i==8192){
		count=0;
				}
	if(i>=8192&& i < 9216){
		ICON08[count]=temp>>24 ;
		ICON08[count+1]= ((temp>>(17-1))&((1<<8)-1));
		ICON08[count+2]= ((temp>>(9-1))&((1<<8)-1));
		ICON08[count+3]= ((temp>>(1-1))&((1<<8)-1)); ;
		count = count+4;
					}
	if(i==9216){
		count=0;
				}
	if(i>=9216&& i < 10240){
		ICON09[count]=temp>>24 ;
		ICON09[count+1]= ((temp>>(17-1))&((1<<8)-1));
		ICON09[count+2]= ((temp>>(9-1))&((1<<8)-1));
		ICON09[count+3]= ((temp>>(1-1))&((1<<8)-1)); ;
		count = count+4;
					}
	if(i==10240){
		count=0;
				}
	if(i>=10240&& i < 10624){
		ZERO[count]=temp>>24 ;
		ZERO[count+1]= ((temp>>(17-1))&((1<<8)-1));
		ZERO[count+2]= ((temp>>(9-1))&((1<<8)-1));
		ZERO[count+3]= ((temp>>(1-1))&((1<<8)-1)); ;
		count = count+4;
					}
	if(i==10624){
		count=0;
				}
	if(i>=10624&& i < 11008){
		ONE[count]=temp>>24 ;
		ONE[count+1]= ((temp>>(17-1))&((1<<8)-1));
		ONE[count+2]= ((temp>>(9-1))&((1<<8)-1));
		ONE[count+3]= ((temp>>(1-1))&((1<<8)-1)); ;
		count = count+4;
					}
	if(i==11008){
		count=0;
				}
	if(i>=11008&& i < 11392){
		TWO[count]=temp>>24 ;
		TWO[count+1]= ((temp>>(17-1))&((1<<8)-1));
		TWO[count+2]= ((temp>>(9-1))&((1<<8)-1));
		TWO[count+3]= ((temp>>(1-1))&((1<<8)-1)); ;
		count = count+4;
					}
	if(i==11392){
		count=0;
				}
	if(i>=11392&& i < 11776){
		THREE[count]=temp>>24 ;
		THREE[count+1]= ((temp>>(17-1))&((1<<8)-1));
		THREE[count+2]= ((temp>>(9-1))&((1<<8)-1));
		THREE[count+3]= ((temp>>(1-1))&((1<<8)-1)); ;
		count = count+4;
					}
	if(i==11776){
		count=0;
				}
	if(i>=11776&& i < 12160){
		FOUR[count]=temp>>24 ;
		FOUR[count+1]= ((temp>>(17-1))&((1<<8)-1));
		FOUR[count+2]= ((temp>>(9-1))&((1<<8)-1));
		FOUR[count+3]= ((temp>>(1-1))&((1<<8)-1)); ;
		count = count+4;
					}
	if(i==12160){
		count=0;
				}
	if(i>=12160&& i < 12544){
		FIVE[count]=temp>>24 ;
		FIVE[count+1]= ((temp>>(17-1))&((1<<8)-1));
		FIVE[count+2]= ((temp>>(9-1))&((1<<8)-1));
		FIVE[count+3]= ((temp>>(1-1))&((1<<8)-1)); ;
		count = count+4;
					}
	if(i==12544){
		count=0;
				}
	if(i>=12544&& i < 12928){
		SIX[count]=temp>>24 ;
		SIX[count+1]= ((temp>>(17-1))&((1<<8)-1));
		SIX[count+2]= ((temp>>(9-1))&((1<<8)-1));
		SIX[count+3]= ((temp>>(1-1))&((1<<8)-1)); ;
		count = count+4;
					}
	if(i==12928){
		count=0;
				}
	if(i>=12928&& i < 13312){
		SEVEN[count]=temp>>24 ;
		SEVEN[count+1]= ((temp>>(17-1))&((1<<8)-1));
		SEVEN[count+2]= ((temp>>(9-1))&((1<<8)-1));
		SEVEN[count+3]= ((temp>>(1-1))&((1<<8)-1)); ;
		count = count+4;
					}
	if(i==13312){
		count=0;
				}
	if(i>=13312&& i < 13696){
		EIGHT[count]=temp>>24 ;
		EIGHT[count+1]= ((temp>>(17-1))&((1<<8)-1));
		EIGHT[count+2]= ((temp>>(9-1))&((1<<8)-1));
		EIGHT[count+3]= ((temp>>(1-1))&((1<<8)-1)); ;
		count = count+4;
					}
	if(i==13696){
		count=0;
				}
	if(i>=13696&& i < 14080){
		NINE[count]=temp>>24 ;
		NINE[count+1]= ((temp>>(17-1))&((1<<8)-1));
		NINE[count+2]= ((temp>>(9-1))&((1<<8)-1));
		NINE[count+3]= ((temp>>(1-1))&((1<<8)-1)); ;
		count = count+4;
					}
	if(i==14080){
		count=0;
				}
	if(i>=14080&& i < 14464){
		ALPHA[count]=temp>>24 ;
		ALPHA[count+1]= ((temp>>(17-1))&((1<<8)-1));
		ALPHA[count+2]= ((temp>>(9-1))&((1<<8)-1));
		ALPHA[count+3]= ((temp>>(1-1))&((1<<8)-1)); ;
		count = count+4;
					}
	if(i==14464){
		count=0;
				}
	if(i>=14464&& i < 14848){
		BRAVO[count]=temp>>24 ;
		BRAVO[count+1]= ((temp>>(17-1))&((1<<8)-1));
		BRAVO[count+2]= ((temp>>(9-1))&((1<<8)-1));
		BRAVO[count+3]= ((temp>>(1-1))&((1<<8)-1)); ;
		count = count+4;
					}
	if(i==14848){
		count=0;
				}
	if(i>=14848&& i < 15232){
		CHARLIE[count]=temp>>24 ;
		CHARLIE[count+1]= ((temp>>(17-1))&((1<<8)-1));
		CHARLIE[count+2]= ((temp>>(9-1))&((1<<8)-1));
		CHARLIE[count+3]= ((temp>>(1-1))&((1<<8)-1)); ;
		count = count+4;
					}
	if(i==15232){
		count=0;
				}
	if(i>=15232&& i < 15616){
		DELTA[count]=temp>>24 ;
		DELTA[count+1]= ((temp>>(17-1))&((1<<8)-1));
		DELTA[count+2]= ((temp>>(9-1))&((1<<8)-1));
		DELTA[count+3]= ((temp>>(1-1))&((1<<8)-1)); ;
		count = count+4;
					}
	if(i==15616){
		count=0;
				}
	if(i>=15616&& i < 16000){
		ECHO[count]=temp>>24 ;
		ECHO[count+1]= ((temp>>(17-1))&((1<<8)-1));
		ECHO[count+2]= ((temp>>(9-1))&((1<<8)-1));
		ECHO[count+3]= ((temp>>(1-1))&((1<<8)-1)); ;
		count = count+4;
					}
	if(i==16000){
		count=0;
				}
	if(i>=16000&& i < 16384){
		FOXTROT[count]=temp>>24 ;
		FOXTROT[count+1]= ((temp>>(17-1))&((1<<8)-1));
		FOXTROT[count+2]= ((temp>>(9-1))&((1<<8)-1));
		FOXTROT[count+3]= ((temp>>(1-1))&((1<<8)-1)); ;
		count = count+4;
					}
	if(i==16384){
		count=0;
				}
	if(i>=16384&& i < 16768){
		GOLF[count]=temp>>24 ;
		GOLF[count+1]= ((temp>>(17-1))&((1<<8)-1));
		GOLF[count+2]= ((temp>>(9-1))&((1<<8)-1));
		GOLF[count+3]= ((temp>>(1-1))&((1<<8)-1)); ;
		count = count+4;
					}
	if(i==16768){
		count=0;
				}
	if(i>=16768&& i < 17152){
		HOTEL[count]=temp>>24 ;
		HOTEL[count+1]= ((temp>>(17-1))&((1<<8)-1));
		HOTEL[count+2]= ((temp>>(9-1))&((1<<8)-1));
		HOTEL[count+3]= ((temp>>(1-1))&((1<<8)-1)); ;
		count = count+4;
					}
	if(i==17152){
		count=0;
				}
	if(i>=17152&& i < 17536){
		INDIA[count]=temp>>24 ;
		INDIA[count+1]= ((temp>>(17-1))&((1<<8)-1));
		INDIA[count+2]= ((temp>>(9-1))&((1<<8)-1));
		INDIA[count+3]= ((temp>>(1-1))&((1<<8)-1)); ;
		count = count+4;
					}
	if(i==17536){
		count=0;
				}
	if(i>=17536&& i < 17920){
		JULIETT[count]=temp>>24 ;
		JULIETT[count+1]= ((temp>>(17-1))&((1<<8)-1));
		JULIETT[count+2]= ((temp>>(9-1))&((1<<8)-1));
		JULIETT[count+3]= ((temp>>(1-1))&((1<<8)-1)); ;
		count = count+4;
					}
	if(i==17920){
		count=0;
				}
	if(i>=17920&& i < 18304){
		KILO[count]=temp>>24 ;
		KILO[count+1]= ((temp>>(17-1))&((1<<8)-1));
		KILO[count+2]= ((temp>>(9-1))&((1<<8)-1));
		KILO[count+3]= ((temp>>(1-1))&((1<<8)-1)); ;
		count = count+4;
					}
	if(i==18304){
		count=0;
				}
	if(i>=18304&& i < 18688){
		LIMA[count]=temp>>24 ;
		LIMA[count+1]= ((temp>>(17-1))&((1<<8)-1));
		LIMA[count+2]= ((temp>>(9-1))&((1<<8)-1));
		LIMA[count+3]= ((temp>>(1-1))&((1<<8)-1)); ;
		count = count+4;
					}
	if(i==18688){
		count=0;
				}
	if(i>=18688&& i < 19072){
		MIKE[count]=temp>>24 ;
		MIKE[count+1]= ((temp>>(17-1))&((1<<8)-1));
		MIKE[count+2]= ((temp>>(9-1))&((1<<8)-1));
		MIKE[count+3]= ((temp>>(1-1))&((1<<8)-1)); ;
		count = count+4;
					}
	if(i==19072){
		count=0;
				}
	if(i>=19072&& i < 19456){
		NOVEMBER[count]=temp>>24 ;
		NOVEMBER[count+1]= ((temp>>(17-1))&((1<<8)-1));
		NOVEMBER[count+2]= ((temp>>(9-1))&((1<<8)-1));
		NOVEMBER[count+3]= ((temp>>(1-1))&((1<<8)-1)); ;
		count = count+4;
					}
	if(i==19456){
		count=0;
				}
	if(i>=19456&& i < 19840){
		OSCAR[count]=temp>>24 ;
		OSCAR[count+1]= ((temp>>(17-1))&((1<<8)-1));
		OSCAR[count+2]= ((temp>>(9-1))&((1<<8)-1));
		OSCAR[count+3]= ((temp>>(1-1))&((1<<8)-1)); ;
		count = count+4;
					}
	if(i==19840){
		count=0;
				}
	if(i>=19840&& i < 20224){
		PAPA[count]=temp>>24 ;
		PAPA[count+1]= ((temp>>(17-1))&((1<<8)-1));
		PAPA[count+2]= ((temp>>(9-1))&((1<<8)-1));
		PAPA[count+3]= ((temp>>(1-1))&((1<<8)-1)); ;
		count = count+4;
					}
	if(i==20224){
		count=0;
				}
	if(i>=20224&& i < 20608){
		QUEBEC[count]=temp>>24 ;
		QUEBEC[count+1]= ((temp>>(17-1))&((1<<8)-1));
		QUEBEC[count+2]= ((temp>>(9-1))&((1<<8)-1));
		QUEBEC[count+3]= ((temp>>(1-1))&((1<<8)-1)); ;
		count = count+4;
					}
	if(i==20608){
		count=0;
				}
	if(i>=20608&& i < 20992){
		ROMEO[count]=temp>>24 ;
		ROMEO[count+1]= ((temp>>(17-1))&((1<<8)-1));
		ROMEO[count+2]= ((temp>>(9-1))&((1<<8)-1));
		ROMEO[count+3]= ((temp>>(1-1))&((1<<8)-1)); ;
		count = count+4;
					}
	if(i==20992){
		count=0;
				}
	if(i>=20992&& i < 21376){
		SIERRA[count]=temp>>24 ;
		SIERRA[count+1]= ((temp>>(17-1))&((1<<8)-1));
		SIERRA[count+2]= ((temp>>(9-1))&((1<<8)-1));
		SIERRA[count+3]= ((temp>>(1-1))&((1<<8)-1)); ;
		count = count+4;
					}
	if(i==21376){
		count=0;
				}
	if(i>=21376&& i < 21760){
		TANGO[count]=temp>>24 ;
		TANGO[count+1]= ((temp>>(17-1))&((1<<8)-1));
		TANGO[count+2]= ((temp>>(9-1))&((1<<8)-1));
		TANGO[count+3]= ((temp>>(1-1))&((1<<8)-1)); ;
		count = count+4;
					}
	if(i==21760){
		count=0;
				}
	if(i>=21760&& i < 22144){
		UNIFORM[count]=temp>>24 ;
		UNIFORM[count+1]= ((temp>>(17-1))&((1<<8)-1));
		UNIFORM[count+2]= ((temp>>(9-1))&((1<<8)-1));
		UNIFORM[count+3]= ((temp>>(1-1))&((1<<8)-1)); ;
		count = count+4;
					}
	if(i==22144){
		count=0;
				}
	if(i>=22144&& i < 22528){
		VICTOR[count]=temp>>24 ;
		VICTOR[count+1]= ((temp>>(17-1))&((1<<8)-1));
		VICTOR[count+2]= ((temp>>(9-1))&((1<<8)-1));
		VICTOR[count+3]= ((temp>>(1-1))&((1<<8)-1)); ;
		count = count+4;
					}
	if(i==22528){
		count=0;
				}
	if(i>=22528&& i < 22912){
		WHISKEY[count]=temp>>24 ;
		WHISKEY[count+1]= ((temp>>(17-1))&((1<<8)-1));
		WHISKEY[count+2]= ((temp>>(9-1))&((1<<8)-1));
		WHISKEY[count+3]= ((temp>>(1-1))&((1<<8)-1)); ;
		count = count+4;
					}
	if(i==22912){
		count=0;
				}
	if(i>=22912&& i < 23296){
		XRAY[count]=temp>>24 ;
		XRAY[count+1]= ((temp>>(17-1))&((1<<8)-1));
		XRAY[count+2]= ((temp>>(9-1))&((1<<8)-1));
		XRAY[count+3]= ((temp>>(1-1))&((1<<8)-1)); ;
		count = count+4;
					}
	if(i==23296){
		count=0;
				}
	if(i>=23296&& i < 23680){
		YANKEE[count]=temp>>24 ;
		YANKEE[count+1]= ((temp>>(17-1))&((1<<8)-1));
		YANKEE[count+2]= ((temp>>(9-1))&((1<<8)-1));
		YANKEE[count+3]= ((temp>>(1-1))&((1<<8)-1)); ;
		count = count+4;
					}
	if(i==23680){
		count=0;
				}
	if(i>=23680){
		ZULU[count]=temp>>24 ;
		ZULU[count+1]= ((temp>>(17-1))&((1<<8)-1));
		ZULU[count+2]= ((temp>>(9-1))&((1<<8)-1));
		ZULU[count+3]= ((temp>>(1-1))&((1<<8)-1)); ;
		count = count+4;
					}

	}
	count =0;
	int ii = 0;

	  int row = 1;
	  int column = 0;

	  int x_pos=2;
	  int y_pos=2;
	  int xtemp=2;
	  int ytemp=2;
	  int counter=0;
	  char select [6][6]= {
			  	  {0,0,0,0,0,0},
				  {0,0,0,0,0,0},
				  {0,0,0,0,0,0},
				  {0,0,0,0,0,0},
				  {0,0,0,0,0,0},
				  {0,0,0,0,0,0},
	  };
	  int    UART_ER = ~UART_OK;
	  alt_u8 UART_PE = 0;
	  unsigned int UART_FL_RD = 10000;
	  unsigned int UART_FL_WR = 20000;

	  alt_u8 UART_BYTE = 0;
	  alt_u8 UART_RD_08 [UART_DATA_COUNT];
	  alt_u8 UART_WR_08 [UART_DATA_COUNT];


	  hPB = alt_up_pixel_buffer_dma_open_dev (VGA_PIXEL_DMA_NAME);
	  alt_up_pixel_buffer_dma_clear_screen (hPB, 0);
	  alt_up_pixel_buffer_dma_clear_screen (hPB, 1);
		for (x = 0; x < 24; x++) {
			for (y = 0; y < 16; y++) {


										alt_up_pixel_buffer_dma_draw(hPB, ECHO[count],
												(y + 6 * 16), (x + 0 * 24));
										alt_up_pixel_buffer_dma_draw(hPB, NOVEMBER[count],
												(y + 7 * 16), (x + 0 * 24));
										alt_up_pixel_buffer_dma_draw(hPB, GOLF[count],
												(y + 8 * 16), (x + 0 * 24));
										alt_up_pixel_buffer_dma_draw(hPB, NOVEMBER[count],
												(y + 9 * 16), (x + 0 * 24));
										alt_up_pixel_buffer_dma_draw(hPB, FOUR[count],
												(y + 10 * 16), (x + 0 * 24));
										alt_up_pixel_buffer_dma_draw(hPB, ZERO[count],
												(y + 11 * 16), (x + 0 * 24));
										alt_up_pixel_buffer_dma_draw(hPB, SIX[count],
												(y + 12 * 16), (x + 0 * 24));
										alt_up_pixel_buffer_dma_draw(hPB, ZERO[count],
												(y + 13 * 16), (x + 0 * 24));
										alt_up_pixel_buffer_dma_draw(hPB, SIERRA[count],
												(y + 14 * 16), (x + 3 * 24));
										alt_up_pixel_buffer_dma_draw(hPB, CHARLIE[count],
												(y + 15 * 16), (x + 3 * 24));
										alt_up_pixel_buffer_dma_draw(hPB, OSCAR[count],
												(y + 16 * 16), (x + 3 * 24));
										alt_up_pixel_buffer_dma_draw(hPB, ROMEO[count],
												(y + 17 * 16), (x + 3 * 24));
										alt_up_pixel_buffer_dma_draw(hPB, ECHO[count],
												(y + 18 * 16), (x + 3 * 24));

										alt_up_pixel_buffer_dma_draw(hPB, ZERO[count],
												(y + 14 * 16)+8, (x + 4 * 24));
										alt_up_pixel_buffer_dma_draw(hPB, ZERO[count],
												(y + 15 * 16)+8, (x + 4 * 24));
										alt_up_pixel_buffer_dma_draw(hPB, ZERO[count],
												(y + 16 * 16)+8, (x + 4 * 24));
										alt_up_pixel_buffer_dma_draw(hPB, ZERO[count],
												(y + 17 * 16)+8, (x + 4 * 24));
										alt_up_pixel_buffer_dma_draw(hPB, ROMEO[count],
												(y + 14 * 16), (x + 7 * 24));
										alt_up_pixel_buffer_dma_draw(hPB, OSCAR[count],
												(y + 15 * 16), (x + 7 * 24));
										alt_up_pixel_buffer_dma_draw(hPB, UNIFORM[count],
												(y + 16 * 16), (x + 7 * 24));
										alt_up_pixel_buffer_dma_draw(hPB, NOVEMBER[count],
												(y + 17 * 16), (x + 7 * 24));
										alt_up_pixel_buffer_dma_draw(hPB, DELTA[count],
												(y + 18 * 16), (x + 7 * 24));

										alt_up_pixel_buffer_dma_draw(hPB, ZERO[count],
												(y + 14 * 16)+8, (x + 8 * 24));
										alt_up_pixel_buffer_dma_draw(hPB, ZERO[count],
												(y + 15 * 16)+8, (x + 8 * 24));
										alt_up_pixel_buffer_dma_draw(hPB, ZERO[count],
												(y + 16 * 16)+8, (x + 8 * 24));
										alt_up_pixel_buffer_dma_draw(hPB, ZERO[count],
												(y + 17 * 16)+8, (x + 8 * 24));

								count++;
							}

		}

	  for (ii = 0; ii < UART_DATA_COUNT; ii++)
	  {
	   UART_RD_08 [ii] = 0;
	   UART_WR_08 [ii] = 0;
	  }



	  alt_up_rs232_dev* hUART = alt_up_rs232_open_dev (ARDUINO_UART0_NAME);

	  if (hUART == NULL)
	  {


	   while (1);
	  }
	  else
	  {
	   UART_FL_RD = alt_up_rs232_get_used_space_in_read_FIFO (hUART);
	   UART_FL_WR = alt_up_rs232_get_available_space_in_write_FIFO (hUART);


	  }

	  while (1)
	  {
	   UART_FL_RD = alt_up_rs232_get_used_space_in_read_FIFO (hUART);
	   UART_FL_WR = alt_up_rs232_get_available_space_in_write_FIFO (hUART);
	   if (UART_FL_RD >= UART_DATA_COUNT)
	   {
		   counter=counter+1;


	    for (ii = 0; ii < UART_DATA_COUNT; ii++)
	    {
	     UART_ER = alt_up_rs232_read_data (hUART, &UART_BYTE, &UART_PE);
	     UART_RD_08 [ii] = UART_BYTE;
	    }



	    for (ii = 0; ii < UART_DATA_COUNT; ii++)
	    {

	     if ( counter==1 ){
	    	 UART_ER = alt_up_rs232_write_data (hUART, 0x64);

	    	 //IOWR_ALTERA_AVALON_PIO_DATA (HEX4_BASE, 0x04);
	    	 Delay_Medium ();



	     }
	     if ( counter>1 && counter < 38 ) {
	    	 if (column < 6 && row <7){
	    		 count = 0;
	    	 IOWR_ALTERA_AVALON_PIO_DATA (HEX3_BASE, 0x03);


	    			   						if (( UART_RD_08 [ii]== 48 ||UART_RD_08 [ii]== 0) ) {
	    			   							for (y = 0; y < 32; y++) {
	    			   							    for (x = 0; x < 32; x++) {
	    			   							    	alt_up_pixel_buffer_dma_draw(hPB, ICON00[count],
	    			   										(x + column * 32)+5, (y + row * 32)+15);
	    			   							    	count=count+1;
	    			   							    }
	    			   							}
	    			   						}
	    			   						if ((UART_RD_08 [ii] == 49||UART_RD_08 [ii]== 1) ) {
	    			   							for (y = 0; y < 32; y++) {
	    			   							    for (x = 0; x < 32; x++) {
	    			   							    	alt_up_pixel_buffer_dma_draw(hPB, ICON09[count],
	    			   										(x + column * 32)+5, (y + row * 32)+15);
	    			   							    	count=count+1;
	    			   							    }
	    			   							}
	    			   						}
	    			   						if ((UART_RD_08 [ii] == 50 || UART_RD_08 [ii]== 2)) {

	    			   							for (y = 0; y < 32; y++) {
	    			   							    for (x = 0; x < 32; x++) {
	    			   							    	alt_up_pixel_buffer_dma_draw(hPB, ICON04[count],
	    			   										(x + column * 32)+5, (y + row * 32)+15);
	    			   							    	count=count+1;
	    			   							    }
	    			   							}
	    			   						}
	    			   						if ((UART_RD_08 [ii]== 51 || UART_RD_08 [ii]== 3)) {
	    			   							for (y = 0; y < 32; y++) {
	    			   							    for (x = 0; x < 32; x++) {
	    			   							    	alt_up_pixel_buffer_dma_draw(hPB, ICON03[count],
	    			   										(x + column * 32)+5, (y + row * 32)+15);
	    			   							    	count=count+1;
	    			   							    }
	    			   							}
	    			   						}
	    			   						if (UART_RD_08 [ii] == 52|| UART_RD_08 [ii]== 4) {
	    			   							for (y = 0; y < 32; y++) {
	    			   							    for (x = 0; x < 32; x++) {
	    			   							    	alt_up_pixel_buffer_dma_draw(hPB, ICON04[count],
	    			   										(x + column * 32)+5, (y + row * 32)+15);
	    			   							    	count=count+1;
	    			   							    }
	    			   							}
	    			   						}
	    			   						if (UART_RD_08 [ii] == 53 || UART_RD_08 [ii]== 5) {
	    			   							for (y = 0; y < 32; y++) {
	    			   							    for (x = 0; x < 32; x++) {
	    			   							    	alt_up_pixel_buffer_dma_draw(hPB, ICON05[count],
	    			   										(x + column * 32)+5, (y + row * 32)+15);
	    			   							    	count=count+1;
	    			   							    }
	    			   							}
	    			   						}


	    			   						Delay_Medium ();
	    	 column++;
	    	 }
	    	 if(column == 6 && row <6){
	    		row++;
	    		column = 0;
	    		IOWR_ALTERA_AVALON_PIO_DATA (HEX1_BASE, 0x55);
	    	 }


	    	 }
	     if(counter == 38){

	         		x_pos = UART_RD_08 [ii]-'0' ;
	         		Delay_Medium ();
	         		row = x_pos;
	         	     }
	     if(counter == 39){
	              	IOWR_ALTERA_AVALON_PIO_DATA (HEX2_BASE, 0x55);
	              	 y_pos = UART_RD_08 [ii]-'0' ;
	              	 column = y_pos;
	              	 alt_up_pixel_buffer_dma_draw_vline(hPB, (x_pos*32)+5, (y_pos*32)+47, (y_pos*32)+78, 0xA3,0);
	              	 alt_up_pixel_buffer_dma_draw_vline(hPB, (x_pos*32)+36, (y_pos*32)+47, (y_pos*32)+78, 0xA3,0);

	              	 alt_up_pixel_buffer_dma_draw_hline(hPB, (x_pos*32)+5,(x_pos*32)+36, (y_pos*32)+47, 0xA3,0);
	              	 alt_up_pixel_buffer_dma_draw_hline(hPB, (x_pos*32)+5,(x_pos*32)+36, (y_pos*32)+78, 0xA3,0);

	              	 Delay_Medium ();
	                 if ( ((xtemp !=  x_pos) || (ytemp != y_pos)) ){
	               		IOWR_ALTERA_AVALON_PIO_DATA (HEX0_BASE, 0x55);
	               		alt_up_pixel_buffer_dma_draw_vline(hPB, (xtemp*32)+5, (ytemp*32)+47, (ytemp*32)+78, 0x00,0);
	               		alt_up_pixel_buffer_dma_draw_vline(hPB, (xtemp*32)+36, (ytemp*32)+47, (ytemp*32)+78, 0x00,0);
	               		alt_up_pixel_buffer_dma_draw_hline(hPB, (xtemp*32)+5,(xtemp*32)+36, (ytemp*32)+47, 0X00,0);
	               		alt_up_pixel_buffer_dma_draw_hline(hPB, (xtemp*32)+5,(xtemp*32)+36, (ytemp*32)+78, 0X00,0);
	               		//IOWR_ALTERA_AVALON_PIO_DATA (HEX5_BASE, 0x04);

	                	}

	                 Delay_Medium ();
	              	 }
	    if(counter == 40){
	              	IOWR_ALTERA_AVALON_PIO_DATA (HEX4_BASE, 0x55);

	              	if(UART_RD_08 [ii]==1 || UART_RD_08 [ii]==49){
	              		 select[row][column]=1;
	              		 IOWR_ALTERA_AVALON_PIO_DATA (HEX5_BASE, 0x55);
	              		 alt_up_pixel_buffer_dma_draw_box(hPB, (x_pos*32)+5,(y_pos*32)+47 , (x_pos*32)+36, (y_pos*32)+78, 0xFF,0);
	              		 Delay_Medium ();


	              		}
	              	for (row=0;row<6;row++){
	              		for(column=0;column<6;column++){
	              			if (select[row][column]==1){
	              				alt_up_pixel_buffer_dma_draw_vline(hPB, (row*32)+5, (column*32)+47, (column*32)+78, 0xFF,0);
	              				alt_up_pixel_buffer_dma_draw_vline(hPB, (row*32)+36, (column*32)+47, (column*32)+78, 0xFF,0);

	              				alt_up_pixel_buffer_dma_draw_hline(hPB, (row*32)+5,(row*32)+36, (column*32)+47, 0xFF,0);
	              				alt_up_pixel_buffer_dma_draw_hline(hPB, (row*32)+5,(row*32)+36, (column*32)+78, 0xFF,0);

	                 	Delay_Medium ();
	              	}
	              		}
	              	}


	              	 }


	    if(counter == 43){
			 UART_ER = alt_up_rs232_write_data (hUART, 0x72);
			 Delay_Medium ();
		     row=1;
		     column=0;
		     counter = 0;
	      	 xtemp = x_pos;
	         ytemp = y_pos;


	    }
	    }

	   UART_FL_RD = 0;
	   UART_FL_WR = 0;
	   }
	  }

 return 0;
}
