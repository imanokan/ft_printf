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
	if (all->space)
		write(1," ",1);
	c = va_arg(all->a_list, int);
	all->len_arg = size_nb(c);
	fill_space(all);
	//all->s = ft_itoa(c);
	//printf("pvision : %d\n",all->vision);
	write(1, "\n", 1);
	return (0);
}

int specifier_x(t_spec *all, ...)
{
	int c;
	char *s;
	//c = toupper(va_arg(all->all_list, int*));
	//flag_hh_ll(all); //ordre 
	c = va_arg(all->a_list, int);
	ft_itoa_base(c,16,c);
	all->len_arg = size_nb(c);
	//all->s = ft_itoa(c); add all->s dans la struct
	//flag_hash(all); // ordre 
	return (0);
}

int specifier_o(t_spec *all, ...)
{
	int c;

	c = va_arg(all->a_list, int);
	ft_itoa_base(c,8);
	all_>len_arg = size_nb(c);
	return (0);
}

int specifier_u(t_spec *all)
{
	unsigned uint_max c;
	
	c = va_arg(all->a_list, unsigned uint_max);
	all->len_arg = size_nb(c);



