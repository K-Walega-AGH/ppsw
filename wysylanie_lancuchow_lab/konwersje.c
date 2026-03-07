
#include "konwersje.h"

enum Result {OK, ERROR};

unsigned int uiValue;




void UIntToHexStr(unsigned int uiValue, char pcStr[]) {

    int ilicznikTetrady;
	
    unsigned int uitetrada;
 
    pcStr[0] = '0';
	
    pcStr[1] = 'x';

  
    for (ilicznikTetrady = 0; ilicznikTetrady < 8; ilicznikTetrady++) {
     
        uitetrada = (uiValue >> (4 * ilicznikTetrady)) & 0x0F;  
      
				if (uitetrada < 10) {
					
					pcStr[9 - ilicznikTetrady] = 	(uitetrada + '0');}
					
				else{
					
					pcStr[9 - ilicznikTetrady] = (uitetrada - 10 + 'A');
			}
    }
		   pcStr[10] = NULL;
	}


enum Result eHexStringToUInt(char pcStr[],unsigned int *puiValue)
{
		unsigned char ucLicznikZnakoWTablicy;
		unsigned char ucZnakWTablicy;
		unsigned char ucLiczba;
		*puiValue = 0;
	
	
	
		if((pcStr[0]!='0') || (pcStr[1]!='x') || (pcStr[2]==NULL))
		{
			return ERROR;
		}
		
		for ( ucLicznikZnakoWTablicy = 2; pcStr[ucLicznikZnakoWTablicy]!=NULL; ucLicznikZnakoWTablicy++)
		{
				ucZnakWTablicy = pcStr[ucLicznikZnakoWTablicy];
			
				if(ucLicznikZnakoWTablicy > 6)
				{
						return ERROR;
				}
				
				*puiValue = *puiValue << 4;
			
				if ((pcStr[ucLicznikZnakoWTablicy] >= '0') && (pcStr[ucLicznikZnakoWTablicy] <= '9'))
				{
							ucLiczba = ucZnakWTablicy - '0';
				}
				else if ((pcStr[ucLicznikZnakoWTablicy] >= 'A') && (pcStr[ucLicznikZnakoWTablicy] <= 'F'))
				{
							ucLiczba = ucZnakWTablicy - 'A' + 10;
				}
				else 
				{
					return ERROR;
				}
				
				*puiValue = *puiValue | ucLiczba; 
		}
			
		return OK;
}



void AppendUIntToString(unsigned int uiValue, char pcDestinationStr[]){

unsigned char ucLicznikZnaku;

for(ucLicznikZnaku=0; pcDestinationStr[ucLicznikZnaku]!=NULL; ucLicznikZnaku++){}

UIntToHexStr(uiValue, &pcDestinationStr[ucLicznikZnaku]);
}



