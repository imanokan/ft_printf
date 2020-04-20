#include <stdarg.h>
#include "./libft/libft.h"


int specifier_d(const char *str, ...)
{
	int i; 
	int c;
	va_list a_list;

	i = 0;
	va_start(a_list,str);
	while (str[i] != '\0)
	{
		if (str[i] == '%' && (str[i + 1] == 'd' || 'i'|| 'o'))
		{
			if (str[i+1] == 'o')
				check_binary(va_arg);
			c = va_arg(a_list, char *);
			ft_putstr(c);
		}
		i++;
	}
	va_end(a_list);
	write(1, "\n", 1);
	return (0);
}

