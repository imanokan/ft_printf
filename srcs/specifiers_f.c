/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imanoka- <imanoka-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 12:18:03 by imanoka-          #+#    #+#             */
/*   Updated: 2020/09/30 12:42:54 by imanoka-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		specifiers_f(t_spec *all)
{
	all->conv->f = check_l_lupper(all);

	all->p = all->conv->f < 0 ? '-' : '+';
	all->isneg = all->conv->f < 0 ? 1 : 0;
	sep_int_deci(all);
	all->len_arg = ft_strlen(all->conv->fl_str);
	if ((all->plus == 1 && all->conv->f > 0) ||
		(all->esp == 1 && all->conv->f > 0)
		|| all->isneg == 1)
		all->len_arg += 1;
	fill_width_diouxx(all);
	if (all->plus == 1 && all->p == '+')
		ft_putchar(all->p);
	else if (all->esp == 1 && all->conv->f > 0)
		write(1, " ", 1);
	width_float(all);
	return (1);
}

int		width_float(t_spec *all)
{
	if (all->w == 1 && all->moins == 0)
	{
		ft_putstr(all->s_filled_d);
		if (all->isneg == 1)
			ft_putchar(all->p);
		if (all->vision == 0 && all->precision == 1)
		{
			if (all->isneg == 0)
				ft_putnbr(all->conv->ent * -1);
			else
				ft_putnbr(all->conv->ent);
		}
		else
			ft_putstr(all->conv->fl_str);
	}
	else if (all->w == 1 && all->moins == 1)
	{
		if (all->isneg == 1)
			ft_putchar(all->p);
		ft_putstr(all->conv->fl_str);
		ft_putstr(all->s_filled_d);
	}
	else
		ft_putstr(all->conv->fl_str);
	return (1);
}

int		sep_int_deci(t_spec *all)
{
	all->conv->ent = (int)all->conv->f;
	all->conv->deci = all->conv->f - all->conv->ent;
	if (all->conv->ent < 0)
		all->conv->ent *= -1;
	all->stop = all->precision == 0 ? 6 : all->vision;
	all->conv->fl = all->conv->deci;
	round_up_mine(all);
	round_up_bis(all);
	join_float(all);
	return (1);
}

char	*join_float(t_spec *all)
{
	char *float_str;
	char *tmp_ent;
	char *tmp_float;
	char *point;

	float_str = malloc(sizeof(char*) + 1);
	all->conv->fl_str = malloc(sizeof(char*) + 1);
	point = ".";
	tmp_ent = ft_itoa(all->conv->ent);
	if (all->conv->fl_int < 0)
		all->conv->fl_int *= -1;
	tmp_float = ft_itoa(all->conv->fl_int);
	float_str = ft_strjoin(tmp_ent, point);
	all->conv->fl_str = all->vision == 0 ? tmp_float
	: ft_strjoin(float_str, tmp_float);
	if (all->stop == 6)
		all->conv->fl_str = ft_strjoin(float_str, tmp_float);
	if (all->vision == 0 && all->hash == 1 && all->stop != 6)
		all->conv->fl_str = float_str;
	if (all->conv->ent % 1 == 0 && all->vision != 0)
		all->conv->fl_str = ft_strjoin(float_str, tmp_float);
	free(float_str);
	return (all->conv->fl_str);
}

int		round_up_mine(t_spec *all) //28 lignes
{
	double	cp_float;
	int		tmp_float;
	double	up;
	int		a;
	int		dix;

	cp_float = all->conv->fl;
	up = 1.0;
	a = 0;
	dix = 10;
	if (all->stop > 1)
	{
		while (a != all->stop)
		{
			cp_float *= 10;
			dix = dix * 10;
			up /= 10;
			a++;
		}
		all->conv->fl = cp_float + up;
		cp_float *= 10;
		tmp_float = (int)cp_float;
		if (tmp_float % 10 < 5)
			all->conv->fl = all->conv->f > 0 ?
				all->conv->fl : all->conv->fl - 1;
		all->conv->fl_int = (int)all->conv->fl;
	}
	return (1);
}
