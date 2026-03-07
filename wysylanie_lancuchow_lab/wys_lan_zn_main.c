#include "uart.h"
#include "strings.h"
#include "decode.h"
#include "konwersje.h"

#include "timerinterrupts.h"

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


char acReciveBuffer[16];
char acMessageBuffer[36];
char acHexKeeper[12];
char acCalcKeeper[12];

char fCalcValueChanged;


int main (){
	UART_InitWithInt(9600);
	Timer0Interrupts_Init(1000000,WatchUpdate);
		
while (1){
		if(eReciever_GetStatus() == READY){
			Reciever_GetStringCopy(acReciveBuffer);
			DecodeMsg(acReciveBuffer);
			if(ucTokenNr > 0) {
					switch(asToken[0].uValue.eKeyword) {
						case CL:

						  fCalcValueChanged = 1;
							break;
						default:
							break;
					}
				}
		} 

		if(sTransmiterBuffer.eStatus == FREE){


				if(fCalcValueChanged){

						fCalcValueChanged = 0;

						acMessageBuffer[0] = '\0';

						AppendString("calc ", acMessageBuffer);
						UIntToHexStr((asToken[1].uValue.uiNumber * 2), acCalcKeeper);
						AppendString(acCalcKeeper, acMessageBuffer);
						AppendString("\n", acMessageBuffer);

						Transmiter_SendString(acMessageBuffer);
				}

				else if(sWatch.fSeccondsValueChanged){

						acMessageBuffer[0] = '\0';

						sWatch.fSeccondsValueChanged = 0;

						AppendString("sec: ", acMessageBuffer);

						UIntToHexStr(sWatch.ucSecconds, acHexKeeper);
						AppendString(acHexKeeper, acMessageBuffer);

						if(sWatch.fMinutesValueChanged){

								sWatch.fMinutesValueChanged = 0;

								AppendString(" min: ", acMessageBuffer);

								UIntToHexStr(sWatch.ucMinutes, acHexKeeper);
								AppendString(acHexKeeper, acMessageBuffer);
						}

						AppendString("\n", acMessageBuffer);

						Transmiter_SendString(acMessageBuffer);
				}
}
	}
}


