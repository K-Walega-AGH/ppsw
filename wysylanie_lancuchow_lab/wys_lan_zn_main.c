#include "uart.h"
#include "serwo.h"
#include "led.h"
#include "keyboard.h"
#include "strings.h"
#include "decode.h"
#include <LPC210X.H>



unsigned char ucStartChar = 0;


int main (){
	UART_InitWithInt(9600);
	Transmiter_SendString("test123");
		
	while (1){
	}
}

