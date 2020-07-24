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
	//flag_simple(all);
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
	all->conv = (t_conv*)malloc(sizeof(t_conv));
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
	s = "abcdefghijk";
	c = 'a';

printf("ORDI-->[%.5d]\n", 252);
ft_printf("MOOI-->[%.5d]\n", 252); //manque l'espace

	//put va_arg  
 //printf("ORDI-->[%+.2d]\n",1); 
 //ft_printf("MOOI-->[%+.2d]\n",1);

  //printf("ORDI -->[%-.5d]\n", 1);
  //ft_printf("MOI  -->[%-.5d]\n", 1);

  //printf("ORDI-->[%-4d]\n", 1);
  //ft_printf("MOOI-->[%-4d]\n",1);
/*printf("OCTAL/n");
/printf("printf    :|%5o|%5.3o|%5.1o|%5.0o|%5.o|\n", 0,0,0,0,0);
      ft_printf("ft_printf  :|%5o|%5.3o|%5.1o|%5.0o|%5.o|\n\n", 0,0,0,0,0);

      printf    ("printf1     :|%5o|%5.3o|%5.1o|%5.0o|%5.o|\n", 1,1,1,1,1);
      ft_printf ("ft_printf1  :|%5o|%5.3o|%5.1o|%5.0o|%5.o|\n\n", 1,1,1,1,1);
printf("DECI/n");
    printf    ("printf1     :|%5o|%5.3o|%5.1o|%5.0o|%5.o|\n", 0,0,0,0,0);
    ft_printf ("ft_printf1  :|%5o|%5.3o|%5.1o|%5.0o|%5.o|\n\n", 0,0,0,0,0);
printf("DECI/n");
    printf    ("printf1     :|%+ 5d|%+ 5.3d|%+ 5.1d|%+ 5.0d|%+ 5.d|\n", 1,1,1,1,1);
      ft_printf ("ft_printf1  :|%+ 5d|%+ 5.3d|%+ 5.1d|%+ 5.0d|%+ 5.d|\n\n", 1,1,1,1,1);*/
	printf("real[%.5s]\n",s);
	ft_printf("meee[%.5s]\n",s);
	return(0);
}
