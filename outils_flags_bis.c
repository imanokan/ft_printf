#include "libftprintf.h"
int size_nb_unsigned (unsigned int n)
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
