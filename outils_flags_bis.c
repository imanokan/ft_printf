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


int plus_min(t_spec *all)
{
	if  (all->min) //fonctionne pour s mais à réfléchir pour diouxX
		all->s = ft_strjoin(c, all->s_filled);

}
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
int flag_hash(t_spec *all)
{
	int c;
	int x;
	if (all->type == 'X')
		c = toupper(va_arg(all->all_list, int));
	if (all->hash)
	{
		if (all->type == 'X')
			write(1,"OX",2);
		else
			write(1,"ox",2);
	}
	all->x = ft_itoa_base(x,16);
	return (all->);
}

