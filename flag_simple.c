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
     			 //i++;
		if (all->spec[i] == '0' && ft_isdigit(all->spec[i + 1]))
			all->zero = 1;
		if (all->spec[i] == ' ')
			all->space = 1;
		if (all->spec[i] == '#')
			all->hash = 1;
    if (ft_isdigit(all->spec[i]))
      all->width = ft_atoi(&all->spec[i]);
      i = i + ft_numlen(all->width);
		if (all->spec[i] == '.')
      			{//all->pision = (int)NULL; linux problem de compi
          all->precision = 1;
          //while (ft_isdigit(s[i + 1]))
          all->vision = ft_atoi(&all->spec[i + 1]);
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
	all->space = all->width - all->len_arg; // s
  //all->space  = all->len_arg - all->len;
	if (all->len_arg  < all->space)
  	{
		if ((all->width/*not useful*/&& all->plus != 1 && all->zero != 1) || (all->type == 's'))
             fill_width(all);
    		else if (all->plus == 1 && all->width /*not useful*/)
         		 fill_width_plus(all);
		else if (all->width/*not useful*/ && all->zero == 1)
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
	if (all->width && all->precision == 1)
	{
     	 j = ft_strsub(all->conv->c,0,all->vision);
      	all->len_arg = ft_strlen(j);
      	width_min(all);
      	if (all->moins == 1)
	     		 f = ft_strjoin(j,all->s_filled);
	else if (!all->moins)
		f = ft_strjoin(all->s_filled, j);
     	ft_putstr(f);
	}
	else if(all->precision)
	{
		while (i < all->vision)
			ft_putchar(all->conv->c[i++]);
	}
	else if (all->width)
	{
		width_min(all);
		if (all->moins) 
		{	
			ft_putstr(all->conv->c);
			ft_putstr(all->s_filled);
		}
		else if (!all->moins)
		{
			ft_putstr(all->s_filled);
			ft_putstr(all->conv->c);
		}
	}
	return (0);
}
