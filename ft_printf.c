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
    	//va_end(a_list);
        return (0);
}
int 	ft_printf(const char *format, ...)
{	
	t_spec *all;
	
	all = malloc(sizeof(t_spec));
	va_start(all->a_list, format);
	cut_str(format,all);
	flag_exist(format, all);
	flag_simple(all);
	conversion_specifier(all);
	va_end(all->a_list);
	//²²free(all);
	return(0);
}

int main(void)
{
	char *s;
	int d;
	int c;

	s = "aaa";
	d = 45;
	c = -3;
	//printf("space:%+d\n",d);
	//printf("real : %s\n",s);
	ft_printf("mine : %s\n", s);
	return(0);
}
