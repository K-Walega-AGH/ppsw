#define NULL 0
#include "strings.h"




void CopyString(char pcSource[], char pcDestination[])
{
	unsigned char ucLicznik;

	for (ucLicznik=0;pcSource[ucLicznik] != NULL;ucLicznik++)
	{
		pcDestination[ucLicznik] = pcSource[ucLicznik];
	}
	pcDestination[ucLicznik] = NULL;
}






enum CompResult eCompareString(char pcStr1[], char pcStr2[])
{
	unsigned char ucNumerZnakuWLancuchu;
	
	for (ucNumerZnakuWLancuchu = 0; !(pcStr1[ucNumerZnakuWLancuchu] == NULL && pcStr2[ucNumerZnakuWLancuchu] == NULL)  ;ucNumerZnakuWLancuchu++ )
	{
		if(pcStr1[ucNumerZnakuWLancuchu] != pcStr2[ucNumerZnakuWLancuchu])
			
			{
				return DIFFERENT;
				
			}
		
			
	}

	return EQUAL;

}



void AppendString (char pcSourceStr[],char pcDestinationStr[])
{
	unsigned char ucLicznikDrugi;
	
	unsigned char ucLicznikDlaWarunkuSourca = 0;
	
		for	(ucLicznikDrugi = 9; pcSourceStr[ucLicznikDlaWarunkuSourca] != NULL; ucLicznikDrugi++,ucLicznikDlaWarunkuSourca++)
			{
				pcDestinationStr[ucLicznikDrugi] = pcSourceStr[ucLicznikDlaWarunkuSourca];
			}
	pcDestinationStr[ucLicznikDrugi] = NULL;
}


void ReplaceCharactersInString(char pcString[],char cOldChar,char cNewChar)
{
	unsigned char ucNumerZnaku;
	
		for(ucNumerZnaku = 0; pcString[ucNumerZnaku] != NULL; ucNumerZnaku++)
	{
		if
			(pcString[ucNumerZnaku] == cOldChar)
		{
			 pcString[ucNumerZnaku] = cNewChar;
		}
	}
	
}


