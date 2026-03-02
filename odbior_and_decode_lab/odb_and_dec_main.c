#include "uart.h"
#include "serwo.h"
#include "led.h"
#include "keyboard.h"

extern struct RecieverBuffer sRecieverBuffer;


int main (){
	extern char cOdebranyZnak;
//		LedInit();
//	UART_InitWithInt(9600);
//		ServoInit(50);
		
	Reciever_PutCharacterToBuffer ('k');
	Reciever_PutCharacterToBuffer ('o');
	Reciever_PutCharacterToBuffer ('d');
	Reciever_PutCharacterToBuffer (TERMINATOR);
	Reciever_PutCharacterToBuffer ('k');
	Reciever_PutCharacterToBuffer ('o');
	Reciever_PutCharacterToBuffer ('d');
	Reciever_PutCharacterToBuffer ('1');
	Reciever_PutCharacterToBuffer (TERMINATOR);
	
		/*
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
	 */ 
}

