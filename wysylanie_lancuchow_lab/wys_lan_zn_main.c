#include "uart.h"
#include "strings.h"
#include "decode.h"
#include "konwersje.h"
#include "serwo.h"
#include "timerinterrupts.h"
#include "led.h"


#define RED     "\x1B[31m"
#define GREEN   "\x1B[32m"
#define YELLOW  "\x1B[33m"
#define RESET   "\x1B[0m"



struct Watch { 
	unsigned char ucMinutes,ucSecconds; 
	unsigned char fSeccondsValueChanged,fMinutesValueChanged;
}Watch;

volatile  struct Watch sWatch;



void WatchUpdate(){
	sWatch.ucSecconds++;
	sWatch.fSeccondsValueChanged = 1;
	if(sWatch.ucSecconds == 60){
		sWatch.ucSecconds = 0;
		sWatch.ucMinutes++;
		sWatch.fMinutesValueChanged = 1;
	}



}


char acReciveBuffer[64];
char acMessageBuffer[64];
char acHexKeeper[12];
char acCalcKeeper[12];

char fCalcValueChanged;
char fWrongCommand;
char fHelp;

int main (){
	LedInit();
	ServoInit(50);
	UART_InitWithInt(9600);
	Timer1Interrupts_Init(1000000,&WatchUpdate);
		
while (1){
		if(eReciever_GetStatus() == READY){
			Reciever_GetStringCopy(acReciveBuffer);
			DecodeMsg(acReciveBuffer);
			if(ucTokenNr > 0) {
					switch(asToken[0].uValue.eKeyword) {
						case CL:
							if(ucTokenNr > 1){
								fCalcValueChanged = 1;
							}
							else{
								fWrongCommand = 1;
							}
							break;
						case CB:
							ServoCallib();
							break;
						case GT:
							ServoGoTo(asToken[1].uValue.uiNumber);
							break;
						case HP:
							fHelp = 1;
							break;
						default:
							fWrongCommand = 1;
							break;
					}
				}
		} 

		if(sTransmiterBuffer.eStatus == FREE){


				if(fCalcValueChanged){

						fCalcValueChanged = 0;

						acMessageBuffer[0] = '\0';
						AppendString(GREEN, acMessageBuffer);
						AppendString("calc ", acMessageBuffer);
						UIntToHexStr((asToken[1].uValue.uiNumber * 2), acCalcKeeper);
						AppendString(acCalcKeeper, acMessageBuffer);
					  AppendString(RESET, acMessageBuffer);
						AppendString("\n", acMessageBuffer);

						Transmiter_SendString(acMessageBuffer);
				}

				else if(sWatch.fSeccondsValueChanged){

						acMessageBuffer[0] = '\0';

						sWatch.fSeccondsValueChanged = 0;

						AppendString("sec: ", acMessageBuffer);

						UIntToHexStr(sWatch.ucSecconds, acHexKeeper);
						AppendString(acHexKeeper, acMessageBuffer);
						AppendString("\n", acMessageBuffer);
						Transmiter_SendString(acMessageBuffer);
				}
				
				else if(sWatch.fMinutesValueChanged){
								
								acMessageBuffer[0] = '\0';
								sWatch.fMinutesValueChanged = 0;

								AppendString("min: ", acMessageBuffer);

								UIntToHexStr(sWatch.ucMinutes, acHexKeeper);
								AppendString(acHexKeeper, acMessageBuffer);
								AppendString("\n", acMessageBuffer);
						    Transmiter_SendString(acMessageBuffer);
				}
				
				else if(fWrongCommand == 1){
					acMessageBuffer[0] = '\0';
					fWrongCommand = 0;
					AppendString(RED, acMessageBuffer);
					AppendString("Wrong command. Try --help", acMessageBuffer);		
					AppendString(RESET, acMessageBuffer);
					AppendString("\n", acMessageBuffer);
					Transmiter_SendString(acMessageBuffer);					
				}

				else if(fHelp == 1){
					acMessageBuffer[0] = '\0';
					fHelp = 0;
					AppendString(YELLOW, acMessageBuffer);
					AppendString("list of commands: goto,calc,callib", acMessageBuffer);		
					AppendString(RESET, acMessageBuffer);
					AppendString("\n", acMessageBuffer);
				  Transmiter_SendString(acMessageBuffer);
				}
		}
	}
}


