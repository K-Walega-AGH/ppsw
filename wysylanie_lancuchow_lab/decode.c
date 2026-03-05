#include "decode.h"
#include "strings.h"



enum State {TOKEN, DELIMITER};

enum Result eHexStringToUInt(char pcStr[],unsigned int *puiValue);
enum Result {OK,ERROR};

struct Keyword asKeywordList[MAX_KEYWORD_NR] = {
	{CB, "callib"},
	{GT, "goto"}
};
unsigned char ucTokenNr;
struct Token asToken[MAX_TOKEN_NR];

//Funkcje

unsigned char ucFindTokensInString (char *pcString) {
	
	unsigned char ucCharCounter;
	unsigned char ucCurrentChar;
	enum State eState = DELIMITER;
	ucTokenNr = 0;
	
	for(ucCharCounter = 0;;ucCharCounter++) {
		
		ucCurrentChar = pcString[ucCharCounter];
		switch(eState) {
			case DELIMITER:
				if(ucCurrentChar == NULL) {
					return ucTokenNr;
				} else if(ucCurrentChar != ' ') {
					eState = TOKEN;
					asToken[ucTokenNr].uValue.pcString = pcString + ucCharCounter;
					ucTokenNr++;
				} else {
					break;
				}
			case TOKEN:
				if(ucTokenNr == MAX_TOKEN_NR) {
					return ucTokenNr;
				}	else if(ucCurrentChar == NULL) {
					return ucTokenNr;
				} else if(ucCurrentChar == ' ') {
					eState = DELIMITER;
				}
				break;
		}
	}
}

enum Result eStringToKeyword (char pcStr[], enum KeywordCode *peKeywordCode) {
	
	unsigned char ucKeywordCounter;
	
	for(ucKeywordCounter = 0;ucKeywordCounter < MAX_KEYWORD_NR;ucKeywordCounter++) {
		if(eCompareString(pcStr, asKeywordList[ucKeywordCounter].cString) == EQUAL) {
			*peKeywordCode = asKeywordList[ucKeywordCounter].eCode;
			return OK;
		}
	}
	return ERROR;
}

void DecodeTokens(void) {
	
	unsigned char ucTokenCounter;
	struct Token *psCurrentToken;
	
	for(ucTokenCounter = 0; ucTokenCounter < ucTokenNr; ucTokenCounter++) {
		psCurrentToken = &asToken[ucTokenCounter];
		if(eStringToKeyword(psCurrentToken -> uValue.pcString, &psCurrentToken -> uValue.eKeyword) == OK) { //&psCurrentToken -> uValue.eKeyword tu masz przekazanie wartosci adresu do wnetrza funkcji i w funkcji wew przez wszkaznik przypisujesz mu wartosc
			psCurrentToken -> eType = KEYWORD;
		} else if(eHexStringToUInt(psCurrentToken -> uValue.pcString, &psCurrentToken -> uValue.uiNumber) == OK) {
			psCurrentToken -> eType = NUMBER;
		} else {
			psCurrentToken -> eType = STRING;
		}
	}
}

void DecodeMsg(char *pcString) {
	ucFindTokensInString(pcString);
	ReplaceCharactersInString(pcString, ' ', NULL);
	DecodeTokens();
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




















