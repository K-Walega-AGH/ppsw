
#include "serwo.h"
#include "keyboard.h"

int main (){
	KeyBoardInit();
	ServoInit(50);
	while(1){
	 	if(eKeyboardRead()==BUTTON_0){
			ServoCallib();
		}
		else if(eKeyboardRead()==BUTTON_1){
			ServoGoTo(12);
		}
		else if(eKeyboardRead()==BUTTON_2){
			ServoGoTo(24);
		}
		else if(eKeyboardRead()==BUTTON_3){
			ServoGoTo(36);
		}
	}
}

