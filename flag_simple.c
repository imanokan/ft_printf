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
			printf("ision  : %d\n", all->vision);
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

//int	flag_exist_bis(t_spec *all)

int 	width_min(t_spec *all)
{
	//char *s1;

	//s1 = malloc(sizeof(char*));
	all->len = int_in_str(all); //spec 
	all->space = all->len - all->len_arg;
	printf("len space : %d\n", all->len);	
	if (all->len_arg < all->len)
	{
		fill_space(all);
		//fill_0(all);
	}	
	return (0);

}
int 	flag_simple(t_spec *all)
{
	//if (sign == 1)
		//ft_strjoin(fill_space(len,s),arg);
	if (all->plus == 2)
		write(1,"-",1);
	//else 
		//write(1,'+',1); CONDITION TO CHECK LATER 
	//if (all->plus) 
		//write(1,"+",1);
	else if (all->moins)
		fill_space(all);
	else if (all->zero)
		fill_0(all);
	else if (all->space)
		write(1," ",1);
	return (0);
}

