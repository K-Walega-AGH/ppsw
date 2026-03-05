#include "serwo.h"
#include <LPC21xx.H>
#include "led.h"
#include "timerinterrupts.h"
#include "keyboard.h"
#define DETECTOR_bm (1<<10)
#define OFFSET_VALUE  12

struct Servo sServo;

void DetectorInit(){
	IO0DIR = IO0DIR&(~(DETECTOR_bm));
}


enum DetectorState {ACTIVE, INACTIVE};
enum DetectorState eReadDetector(){
	if((IO0PIN&DETECTOR_bm)==0){
		return ACTIVE;
	}
	else{
		return INACTIVE;
	}
}


 void Automat(void){
		switch(sServo.eState){
			case CALLIB:
				if(eReadDetector()==INACTIVE){
					LedStepRight();
					sServo.eState = CALLIB;
				}
				else{
					sServo.uiCurrentPosition=0;
					sServo.uiDesiredPosition=0;
					sServo.eState = IDLE;
				}
				break;
			case OFFSET:
				if(sServo.uiCurrentPosition == OFFSET_VALUE) 	
				{	
					sServo.uiCurrentPosition = 0;
					sServo.uiDesiredPosition=0;
					sServo.eState = IDLE;
				}
				else{
					sServo.uiCurrentPosition++;
					LedStepRight();
				} 
				break;
			case IDLE:
				if(sServo.uiCurrentPosition!=sServo.uiDesiredPosition){
					sServo.eState = IN_PROGRESS;
				}
				else{
					sServo.eState = IDLE;
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
void ServoInit(unsigned int uiServoFrequency){ 
	sServo.eState = CALLIB; 
	LedInit();
	Timer0Interrupts_Init((1000000/uiServoFrequency),&Automat); 

}
void ServoCallib(void){
	sServo.eState = CALLIB;
			while(sServo.eState == CALLIB)
	{
	
		}
}
void ServoGoTo(unsigned int uiPosition){
	sServo.uiDesiredPosition = uiPosition;
	
	sServo.eState = IN_PROGRESS;
	while(sServo.eState == IN_PROGRESS)
	{

		}
}
