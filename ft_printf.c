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
  all->esp = 0;
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
  ft_precision(all);
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



  //printf("Salut %00+10.4d  %+12.5d %.5d %.0d %.i\n", 50, 140, -587, -21, 23);

  //ft_printf("Salut %00+10.4d  %+12.5d %.5d %.0d %.i\n", 50, 140, -587, -21, 23);



//printf("Salut %-+10.4d  %-+5.20d %-+5.30d %-4d %-d %-d %-7d %-8i %-5ibipboup\n", 50, 140, 230, 0, -230, 79, 1234, -7, -53);
//ft_printf("Salut %-+10.4d  %-+5.20d %-+5.30d %-4d %-d %-d %-7d %-8i %-5ibipboup\n", 50, 140, 230, 0, -230, 79, 1234, -7, -53);


printf("%-8i\n",-7);
ft_printf("%-8i\n",-7);




	return(0);
}
