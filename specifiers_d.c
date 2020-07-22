#include "libftprintf.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
int specifier_d(t_spec *all, ...)
{
	int i; 
	unsigned int c;
	char *s;

	i = 0;
	flag_hh_ll_d(all); //ordre
	c = va_arg(all->a_list,signed int);
	all->len_arg = size_nb(c);
	width_min(all);
	if (all->space)
		write(1," ",1);
	if (all->plus)
		all->conv->d < 0 ? write(1,"-",1) : write(1,"+",1);
	s = ft_itoa(c);
	write(1, "\n", 1);
	return (0);
}

int specifier_x(t_spec *all, ...)
{
	char *f;
	char *s;

	//flag_hh_ll(all); //ordre 
	all->conv->x = va_arg(all->a_list,signed int);
	if (all->type == 'X')
		//c = toupper(va_arg(all->a_list, int));
		ft_toupper(all->conv->x);
	ft_itoa_base(all->conv->x,16);
	if (all->hash && all->conv->x != 0)
	{
		if (all->type == 'X')
			write(1,"OX",2);
		else 
			write(1,"ox",2);
	}
	all->len_arg = size_nb(all->conv->x);
	width_min(all); 
	space_x(all);
	s = ft_itoa(all->conv->x);
	if (all->moins) // plus autre fonction ou pas ?
		f = ft_strjoin(s, all->s_filled);
	return (0);
}

int specifier_o(t_spec *all, ...)
{
	int c;
	char *f;
	char *s;

	//flag_hh_ll(all);
	all->conv->o = va_arg(all->a_list, signed int);
	ft_itoa_base(all->conv->o,8);
	all->len_arg = size_nb(all->conv->o);
	width_min(all);
	if (all->space)
		write(1," ",1);
	s = ft_itoa(all->conv->d);
	//plus autre fonction ou pas ?
	ft_putstr(f);
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
