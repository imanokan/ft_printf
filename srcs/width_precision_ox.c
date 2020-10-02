/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_precision_ox.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imanoka- <imanoka-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 15:55:33 by imanoka-          #+#    #+#             */
/*   Updated: 2020/10/02 17:55:00 by imanoka-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		precision_ox(t_spec *all, char *s)
{
	if (all->hash == 1)
	{
		if (all->type == 'X')
			write(1, "0X", 2);
		else
			write(1, "0x", 2);
	}
	fill_precision(all);
	space_plus_p(all);
	if (all->vision > 0)
		ft_putstr(all->s_filled_p);
	ft_putstr(s);
	return (1);
}

int		width_precision_ox(t_spec *all, char *s)
{
	fill_precision(all);
	if (all->hash == 1)
		all->len_arg += 2;
	fill_width_diouxx(all);
	if (all->moins == 1)
	{
		space_plus(all);
		ft_putstr(all->s_filled_p);
		ft_putstr(s);
		ft_putstr(all->s_filled_d);
	}
	else if (all->moins == 0)
	{
		ft_putstr(all->s_filled_d);
		space_plus(all);
		if (all->hash == 1)
			all->type == 'X' ? write(1, "0X", 2) : write(1, "0x", 2);
		ft_putstr(all->s_filled_p);
		ft_putstr(s);
	}
	return (1);
}

int		width_unsigned(t_spec *all, unsigned int nb)
{
	fill_width_diouxx(all);
	all->moins == 1 ? ft_putnbr_long(nb) : ft_putstr(all->s_filled_d);
	all->moins == 1 ? ft_putstr(all->s_filled_d) : ft_putnbr_long(nb);
	return (1);
}

int		precision_unsigned(t_spec *all, unsigned int nb)
{
	fill_precision(all);
	space_plus_p(all);
	if (all->vision > 0)
		ft_putstr(all->s_filled_p);
	ft_putnbr_long(nb);
	return (1);
}

int		width_precision_unsigned(t_spec *all, unsigned int nb)
{
	fill_precision(all);
	fill_width_diouxx(all);
	if (all->moins == 1)
 	{
		//space_plus(all);
		ft_putstr(all->s_filled_p);
		ft_putnbr_long(nb);
		ft_putstr(all->s_filled_d);
	}
	else if (all->moins == 0)
	{
		ft_putstr(all->s_filled_d);
		//space_plus(all);
		ft_putstr(all->s_filled_p);
		ft_putnbr_long(nb);
	}
	return (1);
}
