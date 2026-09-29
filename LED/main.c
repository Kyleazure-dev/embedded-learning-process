#include <REGX52.H>
#include <INTRINS.H>
#include <MATH.H>
void Delay500ms(void)	//@12.000MHz
{
	unsigned char data i, j, k;

	_nop_();
	i = 4;
	j = 205;
	k = 187;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

int lit(int a){
    int n=0;
    n=255-pow(2,a-1);
    return n;
}
void main(){
    int i=1;
    while(1){
        P2=lit(i);
        i++;
        Delay500ms();
        i=i%9;
        }
}