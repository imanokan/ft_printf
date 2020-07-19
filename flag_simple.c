#include "libftprintf.h"

int	flag_exist(const char *format, t_spec *all)
{
 	int i; 
	i = 0;
	while (format[i] != '\0')
	{
		if (all->spec[i] == '+')
		{
			all->plus = 1;
			printf("+K\n");
		}
		else if (all->spec[i] == '-')
		{
			all->moins = 1;
			printf("-K\n");
		}
		else if (all->spec[i] == '0') 
		{
			all->zero = 1;
			printf("0K\n");
		}
		else if (all->spec[i] == ' ') 
		{
			all->space = 1;
			printf("sK\n");
		}
		else if (all->spec[i] == '#')
		{
			all->hash = 1;
			printf("#K\n");
		}
		else if (all->spec[i] == '.' && ft_isdigit(all->spec[i + 1]))
		{
			//all->ision = 1;
			all->vision = int_in_str(all);
		}
		else if (all->moins == 1 && all->zero == 1)   
		{
			all->zero = 0;
			printf("d-K\n");
		}
		else if (all->plus == 1 && all->space == 1)
		{
			all->space = 0;
			printf("d+K\n");
		}
		i++;
	}
	return (0);
}


int 	width_min(t_spec *all)
{

	if (all->len = int_in_str(all)); //spec
		//return (-1);
	all->space = all->len - all->len_arg;
	printf("len space : %d\n", all->len);	
	if (all->len_arg < all->len)
		fill_space(all);
	return (0);

}
