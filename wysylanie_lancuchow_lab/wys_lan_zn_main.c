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

char cHexKeeper[36];
char cTemp[12];

int main (){
	UART_InitWithInt(9600);
	Timer0Interrupts_Init(1000000,WatchUpdate);
		
while (1){
    if(sTransmiterBuffer.eStatus == FREE){

        if(sWatch.fSeccondsValueChanged){

            cHexKeeper[0] = '\0';   

            sWatch.fSeccondsValueChanged = 0;

            AppendString("sec: ", cHexKeeper);

            UIntToHexStr(sWatch.ucSecconds, cTemp);
            AppendString(cTemp, cHexKeeper);

            if(sWatch.fMinutesValueChanged){

                sWatch.fMinutesValueChanged = 0;

                AppendString(" min: ", cHexKeeper);

                UIntToHexStr(sWatch.ucMinutes, cTemp);
                AppendString(cTemp, cHexKeeper);
            }

            AppendString("\n", cHexKeeper);

            Transmiter_SendString(cHexKeeper);
        }
    }
}
}


