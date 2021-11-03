/*
 *
 * ENGN2085
 * 2/5/2020
 * Project phase 2
 */
    #include "stdlib.h"
    #include "stdbool.h"
    #include "alt_types.h"
    #include "system.h"
    #include "altera_avalon_pio_regs.h"
	#include "altera_up_avalon_video_pixel_buffer_dma.h"
	#include <unistd.h>
	#include "ICON.h"




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




	int column, row, y, x;
	unsigned int u32Seed = 1;
	unsigned int ss;
	u32Seed = IORD_ALTERA_AVALON_PIO_DATA(SWITCH_BASE);
	srand(u32Seed);
	for (row = 1; row < 7; row++) {
		for (column = 1; column < 7; column++) {
			ss = rand() % 10;


			for (y = 0; y < 32; y++) {

				for (x = 0; x < 32; x++) {

					if (ss == 0) {

							alt_up_pixel_buffer_dma_draw(hPB, ICON00[y][x],
									x + column * 32, y + row * 32);

					}
					if (ss == 1) {

							alt_up_pixel_buffer_dma_draw(hPB, ICON01[y][x],
									x + column * 32, y + row * 32);

					}
					if (ss == 2) {

							alt_up_pixel_buffer_dma_draw(hPB, ICON02[y][x],
									x + column * 32, y + row * 32);

					}
					if (ss == 3) {

							alt_up_pixel_buffer_dma_draw(hPB, ICON03[y][x],
									x + column * 32, y + row * 32);

					}
					if (ss == 4) {

							alt_up_pixel_buffer_dma_draw(hPB, ICON04[y][x],
									x + column * 32, y + row * 32);

					}
					if (ss == 5) {

							alt_up_pixel_buffer_dma_draw(hPB, ICON05[y][x],
									x + column * 32, y + row * 32);

					}
					if (ss == 6) {

							alt_up_pixel_buffer_dma_draw(hPB, ICON06[y][x],
									x + column * 32, y + row * 32);

					}
					if (ss == 7) {

							alt_up_pixel_buffer_dma_draw(hPB, ICON07[y][x],
									x + column * 32, y + row * 32);

					}
					if (ss == 8) {

							alt_up_pixel_buffer_dma_draw(hPB, ICON08[y][x],
									x + column * 32, y + row * 32);

					}
					if (ss == 9) {

							alt_up_pixel_buffer_dma_draw(hPB, ICON09[y][x],
									x + column * 32, y + row * 32);

					}

				}
			}

		}
	}


			}
