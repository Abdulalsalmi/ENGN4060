#include "system.h"
#include "alt_types.h"
#include "altera_avalon_pio_regs.h"
#include "altera_up_avalon_video_pixel_buffer_dma.h"
#include "altera_up_avalon_rs232.h"
#include <unistd.h>

unsigned char __attribute__ ((section (".bss"))) ICON00 [32*32];
unsigned char __attribute__ ((section (".bss"))) ICON01 [32*32];
//unsigned char __attribute__ ((section (".bss"))) ICON02 [32*32];
//unsigned char __attribute__ ((section (".bss"))) ICON03 [32*32];
unsigned char __attribute__ ((section (".bss"))) ICON04 [32*32];
//unsigned char __attribute__ ((section (".bss"))) ICON05 [32*32];
unsigned char __attribute__ ((section (".bss"))) ICON06 [32*32];
//unsigned char __attribute__ ((section (".bss"))) ICON07 [32*32];
unsigned char __attribute__ ((section (".bss"))) ICON08 [32*32];
//unsigned char __attribute__ ((section (".bss"))) ICON09 [32*32];
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
//unsigned char __attribute__ ((section (".bss"))) BRAVO [24*16];
unsigned char __attribute__ ((section (".bss"))) CHARLIE [24*16];
unsigned char __attribute__ ((section (".bss"))) DELTA [24*16];
unsigned char __attribute__ ((section (".bss"))) ECHO [24*16];
//unsigned char __attribute__ ((section (".bss"))) FOXTROT [24*16];
unsigned char __attribute__ ((section (".bss"))) GOLF [24*16];
unsigned char __attribute__ ((section (".bss"))) HOTEL [24*16];
unsigned char __attribute__ ((section (".bss"))) INDIA [24*16];
//unsigned char __attribute__ ((section (".bss"))) JULIETT [24*16];
//unsigned char __attribute__ ((section (".bss"))) KILO [24*16];
unsigned char __attribute__ ((section (".bss"))) LIMA [24*16];
unsigned char __attribute__ ((section (".bss"))) MIKE [24*16];
unsigned char __attribute__ ((section (".bss"))) NOVEMBER [24*16];
unsigned char __attribute__ ((section (".bss"))) OSCAR [24*16];
//unsigned char __attribute__ ((section (".bss"))) PAPA [24*16];
//unsigned char __attribute__ ((section (".bss"))) QUEBEC [24*16];
unsigned char __attribute__ ((section (".bss"))) ROMEO [24*16];
unsigned char __attribute__ ((section (".bss"))) SIERRA [24*16];
unsigned char __attribute__ ((section (".bss"))) TANGO [24*16];
unsigned char __attribute__ ((section (".bss"))) UNIFORM [24*16];
unsigned char __attribute__ ((section (".bss"))) VICTOR [24*16];
//unsigned char __attribute__ ((section (".bss"))) WHISKEY [24*16];
unsigned char __attribute__ ((section (".bss"))) XRAY [24*16];
//unsigned char __attribute__ ((section (".bss"))) YANKEE [24*16];
//unsigned char __attribute__ ((section (".bss"))) ZULU [24*16];
unsigned char __attribute__ ((section (".bss"))) ICON0_1 [32*32];
unsigned char __attribute__ ((section (".bss"))) ICON1_1 [32*32];
//unsigned char __attribute__ ((section (".bss"))) ICON2_1 [32*32];
//unsigned char __attribute__ ((section (".bss"))) ICON3_1 [32*32];
unsigned char __attribute__ ((section (".bss"))) ICON4_1 [32*32];
//unsigned char __attribute__ ((section (".bss"))) ICON5_1 [32*32];
unsigned char __attribute__ ((section (".bss"))) ICON6_1 [32*32];
//unsigned char __attribute__ ((section (".bss"))) ICON7_1 [32*32];
unsigned char __attribute__ ((section (".bss"))) ICON8_1 [32*32];
//unsigned char __attribute__ ((section (".bss"))) ICON9_1 [32*32];
unsigned char __attribute__ ((section (".bss"))) BACKGROUND [144*64];
unsigned char __attribute__ ((section (".bss"))) BACKGROUND_1 [144*64];
unsigned char __attribute__ ((section (".bss"))) BACKGROUND_2 [144*64];
#define  UART_OK             0
#define  UART_ERROR         -1
#define  UART_DATA_COUNT     1

void Delay_Medium   () {volatile int d = 0; for (d = 0; d <  10000; d++) {}}
//void Delay_short   () {volatile int d = 0; for (d = 0; d <  2500; d++) {}}
void Delay_long   () {volatile int d = 0; for (d = 0; d <  800000; d++) {}}
void calculate (int a, int b, int c,int d);
void flash_memory();
int x,y;
int count = 0;

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
	flash_memory();
	count =0;
	int ii = 0;
	  char score_h = 0;
	  char score_t = 0;
	  char score_o = 0;

	  char score_h_temp = 0;
	  char score_t_temp = 0;
	  char score_o_temp = 0;
	  char round_h = 0;
	  char round_t = 0;
	  char round_o = 0;

	  char round_h_temp = 0;
	  char round_t_temp = 0;
	  char round_o_temp = 0;
	  char pre_go;
	  int row = 1;
	  int column = 0;
	  char go = 0;
	  char x_pos=2;
	  char y_pos=2;
	  char xtemp=2;
	  char ytemp=2;
	  char counter=0;
	  char round = 1;
	  int select [6][6]= {
			  	  {0,0,0,0,0,0},
				  {0,0,0,0,0,0},
				  {0,0,0,0,0,0},
				  {0,0,0,0,0,0},
				  {0,0,0,0,0,0},
				  {0,0,0,0,0,0},
	  };
	  char pre_select [6][6]= {
			  	  {0,0,0,0,0,0},
				  {0,0,0,0,0,0},
				  {0,0,0,0,0,0},
				  {0,0,0,0,0,0},
				  {0,0,0,0,0,0},
				  {0,0,0,0,0,0},
	  };

	  char num [6][6]= {
	  			  	  {-1,-1,-1,-1,-1,-1},
	  				  {-1,-1,-1,-1,-1,-1},
	  				  {-1,-1,-1,-1,-1,-1},
	  				  {-1,-1,-1,-1,-1,-1},
	  				  {-1,-1,-1,-1,-1,-1},
	  				  {-1,-1,-1,-1,-1,-1},
	  	  };
	  int    UART_ER = ~UART_OK;
	  alt_u8 UART_PE = 0;
	  unsigned int UART_FL_RD = 10000;
	  unsigned int UART_FL_WR = 20000;
	  int change = 0;
	  alt_u8 UART_BYTE = 0;
	  alt_u8 UART_RD_08 [UART_DATA_COUNT];
	  alt_u8 UART_WR_08 [UART_DATA_COUNT];

	  hPB = alt_up_pixel_buffer_dma_open_dev (VGA_PIXEL_DMA_NAME);

	  alt_up_pixel_buffer_dma_clear_screen (hPB, 0);
	  alt_up_pixel_buffer_dma_clear_screen (hPB, 1);
		for (x = 0; x < 24; x++) {
			for (y = 0; y < 16; y++) {

									if (ECHO[count]==1){
										alt_up_pixel_buffer_dma_draw(hPB, 255,
												(y + 6 * 16), (x + 0 * 24));
									}
									if (NOVEMBER[count]==1){
										alt_up_pixel_buffer_dma_draw(hPB, 255,
												(y + 7 * 16), (x + 0 * 24));
									}
									if (GOLF[count]==1){
										alt_up_pixel_buffer_dma_draw(hPB, 255,
												(y + 8 * 16), (x + 0 * 24));
									}
									if (NOVEMBER[count]==1){
										alt_up_pixel_buffer_dma_draw(hPB, 255,
												(y + 9 * 16), (x + 0 * 24));
									}
									if (FOUR[count]==1){
										alt_up_pixel_buffer_dma_draw(hPB, 255,
												(y + 10 * 16), (x + 0 * 24));
									}
									if (ZERO[count]==1){
										alt_up_pixel_buffer_dma_draw(hPB, 255,
												(y + 11 * 16), (x + 0 * 24));
									}
									if (SIX[count]==1){
										alt_up_pixel_buffer_dma_draw(hPB, 255,
												(y + 12 * 16), (x + 0 * 24));
									}
									if (FIVE[count]==1){
										alt_up_pixel_buffer_dma_draw(hPB, 255,
												(y + 13 * 16), (x + 0 * 24));
									}
									if(SIERRA[count]==1){
										alt_up_pixel_buffer_dma_draw(hPB, 31,
												(y + 15 * 16), (x + 0 * 24));
									}
									if(CHARLIE[count]==1){
										alt_up_pixel_buffer_dma_draw(hPB, 31,
												(y + 16 * 16), (x + 0 * 24));
									}
									if(OSCAR[count]==1){
										alt_up_pixel_buffer_dma_draw(hPB, 31,
												(y + 17 * 16), (x + 0 * 24));
									}
									if(ROMEO[count]==1){
										alt_up_pixel_buffer_dma_draw(hPB, 31,
												(y + 18 * 16), (x + 0 * 24));
									}
									if(ECHO[count]==1){
										alt_up_pixel_buffer_dma_draw(hPB, 31,
												(y + 19 * 16), (x + 0 * 24));
									}
									if(ZERO[count]==1){
										alt_up_pixel_buffer_dma_draw(hPB, 31,
												(y + 16 * 16), (x + 2 * 24));
									}
									if(ZERO[count]==1){
										alt_up_pixel_buffer_dma_draw(hPB, 31,
												(y + 17 * 16), (x + 2 * 24));
									}
									if(ZERO[count]==1){
										alt_up_pixel_buffer_dma_draw(hPB, 31,
												(y + 18 * 16), (x + 2 * 24));
									}
									if(ZERO[count]==1){
										alt_up_pixel_buffer_dma_draw(hPB, 31,
												(y + 19 * 16), (x + 2 * 24));
									}
									if(ROMEO[count]==1){
										alt_up_pixel_buffer_dma_draw(hPB, 240,
												(y + 0 * 16), (x + 0 * 24));
			}
									if(OSCAR[count]==1){
										alt_up_pixel_buffer_dma_draw(hPB, 240,
												(y + 1 * 16), (x + 0 * 24));
									}
									if(UNIFORM[count]==1){
										alt_up_pixel_buffer_dma_draw(hPB, 240,
												(y + 2 * 16), (x + 0 * 24));
									}
									if(NOVEMBER[count]==1){
										alt_up_pixel_buffer_dma_draw(hPB, 240,
												(y + 3 * 16), (x + 0 * 24));
									}
									if(DELTA[count]==1){
										alt_up_pixel_buffer_dma_draw(hPB, 240,
												(y + 4 * 16), (x + 0 * 24));
									}
									if(ZERO[count]==1){
										alt_up_pixel_buffer_dma_draw(hPB, 240,
												(y + 0 * 16), (x + 2 * 24));
									}
									if(ZERO[count]==1){
										alt_up_pixel_buffer_dma_draw(hPB, 240,
												(y + 1 * 16), (x + 2 * 24));
									}
									if(ZERO[count]==1){
										alt_up_pixel_buffer_dma_draw(hPB, 240,
												(y + 2 * 16), (x + 2 * 24));
									}
									if(ZERO[count]==1){
										alt_up_pixel_buffer_dma_draw(hPB, 240,
												(y + 3 * 16), (x + 2 * 24));
									}

									if (SIERRA[count]==1){
										alt_up_pixel_buffer_dma_draw(hPB, 15,
												(y + 6 * 16), (x + 9 * 24));
									}
									if (TANGO[count]==1){
										alt_up_pixel_buffer_dma_draw(hPB, 15,
												(y + 7 * 16), (x + 9 * 24));
									}
									if (ALPHA[count]==1){
										alt_up_pixel_buffer_dma_draw(hPB, 15,
												(y + 8 * 16), (x + 9 * 24));
									}
									if (ROMEO[count]==1){
										alt_up_pixel_buffer_dma_draw(hPB, 15,
												(y + 9 * 16), (x + 9 * 24));
									}
									if (TANGO[count]==1){
										alt_up_pixel_buffer_dma_draw(hPB, 15,
												(y + 10 * 16), (x + 9 * 24));
									}
									if (INDIA[count]==1){
										alt_up_pixel_buffer_dma_draw(hPB, 15,
												(y + 11 * 16), (x + 9 * 24));
									}
									if (NOVEMBER[count]==1){
										alt_up_pixel_buffer_dma_draw(hPB, 15,
												(y + 12 * 16), (x + 9 * 24));
									}
									if (GOLF[count]==1){
										alt_up_pixel_buffer_dma_draw(hPB, 15,
												(y + 13 * 16), (x + 9 * 24));
									}

								count++;
							}

		}
        count = 0;
      	for (x = 0; x < 144; x++) {
			for (y = 0; y < 64; y++) {

					alt_up_pixel_buffer_dma_draw(hPB, BACKGROUND_1[count],
								(y), (x + 3 * 24));
					count++;



            }
          }
      	count = 0;
      	for (x = 0; x < 144; x++) {
			for (y = 0; y < 64; y++) {

                                    alt_up_pixel_buffer_dma_draw(hPB, BACKGROUND_2[count],
												(y+ 16*16 ), (x + 3 * 24));
                                count++;
            }
          }q
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
	     if (round <4 || change==1){
	     if ( counter>1 && counter < 38 ) {
	    	 if (column < 6 && row <7){
	    		 count = 0;
	    	 IOWR_ALTERA_AVALON_PIO_DATA (HEX3_BASE, 0x03);
	    	 num[column][row-1]=UART_RD_08 [ii];


	    			   						if (( UART_RD_08 [ii]== 48 ||UART_RD_08 [ii]== 0)) {

	    			   							for (y = 0; y < 32; y++) {
	    			   							    for (x = 0; x < 32; x++) {
	    			   							    	alt_up_pixel_buffer_dma_draw(hPB, ICON00[count],
	    			   										(x + column * 32)+64, (y + row * 32)-8);
	    			   							    	count=count+1;
	    			   							    }
	    			   							}
	    			   						}

	    			   						if ((UART_RD_08 [ii] == 49||UART_RD_08 [ii]== 1)) {
	    			   							for (y = 0; y < 32; y++) {
	    			   							    for (x = 0; x < 32; x++) {
	    			   							    	alt_up_pixel_buffer_dma_draw(hPB, ICON01[count],
	    			   										(x + column * 32)+64, (y + row * 32)-8);
	    			   							    	count=count+1;
	    			   							    }
	    			   							}
	    			   						}
	    			   						if ((UART_RD_08 [ii] == 50 || UART_RD_08 [ii]== 2)) {

	    			   							for (y = 0; y < 32; y++) {
	    			   							    for (x = 0; x < 32; x++) {
	    			   							    	alt_up_pixel_buffer_dma_draw(hPB, ICON06[count],
	    			   										(x + column * 32)+64, (y + row * 32)-8);
	    			   							    	count=count+1;
	    			   							    }
	    			   							}
	    			   						}
	    			   						if ((UART_RD_08 [ii]== 51 || UART_RD_08 [ii]== 3)) {
	    			   							for (y = 0; y < 32; y++) {
	    			   							    for (x = 0; x < 32; x++) {
	    			   							    	alt_up_pixel_buffer_dma_draw(hPB, ICON08[count],
	    			   										(x + column * 32)+64, (y + row * 32)-8);
	    			   							    	count=count+1;
	    			   							    }
	    			   							}
	    			   						}
	    			   						if ((UART_RD_08 [ii] == 52|| UART_RD_08 [ii]== 4)) {
	    			   							for (y = 0; y < 32; y++) {
	    			   							    for (x = 0; x < 32; x++) {
	    			   							    	alt_up_pixel_buffer_dma_draw(hPB, ICON04[count],
	    			   										(x + column * 32)+64, (y + row * 32)-8);
	    			   							    	count=count+1;
	    			   							    }
	    			   							}
	    			   						}/*
	    			   						if ((UART_RD_08 [ii] == 53 || UART_RD_08 [ii]== 5)) {
	    			   							for (y = 0; y < 32; y++) {
	    			   							    for (x = 0; x < 32; x++) {
	    			   							    	alt_up_pixel_buffer_dma_draw(hPB, ICON05[count],
	    			   										(x + column * 32)+64, (y + row * 32)-8);
	    			   							    	count=count+1;
	    			   							    }
	    			   							}
	    			   						}
	    			   						if ((UART_RD_08 [ii] == 54 || UART_RD_08 [ii]== 6)) {
	    			   							for (y = 0; y < 32; y++) {
	    			   							    for (x = 0; x < 32; x++) {
	    			   							    	alt_up_pixel_buffer_dma_draw(hPB, ICON02[count],
	    			   										(x + column * 32)+64, (y + row * 32)-8);
	    			   							    	count=count+1;
	    			   							    }
	    			   							}
	    			   						}
	    			   						if ((UART_RD_08 [ii] == 55 || UART_RD_08 [ii]== 7)) {
	    			   							for (y = 0; y < 32; y++) {
	    			   							    for (x = 0; x < 32; x++) {
	    			   							    	alt_up_pixel_buffer_dma_draw(hPB, ICON07[count],
	    			   										(x + column * 32)+64, (y + row * 32)-8);
	    			   							    	count=count+1;
	    			   							    }
	    			   							}
	    			   						}
	    			   						if ((UART_RD_08 [ii] == 56 || UART_RD_08 [ii]== 8)) {
	    			   							for (y = 0; y < 32; y++) {
	    			   							    for (x = 0; x < 32; x++) {
	    			   							    	alt_up_pixel_buffer_dma_draw(hPB, ICON03[count],
	    			   										(x + column * 32)+64, (y + row * 32)-8);
	    			   							    	count=count+1;
	    			   							    }
	    			   							}
	    			   						}
*/

	    			   						if (UART_RD_08 [ii] == 57 || UART_RD_08 [ii]== 9) {
	    			   							select[column][row-1]=0;
	    			   							for (y = 0; y < 32; y++) {
	    			   							    for (x = 0; x < 32; x++) {
	    			   							    	alt_up_pixel_buffer_dma_draw(hPB, 0x00,
	    			   										(x + column * 32)+64, (y + row * 32)-8);
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
	    	 }

	     if(counter == 38){

	         		x_pos = UART_RD_08 [ii]-'0' ;
	         		Delay_Medium ();
	         		//row = x_pos;
	         	     }
	     if(counter == 39){
	              	IOWR_ALTERA_AVALON_PIO_DATA (HEX2_BASE, 0x55);
	              	 y_pos = UART_RD_08 [ii]-'0' ;
	              	 //column = y_pos;
	              	 alt_up_pixel_buffer_dma_draw_vline(hPB, (x_pos*32)+64, (y_pos*32)+24, (y_pos*32)+55, 0xA3,0);
	              	 alt_up_pixel_buffer_dma_draw_vline(hPB, (x_pos*32)+95, (y_pos*32)+24, (y_pos*32)+55, 0xA3,0);

	              	 alt_up_pixel_buffer_dma_draw_hline(hPB, (x_pos*32)+64,(x_pos*32)+95, (y_pos*32)+24, 0xA3,0);
	              	 alt_up_pixel_buffer_dma_draw_hline(hPB, (x_pos*32)+64,(x_pos*32)+95, (y_pos*32)+55, 0xA3,0);


	              	 Delay_Medium ();
	                 if ( ((xtemp !=  x_pos || ytemp != y_pos)) ){
	               		IOWR_ALTERA_AVALON_PIO_DATA (HEX0_BASE, 0x55);
	               		alt_up_pixel_buffer_dma_draw_vline(hPB, (xtemp*32)+64, (ytemp*32)+24, (ytemp*32)+55, 0x00,0);
	               		alt_up_pixel_buffer_dma_draw_vline(hPB, (xtemp*32)+95, (ytemp*32)+24, (ytemp*32)+55, 0x00,0);
	               		alt_up_pixel_buffer_dma_draw_hline(hPB, (xtemp*32)+64,(xtemp*32)+95, (ytemp*32)+24, 0X00,0);
	               		alt_up_pixel_buffer_dma_draw_hline(hPB, (xtemp*32)+64,(xtemp*32)+95, (ytemp*32)+55, 0X00,0);

	               		//IOWR_ALTERA_AVALON_PIO_DATA (HEX5_BASE, 0x04);

	                	}

	                 Delay_Medium ();
	              	 }
	    if(counter == 40){
	              	IOWR_ALTERA_AVALON_PIO_DATA (HEX4_BASE, 0x55);

	              	if(UART_RD_08 [ii]==1 || UART_RD_08 [ii]==49){
	              		 select[x_pos][y_pos]=1;
	              		 IOWR_ALTERA_AVALON_PIO_DATA (HEX5_BASE, 0x55);
	              		 change =1;
	              		 Delay_Medium ();


	              		}
	              	if(UART_RD_08 [ii]==0 || UART_RD_08 [ii]==48){
	              		 select[x_pos][y_pos]=0;
	              		 IOWR_ALTERA_AVALON_PIO_DATA (HEX5_BASE, 0x55);

	              		 Delay_Medium ();


	              		}
	              	for (row=0;row<6;row++){
	              		for(column=0;column<6;column++){
	              			count = 0;

	              			if (select[row][column]==1 ){
	              				pre_select[row][column]=1;
	              				if(num[row][column]==0){
		   							for (y = 0; y < 32; y++) {
		   							    for (x = 0; x < 32; x++) {
		   							    	alt_up_pixel_buffer_dma_draw(hPB, ICON0_1[count],
		   										(x + row * 32)+64, (y + column * 32)+24);
		   							    	count=count+1;
		   							    }
		   							}
	              				}
	              				if(num[row][column]==1){
		   							for (y = 0; y < 32; y++) {
		   							    for (x = 0; x < 32; x++) {
		   							    	alt_up_pixel_buffer_dma_draw(hPB, ICON1_1[count],
		   										(x + row * 32)+64, (y + column * 32)+24);
		   							    	count=count+1;
		   							    }
		   							}
	              				}
	              				if(num[row][column]==2){
		   							for (y = 0; y < 32; y++) {
		   							    for (x = 0; x < 32; x++) {
		   							    	alt_up_pixel_buffer_dma_draw(hPB, ICON6_1[count],
		   										(x + row * 32)+64, (y + column * 32)+24);
		   							    	count=count+1;
		   							    }
		   							}
	              				}
	              				if(num[row][column]==3){
		   							for (y = 0; y < 32; y++) {
		   							    for (x = 0; x < 32; x++) {
		   							    	alt_up_pixel_buffer_dma_draw(hPB, ICON8_1[count],
		   										(x + row * 32)+64, (y + column * 32)+24);
		   							    	count=count+1;
		   							    }
		   							}
	              				}
	              				if(num[row][column]==4){
		   							for (y = 0; y < 32; y++) {
		   							    for (x = 0; x < 32; x++) {
		   							    	alt_up_pixel_buffer_dma_draw(hPB, ICON4_1[count],
		   										(x + row * 32)+64, (y + column * 32)+24);
		   							    	count=count+1;
		   							    }
		   							}
	              				}/*
	              				if(num[row][column]==5){
		   							for (y = 0; y < 32; y++) {
		   							    for (x = 0; x < 32; x++) {
		   							    	alt_up_pixel_buffer_dma_draw(hPB, ICON5_1[count],
		   										(x + row * 32)+64, (y + column * 32)+24);
		   							    	count=count+1;
		   							    }
		   							}
	              				}
	              				if(num[row][column]==6){
		   							for (y = 0; y < 32; y++) {
		   							    for (x = 0; x < 32; x++) {
		   							    	alt_up_pixel_buffer_dma_draw(hPB, ICON2_1[count],
		   										(x + row * 32)+64, (y + column * 32)+24);
		   							    	count=count+1;
		   							    }
		   							}
	              				}
	              				if(num[row][column]==7){
		   							for (y = 0; y < 32; y++) {
		   							    for (x = 0; x < 32; x++) {
		   							    	alt_up_pixel_buffer_dma_draw(hPB, ICON7_1[count],
		   										(x + row * 32)+64, (y + column * 32)+24);
		   							    	count=count+1;
		   							    }
		   							}
	              				}
	              				if(num[row][column]==8){
		   							for (y = 0; y < 32; y++) {
		   							    for (x = 0; x < 32; x++) {
		   							    	alt_up_pixel_buffer_dma_draw(hPB, ICON3_1[count],
		   										(x + row * 32)+64, (y + column * 32)+24);
		   							    	count=count+1;
		   							    }
		   							}
	              				}
	              				if(num[row][column]==9){
		   							for (y = 0; y < 32; y++) {
		   							    for (x = 0; x < 32; x++) {
		   							    	alt_up_pixel_buffer_dma_draw(hPB, ICON9_1[count],
		   										(x + row * 32)+64, (y + column * 32)+24);
		   							    	count=count+1;
		   							    }
		   							}
	              				} */


	              	}

	              			if (select[row][column]==0 && pre_select[row][column]==1){
	              				pre_select[row][column]=0;
	              				if(num[row][column]==0){
		   							for (y = 0; y < 32; y++) {
		   							    for (x = 0; x < 32; x++) {
		   							    	alt_up_pixel_buffer_dma_draw(hPB, ICON00[count],
		   										(x + row * 32)+64, (y + column * 32)+24);
		   							    	count=count+1;
		   							    }
		   							}
	              				}
	              				if(num[row][column]==1){
		   							for (y = 0; y < 32; y++) {
		   							    for (x = 0; x < 32; x++) {
		   							    	alt_up_pixel_buffer_dma_draw(hPB, ICON01[count],
		   										(x + row * 32)+64, (y + column * 32)+24);
		   							    	count=count+1;
		   							    }
		   							}
	              				}
	              				if(num[row][column]==2){
		   							for (y = 0; y < 32; y++) {
		   							    for (x = 0; x < 32; x++) {
		   							    	alt_up_pixel_buffer_dma_draw(hPB, ICON06[count],
		   										(x + row * 32)+64, (y + column * 32)+24);
		   							    	count=count+1;
		   							    }
		   							}
	              				}
	              				if(num[row][column]==3){
		   							for (y = 0; y < 32; y++) {
		   							    for (x = 0; x < 32; x++) {
		   							    	alt_up_pixel_buffer_dma_draw(hPB, ICON08[count],
		   										(x + row * 32)+64, (y + column * 32)+24);
		   							    	count=count+1;
		   							    }
		   							}
	              				}/*
	              				alt_up_pixel_buffer_dma_draw_vline(hPB, (row*32)+64, (column*32)+24, (column*32)+55, 0x00,0);
	              				alt_up_pixel_buffer_dma_draw_vline(hPB, (row*32)+95, (column*32)+24, (column*32)+55, 0x00,0);

	              				alt_up_pixel_buffer_dma_draw_hline(hPB, (row*32)+64,(row*32)+95, (column*32)+24, 0x00,0);
	              				alt_up_pixel_buffer_dma_draw_hline(hPB, (row*32)+64,(row*32)+95, (column*32)+55, 0x00,0); */
	              				if(num[row][column]==4){
		   							for (y = 0; y < 32; y++) {
		   							    for (x = 0; x < 32; x++) {
		   							    	alt_up_pixel_buffer_dma_draw(hPB, ICON04[count],
		   										(x + row * 32)+64, (y + column * 32)+24);
		   							    	count=count+1;
		   							    }
		   							}
	              				}/*
	              				if(num[row][column]==5){
		   							for (y = 0; y < 32; y++) {
		   							    for (x = 0; x < 32; x++) {
		   							    	alt_up_pixel_buffer_dma_draw(hPB, ICON05[count],
		   										(x + row * 32)+64, (y + column * 32)+24);
		   							    	count=count+1;
		   							    }
		   							}
	              				}
	              				if(num[row][column]==6){
		   							for (y = 0; y < 32; y++) {
		   							    for (x = 0; x < 32; x++) {
		   							    	alt_up_pixel_buffer_dma_draw(hPB, ICON02[count],
		   										(x + row * 32)+64, (y + column * 32)+24);
		   							    	count=count+1;
		   							    }
		   							}
	              				}
	              				if(num[row][column]==7){
		   							for (y = 0; y < 32; y++) {
		   							    for (x = 0; x < 32; x++) {
		   							    	alt_up_pixel_buffer_dma_draw(hPB, ICON07[count],
		   										(x + row * 32)+64, (y + column * 32)+24);
		   							    	count=count+1;
		   							    }
		   							}
	              				}
	              				if(num[row][column]==8){
		   							for (y = 0; y < 32; y++) {
		   							    for (x = 0; x < 32; x++) {
		   							    	alt_up_pixel_buffer_dma_draw(hPB, ICON03[count],
		   										(x + row * 32)+64, (y + column * 32)+24);
		   							    	count=count+1;
		   							    }
		   							}
	              				}
*/
	              			}

	              		}
	              	}

	              	Delay_Medium ();
	              	 }

     	 alt_up_pixel_buffer_dma_draw_vline(hPB, (x_pos*32)+64, (y_pos*32)+24, (y_pos*32)+55, 0xA3,0);
     	 alt_up_pixel_buffer_dma_draw_vline(hPB, (x_pos*32)+95, (y_pos*32)+24, (y_pos*32)+55, 0xA3,0);

     	 alt_up_pixel_buffer_dma_draw_hline(hPB, (x_pos*32)+64,(x_pos*32)+95, (y_pos*32)+24, 0xA3,0);
     	 alt_up_pixel_buffer_dma_draw_hline(hPB, (x_pos*32)+64,(x_pos*32)+95, (y_pos*32)+55, 0xA3,0);

	    if(counter == 41){
	    	if(UART_RD_08 [ii]==1 || UART_RD_08 [ii]==49){
	    		round = 0;
              	for (row=0;row<6;row++){
              		for(column=0;column<6;column++){

              			if (select[row][column]==1){

              				select[row][column]=0;
              			}
                 	Delay_Medium ();

              		}
              	}


	    	}

	    }


/*
 	 	    if(counter == 42){

			score_th =UART_RD_08 [ii];
			row=16;
			if (score_th_temp != score_th){
			alt_up_pixel_buffer_dma_draw_box(hPB,16*16,48,(16*16)+16,72 ,0,0);
			calculate(score_th,31,row,2);
			}




	    }*/

	    if(counter == 43){
			score_h =UART_RD_08 [ii];
			row=17;
			if (score_h_temp != score_h){
			alt_up_pixel_buffer_dma_draw_box(hPB,(row)*16,48,((row)*16)+16,72 ,0,0);
			calculate(score_h,31,row,2);
			}
	    }

	    if(counter == 44){
			score_t =UART_RD_08 [ii];
			row=18;
			if (score_t_temp != score_t){
			alt_up_pixel_buffer_dma_draw_box(hPB,(row)*16,48,((row)*16)+16,72 ,0,0);
			calculate(score_t,31,row,2);
			}
			}


	    if(counter == 45){
			score_o =UART_RD_08 [ii];
			row=19;
			if (score_o_temp != score_o){
			alt_up_pixel_buffer_dma_draw_box(hPB,(row)*16,48,((row)*16)+16,72 ,0,0);
			calculate(score_o,31,row,2);
			}
	    }

	    if(counter == 46){

	    }

	    if(counter == 47){
	    	round_h =UART_RD_08 [ii];
			row=1;
			if (round_h_temp != round_h){
			alt_up_pixel_buffer_dma_draw_box(hPB,(row)*16,48,((row)*16)+16,72 ,0,0);
			calculate(round_h,252,row,2);
			}

	    }

	    if(counter == 48){
	    	round_t =UART_RD_08 [ii];
			row=2;
			if (round_t_temp != round_t){
			alt_up_pixel_buffer_dma_draw_box(hPB,(row)*16,48,((row)*16)+16,72 ,0,0);
			calculate(round_t,252,row,2);
			}    }

	    if(counter == 49){
	    	round_o =UART_RD_08 [ii];
			row=3;
			if (round_o_temp != round_o){
			alt_up_pixel_buffer_dma_draw_box(hPB,(row)*16,48,((row)*16)+16,72 ,0,0);
			calculate(round_o,252,row,2);
			}
			  }

	    Delay_Medium ();

	 if(counter == 50){
		 go = UART_RD_08 [ii];
		 count=0;
			if((UART_RD_08 [ii]==1 || UART_RD_08 [ii]==48) && pre_go!=UART_RD_08 [ii]){
				alt_up_pixel_buffer_dma_draw_box(hPB,80,216,240,240 ,0,0);
				for (x = 0; x < 24; x++) {
					for (y = 0; y < 16; y++) {

						if (SIERRA[count]==1){
							alt_up_pixel_buffer_dma_draw(hPB, 15,
									(y + 6 * 16)-8, (x + 9 * 24));
						}
						if (ECHO[count]==1){
							alt_up_pixel_buffer_dma_draw(hPB, 15,
									(y + 7 * 16)-8, (x + 9 * 24));
						}
						if (LIMA[count]==1){
							alt_up_pixel_buffer_dma_draw(hPB, 15,
									(y + 8 * 16)-8, (x + 9 * 24));
						}
						if (ECHO[count]==1){
							alt_up_pixel_buffer_dma_draw(hPB, 15,
									(y + 9 * 16)-8, (x + 9 * 24));
						}
						if (CHARLIE[count]==1){
							alt_up_pixel_buffer_dma_draw(hPB, 15,
									(y + 10 * 16)-8, (x + 9 * 24));
						}
						if (TANGO[count]==1){
							alt_up_pixel_buffer_dma_draw(hPB, 15,
									(y + 11 * 16)-8, (x + 9 * 24));
						}
						if (INDIA[count]==1){
							alt_up_pixel_buffer_dma_draw(hPB, 15,
									(y + 12 * 16)-8, (x + 9 * 24));
						}
						if (NOVEMBER[count]==1){
							alt_up_pixel_buffer_dma_draw(hPB, 15,
									(y + 13 * 16)-8, (x + 9 * 24));
						}
						if (GOLF[count]==1){
							alt_up_pixel_buffer_dma_draw(hPB, 15,
									(y + 14 * 16)-8, (x + 9 * 24));
						}
						count = count+1;
					}
				}

				}
			if((UART_RD_08 [ii]==2 || UART_RD_08 [ii]==49)&& pre_go!=UART_RD_08 [ii]){
				alt_up_pixel_buffer_dma_draw_box(hPB,80,216,240,240 ,0,0);
				for (x = 0; x < 24; x++) {
					for (y = 0; y < 16; y++) {

						if (CHARLIE[count]==1){
							alt_up_pixel_buffer_dma_draw(hPB, 15,
									(y + 6 * 16), (x + 9 * 24));
						}
						if (LIMA[count]==1){
							alt_up_pixel_buffer_dma_draw(hPB, 15,
									(y + 7 * 16), (x + 9 * 24));
						}
						if (ECHO[count]==1){
							alt_up_pixel_buffer_dma_draw(hPB, 15,
									(y + 8 * 16), (x + 9 * 24));
						}
						if (ALPHA[count]==1){
							alt_up_pixel_buffer_dma_draw(hPB, 15,
									(y + 9 * 16), (x + 9 * 24));
						}
						if (ROMEO[count]==1){
							alt_up_pixel_buffer_dma_draw(hPB, 15,
									(y + 10 * 16), (x + 9 * 24));
						}
						if (INDIA[count]==1){
							alt_up_pixel_buffer_dma_draw(hPB, 15,
									(y + 11 * 16), (x + 9 * 24));
						}
						if (NOVEMBER[count]==1){
							alt_up_pixel_buffer_dma_draw(hPB, 15,
									(y + 12 * 16), (x + 9 * 24));
						}
						if (GOLF[count]==1){
							alt_up_pixel_buffer_dma_draw(hPB, 15,
									(y + 13 * 16), (x + 9 * 24));
						}

						count = count+1;
					}
				}

				}
			if((UART_RD_08 [ii]==3 || UART_RD_08 [ii]==50) && pre_go!=UART_RD_08 [ii]){
				alt_up_pixel_buffer_dma_draw_box(hPB,80,216,240,240 ,0,0);
				for (x = 0; x < 24; x++) {
					for (y = 0; y < 16; y++) {

						if (MIKE[count]==1){
							alt_up_pixel_buffer_dma_draw(hPB, 15,
									(y + 6 * 16), (x + 9 * 24));
						}
						if (ALPHA[count]==1){
							alt_up_pixel_buffer_dma_draw(hPB, 15,
									(y + 7 * 16), (x + 9 * 24));
						}
						if (TANGO[count]==1){
							alt_up_pixel_buffer_dma_draw(hPB, 15,
									(y + 8 * 16), (x + 9 * 24));
						}
						if (CHARLIE[count]==1){
							alt_up_pixel_buffer_dma_draw(hPB, 15,
									(y + 9 * 16), (x + 9 * 24));
						}
						if (HOTEL[count]==1){
							alt_up_pixel_buffer_dma_draw(hPB, 15,
									(y + 10 * 16), (x + 9 * 24));
						}
						if (INDIA[count]==1){
							alt_up_pixel_buffer_dma_draw(hPB, 15,
									(y + 11 * 16), (x + 9 * 24));
						}
						if (NOVEMBER[count]==1){
							alt_up_pixel_buffer_dma_draw(hPB, 15,
									(y + 12 * 16), (x + 9 * 24));
						}
						if (GOLF[count]==1){
							alt_up_pixel_buffer_dma_draw(hPB, 15,
									(y + 13 * 16), (x + 9 * 24));
						}

						count = count+1;
					}
				}

				}
			if(UART_RD_08 [ii]==4 || UART_RD_08 [ii]==51){
				alt_up_pixel_buffer_dma_draw_box(hPB,80,216,240,240 ,0,0);
				while(1){
				count=0;
				for (x = 0; x < 24; x++) {
					for (y = 0; y < 16; y++) {

						if (GOLF[count]==1){
							alt_up_pixel_buffer_dma_draw(hPB, 64,
									(y + 5 * 16)+8, (x + 9 * 24));
						}
						if (ALPHA[count]==1){
							alt_up_pixel_buffer_dma_draw(hPB, 64,
									(y + 6 * 16)+8, (x + 9 * 24));
						}
						if (MIKE[count]==1){
							alt_up_pixel_buffer_dma_draw(hPB, 64,
									(y + 7 * 16)+8, (x + 9 * 24));
						}
						if (ECHO[count]==1){
							alt_up_pixel_buffer_dma_draw(hPB, 64,
									(y + 8 * 16)+8, (x + 9 * 24));
						}

							alt_up_pixel_buffer_dma_draw(hPB, 0,
									(y + 9 * 16)+8, (x + 9 * 24));

						if (OSCAR[count]==1){
							alt_up_pixel_buffer_dma_draw(hPB, 64,
									(y + 10 * 16)+8, (x + 9 * 24));
						}
						if (VICTOR[count]==1){
							alt_up_pixel_buffer_dma_draw(hPB, 64,
									(y + 11 * 16)+8, (x + 9 * 24));
						}
						if (ECHO[count]==1){
							alt_up_pixel_buffer_dma_draw(hPB, 64,
									(y + 12 * 16)+8, (x + 9 * 24));
						}
						if (ROMEO[count]==1){
							alt_up_pixel_buffer_dma_draw(hPB, 64,
									(y + 13 * 16)+8, (x + 9 * 24));
						}

						count = count+1;
					}
				}
				Delay_long   ();
				alt_up_pixel_buffer_dma_draw_box(hPB,80,216,240,240 ,0,0);
				Delay_long   ();
				}
				}
			if((UART_RD_08 [ii]==5 || UART_RD_08 [ii]==52) && pre_go!=UART_RD_08 [ii]){
				alt_up_pixel_buffer_dma_draw_box(hPB,80,216,240,240 ,0,0);
				for (x = 0; x < 24; x++) {
					for (y = 0; y < 16; y++) {

						if (NOVEMBER[count]==1){
							alt_up_pixel_buffer_dma_draw(hPB, 15,
									(y + 5 * 16), (x + 9 * 24));
						}
						if (ECHO[count]==1){
							alt_up_pixel_buffer_dma_draw(hPB, 15,
									(y + 6 * 16), (x + 9 * 24));
						}
						if (XRAY[count]==1){
							alt_up_pixel_buffer_dma_draw(hPB, 15,
									(y + 7 * 16), (x + 9 * 24));
						}
						if (TANGO[count]==1){
							alt_up_pixel_buffer_dma_draw(hPB, 15,
									(y + 8 * 16), (x + 9 * 24));
						}

							alt_up_pixel_buffer_dma_draw(hPB, 0,
									(y + 9 * 16), (x + 9 * 24));

						if (ROMEO[count]==1){
							alt_up_pixel_buffer_dma_draw(hPB, 15,
									(y + 10 * 16), (x + 9 * 24));
						}
						if (OSCAR[count]==1){
							alt_up_pixel_buffer_dma_draw(hPB, 15,
									(y + 11 * 16), (x + 9 * 24));
						}
						if (UNIFORM[count]==1){
							alt_up_pixel_buffer_dma_draw(hPB, 15,
									(y + 12 * 16), (x + 9 * 24));
						}
						if (NOVEMBER[count]==1){
							alt_up_pixel_buffer_dma_draw(hPB, 15,
									(y + 13 * 16), (x + 9 * 24));
						}
						if (DELTA[count]==1){
							alt_up_pixel_buffer_dma_draw(hPB, 15,
									(y + 14 * 16), (x + 9 * 24));
						}
						count = count+1;
					}
				}

				}
	 }

    if(counter == 55){
			 UART_ER = alt_up_rs232_write_data (hUART, 0x72);
			 Delay_Medium ();
		     row=1;
		     column=0;
		     counter = 0;
	      	 xtemp = x_pos;
	         ytemp = y_pos;
	         round = round +1;
	         change =0;

	         score_h_temp=score_h;
	         score_t_temp=score_t;
	         score_o_temp=score_o;
	         round_h_temp=round_h;
	         round_t_temp=round_t;
	         round_o_temp=round_o;
	         pre_go=go;

	    }
	    }

	   UART_FL_RD = 0;
	   UART_FL_WR = 0;
	   }
	  }

 return 0;
}
void calculate (int a, int b, int c, int d){ // a = number , b = color , c = row , d = column
	IOWR_ALTERA_AVALON_PIO_DATA (HEX3_BASE, 0x55);
	count =0;
	if (a==0 || a== 48 ){
		for (x = 0; x < 24; x++) {
			for (y = 0; y < 16; y++) {
			if(ZERO[count]==1){
						alt_up_pixel_buffer_dma_draw(alt_up_pixel_buffer_dma_open_dev (VGA_PIXEL_DMA_NAME), b,
								(y + c * 16), (x + d * 24));

					}
			count = count+1;
				}
			}
	}
	if (a==1|| a== 49){
		for (x = 0; x < 24; x++) {
			for (y = 0; y < 16; y++) {
			if(ONE[count]==1){

						alt_up_pixel_buffer_dma_draw(alt_up_pixel_buffer_dma_open_dev (VGA_PIXEL_DMA_NAME), b,
								(y + c * 16), (x + d * 24));

			}
			count = count+1;
							}
			}
	}
	if (a==2 || a== 50){
		for (x = 0; x < 24; x++) {
			for (y = 0; y < 16; y++) {
			if(TWO[count]==1){

						alt_up_pixel_buffer_dma_draw(alt_up_pixel_buffer_dma_open_dev (VGA_PIXEL_DMA_NAME), b,
								(y + c * 16), (x + d * 24));

					}
			count = count+1;
				}
			}
	}
	if (a==3|| a== 51){
		for (x = 0; x < 24; x++) {
			for (y = 0; y < 16; y++) {
			if(THREE[count]==1){

						alt_up_pixel_buffer_dma_draw(alt_up_pixel_buffer_dma_open_dev (VGA_PIXEL_DMA_NAME), b,
								(y + c * 16), (x + d * 24));

					}
			count = count+1;
				}
			}
	}
	if (a==4|| a== 52){
		for (x = 0; x < 24; x++) {
			for (y = 0; y < 16; y++) {
			if(FOUR[count]==1){

						alt_up_pixel_buffer_dma_draw(alt_up_pixel_buffer_dma_open_dev (VGA_PIXEL_DMA_NAME), b,
								(y + c * 16), (x + d * 24));

					}
			count = count+1;
				}
			}
	}
	if (a==5|| a== 53){
		for (x = 0; x < 24; x++) {
			for (y = 0; y < 16; y++) {
			if(FIVE[count]==1){

						alt_up_pixel_buffer_dma_draw(alt_up_pixel_buffer_dma_open_dev (VGA_PIXEL_DMA_NAME), b,
								(y + c * 16), (x + d * 24));

					}
			count = count+1;
				}
			}
	}
	if (a==6 || a== 54){
		for (x = 0; x < 24; x++) {
			for (y = 0; y < 16; y++) {
			if(SIX[count]==1){

						alt_up_pixel_buffer_dma_draw(alt_up_pixel_buffer_dma_open_dev (VGA_PIXEL_DMA_NAME), b,
								(y + c * 16), (x + d * 24));

					}
			count = count+1;
				}
			}
	}
	if (a==7 || a== 55){
		for (x = 0; x < 24; x++) {
			for (y = 0; y < 16; y++) {
			if(SEVEN[count]==1){

						alt_up_pixel_buffer_dma_draw(alt_up_pixel_buffer_dma_open_dev (VGA_PIXEL_DMA_NAME), b,
								(y + c * 16), (x + d * 24));

					}
			count = count+1;
				}
			}
	}
	if (a==8 || a== 56){
		for (x = 0; x < 24; x++) {
			for (y = 0; y < 16; y++) {
			if(EIGHT[count]==1){

						alt_up_pixel_buffer_dma_draw(alt_up_pixel_buffer_dma_open_dev (VGA_PIXEL_DMA_NAME), b,
								(y + c * 16), (x + d * 24));

					}
			count = count+1;
				}
			}
	}
	if (a==9 || a== 57){
		for (x = 0; x < 24; x++) {
			for (y = 0; y < 16; y++) {
			if(NINE[count]==1){

						alt_up_pixel_buffer_dma_draw(alt_up_pixel_buffer_dma_open_dev (VGA_PIXEL_DMA_NAME), b,
								(y + c * 16), (x + d * 24));

					}
			count = count+1;
				}
			}
	}
	Delay_Medium ();


}
void flash_memory(){

	unsigned int temp;
	for(int i = 0x0; i<= 0xF200; i+=4){ // 61952
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

		count = count+4;
		}
	if(i==3072){
		count=0;
		 }
	if(i>=3072&& i < 4096){

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
//		BRAVO[count]=temp>>24 ;
//		BRAVO[count+1]= ((temp>>(17-1))&((1<<8)-1));
//		BRAVO[count+2]= ((temp>>(9-1))&((1<<8)-1));
//		BRAVO[count+3]= ((temp>>(1-1))&((1<<8)-1)); ;
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
//		FOXTROT[count]=temp>>24 ;
//		FOXTROT[count+1]= ((temp>>(17-1))&((1<<8)-1));
//		FOXTROT[count+2]= ((temp>>(9-1))&((1<<8)-1));
//		FOXTROT[count+3]= ((temp>>(1-1))&((1<<8)-1)); ;
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
//		JULIETT[count]=temp>>24 ;
//		JULIETT[count+1]= ((temp>>(17-1))&((1<<8)-1));
//		JULIETT[count+2]= ((temp>>(9-1))&((1<<8)-1));
//		JULIETT[count+3]= ((temp>>(1-1))&((1<<8)-1)); ;
		count = count+4;
					}
	if(i==17920){
		count=0;
				}
	if(i>=17920&& i < 18304){
//		KILO[count]=temp>>24 ;
//		KILO[count+1]= ((temp>>(17-1))&((1<<8)-1));
//		KILO[count+2]= ((temp>>(9-1))&((1<<8)-1));
//		KILO[count+3]= ((temp>>(1-1))&((1<<8)-1)); ;
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
//		PAPA[count]=temp>>24 ;
//		PAPA[count+1]= ((temp>>(17-1))&((1<<8)-1));
//		PAPA[count+2]= ((temp>>(9-1))&((1<<8)-1));
//		PAPA[count+3]= ((temp>>(1-1))&((1<<8)-1)); ;
		count = count+4;
					}
	if(i==20224){
		count=0;
				}
	if(i>=20224&& i < 20608){
//		QUEBEC[count]=temp>>24 ;
//		QUEBEC[count+1]= ((temp>>(17-1))&((1<<8)-1));
//		QUEBEC[count+2]= ((temp>>(9-1))&((1<<8)-1));
//		QUEBEC[count+3]= ((temp>>(1-1))&((1<<8)-1)); ;
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
//		WHISKEY[count]=temp>>24 ;
//		WHISKEY[count+1]= ((temp>>(17-1))&((1<<8)-1));
//		WHISKEY[count+2]= ((temp>>(9-1))&((1<<8)-1));
//		WHISKEY[count+3]= ((temp>>(1-1))&((1<<8)-1)); ;
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
//		YANKEE[count]=temp>>24 ;
//		YANKEE[count+1]= ((temp>>(17-1))&((1<<8)-1));
//		YANKEE[count+2]= ((temp>>(9-1))&((1<<8)-1));
//		YANKEE[count+3]= ((temp>>(1-1))&((1<<8)-1)); ;
		count = count+4;
					}
	if(i==23680){
		count=0;
				}
	if(i>=23680 && i <24064){
//		ZULU[count]=temp>>24 ;
//		ZULU[count+1]= ((temp>>(17-1))&((1<<8)-1));
//		ZULU[count+2]= ((temp>>(9-1))&((1<<8)-1));
//		ZULU[count+3]= ((temp>>(1-1))&((1<<8)-1)); ;
		count = count+4;
					}
	if(i==24064){
		count=0;
				}
	if(i>=24064&& i < 25088){
		ICON0_1[count]=temp>>24 ;
		ICON0_1[count+1]= ((temp>>(17-1))&((1<<8)-1));
		ICON0_1[count+2]= ((temp>>(9-1))&((1<<8)-1));
		ICON0_1[count+3]= ((temp>>(1-1))&((1<<8)-1)); ;
		count = count+4;
					}
	if(i==25088){
		count=0;
				}
	if(i>=25088&& i < 26112){
		ICON1_1[count]=temp>>24 ;
		ICON1_1[count+1]= ((temp>>(17-1))&((1<<8)-1));
		ICON1_1[count+2]= ((temp>>(9-1))&((1<<8)-1));
		ICON1_1[count+3]= ((temp>>(1-1))&((1<<8)-1)); ;
		count = count+4;
					}
	if(i==26112){
		count=0;
				}
	if(i>=26112&& i < 27136){

		count = count+4;
					}
	if(i==27136){
		count=0;
				}
	if(i>=27136&& i < 28160){

		count = count+4;
					}
	if(i==28160){
		count=0;
				}
	if(i>=28160&& i < 29184){
		ICON4_1[count]=temp>>24 ;
		ICON4_1[count+1]= ((temp>>(17-1))&((1<<8)-1));
		ICON4_1[count+2]= ((temp>>(9-1))&((1<<8)-1));
		ICON4_1[count+3]= ((temp>>(1-1))&((1<<8)-1)); ;
		count = count+4;
					}
	if(i==29184){
		count=0;
				}
	if(i>=29184&& i < 30208){
				count = count+4;
					}
	if(i==30208){
		count=0;
				}
	if(i>=30208&& i < 31232){
		ICON6_1[count]=temp>>24 ;
		ICON6_1[count+1]= ((temp>>(17-1))&((1<<8)-1));
		ICON6_1[count+2]= ((temp>>(9-1))&((1<<8)-1));
		ICON6_1[count+3]= ((temp>>(1-1))&((1<<8)-1)); ;
		count = count+4;
					}
	if(i==31232){
		count=0;
				}
	if(i>=31232&& i < 32256){

		count = count+4;
					}
	if(i==32256){
		count=0;
				}
	if(i>=32256&& i < 33280){
		ICON8_1[count]=temp>>24 ;
		ICON8_1[count+1]= ((temp>>(17-1))&((1<<8)-1));
		ICON8_1[count+2]= ((temp>>(9-1))&((1<<8)-1));
		ICON8_1[count+3]= ((temp>>(1-1))&((1<<8)-1)); ;
		count = count+4;
					}
	if(i==33280){
		count=0;
				}
	if(i>=33280 && i < 34304){

		count = count+4;
					}
	if(i==34304){
		count=0;
				}
	if(i>=34304 && i < 43520){
		BACKGROUND[count]=temp>>24 ;
		BACKGROUND[count+1]= ((temp>>(17-1))&((1<<8)-1));
		BACKGROUND[count+2]= ((temp>>(9-1))&((1<<8)-1));
		BACKGROUND[count+3]= ((temp>>(1-1))&((1<<8)-1)); ;
		count = count+4;
					}
	if(i==43520){
		count=0;
				}
	if(i>=43520 && i < 52736){
		BACKGROUND_1[count]=temp>>24 ;
		BACKGROUND_1[count+1]= ((temp>>(17-1))&((1<<8)-1));
		BACKGROUND_1[count+2]= ((temp>>(9-1))&((1<<8)-1));
		BACKGROUND_1[count+3]= ((temp>>(1-1))&((1<<8)-1)); ;
		count = count+4;
					}
	if(i==52736){
		count=0;
				}
	if(i>=52736 ){
		BACKGROUND_2[count]=temp>>24 ;
		BACKGROUND_2[count+1]= ((temp>>(17-1))&((1<<8)-1));
		BACKGROUND_2[count+2]= ((temp>>(9-1))&((1<<8)-1));
		BACKGROUND_2[count+3]= ((temp>>(1-1))&((1<<8)-1)); ;
		count = count+4;
					}

	}

}
