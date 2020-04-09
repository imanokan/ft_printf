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
		if (str[i] == '%' && (str[i + 1] == 'd' || 'i'))
		{
			c = va_arg(a_list, int)

