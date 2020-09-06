#include <stdio.h>

int size_nb(double n)
{
	int l;

	l = 0;
	printf(" n : %f\n",n);
	if (n == 0)
		return(1);
	while (n != 0)
	{
		n / 0.1;
		l++;
	}
	return(l);
}
		
/*
int main(void)
{
	int a = 0;
	int i; 
	double j;
       	int f;
        char *s;
	int len;
	int dix = 10;	
	double d = 45.1236;

	i = (int)d; 
	j = d - i;
	printf("j : %f\n",j);
	//check si il y a une précision si oui while a != all->precision or else 6 
	while (a != 6)
	{ 
		f = j * dix;
		dix = dix *10;
		printf("f : %d\n",f);
		a++;
	
	}
	f = f + 1;
	//ii/ntf("size : %d\n",size_nb(j));
	while ( a < 6)
	{
		f = j * 10;
		//printf("f1 : %d\n",f);
		a++;

	}
	printf(" final : %d\n", f);
	//printf(" f : %d\n",f);
	return (0);
}*/
int main()
{
	int deci = 597; 
	int count = 0; 
	//t new = 0;
	int new;
	int sous = 1; 

	new = deci % 10;
	while (new != 10)
	{	
		new += 1;
		count += 1;
	}
	deci = deci + count;
	printf("deci : %d\n",deci);
	return (1);
}
	

