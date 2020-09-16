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


int main()
{


//printf("|%-.5d| |%-.0d| |%-.i|\n",-587,-21,44 );
//ft_printf("|%-.5d| |%-.0d| |%-.i|\n",-587,-21,44 );


//printf("|%-.5d|\n",-144 );
//ft_printf("|%-.5d|\n",-144 );

printf("|%- .5d|\n",-555 );
ft_printf("|%- .5d|\n",-555);

printf("|%-.ibipboup|\n",44);
ft_printf("|%-.ibipboup|\n",44);

printf("|%+ 5i|%+ 5.3i|%+ 5.1i|%+ 5.0i|%+ 5.i|\n", 5,5,5,5,5);
ft_printf ("|%+ 5i|%+ 5.3i|%+ 5.1i|%+ 5.0i|%+ 5.i|\n", 5,5,5,5,5);

printf("Salut %-+10.4d  %-+12.5d |%-.5d| |%-.0d| |%-.ibipboup|\n", 50, 140, -587, -21, 44);
ft_printf("Salut %-+10.4d  %+-12.5d |%-.5d| |%-.0d| |%-.ibipboup|\n", 50, 140, -587, -21, 44);


//  ft_printf("Salut %-+10.4d  %-+5.20d %-+5.30d %-4d %-d %-d %-7d %-8i %-5ibipboup\n", 50, 140, 230, 0, -230, 79, 1234, -7, -53);
  //printf("Salut %-+10.4d  %-+5.20d %-+5.30d %-4d %-d %-d %-7d %-8i %-5ibipboup\n", 50, 140, 230, 0, -230, 79, 1234, -7, -53);
}
/*
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

// + - flag avec un moins et space
// 0 avec flag width et precision
// .0
//int max
// flag space
//moins width

  //printf("Salut %00+10.4d  %+12.5d %.5d %.0d %.i\n", 50, 140, -587, -21, 23);

  //ft_printf("Salut %00+10.4d  %+12.5d %.5d %.0d %.i\n", 50, 140, -587, -21, 23);



//printf("Salut %-+10.4d  %-+5.20d %-+5.30d %-4d %-d %-d %-7d %-8i %-5ibipboup\n", 50, 140, 230, 0, -230, 79, 1234, -7, -53);
//ft_printf("Salut %-+10.4d  %-+5.20d %-+5.30d %-4d %-d %-d %-7d %-8i %-5ibipboup\n", 50, 140, 230, 0, -230, 79, 1234, -7, -53);

//ft_printf("Salut %- .d this %-.0d %-+.i %-     .0d s not a test\n", 0, 0, 0, 0));
//printf("Salut %- .d this %-.0d %-+.i %-     .0d s not a test\n", 0, 0, 0, 0));
//ft_printf("ft_printf11 : %+-5.3i-\n", 0);
  //printf( "printf1     : %+-5.3i-\n", 0);
  ft_printf("hey1:%-0+5d\n",-50);
  printf("hey2:%-0+5d\n", -50 );

	 // printf( "printf9    : %+010.4i-\n", 0);
//printf("Salut %-+.4d  %-+12.5d %-.5d %-.0d %-.i hihi\n", 50, 140, -587, -21, 44);
//ft_printf("Salut %-+.4d  %-+12.5d %-.5d %-.0d %-.i hihi\n", 50, 140, -587, -21, 44);


//printf("Salut %-+10.4d  %-+5.20d %-+5.30d %-4d %-d %-d %-7d %-8i %-8i lol\n", 50, 140, 230, 0, -230, 79, 1234, -7, -53);
//ft_printf("Salut %-+10.4d  %-+5.20d %-+5.30d %-4d %-d %-d %-7d %-8i %-8i lol\n", 50, 140, 230, 0, -230, 79, 1234, -7, -53);
printf("\n");
//printf("|%+ 5d|%+ 5.3d|%+ 5.1d|%+5.0d|%+ 5.d|\n",   0,0,0,0,0);
//ft_printf("|%+ 5d|%+ 5.3d|%+ 5.1d|%+5.0d|%+ 5.d|\n", 0,0,0,0,0);

 //printf("|% 5d|% 5.3d|% 5.1d|% 5.0d|% 5.d|\n",   0,056135135315,22,23,0);
//ft_printf("|% 5d|% 5.3d|% 5.1d|% 5.0d|% 5.d|\n", 0,056135135315,22,23,0);

//printf("|%+5d|%+5.3d|%+5.4d|%+5.4d|%+5.0d|\n",   0,0,-45,-45,-45);
//ft_printf("|%+5d|%+5.3d|%+5.4d|%+5.4d|%+5.0d|\n", 0,0,-45,-45,-45);

//printf("|%0+5d|%0+5.3d|%0+5.1d|%0+5.0d|%0+5.d|\n",   0,0,-85,0,0);
//ft_printf("|%0+5d|%0+5.3d|%0+5.1d|%0+5.0d|%0+5.d|\n", 0,0,-85,0,0);

  //printf("|%+05d|%+05.3d|%+05.1d|%+05.0d|%+05.d|\n",   0,0,0,0,0);
//ft_printf("|%+05d|%+05.3d|%+05.1d|%+05.0d|%+05.d|\n", 0,0,0,0,0);

  // printf("|% 05d|% 05.3d|% 05.1d|% 05.0d|% 05.d|\n",   0,INT_MIN,0,0,0);
//ft_printf("|% 05d|% 05.3d|% 05.1d|% 05.0d|% 05.d|\n", 0,INT_MIN,0,0,0);



	return(0);
}*/
