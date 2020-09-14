/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imanoka- <imanoka-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 13:30:01 by imanoka-          #+#    #+#             */
/*   Updated: 2020/09/14 12:21:03 by imanoka-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libftprintf.h"

int		specifier_p(t_spec *all, ...)
{
	int i;
	long long c;
 	char *s;
	unsigned char *f;

	i = 0;
	c = va_arg(all->a_list, long long);
	s = ft_itoa_base(c,16);
	f = (unsigned char *)ft_strjoin("0x",s);
	//ft_strcpy(all->conv->p, f);
	all->len_arg = ft_strlen((const char*)c);
	if (all->w != 1 && all->precision != 1)
			ft_putstr((const char *)f);
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
		all->conv->c = va_arg(all->a_list, char*);
		all->len_arg = ft_strlen(all->conv->c);
		if (all->w == 1  && all->precision == 0)
			width_s(all);
		else if (all->precision == 1 && all->w == 0)
			precision_s(all);
		else if (all->wp == 1)
			width_precision_s(all);
		//else if (all->conv->c == NULL)
		else if (all->w != 1 && all->precision != 1)
				ft_putstr(all->conv->c);
		return (0);
}
