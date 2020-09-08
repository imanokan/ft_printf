#include <stdio.h>
#include "./libft/libft.h"
#include "libftprintf.h"

int  type_spec(char c)
{
    return (c == 'c' || c == 's' || c == 'p' | c == 'f'
    || c == 'd' || c == 'x' || c == 'X' || c == 'i' || c == 'o' || c == 'u');
}
void initialisation(t_spec *all)
{
  all->zero = 0;
  all->space = 0;
  all->len_arg = 0;
  all->width = 0;
  all->s_filled_d = NULL;
  all->s_filled_p = NULL;
  all->pision = 0;
  all->w = 0;
  all->point = 0;
  all->plus = 0;
  all->wp = 0;
  all->check = 0;
  all->moins = 0;
  all->hash = 0;
  all->precision = 0;
  all->vision = 0;
  all->isneg = 0;
  all->check1  = 0;
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
	flag_exist(all);
  	flag_corr(all);
	ft_precision(all);
	printf("width : %d precision: %d\n", all->width, all->vision);
	conversion_specifier(all);
	free(all->spec);
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
  	initialisation(all);
	all->conv = (t_conv*)malloc(sizeof(t_conv));
	va_start(all->a_list, format);
	while (format[i])
	{
		cut_str(format, &i, all);
		i++;
	}
	va_end(all->a_list);
	free(all->conv);
	free(all);
	return(0);
}

int main(void)
{
	char *s;
	char c;
	int a;
  unsigned int d;
  	float b;


  	d = 28;
	a = -35;
	s = "abcdef";
	c = 'a';
	b = 45.002;

//printf("ORDI-->[%.5d]\n", 252);
//ft_printf("MOOI-->[%.5d]\n", 252); //manque l'espace

	//put va_arg
//printf("ORDI-->[%+.2d]\n",5);
//ft_printf("MOOI-->[%+.2d]\n",5);

  //printf("ORDI -->[%-8d]\n", 6);
  //ft_printf("MOI  -->[%-8d]\n", 6);

 //printf("ORDI-->i%-4d]\n", 1);
 //ft_printf("MOOI-->[%-4d]\n",1); //gerer le  output du moins
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
	//printf("ORDI[%d]\n",d);
	ft_printf("mee[%f]\n",b);
	return(0);
}
