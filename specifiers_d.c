#include "libftprintf.h"

int specifier_d(t_spec *all, ...)
{
	int i; 
	int c;

	i = 0;
	while (str[i] != '\0)
	{
		if (str[i] == '%' && (str[i + 1] == 'd' || 'i'|| 'o'))
		{
			if (str[i + 1] == 'o')
				check_binary(va_arg);
			c = va_arg(a_list, char *);
			ft_putstr(c);
		}
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
