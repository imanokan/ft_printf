#include <stdio.h>
#include "libft/libft.h"

int main ()
{
//	char *s = ".";
	int point = 0;
	char *str = "%4%";
	int w = 0;
	int width = 0;
	char *a = "%05.4%";
	int i = 0;
	int j = 0;
	char *spec;

	if (a[i] == '%')
		j = i;
	j +=  1;
	while (a[j] != '%')
		j++;
	spec = ft_strsub(a, i, j + 1);
	i = 0;
	while (spec[i] != '\0')
	{
		if (spec[i] == '.')
			point = 1;
		else if (spec[i] == ' ')
			space = 1;
		else if ((ft_isdigit(spec[i]) && point != 1))// all->spec[i - 1] != '.'))
		{
		 	w = 1;
		 	width = ft_atoi(&spec[i]);
		 	break;
	 	}
	 	i++;
	}
	//fill space
//	printf("|%0.5%|\n");
	printf(" width : %d\n", width);
//	if spec = "%"
//		print spec;
	ft_putstr(spec);
	free(spec);
	return (0);
}
