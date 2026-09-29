#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "Seg.h"
#include "Timer0.h"
//
void main(){
    int time=100;
    Timer0_Init();
    do{P2_5=1;
        Delay(1);
        P2_5=0;
        Delay(1);
        time--;
    }while(time!=0);
    LCD_Init();
    LCD_ShowString(1,2,"--INITIALIZE--");
    Delay(5000);
    LCD_ShowString(1,2,"              ");
    while(1){
        
    }
}

void Timer0_Routine() interrupt 1{
    static unsigned int T0Count;
    TH0=0xFC;
    TL0=0x66;
    T0Count++;
    if(T0Count>=1000){
        P2_0=~P2_0;
        LCD_ShowString(1,1,"INTERRUPT      ");
        T0Count=0;
    }
}