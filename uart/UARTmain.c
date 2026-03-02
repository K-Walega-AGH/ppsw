#include "uart.h"
#include "serwo.h"
#include "led.h"
#include "keyboard.h"

int main (){
	extern char cOdebranyZnak;
	unsigned char ucInfiniteGoTo =1;
		LedInit();
	UART_InitWithInt(9600);
		ServoInit(50);

		
	
 while (1)
    {
        switch (cOdebranyZnak)
        {
            case '1':	
							ServoGoTo(12*ucInfiniteGoTo);
							cOdebranyZnak = '2';
							ucInfiniteGoTo++;
            break;
            case '2':
            break;
            case '3':
            break;
            case '4':
                break;
            case 'c':
							ServoCallib();
						ucInfiniteGoTo =1;
            break;
            default:
            break;
        }
				
		switch(eKeyboardRead())
		{
			case BUTTON_0:
				ServoCallib();
				break;
			case BUTTON_1:
				ServoGoTo(12);
				break;
			case BUTTON_2:
				ServoGoTo(24);
				break;
			case BUTTON_3:
				ServoGoTo(36);
				break;
			case RELASED:
				break;
		}
      
	}
}

