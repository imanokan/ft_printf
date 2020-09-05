
#include <stdio.h>

int size_nb(double n)
{
	int l;

	l = 0;
	if (n == 0)
		return(1);
	while (n != 0)
	{
		n /= 10;
		l++;
	}
	return(l);
}
		

int main(void)
{
	int a = 0;
	int *b = 455;
	int i; 
	double j;
       	int f; 
	double d = 45.123;
	//double *z = 123.456;


	i = (int)d; 
	j = d - i;
	ii/ntf("size : %d\n",size_nb(j));
	while ( a < 6)
	{
		f = j * 10;
		//printf("f1 : %d\n",f);
		a++;

	}
	a = 0;
	while ( a < 6);
	{
		b[a];
		a++;
	}
	printf(" b : %ls\n",b);
	return (0);
}


