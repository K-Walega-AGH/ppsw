#include <LPC21xx.H>
#include "led.h"
#include "keyboard.h"
#include "Timery.h"


int main()

{
	//InitTimer0 ();
	InitTimer0Match0(25000);
	//LedInit();
	//KeyBoardInit();
	while (1)
	{
//		InitTimer0();
	//	StepLeft();
		//WaitOnTimer0(25000);
		

//WaitOnTimer0(25000);

WaitOnTimer0Match0();
		
	}

}
