#include <LPC21xx.H>
#include "led.h"
#include "keyboard.h"

enum LedState eLedState = LED_STAY;



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
		switch (eLedState)
		{
			case LED_RIGHT:
				if (eKeyboardRead() == BUTTON_1)
					{
						eLedState = LED_STAY;
						break;
					}
				else
				{
					LedStepRight();
					break;
				}
				
			case LED_STAY:
				if (eKeyboardRead() == BUTTON_2)
				{
					eLedState = LED_RIGHT;
					break;
				}
				else if (eKeyboardRead() == BUTTON_0)
				{
					eLedState = LED_LEFT;
					break;
				}
				else
					break;
				
			case LED_LEFT:
				if (eKeyboardRead() == BUTTON_1)
				{
					eLedState = LED_STAY;
					break;
				}
				else
					{
						LedStepLeft();
					}
					break;				
			default:
				break;

			
		}
		
		
		
	}
}
