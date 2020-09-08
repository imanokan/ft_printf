#include <stdio.h>
#include <ctype.h>

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
static double nlen(double value, int base) 
{
	int count  = 0; 
	while (value)
	 {
	 	count++; 
       		value /=base; 
	}
	return(count); 
}	

static char *ft_itoa_base_float(double value, int base) 
{
	char *str_base;
	char *dst; 
	int len; 
	int sign; 

	sign = 0; 
	str_base = "0123456789";
	if (value == 0) 
		return (0); 
	(base == 10 && value < 0) ? sign = 1 && len++ : sign; 
	dst = malloc(sizeof(char) * (len + 1)); 
	sign ? dst[0] = '-' : 0; 
	dst[len] = '\0'; 
	while (value) 
	{
		dst[--len] = str_base[value % base];
		value /= base; 
	}
	return (dst);
}
       	

int main()
{
	int after_deci = 0; 
	int count = 0; 
	//t new = 0;
	int new;
	double fl = 0.945;
	char *str;

	str = ft_itoa_base_float(fl, 10);
	printf("str : %s\n",str); 
	while (isdigit(fl))
	{
		printf("ok\n");
	
	}
	return (1);
}
	

