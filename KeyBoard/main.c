#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "Seg.h"
#include "KeyBoard.h"
void main(){
    //
    int time=50;
    int key=00;
    int correct=0;
    int password=0;
    int count=0;
    do{P2_5=1;
        Delay(1);
        P2_5=0;
        Delay(1);
        time--;
    }while(time!=0);
    LCD_Init();
    LCD_ShowString(1,2,"--INITIALIZE--");
    Delay(500);
    LCD_ShowString(1,2,"              ");
    //
    LCD_ShowString(1,1,"PASSWORD ENTER");
    while(1){
        key=KeyBoard();
                LCD_ShowNum(2,1,correct,4);        
        if(key){
            if(key<=10){
                correct=key%10+correct*10;
            }
            if(key==11){
                correct=correct/10;
            }
            if(key==12){
                LCD_ShowString(1,1,"PASSWORD CONFIRM");
                LCD_ShowNum(2,1,correct,4);
                Delay(1000);
                LCD_ShowString(1,1,"                 ");
                break;
                }
            }
    }
    //
    LCD_ShowString(1,1,"PASSWORD");
    while(1){
        key=KeyBoard();
                LCD_ShowNum(2,1,password,4);        
        if(key){
            if(key<=10){
                password=key%10+password*10;
                count++;
            }
            if(key==11){
                password=password/10;
                count--;
            }
            if(key==12 || count==4){
                if(password==correct){
                    LCD_ShowNum(2,1,correct,4);
                    Delay(50);
                    LCD_ShowString(2,11,"UNLOCK");
                    Delay(700);
                    LCD_ShowString(2,11,"       ");
                    password=0;
                    count=0;
                }else{
                    LCD_ShowNum(2,1,password,4);
                    Delay(50);
                    LCD_ShowString(2,12,"ERROR");
                    Delay(700);
                    LCD_ShowString(2,11,"       ");
                    password=0;
                    count=0;
                }
            }
            
        }
    }
}
