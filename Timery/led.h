enum eLedTurn {RIGHT,LEFT};

void LedInit(void);
void LedStepLeft(void);
void LedStepRight(void);
//enum LedState{LED_LEFT, LED_RIGHT}; //DO ZAD3
//enum LedState{LED_STAY, LED_RIGHT}; // DO ZAD 4 i 5
enum LedState{LED_STAY, LED_RIGHT,LED_LEFT};

void StepLeft (void); // do timerów
