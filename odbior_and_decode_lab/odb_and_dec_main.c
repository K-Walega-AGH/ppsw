#include "uart.h"
#include "serwo.h"
#include "led.h"
#include "keyboard.h"
#include "strings.h"


int main (){
	char acHelpArray[6];
	LedInit();
	UART_InitWithInt(9600);
	ServoInit(50);
		
 while (1){
	if(eReciever_GetStatus() == READY){
			Reciever_GetStringCopy(acHelpArray);
		  if(eCompareString(acHelpArray,"calib") == EQUAL){
				ServoCallib();
			}
			else if (eCompareString(acHelpArray,"left") == EQUAL){
				ServoGoTo(50);
			}
			else if (eCompareString(acHelpArray,"right") == EQUAL){
				ServoGoTo(150);
			}
		} 
	}
}

