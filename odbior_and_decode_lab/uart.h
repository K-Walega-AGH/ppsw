#define RECIEVER_SIZE 6
#define TERMINATOR '\0'

enum eRecieverStatus {EMPTY, READY, OVERFLOW};


typedef struct RecieverBuffer {
    char cData[RECIEVER_SIZE];
    unsigned char ucCharCtr;
    enum eRecieverStatus eStatus;
} RecieverBuffer;


extern struct RecieverBuffer sRecieverBuffer;
enum eRecieverStatus eReciever_GetStatus(void);

void UART_InitWithInt(unsigned int uiBaudRate);
void Reciever_GetStringCopy(char * ucDestination);
void Reciever_PutCharacterToBuffer(char cCharacter);



