
#define NULL 0
#define MAX_TOKEN_NR 3
#define MAX_KEYWORD_STRING_LTH 10
#define MAX_KEYWORD_NR 3


enum Result {OK,ERROR};

typedef enum KeywordCode {LD, ST, RST} KeywordCode;

typedef union TokenValue {
	enum KeywordCode eKeyword;
	unsigned int uiNumber;
	char * pcString;
} TokenValue;

typedef enum TokenType {KEYWORD, NUMBER, STRING} TokenType;

typedef struct Token {
	enum TokenType eType;
	union TokenValue uValue; 
} Token;

typedef struct Keyword {
	enum KeywordCode eCode;
	char cString[MAX_KEYWORD_STRING_LTH + 1];
} Keyword;

struct Keyword asKeywordList[MAX_KEYWORD_NR] = {
	{RST, "reset"},
	{LD, "load"},
	{ST, "store"}
};

unsigned char ucTokenNr;
struct Token asToken[MAX_TOKEN_NR];

enum State {TOKEN, DELIMITER};


enum CompResult { DIFFERENT , EQUAL };
enum CompResult eCompareString(char pcStr1[], char pcStr2[]);
enum Result eHexStringToUInt(char pcStr[],unsigned int *puiValue);
void ReplaceCharactersInString(char pcString[],char cOldChar,char cNewChar);


