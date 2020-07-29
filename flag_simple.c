#include "libftprintf.h"

static int		ft_numlen(int n)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}


void flag_exist(const char *format, t_spec *all)
{
 	int i;
  int j;
	i = 0;
	while (all->spec[i] != '\0')
	{
		if (all->spec[i] == '+')
			all->plus = 1;
		if (all->spec[i] == '-')
			all->moins = 1;
      i++;
		if (all->spec[i] == '0' && ft_isdigit(all->spec[i + 1]))
			all->zero = 1;
		if (all->spec[i] == ' ')
			all->space = 1;
		if (all->spec[i] == '#')
			all->hash = 1;
    if (ft_isdigit(all->spec[i]))
      all->width = ft_atoi(&all->spec[i]);
      i = i + ft_numlen(all->width);
      printf("i : %d\n",all->width);
		if (all->spec[i] == '.')
      			{//all->pision = (int)NULL; linux problem de compi
          all->precision = 1;
          //while (ft_isdigit(s[i + 1]))
          all->vision = ft_atoi(&all->spec[i + 1]);
          printf("vision %d\n",all->vision );
        break;
  }
	/*	else if (all->moins == 1 && all->zero == 1)
			all->zero = 0;
		else if (all->plus == 1 && all->space == 1)
			all->space = 0;
		else if (all->zero == 1 && all->precision == 1)
			all->zero = 0;*/
	}
}

void    flag_corr(t_spec *all)
{
	if (all->moins == 1 && all->zero == 1)
    all->zero = 0;
  if (all->plus == 1 && all->space == 1)
    all->space = 0;
  if (all->zero == 1 && all->precision == 1)
    all->zero = 0;
  }
void	flag_exist_bis(const char *format, t_spec *all)
{
	int i;
	i = 0;
	while (format[i] != '\0')
	{
		if (all->spec[i] == 'h')
			all->h = 1;
		else if (all->spec[i] == 'l')
			all->l = 1;
		else if (all->spec[i] == 'h' && all->spec[i + 1] == 'h')
			all->hh = 1;
		else if (all->spec[i] == 'l' && all->spec[i + 1] == 'l')
			all->ll = 1;
		else if (all->spec[i] == 'L')
			all->L = 1;
		i++;
	}
}

int 	width_min(t_spec *all)
{
  	//all->width = 1;
	//all->len = int_in_str(all); //spec
		//return (-1);
	all->space = all->len_arg - all->width; // s
  //all->space  = all->len_arg - all->len;
  //printf("len : %d\n", all->len);
  //printf("space : %d\n", all->space);
	if (all->len_arg  < all->len)
  	{
		all->width = 1;
		if ((all->width == 1 /*not useful*/&& all->plus != 1 && all->zero != 1) || (all->type == 's'))
             fill_width(all);
    		else if (all->plus == 1 && all->width == 1 /*not useful*/)
         		 fill_width_plus(all);
		else if (all->width == 1 /*not useful*/ && all->zero == 1)
			fill_zero(all);

	}
	return (0);

}

int	fnct_output_s(t_spec *all)
{
	int i;
  char *s;
	char *j;
  char *f;
	i = 0;
  //j = (malloc(sizeof(char));
	if (all->width == 1 && all->precision == 1)
	{
      j = ft_strsub(all->conv->c,0,all->vision);
      all->len_arg = ft_strlen(j);
      width_min(all);
      f = ft_strjoin(all->s_filled, j);
      ft_putstr(f);
	}
	else if(all->precision)
	{
		all->pision = all->len_arg - all->vision;
		while (i < all->pision)
			ft_putchar(all->conv->c[i++]);
	}
	/*else if (all->moins)
	{
    printf("moins : %d\n", all->moins);
		s = ft_strjoin(all->conv->c,all->s_filled);
		ft_putstr(s);
	}*/
	else if (all->width == 1)
	{
    //printf("%s\n","in1" );
		ft_putstr(all->s_filled);
		ft_putstr(all->conv->c);
	}
	return (0);
}
