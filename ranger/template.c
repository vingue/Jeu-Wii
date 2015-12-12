#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <gccore.h>
#include <wiiuse/wpad.h>
#include <grrlib.h>

#include <icon_png.h>
#include <palm_png.h>
#include <palmeraie_png.h>
#include <billet_png.h>
#include <menu1_png.h>
#include <menu2_png.h>
#include <menu5_png.h>
#include <menu6_png.h>


GXRModeObj* IR_Init() {
    GXRModeObj *rmode=NULL;
    rmode=VIDEO_GetPreferredMode(NULL);
    return rmode;
}

//---------------------------------------------------------------------------------
int main(int argc, char **argv) {
//---------------------------------------------------------------------------------
    GRRLIB_Init();

	WPAD_Init();

	GXRModeObj *rmode=IR_Init();
	WPAD_SetVRes(WPAD_CHAN_ALL, rmode->fbWidth,rmode->xfbHeight);

	WPAD_SetDataFormat(WPAD_CHAN_0,WPAD_FMT_BTNS_ACC_IR);
	GRRLIB_SetBackgroundColour(0x00, 0x00, 0x00, 0xFF);
	// Wait for Video setup to complete
	VIDEO_WaitVSync();

	//menu principal
	GRRLIB_texImg* pic1;
	pic1=GRRLIB_LoadTexture(icon_png);
	GRRLIB_texImg* pic2;
	pic2=GRRLIB_LoadTexture(palm_png);
	GRRLIB_texImg* pic3;
	pic3=GRRLIB_LoadTexture(palmeraie_png);
	GRRLIB_texImg* menu1;
	menu1=GRRLIB_LoadTexture(menu1_png);
	GRRLIB_texImg* menu2;
	menu2=GRRLIB_LoadTexture(menu2_png);
	GRRLIB_texImg* menu5;
	menu5=GRRLIB_LoadTexture(menu5_png);
	GRRLIB_texImg* menu6;
	menu6=GRRLIB_LoadTexture(menu6_png);
	GRRLIB_texImg* menuj1;

	int i;
	for(i=0;i<255;i++) {

        GRRLIB_DrawImg(0,0,pic1,0,1,1,0xFFFFFFFF|i);
        GRRLIB_Render();
		}
	GRRLIB_FreeTexture(pic1);
	GRRLIB_texImg* pointer=GRRLIB_LoadTexture(billet_png);
	GRRLIB_SetMidHandle(pointer,true);
	ir_t irPointer;
	while(1) {

		// Call WPAD_ScanPads each loop, this reads the latest controller states
		WPAD_ScanPads();
        WPAD_IR(WPAD_CHAN_0, &irPointer);
        GRRLIB_DrawImg(0,0,pic2,0,1,1,0xFFFFFFFF);
        GRRLIB_DrawImg(270,200,menu1,0,1,1,0xFFFFFFFF);
        GRRLIB_DrawImg(270,350,menu5,0,1,1,0xFFFFFFFF);
        //GRRLIB_DrawImg( irPointer.x, irPointer.y, pointer, 0, 1, 1, RGBA(255, 255, 255, 255) );
         if(irPointer.x>270 && irPointer.x<570 && irPointer.y>200 && irPointer.y<300) // PLAY
      {
         GRRLIB_DrawImg(270,200,menu2,0,1,1,0xFFFFFFFF);
         if(WPAD_ButtonsDown(0) & WPAD_BUTTON_A) {
         }
      }
         if(irPointer.x>270 && irPointer.x<570 && irPointer.y>350 && irPointer.y<450) // ABOUT
      {
         GRRLIB_DrawImg(270,350,menu6,0,1,1,0xFFFFFFFF);
         if(WPAD_ButtonsDown(0) & WPAD_BUTTON_A)
         {
            exit(0);
         }
      }
	    GRRLIB_DrawImg(irPointer.x, irPointer.y, pointer, 0, 1, 1, 0xFFFFFFFF);

		// We return to the launcher application via exit
		if ( WPAD_ButtonsDown(0) & WPAD_BUTTON_HOME ) exit(0);
		GRRLIB_Render();
	}
	GRRLIB_FreeTexture(pic2);
	GRRLIB_FreeTexture(menu1);
	GRRLIB_FreeTexture(menu5);
	GRRLIB_FreeTexture(menu2);
	GRRLIB_FreeTexture(menu6);

	return 0;
}
