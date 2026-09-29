void Delay(int msec)	//@12.000MHz
{
	while(msec){
        unsigned char data i, j;

        i = 2;
        j = 239;
        do
        {
            while (--j);
        } while (--i);
        msec--;
    }
}
