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
	ft_precision(all);
  	flag_corr(all);
//	ft_precision(all);
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
int kiki;
int coucou = 0;
int caca = 1;

kiki = 2;
  d = 28;
	a = -35;
	s = "abcdef";
	c = 'a';
	b = 45.123456;



     	printf("|%-2s|\n", "Hola hola");
      ft_printf("|%-2s|\n", "Hola hola");

     	printf("|%s|\n", NULL);
      ft_printf("|%s|\n", NULL);


	//printf("#25 hello\n", coucou, caca, kiki);
/*printf("printf    :|%5o|%5.3o|%5.1o|%5.0o|%5.o|\n", 0,0,0,0,0);
      ft_printf("ft_printf  :|%5o|%5.3o|%5.1o|%5.0o|%5.o|\n\n", 0,0,0,0,0);

      printf    ("printf1     :|%5o|%5.3o|%5.1o|%5.0o|%5.o|\n", 1,1,1,1,1);
      ft_printf ("ft_printf1  :|%5o|%5.3o|%5.1o|%5.0o|%5.o|\n\n", 1,1,1,1,1);
printf("DECI/n");
    printf    ("printf1     :|%5o|%5.3o|%5.1o|%5.0o|%5.o|\n", 0,0,0,0,0);
    ft_printf ("ft_printf1  :|%5o|%5.3o|%5.1o|%5.0o|%5.o|\n\n", 0,0,0,0,0);
printf("DECI/n");*/

//printf("Salut %20.12d this % 5.8d % 5d % 4.8i is not a test\n", 0x11ffaa147, 45, 45, 23));
//ft_printf("Salut %20.12d this % 5.8d % 5d % 4.8i is not a test\n", 0x11ffaa147, 45, 45, 23));

	/*printf("ft_printf1:|%+ 5d|%+ 5.3d|%+ 5.1d|%+ 5.0d|%+ 5.d|\n", 1,1,1,1,1);
	ft_printf("#4 %00.0d\n", 542);
	printf("#4 %00.0d\n", 542);
    ft_printf("ft_printf1:|%+ 5d|%+ 5.3d|%+ 5.1d|%+ 5.0d|%+ 5.d|\n", 1,1,1,1,1);

	printf("ORDI[%.8f]\n",b);
	ft_printf("meee[%.8f]\n",b);
	printf("ORDI[%.8f]\n",1.1234);
	ft_printf("mee[%.8f]\n",1.1234);

	printf("ORDI[%.8f]\n",1.1233);
	ft_printf("mee[%.8f]\n",1.1233);
	printf("ORDI[%.8f]\n",1.155);
	ft_printf("mee[%.8f]\n",1.155);
	printf("ORDI[%.8f]\n",1.8889);
	ft_printf("mee[%.8f]\n",1.8889);*/
	return(0);
}
