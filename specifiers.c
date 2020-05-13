/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imanoka- <imanoka-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 13:30:01 by imanoka-          #+#    #+#             */
/*   Updated: 2020/03/12 15:47:54 by imanoka-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libftprintf.h"

int		specifier_p(t_spec *all, ...)
{	
	int i;
	long c;

	i = 0;
	while(all->spec[i] != '\0')
	{
		if (all->spec[i] == '%' && all->spec[i + 1] == 'p')
		{
			c = va_arg(all->a_list, long);
			all->len_arg = ft_strlen((const char*)c);
			ft_putstr(ft_strjoin("0x", ft_itoa_base(c, 16, 'm')));
		}
		i++;
	}
	write (1,"\n",1);
	return (0);
}


int			specifier_c(t_spec *all, ...)
{
		int i;
		char c;

		i = 0;
		while (all->spec[i] != '\0')
		{
			if (all->spec[i] == '%' && all->spec[i + 1] == 'c')
			{
				c = va_arg(all->a_list, int);
				all->len_arg = 1;
				ft_putchar(c);
			}
			i++;
		}
		write(1,"\n",1);
		return (0);
}


int 	specifier_s(t_spec *all, ...)
{
		char *c;
		
		c = va_arg(all->a_list, char*);
		//printf("\n arg1 : %s\n", c);
		all->len_arg = ft_strlen(c);
		//ft_putchar(c);
		ft_putstr(c);
		//write(1, "\n",1);
		return (0);
}
