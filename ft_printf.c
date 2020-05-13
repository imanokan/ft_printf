#include <stdio.h>
#include "./libft/libft.h"
#include "libftprintf.h"

int  type_spec(char c)
{
    return (c == 'c' || c == 's' || c == 'p' | c == 'f'
    || c == 'd' || c == 'x' || c == 'X' || c == 'i' || c == 'o');
}

int       cut_str(const char *format, t_spec *all)
{
    int i;
    int j;
    i = 0;
    while (format[i] != '\0')
    {	
        if (format[i] == '%' && format[i + 1] != '%')
       	{	
            j = 0;
            while (format[i] && !type_spec(format[i]))
	    {	
		i++;	
                j++;
	    }
	    all->type = format[i];
            all->spec = ft_strsub(format, i - j, j + 1);
            //printf("spec : %s\n", all->spec);
	    //printf("type : %c\n",all->type);
            //free(all->spec); 
        }
            else
            {
                if (format[i] == '%')
		      	i++;
                write(1, &format[i], 1);
            }
            i++;
        }
        return (0);
}
int 	ft_printf(const char *format, ...)
{	
	t_spec *all;
	int i; 
	i = 0;
	all = malloc(sizeof(t_spec));
	va_start(all->a_list, format);
	while (format[i] != '\0')
	{
		cut_str(format,all);
		flag_exist(format, all);
		//flag_simple(all);
		conversion_specifier(all);
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

	s = "aaa bbbb vvvv";
	d = "cccc";
	printf("real: %23s\n",s);
	ft_printf("mine : %s %s\n", s,d);
	return(0);
}	
