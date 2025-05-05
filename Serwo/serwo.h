

void ServoInit(unsigned int uiServoFrequency);
void ServoCallib(void);
void ServoGoTo(unsigned int uiPosition);
void Automat(void);
void DetectorInit(void);


struct Servo;

enum DetectorState eReadDetector(void);
