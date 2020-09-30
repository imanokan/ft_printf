/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imanoka- <imanoka-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 15:52:48 by imanoka-          #+#    #+#             */
/*   Updated: 2020/09/30 13:01:11 by imanoka-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		width_s_plus(t_spec *all, char *s)
{
	if (all->hash == 1)
		all->len_arg += 2;
	if (all->len_arg < all->width)
		fill_width_diouxx(all);
	if (all->moins == 1)
	{
		if (all->hash == 1)
		{
			if (all->type == 'X')
				write(1, "0X", 2);
			else
				write(1, "0x", 2);
		}
		ft_putstr(s);
		ft_putstr(all->s_filled_d);
	}
	if (all->moins == 0)
		width_min_s(all, s);
	return (0);
}

void	width_min_s(t_spec *all, char *s)
{
	ft_putstr(all->s_filled_d);
	if (all->hash == 1)
	{
		if (all->type == 'X')
			write(1, "0X", 2);
		else
			write(1, "0x", 2);
	}
	ft_putstr(s);
}

int		precision_s(t_spec *all, char *s)
{
	int i;

	i = 0;
	if (all->len_arg >= all->vision)
	{
		while (i != all->vision)
			ft_putchar(s[i++]);
	}
	else if (all->vision > all->len_arg)
		ft_putstr(s);
	return (0);
}

int		width_precision_s(t_spec *all, char *s)
{
	fill_precision(all);
	all->conv->tmp_str = ft_strsub(s, 0, all->vision);
	all->len_arg = ft_strlen(all->conv->tmp_str);
	all->space = all->width - all->len_arg;
	if (all->len_arg < all->width)
		fill_width_diouxx(all);
	if (all->moins == 1)
	{
		ft_putstr(all->conv->tmp_str);
		ft_putstr(all->s_filled_d);
	}
	width_precision_s_moins(all);
	return (1);
}

void	width_precision_s_moins(t_spec *all)
{
	if (all->moins == 0)
	{
		ft_putstr(all->s_filled_d);
		ft_putstr(all->conv->tmp_str);
	}
}
