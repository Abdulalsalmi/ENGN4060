 #include "system.h"
 #include "alt_types.h"
 #include "altera_up_avalon_video_pixel_buffer_dma.h"
 #include "altera_avalon_pio_regs.h"
 #include "altera_up_avalon_rs232.h"
 #include "ICON.h"
 #define  UART_OK             0
 #define  UART_ERROR         -1
 #define  UART_DATA_COUNT     1

 void Delay_Medium   () {volatile int d = 0; for (d = 0; d <  10000; d++) {}}

 int main()
 {
  int ii = 0;

  int row = 1;
  int column = 0;
  int x,y;
  int x_pos=2;
  int y_pos=2;
  int xtemp=2;
  int ytemp=2;
  int count=0;
  int    UART_ER = ~UART_OK;
  alt_u8 UART_PE = 0;
  unsigned int UART_FL_RD = 10000;
  unsigned int UART_FL_WR = 20000;

  alt_u8 UART_BYTE = 0;
  alt_u8 UART_RD_08 [UART_DATA_COUNT];
  alt_u8 UART_WR_08 [UART_DATA_COUNT];

  alt_up_pixel_buffer_dma_dev* hPB = NULL;
  hPB = alt_up_pixel_buffer_dma_open_dev (VGA_PIXEL_DMA_NAME);
  alt_up_pixel_buffer_dma_clear_screen (hPB, 0);
  alt_up_pixel_buffer_dma_clear_screen (hPB, 1);
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
	   count=count+1;


    for (ii = 0; ii < UART_DATA_COUNT; ii++)
    {
     UART_ER = alt_up_rs232_read_data (hUART, &UART_BYTE, &UART_PE);
     UART_RD_08 [ii] = UART_BYTE;
    }



    for (ii = 0; ii < UART_DATA_COUNT; ii++)
    {

     if ( count==1 ){
    	 UART_ER = alt_up_rs232_write_data (hUART, 0x64);

    	 IOWR_ALTERA_AVALON_PIO_DATA (HEX4_BASE, 0x04);
    	 Delay_Medium ();



     }
     if ( count>1 && count < 38 ) {
    	 if (column < 6 && row <7){

    	 IOWR_ALTERA_AVALON_PIO_DATA (HEX3_BASE, 0x03);
    	 for (y = 1; y < 31; y++) {

    			   					for (x = 1; x < 31; x++) {

    			   						if ( UART_RD_08 [ii]== 48) {

    			   								alt_up_pixel_buffer_dma_draw(hPB, ICON00[y][x],
    			   										(x + column * 32)+5, (y + row * 32)+15);

    			   						}
    			   						if (UART_RD_08 [ii] == 49) {

    			   								alt_up_pixel_buffer_dma_draw(hPB, ICON01[y][x],
    			   										(x + column * 32)+5, (y + row * 32)+15);

    			   						}
    			   						if (UART_RD_08 [ii] == 50) {

    			   								alt_up_pixel_buffer_dma_draw(hPB, ICON02[y][x],
    			   										(x + column * 32)+5, (y + row * 32)+15);

    			   						}
    			   						if (UART_RD_08 [ii]== 51) {

    			   								alt_up_pixel_buffer_dma_draw(hPB, ICON03[y][x],
    			   										(x + column * 32)+5, (y + row * 32)+15);

    			   						}
    			   						if (UART_RD_08 [ii] == 52) {

    			   								alt_up_pixel_buffer_dma_draw(hPB, ICON04[y][x],
    			   										(x + column * 32)+5, (y + row * 32)+15);

    			   						}
    			   						if (UART_RD_08 [ii] == 53) {

    			   								 alt_up_pixel_buffer_dma_draw(hPB, ICON05[y][x],
    			   								   		(x + column * 32)+5, (y + row * 32)+15);

    			   						}


    			   					}
    			   				}
    	 column++;
    	 }
    	 if(column == 6 && row <6){
    		row++;
    		column = 0;
    		IOWR_ALTERA_AVALON_PIO_DATA (HEX1_BASE, 0x55);
    	 }


    	 }
     if(count == 38){

         		 x_pos = UART_RD_08 [ii] - '0';

         	     }
     if(count == 39){
              	IOWR_ALTERA_AVALON_PIO_DATA (HEX2_BASE, 0x55);
              	 y_pos = UART_RD_08 [ii] - '0';

              	 alt_up_pixel_buffer_dma_draw_vline(hPB, (x_pos*32)+5, (y_pos*32)+47, (y_pos*32)+78, 0xA3,0);
              	 alt_up_pixel_buffer_dma_draw_vline(hPB, (x_pos*32)+36, (y_pos*32)+47, (y_pos*32)+78, 0xA3,0);

              	 alt_up_pixel_buffer_dma_draw_hline(hPB, (x_pos*32)+5,(x_pos*32)+36, (y_pos*32)+47, 0xA3,0);
              	 alt_up_pixel_buffer_dma_draw_hline(hPB, (x_pos*32)+5,(x_pos*32)+36, (y_pos*32)+78, 0xA3,0);
              	 Delay_Medium ();
                 if ( (xtemp !=  x_pos) || (ytemp != y_pos)){
               		IOWR_ALTERA_AVALON_PIO_DATA (HEX0_BASE, 0x55);
               		alt_up_pixel_buffer_dma_draw_vline(hPB, (xtemp*32)+5, (ytemp*32)+47, (ytemp*32)+78, 0x00,0);
               		alt_up_pixel_buffer_dma_draw_vline(hPB, (xtemp*32)+36, (ytemp*32)+47, (ytemp*32)+78, 0x00,0);
               		alt_up_pixel_buffer_dma_draw_hline(hPB, (xtemp*32)+5,(xtemp*32)+36, (ytemp*32)+47, 0X00,0);
               		alt_up_pixel_buffer_dma_draw_hline(hPB, (xtemp*32)+5,(xtemp*32)+36, (ytemp*32)+78, 0X00,0);
               		IOWR_ALTERA_AVALON_PIO_DATA (HEX5_BASE, 0x04);

                	}


              	 }
     if(count == 40){
              	IOWR_ALTERA_AVALON_PIO_DATA (HEX2_BASE, 0x55);
              	 y_pos = UART_RD_08 [ii] - '0';

              	 alt_up_pixel_buffer_dma_draw_vline(hPB, (x_pos*32)+5, (y_pos*32)+47, (y_pos*32)+78, 0xA3,0);
              	 alt_up_pixel_buffer_dma_draw_vline(hPB, (x_pos*32)+36, (y_pos*32)+47, (y_pos*32)+78, 0xA3,0);

              	 alt_up_pixel_buffer_dma_draw_hline(hPB, (x_pos*32)+5,(x_pos*32)+36, (y_pos*32)+47, 0xA3,0);
              	 alt_up_pixel_buffer_dma_draw_hline(hPB, (x_pos*32)+5,(x_pos*32)+36, (y_pos*32)+78, 0xA3,0);
                 if ( (xtemp !=  x_pos) || (ytemp != y_pos)){
               		IOWR_ALTERA_AVALON_PIO_DATA (HEX0_BASE, 0x55);
               		alt_up_pixel_buffer_dma_draw_vline(hPB, (xtemp*32)+5, (ytemp*32)+47, (ytemp*32)+78, 0x00,0);
               		alt_up_pixel_buffer_dma_draw_vline(hPB, (xtemp*32)+36, (ytemp*32)+47, (ytemp*32)+78, 0x00,0);
               		alt_up_pixel_buffer_dma_draw_hline(hPB, (xtemp*32)+5,(xtemp*32)+36, (ytemp*32)+47, 0X00,0);
               		alt_up_pixel_buffer_dma_draw_hline(hPB, (xtemp*32)+5,(xtemp*32)+36, (ytemp*32)+78, 0X00,0);
               		IOWR_ALTERA_AVALON_PIO_DATA (HEX5_BASE, 0x04);

                	}


              	 }

 }
    if(count == 43){
		 UART_ER = alt_up_rs232_write_data (hUART, 0x72);
		 Delay_Medium ();
	     row=1;
	     column=0;
	     count = 0;
      	 xtemp = x_pos;
         ytemp = y_pos;


    }
    }
   UART_FL_RD = 0;
   UART_FL_WR = 0;


  }

  return 0;
 }

