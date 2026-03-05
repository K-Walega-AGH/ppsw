#ifndef DECODE_H
#define DECODE_H

#define NULL 0
#define MAX_TOKEN_NR 3
#define MAX_KEYWORD_STRING_LTH 10
#define MAX_KEYWORD_NR 2



typedef enum TokenType {KEYWORD, NUMBER, STRING} TokenType;
typedef enum KeywordCode {CB,	GT} KeywordCode;

typedef union TokenValue {
	enum KeywordCode eKeyword;
	unsigned int uiNumber;
	char * pcString;
} TokenValue;



typedef struct Token {
	enum TokenType eType;
	union TokenValue uValue; 
} Token;

typedef struct Keyword {
	enum KeywordCode eCode;
	char cString[MAX_KEYWORD_STRING_LTH + 1];
} Keyword;

extern struct Keyword asKeywordList[MAX_KEYWORD_NR];

extern unsigned char ucTokenNr;
extern struct Token asToken[MAX_TOKEN_NR];



void DecodeMsg(char *pcString);

#endif
