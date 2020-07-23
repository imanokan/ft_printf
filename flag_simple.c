#include "libftprintf.h"

void flag_exist(const char *format, t_spec *all)
{
 	int i;
	i = 0;
	while (all->spec[i])
	{
		if (all->spec[i] == '+')
			all->plus = 1;
		else if (all->spec[i] == '-')
			all->moins = 1;
		else if (all->spec[i] == '0')
			all->zero = 1;
		else if (all->spec[i] == ' ')
			all->space = 1;
		else if (all->spec[i] == '#')
			all->hash = 1;
		else if (all->spec[i] == '.' && ft_isdigit(all->spec[i + 1]))
    {
      all->pision = NULL;
      all->precision = 1;
			all->vision = int_in_str(all);
    }
		else if (all->moins == 1 && all->zero == 1)
			all->zero = 0;
		else if (all->plus == 1 && all->space == 1)
			all->space = 0;
		i++;
	}
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
  all->width = 1;
	all->len = int_in_str(all); //spec
		//return (-1);
	all->space = all->len - all->len_arg;
	//printf("len space : %d\n", all->space);
	if (all->len_arg < all->len)
		fill_width(all);
	return (0);

}
