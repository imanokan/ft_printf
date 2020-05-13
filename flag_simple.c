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
	all->len = int_in_str(all); //spec
	all->space = all->len - all->len_arg;
	if (all->len_arg < all->len)
	{
		fill_space(all) - 1; // char² all->space -1
		fill_space(all);
	}	
	return (0);

}
int 	flag_simple(t_spec *all)
{
	//if (sign == 1)
		//ft_strjoin(fill_space(len,s),arg);
	//if (sign == 2)
		//write(1,'+',1);
	if (all->plus)
		write(1,"+",1);
	else if (all->moins)
		fill_space(all);
	else if (all->zero)
		fill_0(all);
	//else if (all->space)
		//write(1," ",1);
	return (0);
}

