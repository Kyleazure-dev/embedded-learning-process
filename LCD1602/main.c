#include <REGX52.H>
#include "Seg.h"
#include "LCD1602.H"
#include "Delay.H"

void main(){
    LCD_Init();
    LCD_ShowString(1,1,"DURIN");
    LCD_ShowNum(2,1,314,3);
    LCD_ShowSignedNum(1,14,-66,2);
    while(1){
    }
}