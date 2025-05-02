#include <LPC21xx.H>


#define LED0_bm (1<<16) 
#define LED1_bm (1<<17) 
#define LED2_bm (1<<18) 
#define LED3_bm (1<<19) 

#define Button0_bm (1<<4) 
#define Button1_bm (1<<6) 
#define Button2_bm (1<<5) 
#define Button3_bm (1<<7) 

enum KeyboardState {RELASED,BUTTON_0,BUTTON_1,BUTTON_2,BUTTON_3};

enum LedTurn {RIGHT,LEFT};

void Delay(unsigned int czas)
{
	unsigned int	i=0;
	for(i = 0 ;i<czas*5455;i++);
}

void LedInit(void)
{
	IO1DIR=IO1DIR|(LED0_bm|LED1_bm|LED2_bm|LED3_bm);
	IO1SET= LED0_bm;
}

void KeyBoardInit(void)
{
	IO0DIR = IO0DIR &(~(Button0_bm|Button1_bm|Button2_bm|Button3_bm));
}

enum KeyboardState KeyboardRead(void)
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

void LedOn(unsigned char ucLedIndeks)
{
	
	IO1CLR = LED0_bm|LED1_bm|LED2_bm|LED3_bm;
	switch (ucLedIndeks)
	{
		case 0:
			IO1SET = LED0_bm;
			break;
		case 1:
			IO1SET = LED1_bm;
			break;
		case 2:
			IO1SET = LED2_bm;
			break;
		case 3:
			IO1SET = LED3_bm;
			break;
		default:
			break;
	}
}


void LedStep (enum LedTurn Direction)
{
	static unsigned int uiLed;
	if(Direction == LEFT)
	{
		uiLed++;
	}
	else
	{
		uiLed--;
	}
	LedOn(uiLed %4);
}

void LedStepLeft(void)
{
	LedStep(LEFT);
}

void LedStepRight(void)
{
	LedStep(RIGHT);
}

int main ()
{
	LedInit();
	KeyBoardInit();
	while (1)
	{
		Delay(100);
		switch (KeyboardRead())
		{
			case BUTTON_0:
				LedStep(RIGHT);
				break;
			case BUTTON_1:
				LedStep(LEFT);
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

