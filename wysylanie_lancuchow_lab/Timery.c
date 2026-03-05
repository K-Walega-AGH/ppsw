#include "Timery.h"
#include <LPC21xx.H>
#define TimerZeroSET_mb (1<<0)
#define TimerZeroRESET_mb (1<<1)
#define mRESET_ON_MR0 (1<<1) 
#define mINTERRUPT_ON_MR0 (1<<0) 
#define mINTERRUPT_FLAG_MR0 (1<<0)

void InitTimer0 (void)
{
	T0TCR = TimerZeroSET_mb; // umozliwiamy by Timer0 zaczal se zliczac
}

void WaitOnTimer0(unsigned int uiTime)
{
	T0TCR = (T0TCR | TimerZeroRESET_mb);  //  resetujemy sobie Timer0
	T0TCR = T0TCR&(~TimerZeroRESET_mb); //  pozwalamy by Timer 0 znow zaczal liczyc (tak aby wartosc na Timerze 0 wynosila 0)
	while(T0TC<=((uiTime)*15)){}      // program sie wykonuje póki Timer0 nie bedzie miec wartosci wiekszej niz liczba podana
}
void InitTimer0Match0(unsigned int uiDelayTime)
{ 
	T0MR0 = uiDelayTime*15;    // dajemy se wartosc do licznika (taka wartosc do porownania)
	T0MCR = T0MCR | (mRESET_ON_MR0|mINTERRUPT_ON_MR0);  // sprawiamy by Timer0 sie zresetowal i by zarobil przerwanie gdy bedzie rowny MR0
	T0TCR = T0TCR | TimerZeroRESET_mb;   // resetujemy sobie Timer0
	T0TCR = T0TCR & (~TimerZeroRESET_mb);  // pozwalamy by Timer 0 znow zaczal liczyc (tak aby wartosc na Timerze 0 wynosila 0)
	T0TCR = TimerZeroSET_mb; // umozliwiamy by Timer0 zaczal se zliczac
}

void WaitOnTimer0Match0()
{ 
	while((T0IR & mINTERRUPT_FLAG_MR0)==0){}		//sie robi póki flaga sie nie zapali (chodzi o interrupt ustawiany w linii nr 23)
	T0IR = mINTERRUPT_FLAG_MR0;          // gasimy sobie flage by funkcja zadzialala wiecej niz raz
}
