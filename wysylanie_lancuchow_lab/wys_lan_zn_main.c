#include "uart.h"
#include "serwo.h"
#include "led.h"
#include "keyboard.h"
#include "strings.h"
#include "decode.h"
#include "konwersje.h"
#include <LPC210X.H>



void Delay (unsigned int delay){
	unsigned int i;
	for( i = 0; i < (delay * 7500); ++i){

		};

}


unsigned char ucStartChar = 0;
char cHexKeeper[32] = "licznik: ";
int main (){
	UART_InitWithInt(9600);

		
	while (1){
		if(sTransmiterBuffer.eStatus == FREE){
			UIntToHexStr(ucStartChar,&cHexKeeper[9]);
			AppendString("\n",cHexKeeper);
			Transmiter_SendString(cHexKeeper);
			ucStartChar++;
		}
		Delay(1000);
	}
}


