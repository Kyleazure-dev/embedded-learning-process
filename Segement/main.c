#include <REGX52.H>
#include "Delay.h"
#include "Seg.h"
#include "LCD1602.h"
void main(){
    int i=1;
    
    while(1){
        Seg(i,i);
        i++;
        if(i==9){
            i=1;
        }
    }
}