#include "uart.h"
#include "serwo.h"
#include "led.h"
#include "keyboard.h"
#include "strings.h"
#include "decode.h"
#include <LPC210X.H>



unsigned char ucStartChar = 0;


int main (){
	LedInit();
	UART_InitWithInt(9600);
	ServoInit(50);
	U0THR = ucStartChar;
		
	while (1){
	}
}

