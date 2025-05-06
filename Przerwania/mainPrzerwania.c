#include "timerinterrupts.h"
#include "led.h"
#include "keyboard.h"


void Automat(void){
	static enum LedState eLedState = LED_STAY;
		switch(eLedState){
			case LED_STAY:
				if(eKeyboardRead()==BUTTON_0){
					eLedState= LED_LEFT;}
				else if(eKeyboardRead()==BUTTON_2){
					eLedState = LED_RIGHT;}
				else{
					eLedState = LED_STAY; }
				break;
			case LED_LEFT :
				LedStepLeft();
				if(eKeyboardRead()==BUTTON_1){
					eLedState = LED_STAY; }
				else{
					eLedState = LED_LEFT; }
				break;
			case LED_RIGHT :
				LedStepRight();
				if(eKeyboardRead()==BUTTON_1){
					eLedState = LED_STAY; }
				else{
					eLedState = LED_RIGHT; }
				break;
			default:
				break; }
}
			

/**********************************************/
int main (){
	unsigned int iMainLoopCtr;
	Timer0Interrupts_Init(20000,&Automat);
	LedInit();
	KeyBoardInit();
	while(1){
	 	iMainLoopCtr++;
		iMainLoopCtr++;
		iMainLoopCtr++;
		iMainLoopCtr++;
		iMainLoopCtr++;
	}
}

//git test
