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
	long long c;
	char *s;
	char *f;

	i = 0;
	c = va_arg(all->a_list, long long);
	s = ft_itoa_base(c,16);
	f = ft_strjoin("0x",s);
	all->len_arg = ft_strlen((const char*)c);
	//fnct_output_p(all); same pour p
	return (0);
}


int			specifier_c(t_spec *all, ...)
{
		int i;
		char *c;
		char *s;

		i = 0;
		c = va_arg(all->a_list, char*);
		all->len_arg = 1;
		width_min(all);
		if (all->moins)
			s = ft_strjoin(c, all->s_filled);
		ft_putstr(s);
		return (0);
}


int 	specifier_s(t_spec *all, ...)
{

		all->conv->c = va_arg(all->a_list, char*); //mettre dans la structure
		//if (all->width == 1 && all->len_arg < all->len)
		all->len_arg = ft_strlen(all->conv->c);
	//	width_min(all);
		fnct_output_s(all);
		return (0);
}
