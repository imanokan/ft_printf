#include <stdio.h>
#include <ctype.h>
#include <unistd.h>


int 	write_arg(char *va_arg, int prec)
{
	int i;
	i = 0; 
	while (va_arg[i] != prec)
		write(1,va_arg[i],1);
	return (0);
}
int	ft_precisions()
{
	char *spec;
	char *str;
	int i;
	i = 0;
	str = "audrey";
	spec = "%.0s";
	while (spec[i] != '\0')
	{
		if (spec[i] == '.' && spec[i + 1] == '0')
			write(1," \n",2);
		else if (spec[i] == '.' && spec[i + 1] == INT)
		{
			spec->prec = spec[i + 1];
			write(va_arg, prec);
		}
		else if (spec[i] == '.' && spec[i] == '*')
		{
			recup num après la virgule;
			spec->prec = spec[i + 1];
			write_arg(va_arg, prec);
		}

	}
	return (0);
}
int main(void)
{
 	int d; 
	int ret;
	d = 2;
	ret = isalnum(d);
	printf("str no precision: %.0s\n","bougie");
	printf("str 1 precision: %.*5s\n","abcdefghi");
	printf("str * precision: %.*s\n",4,"audrey");
	printf("num = %d\n",ret);
	printf("%d\n",isalnum(d));
	return(0);
}

