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
	all->p = all->conv->d < 0 ? '-' :  '+';
	if (all->conv->d < 0)
 	{
		all->isneg = 1;
		all->conv->d  = all->conv->d * - 1;
	}
	all->len_arg = size_nb(all->conv->d);
	if (all->w == 1 && all->precision == 0)
				width(all);
 	else if (all->w == 0 && all->precision == 1)
		precision(all);
	else if (all->w == 1 && all->precision == 1)
			width_precision(all);
	if (all->check != 1)
	{
		if (all->isneg == 1 && all->check1 != 1)
			ft_putnbr(all->conv->d);
	else
		if (all->plus == 1)
			ft_putchar(all->p);
		ft_putnbr(all->conv->d);
	}
	return (0);
}

int specifier_x(t_spec *all)
{
	char *str;
	int i;
	i = 0;
	//flag_hh_ll(all); //ordre
	all->conv->x = va_arg(all->a_list,unsigned int);
	str = ft_itoa_base(all->conv->x,16);
	if (all->type == 'X') // voir l'autre ft_itoa_base avec c
			while (str[i] != '\0')
					ft_toupper(str[i++]);
	if (all->hash == 1 && all->conv->x != 0)
	{
		if (all->type == 'X')
			write(1,"OX",2);
		else
			write(1,"ox",2);
	}
	all->len_arg = size_nb(all->conv->x);
	if (all->w == 1 && all->precision == 0)
				width(all);
 	else if (all->w == 0 && all->precision == 1)
			precision(all);
	else if (all->w == 1 && all->precision == 1)
			width_precision(all);
	if (all->check != 1)
			ft_putstr(str);
	return (0);
}

int specifier_o(t_spec *all)
{
	char *s;
	//flag_hh_ll(all);
	all->conv->o = va_arg(all->a_list, signed int);
	s = ft_itoa_base(all->conv->o,8);
	all->len_arg = size_nb(all->conv->o);
	if (all->w == 1 && all->precision == 0)
			width(all); // moyen de recup la vale
	else if (all->w == 0 && all->precision == 1)
			precision(all);
	else if (all->w == 1 && all->precision == 1)
			width_precision(all); // pour chaque fnction une diff
	if (all->check != 1)
		ft_putstr(s); //do not print the right value even if it has it
	return (0);
}

int specifier_u(t_spec *all)
{
	//unsigned uint_max c;
	//flag_hh_ll_u(all);
	all->conv->u = va_arg(all->a_list, unsigned int);
	//printf("%u\n", all->conv->u);
	if (all->conv->u < 0)
		all->conv->u = UINT_MAX - all->conv->u;
		//printf("%u\n", all->conv->u);
	all->len_arg = size_nb(all->conv->u);
	//printf("len :%u\n", all->len_arg);
	if (all->w == 1 && all->precision == 0)
			width(all); // moyen de recup la vale
	else if (all->w == 0 && all->precision == 1)
			precision(all);
	else if (all->w == 1 && all->precision == 1)
			width_precision(all); // pour chaque fnction une diff
	if (all->check != 1)
		ft_putnbr(all->conv->u);
	return (0);
}
