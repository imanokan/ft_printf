/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_precision_di.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imanoka- <imanoka-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 16:00:21 by imanoka-          #+#    #+#             */
/*   Updated: 2020/09/29 18:32:20 by imanoka-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int     width_signed(t_spec *all, signed int nb)
{
 	if (nb >= 0)
	{
		space_plus(all);
		fill_width_diouxx(all);
		if (all->plus == 1  && all->isneg != 1)
				ft_putchar(all->p);
		all->moins == 1 ? ft_putnbr_long(nb): ft_putstr(all->s_filled_d);
		if (all->plus == 1 && all->isneg == 1)
				ft_putchar(all->p);
		all->moins == 1 ? ft_putstr(all->s_filled_d) : ft_putnbr_long(nb);
	}
	else if (nb < 0)
		width_signed_moins(all, nb);
	return (1);
}

void 	width_signed_moins(t_spec *all, signed int nb)
{
	fill_width_diouxx(all);
	if (all->moins == 1)
	{
	//	space_plus(all);
		all->isneg == 1 ? ft_putchar(all->p) : ft_putnbr_long(nb);
		if (all->isneg == 1)
			ft_putnbr_long(nb * -1);
		ft_putstr(all->s_filled_d);
	}
	else if (all->moins == 0)
	{
		//space_plus(all);
		ft_putstr(all->s_filled_d);
		all->isneg == 1 ? ft_putchar(all->p) : ft_putnbr_long(nb);
			if (all->isneg == 1)
				ft_putnbr_long(nb * -1);
		}
}

int		precision_signed(t_spec *all, signed int nb)
{
	fill_precision(all);
	space_plus_p(all);
	if (all->vision > 0)
		ft_putstr(all->s_filled_p);
	if (all->isneg == 1)
	//ft_putchar(all->p);
		ft_putnbr_long(nb * -1);
	else
		ft_putnbr_long(nb);
	return (1);
}

int		width_precision_signed(t_spec *all, long long nb)
{
	fill_precision(all);
	fill_width_diouxx(all);
	if (all->moins == 1)
	{
		space_plus(all);
		if (all->isneg == 1)
			ft_putchar(all->p);
		ft_putstr(all->s_filled_p);
		all->isneg == 1 ? ft_putnbr_long(nb * -1) : ft_putnbr_long(nb);
		ft_putstr(all->s_filled_d);
	}
	if (all->moins == 1)
		width_precision_signed_moins(all,nb);
	return (1);
}


void width_precision_signed_moins(t_spec *all, long long nb)
{
	ft_putstr(all->s_filled_d);
	space_plus(all);
	if (all->isneg == 1)
	{
		ft_putchar(all->p);
		ft_putstr(all->s_filled_p);
		ft_putnbr_long(nb * -1);
	}
	else if (all->isneg == 0)
	{
		ft_putstr(all->s_filled_p);
		ft_putnbr_long(nb);
	}

}
