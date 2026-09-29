#include <REGX52.H>
#include "Delay.h"
char KeyBoard(){
    code unsigned char C[]={0xF7,0xFB,0xFD,0xFE};
    unsigned char scan=0;
    unsigned char row=0;
    unsigned char key=0;
    for(scan=0;scan<4;scan++){
        P1=C[scan];
        if(P1_7==0){
            Delay(20);
            while(P1_7==0);
            Delay(20);
            row=0;
            key=scan+1+4*row;
            return key;
        }
        if(P1_6==0){
            Delay(20);
            while(P1_6==0);
            Delay(20);
            row=1;
            key=scan+1+4*row;
            return key;
        }
        if(P1_5==0){
            Delay(20);
            while(P1_5==0);
            Delay(20);
            row=2;
            key=scan+1+4*row;
            return key;
        }
        if(P1_4==0){
            Delay(20);
            while(P1_4==0);
            Delay(20);
            row=3;
            key=scan+1+4*row;
            return key;
        }
    }
    return 0;
}
