/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imanoka- <imanoka-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 13:30:01 by imanoka-          #+#    #+#             */
/*   Updated: 2020/03/12 14:13:10 by imanoka-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "./libft/libft.h"

//str = "list avec les flgs et speficiers"
// ... = "list avec les arguments "
void		ft_printf(const char *str, ...)
{
	va_list a_list;
	int i;
	long c;

	i = 0;
	va_start(a_list,str);
	while(str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] == 'p')
		{
			c = va_arg(a_list, long);
			ft_putendl(ft_strjoin("0x", ft_itoa_base(c, 16, 'm')));
		}
		i++;
	}
	va_end(a_list);
}

int main(void)
{
	//char *c;
	char *c;

	c = "audr";
	//p = &c;

	ft_printf("%p\n", &c);

	printf("pointeur : %p\n",&c);
	return (0);
}
