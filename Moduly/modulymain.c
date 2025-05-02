#include <LPC21xx.H>
#include "led.h"
#include "keyboard.h"

void Delay(unsigned int czas)
{
	unsigned int	uiVariableforLoop=0;
	for(uiVariableforLoop = 0 ;uiVariableforLoop<czas*5455;uiVariableforLoop++);
}

int main ()
{
	LedInit();
	KeyBoardInit();
	while (1)
	{
		Delay(100);
		switch (eKeyboardRead())
		{
			case BUTTON_0:
				LedStepRight();
				break;
			case BUTTON_1:
				LedStepLeft();
				break;
			case BUTTON_2:
				break;
			case BUTTON_3:
				break;
			case RELASED:
				break;
			default:
				break;
			
		}
		
		
		
	}
}

