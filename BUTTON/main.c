#include <REGX52.H>

void delay(int sec)	//@12.000MHz
{
	
    unsigned char data i, j;
    while(sec>=0){
        i = 2;
        j = 239;
        do
        {
            while (--j);
        } while (--i);
        sec--;
    }
}

void main(){
    char LedNum=0;
    P2=~0x01;
    while(1){
        if(P3_0==0){
            delay(20);
            while(P3_0==0);
            delay(20);
            LedNum++;
            if(LedNum>=8){
                LedNum=0;
            }
            P2=~(0x01<<LedNum);
        }        
        if(P3_1==0){
            delay(20);
            while(P3_1==0);
            delay(20);
            LedNum--;
            if(LedNum<=-1){
                LedNum=7;
            }
            P2=~(0x01<<LedNum);
        }
    }
}       
        
