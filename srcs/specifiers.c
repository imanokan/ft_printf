/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imanoka- <imanoka-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 13:30:01 by imanoka-          #+#    #+#             */
/*   Updated: 2020/10/02 12:54:39 by imanoka-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		specifier_p(t_spec *all)
{
	long long	c;

	c = va_arg(all->a_list, long long);
	all->conv->p_str = ft_itoa_base(c, 16);
	if (all->w == 1)
		all->conv->p_str = ft_strjoin("0x", all->conv->p_str);
	else
	{
		write(1, "0x", 2);
		all->count += 2;
	}
	all->len_arg = ft_strlen(all->conv->p_str);
	if (all->w == 1 && all->precision == 0)
		width_s_plus(all, all->conv->p_str);
	else
		ft_putstr(all->conv->p_str);
	return (0);
}

int		specifier_c(t_spec *all)
{
	int c;

	c = va_arg(all->a_list, int);
	all->len_arg = 1;
	all->space = all->width - all->len_arg;
	if (all->len_arg < all->space)
		fill_width_diouxx(all);
	if (all->moins == 1)
	{
		ft_putchar(c);
		ft_putstr(all->s_filled_d);
	}
	else if (all->moins == 0)
	{
		ft_putstr(all->s_filled_d);
		ft_putchar(c);
	}
	else
		ft_putchar(c);
	return (0);
}

int		specifier_s(t_spec *all)
{
	all->conv->c = va_arg(all->a_list, char*);
	all->len_arg = ft_strlen(all->conv->c);
	if (all->w == 1 && all->precision == 0)
		width_s_plus(all, all->conv->c);
	else if (all->precision == 1 && all->w == 0)
		precision_s(all, all->conv->c);
	else if (all->wp == 1)
		width_precision_s(all, all->conv->c);
	else if (all->w != 1 && all->precision != 1)
		ft_putstr(all->conv->c);
	return (0);
}
