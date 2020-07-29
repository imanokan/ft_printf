#include "libft.h"
#include <stdio.h>
int		ft_atoi(const char *str)
{
	unsigned int	i;
	int				is_neg;
	int				result;

	//printf("str ; %s\n",str);
	i = 0;
	is_neg = 1;
	result = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\r'
			|| str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		is_neg = -1;
		if (str[i + 1] == '+')
			return (0);
		i++;
	}
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result * is_neg);
}
