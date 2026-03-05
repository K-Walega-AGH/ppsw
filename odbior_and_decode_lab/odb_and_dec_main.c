#include "uart.h"
#include "serwo.h"
#include "led.h"
#include "keyboard.h"
#include "strings.h"
#include "decode.h"




int main (){
	char acHelpArray[16];
	LedInit();
	UART_InitWithInt(9600);
	ServoInit(50);
		
 while (1){

	if(eReciever_GetStatus() == READY){
			Reciever_GetStringCopy(acHelpArray);
			DecodeMsg(acHelpArray);
			if(ucTokenNr > 0) {
					switch(asToken[0].uValue.eKeyword) {
						case CB:
							ServoCallib();
							break;

						case GT:
							ServoGoTo(asToken[1].uValue.uiNumber);
							break;
						default:
							break;
					}
				}
		} 
	}
}

