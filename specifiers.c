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

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "./libft/libft.h"
#include "./libftprint.h"

//str = "list avec les flgs et speficiers"
// ... = "list avec les arguments "

int		ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

void		specifier_p(const char *str, ...)
{
	va_list a_list;
	int i;
	long c;

	i = 0;
	va_start(a_list,str);
	while(str[i] != '\0')
	{
			ft_putchar(str[i]);
		if (str[i] == '%' && str[i + 1] == 'p')
		{
			c = va_arg(a_list, long);
			//flags
			//width
			//precision
			//length
			ft_putstr(ft_strjoin("0x", ft_itoa_base(c, 16, 'm')));
		}
		i++;
	}
	va_end(a_list);
	write (1,"\n",1);
}


int			specifier_c(const char *str, ...)
{
		int i;
		int c;
		va_list a_list;

		i = 0;
		va_start(a_list, str);
		while (str[i] != '\0')
		{
			if (str[i] == '%' && str[i + 1] == 'c')
			{
				c = va_arg(a_list, int);
				ft_putchar(c);
			}
			i++;
		}
		va_end(a_list);
		write(1,"\n",1);
		return (0);
}


int 	specifier_s(const char *str, ...)
{
		int i;
		char *s;

		i = 0;
		va_start(a_list, str);
		while (str[i] != '\0')
		{
			if (str[i] == '%' && str[i + 1] == 's')
			{
				c = va_arg(a_list, char*);
				ft_putstr(c);
			}
			i++;
		}
		va_end(a_list);
		write(1, "\n",1);
		return (0);
}


int		cut_before(char *str)
{
	int i;
	char bef[80];
	
	i = 0;
	while (str)
	{
		if (str[i] == '%')
			ft_strncpy(bef,str,i);
		i++;
	}
	return (0);
}
