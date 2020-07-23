#include "libftprintf.h"
int size_nb(int n)
{
	int l;

	l = 0;
	if (n == 0)
		return(1);
	/*else if (n < 0)
		l++;*/
	while (n != 0)
	{
		n /= 10;
		l++;
	}
	return (l);
}
/*
void flag_plus(t_spec *all)
{
	if  (all->plus == 1) //fonctionne pour s mais à réfléchir pour diouxX
		all->conv;
	else
		all->s = ft_strjoin(all->s_filled, c);


}*/
/*
int flag_hh_ll(t_spec *all)
{
	if (all->h && //type_dioux(all->type)) tu sais
		all->type == 'u' ? conv->d = va_arg(all->a_list, short unsigned int*) : conv->d = va_arg(all->a_list, short int*):
	else if (all->hh && type_dioux(all->type))
		all->type == 'u' ? conv->o = va_arg(all->a_list,unsigned char*): conv->o = va_arg(all->a_list, char*)

	else if (all->l && type_dioux(all->type))
	{
		if (all->type == 'f')
			conv->f = va_arg(all->a_list, long double*)
		else if (all->type = 'u')
			conv->x = va_arg(all->a_list, long unsigned int*)
		else
			conv->X = va_arg(all->a_list, long int*)
	}
	else if (all->ll && type_dioux(all->type))
		all->type == 'u' ? conv->u = va_arg(all->a_list, unsigned long long int*) : conv->u = va_arg(all->a_list, long long int*);
}
*/
void  flag_hh_ll_d(t_spec *all)
{
	if (all->h)
		all->conv->d = va_arg(all->a_list, int);
	else if (all->hh)
		all->conv->d = va_arg(all->a_list, int );
	else if (all->l)
		all->conv->d = va_arg(all->a_list, long int);
	else if (all->ll)
		all->conv->d = va_arg(all->a_list, long long int);
}
void  flag_hh_ll_u(t_spec *all)
{
	if (all->h)
		all->conv->u = va_arg(all->a_list, int);
	else if (all->hh)
		all->conv->u = va_arg(all->a_list, int);
	else if (all->l)
		all->conv->u = va_arg(all->a_list,long unsigned int);
	else if (all->ll)
		all->conv->u = va_arg(all->a_list, unsigned long long int);
}

void  space_x(t_spec *all)
{
	int i;
	i = 0;

	while (all->spec[i] != '\0')
	{
		if (all->spec[i] == ' ' && ft_isdigit(all->spec[i + 1]))
				write(1," ",1);
		i++;
	}
}
