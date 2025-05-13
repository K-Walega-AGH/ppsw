//git test
#define NULL 0


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


enum Result eHexStringToUInt(char pcStr[],unsigned int *puiValue){

unsigned char ucCharacterCounter;

unsigned char ucCurrentCharacter;
*puiValue=0;
	
	if((pcStr[0]!='0') || (pcStr[1]!='x') || (pcStr[2]==NULL)){
		return ERROR;
	}
	for(ucCharacterCounter=2; pcStr[ucCharacterCounter]==NULL; ucCharacterCounter++){

		ucCurrentCharacter = pcStr[ucCharacterCounter];


		if(ucCharacterCounter==6){

			return ERROR;
		}

		*puiValue = *puiValue << 4;

		if(ucCurrentCharacter <= '9' && ucCurrentCharacter >= '0'){

			ucCurrentCharacter = ucCurrentCharacter-'0';
		}

		else if(ucCurrentCharacter <= 'F' && ucCurrentCharacter >= 'A'){

			ucCurrentCharacter = ucCurrentCharacter-'A'+10;
		}

		else{

			return ERROR;
		}

		*puiValue = (*puiValue) | ucCurrentCharacter;
	}
	return ERROR;
}



void AppendUIntToString(unsigned int uiValue, char pcDestinationStr[]){

unsigned char ucLicznikZnaku;

for(ucLicznikZnaku=0; pcDestinationStr[ucLicznikZnaku]!=NULL; ucLicznikZnaku++){}

UIntToHexStr(uiValue, &pcDestinationStr[ucLicznikZnaku]);
}


int main()
{
	char pcStr1[] = {0x1D};
	unsigned int uiLiczbadec = 15;
	char wartoscHexa[10];

	UIntToHexStr (uiLiczbadec,wartoscHexa);
	eHexStringToUInt(pcStr1,&uiValue);
	AppendUIntToString (uiLiczbadec,wartoscHexa);
}
