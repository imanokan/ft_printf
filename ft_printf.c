#include <stdio.h>
#include "./libft/libft.h"
#include "libftprintf.h"

int  type_spec(char c)
{
    return (c == 'c' || c == 's' || c == 'p' | c == 'f'
    || c == 'd' || c == 'x' || c == 'X' || c == 'i' || c == 'o');
}

int       cut_str(const char *format, int *i,  t_spec *all)
{
   int j;

   if (format[*i] == '%' && format[*i + 1] != '%')
   {	
        j = 0;
       	while (format[*i] && !type_spec(format[*i]))
	{
		*i = *i + 1;	
                j++;
	}
	all->type = format[*i];
        all->spec = ft_strsub(format, *i - j, j + 1);
	flag_exist(format, all);
	flag_simple(all);
	conversion_specifier(all);
       //	free(all->spec); 
        }
    else
    {
           if (format[*i] == '%')
		    *i = *i + 1;
            write(1, &format[*i], 1);
     }
        return (1);
}
int 	ft_printf(const char *format, ...)
{	
	t_spec *all;
	int i; 
	i = 0;
	all = malloc(sizeof(t_spec));
	va_start(all->a_list, format);
	while (format[i])
	{
		cut_str(format, &i, all);
		i++;
	}
	va_end(all->a_list);
	//free(all);
	return(0);
}

int main(void)
{
	char *s;
	char *d;
	char c;
	int a;

	a = 24;
	d = "cc";
	c = 'a';

	//printf("real %0s\n",s);
	ft_printf("[%5s] %d \n",d);
	return(0);
}	
