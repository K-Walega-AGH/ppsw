#define RECIEVER_SIZE 16
#define TRANSMITER_SIZE 32
#define TERMINATOR '\r'



enum eTransmiterStatus {FREE, BUSY};

typedef struct TransmiterBuffer{
char cData[TRANSMITER_SIZE];
enum eTransmiterStatus eStatus;
unsigned char fLastCharacter;
unsigned char cCharCtr;
}TransmiterBuffer;

extern struct TransmiterBuffer sTransmiterBuffer;



enum eRecieverStatus {EMPTY, READY, OVERFLOW};
char Transmiter_GetCharacterFromBuffer(void);
void Transmiter_SendString(char cString[]);
enum eTransmiterStatus Transmiter_GetStatus(void);


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



