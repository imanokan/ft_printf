#include "libftprintf.h"
#include <stdio.h>
#include <stdlib.h>
int specifier_d(t_spec *all, ...)
{
	int i; 
	unsigned int c;
	char *s;

	i = 0;
	//flag_hh_ll(all); //ordre
	c = va_arg(all->a_list, int);
	all->len_arg = size_nb(c);
	width_min(all);
	if (all->space)
		write(1," ",1);
	if (all->plus)
		c < 0 ? write(1,"-",1) : write(1,"+",1);
	all->s = ft_itoa(c);
	write(1, "\n", 1);
	return (0);
}
/*
int specifier_x(t_spec *all, ...)
{
	int c; 
	char *s;

	//flag_hh_ll(all); //ordre 
	if (all->type == 'X')
		c = toupper(va_arg(all->a_list, int));
	if (all->hash && c[0] != '0')
	{
		if (all->type == 'X')
			write(1,"OX",2);
		else 
			write(1,"ox",2);
	}
	ft_itoa_base(c,16,c);
	all->len_arg = size_nb(c);
	width_min(all); 
	//fonction check flag - et space 
	//all->s = ft_itoa(c); add all->s dans la struct 
	return (0);
}

int specifier_o(t_spec *all, ...)
{
	int c;

	flag_hh_ll(all);
	c = va_arg(all->a_list, int);
	ft_itoa_base(c,8);
	all->len_arg = size_nb(c);
	width_min(all);
	if (all->space)
		write(1," ",1);
	return (0);
}

int specifier_u(t_spec *all, ...)
{
	unsigned uint_max c;
	
	c = va_arg(all->a_list, unsigned uint_max);
	all->len_arg = size_nb(c);
	width_min(all);

	return (0); 

}*/
