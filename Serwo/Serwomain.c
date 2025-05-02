#include <LPC21xx.H>
#include "led.h"
#include "timerinterrupts.h"
#include "keyboard.h"
#define DETECTOR_bm (1<<10)
enum ServoState {CALLIB, IDLE, IN_PROGRESS};
struct Servo{
	enum ServoState eState;
	unsigned int uiCurrentPosition; //biezaca pozycja
	unsigned int uiDesiredPosition; //do ustawiania pozycji lustra //pozycja która servo ma osiagnac
};
struct Servo sServo; //zmienna globalna do przechowywania aktualnego stanu automatu i serwomechanizmu
// zawsze po starcie programu serwomechanizm wykonuje procedure kalibracji tj. ustawil tarcze w tej samej pozycji.
void DetectorInit(){//ustawia pin podlaczony do detektora (P0.10) jako wejsciowy
	IO0DIR = IO0DIR&(~(DETECTOR_bm));
}
enum DetectorState {ACTIVE, INACTIVE};
// zwraca stan ACTIVE jezeli marker na tarczy znajduje sie nad detektorem lub INACTIVE w przeciwnym przypadku.
enum DetectorState eReadDetector(){
	if((IO0PIN&DETECTOR_bm)==0){
		return ACTIVE;
	}
	else{
		return INACTIVE;
	}
}
void Automat(void){ //sklada sie z 3 stanów C,I,I_P i korzysta ze zmiennych currpos i desiredpos
		switch(sServo.eState){
// silnik obraca sie przeciwnie do ruchu wskazówek zegara do momentu przysloniecia przez pletwe szczeliny w transoptorze
			case CALLIB:
				if(eReadDetector()==INACTIVE){ //ustawienie serwom ech w pozycji 0
					LedStepRight();
					sServo.eState = CALLIB;
				}
				else{
					sServo.uiCurrentPosition=0;//wyzerowanie zmiennych
					sServo.uiDesiredPosition=0;
					sServo.eState = IDLE; //przejscie do stanu idle
				}
				break;
			case IDLE: //jesli aktualna inna niz oczekiwana
				if(sServo.uiCurrentPosition!=sServo.uiDesiredPosition){ 
					sServo.eState = IN_PROGRESS; //to przechodzimy do In progress
				}
				else{
					sServo.eState = IDLE; //jak nie to dalej czekamy
				}
				break;

			case IN_PROGRESS:
				if(sServo.uiCurrentPosition<sServo.uiDesiredPosition){
					LedStepRight();
					sServo.uiCurrentPosition++;
					sServo.eState = IN_PROGRESS;
				}
				else if(sServo.uiCurrentPosition>sServo.uiDesiredPosition){
					LedStepLeft();
					sServo.uiCurrentPosition--;
					sServo.eState = IN_PROGRESS;
				}
				else{
					sServo.eState = IDLE;
				}
				default:
				break;
			}
		}
int main (){
	LedInit();
	KeyBoardInit();
	DetectorInit();
	Timer0Interrupts_Init(20000,&Automat);
	while(1){
		
	 	if(eKeyboardRead()==BUTTON_0){
			sServo.eState = CALLIB;
		}
		else if(eKeyboardRead()==BUTTON_1){
			sServo.uiDesiredPosition = 12;
		}
		else if(eKeyboardRead()==BUTTON_2){
			sServo.uiDesiredPosition = 24;
		}
		else if(eKeyboardRead()==BUTTON_3){
			sServo.uiDesiredPosition = 36;
		}
	}
}
