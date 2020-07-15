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
char *fill_0_bis(t_spec *all)
{
	char *s;
	int i;

	i = 0;
	if( !(all->s_filled = malloc(sizeof(char*) * all->space + 1)))
		//return (-1);
	while (i < all->space)
	{
		all->s_filled[i] = '0';
		i++;
	}
	return (all->s_filled);
}*/
/*
int plus_min(t_spec *all)
{
	if (all->plus)
		all->c < 0 ? write(1,"-",1): write(1,"+",1);
	if (flag && all->min) //fonctionne pour s mais à réfléchir pour diouxX
		all->s = ft_strjoin(c, all->s_filled);

}
// int flag_hh_ll(t_spec *all)

int flag_hh_l(t_spec *all)

int flagif (all->type == 'X')
		c = toupper(va_arg(all->all_list, int*));
	if (all->hash)
	{
		if (all->type == 'X')
			write(1,"OX",2);
		else
			write(1,"ox",2);
	}
	return (0);
}
*/

