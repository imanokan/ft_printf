#include "libftprintf.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
int specifier_d(t_spec *all, ...)
{
	int i;
	signed int c;
	char *s;
	char *f;
	i = 0;
	//flag_hh_ll_d(all); //ordre:
	all->conv->d= va_arg(all->a_list,int);
	all->len_arg = size_nb(all->conv->d);
	if (all->plus)
	{
		all->p = c < 0 ? '-' :  '+';
		all->len_arg = size_nb(all->conv->d) + 1;
	}
	if (all->space == 1)
	{
		write(1, " ", 1);
		all->len_arg = all->len_arg + 1;
	}
	//fill_precision(all);
	//s = ft_itoa(all->conv->d);
	fnct_output_d(all);
	/*if (all->width == 1 && all->plus != 1) //output
		f = ft_strjoin(all->s_filled,s);
	if (all->precision == 1 && all->plus != 1)
			f = ft_strjoin(all->s_filled_p,s);*/
	//ft_putstr(all->s_filled);
	  // put in condition ft_s si le reste n'a pas été fait
		if (all->w != 1 && all->precision != 1)
				ft_putnbr(all->conv->d);
	return (0);
}

int specifier_x(t_spec *all, ...)
{
	char *f;
	char *s;

	//flag_hh_ll(all); //ordre
	all->conv->x = va_arg(all->a_list,signed int);
	if (all->type == 'X')
		all->conv->x = ft_toupper(all->conv->x);
	//all->conv->x = ft_itoa_base(all->conv->x,16);
	if (all->hash && all->conv->x != 0)
	{
		if (all->type == 'X')
			write(1,"OX",2);
		else
			write(1,"ox",2);
	}
	all->len_arg = size_nb(all->conv->x);
	width_min(all);
	fill_precision(all);
	space_x(all);
	s = ft_itoa(all->conv->x);
	if (all->moins) // plus autre fonction ou pas ?
		f = ft_strjoin(s, all->s_filled);
	//fnct output precision && width
	return (0);
}

int specifier_o(t_spec *all, ...)
{

	char *s;

	//flag_hh_ll(all);
	all->conv->o = va_arg(all->a_list, signed int);
	ft_itoa_base(all->conv->o,8);
	all->len_arg = size_nb(all->conv->o);
	width_min(all);
	if (all->space == 1)
		write(1," ",1);
	s = ft_itoa(all->conv->o);
	//plus autre fonction ou pas
	ft_putstr(s);
	return (0);
}

int specifier_u(t_spec *all, ...)
{
	//unsigned uint_max c;
	char *s;
	char *f;

	flag_hh_ll_u(all);
	all->conv->u = va_arg(all->a_list, uintmax_t);
	all->len_arg = size_nb(all->conv->u);
	width_min(all);
	if (all->space)
		write(1," ",1);
	s = ft_itoa(all->conv->u);
	if (all->moins) //fnct
		f = ft_strjoin(s,all->s_filled);
	ft_putstr(f);
	return (0);
}
