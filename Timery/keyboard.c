#include <LPC21xx.H>
#include "keyboard.h"

#define Button0_bm (1<<4) 
#define Button1_bm (1<<6) 
#define Button2_bm (1<<5) 
#define Button3_bm (1<<7) 

void KeyBoardInit(void)
{
	IO0DIR = IO0DIR &(~(Button0_bm|Button1_bm|Button2_bm|Button3_bm));
}
	
enum KeyboardState eKeyboardRead(void)
{
	if((IO0PIN&Button0_bm) == 0)
	{
		return BUTTON_0;
	}
	else if((IO0PIN&Button1_bm) == 0)
	{
		return BUTTON_1;
	}
	else if((IO0PIN&Button2_bm) == 0)
	{
		return BUTTON_2;
	}
	else if((IO0PIN&Button3_bm) == 0)
	{
		return BUTTON_3;
	}	
	return RELASED;
	
}
