/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imanoka- <imanoka-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 21:06:43 by imanoka-          #+#    #+#             */
/*   Updated: 2020/09/30 13:36:57 by imanoka-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void		flag_exist(t_spec *all)
{
	int i;

	i = 0;
	while (all->spec[i] != '\0')
	{
		if (all->spec[i] == '+')
			all->plus = 1;
		else if (all->spec[i] == '-')
			all->moins = 1;
		else if (all->spec[i] == '0' && ft_isdigit(all->spec[i + 1]))
			all->zero = 1;
		else if (all->spec[i] == '0' && ft_isascii(all->spec[i + 1]))
			all->zero = 1;
		else if (all->spec[i] == '.')
			all->point = 1;
		else if ((ft_isdigit(all->spec[i]) && all->point != 1))
		{
			all->w = 1;
			all->width = ft_atoi(&all->spec[i]);
			break ;
		}
		i++;
	}
	flag_exist_1(all);
}

void		flag_exist_1(t_spec *all)
{
	int i;

	i = 0;
	while (all->spec[i] != '\0')
	{
		if (all->spec[i] == ' ')
			all->esp = 1;
		else if (all->spec[i] == '#')
			all->hash = 1;
		i++;
	}
}

void		ft_precision(t_spec *all)
{
	int i;

	i = 0;
	while (all->spec[i] != '\0')
	{
		if (all->spec[i] == '.')
		{
			all->precision = 1;
			all->vision = ft_atoi(&all->spec[i + 1]);
		}
		i++;
	}
}

void		flag_corr(t_spec *all)
{
	if (all->moins == 1 && all->zero == 1)
		all->zero = 0;
	if (all->plus == 1 && all->esp == 1)
		all->esp = 0;
	if (all->zero == 1 && all->precision == 1 && all->type != 'f')
		all->zero = 0;
	if (all->w == 1 && all->precision == 1)
		all->wp = 1;
	if (all->plus == 1 && all->moins == 1)
		all->plus = 1;
}

void		flag_exist_bis(const char *format, t_spec *all)
{
	int i;

	i = 0;
	while (format[i] != '\0')
	{
		if (all->spec[i] == 'h')
			all->h = 1;
		else if (all->spec[i] == 'l')
			all->l = 1;
		else if (all->spec[i] == 'h' && all->spec[i + 1] == 'h')
			all->hh = 1;
		else if (all->spec[i] == 'l' && all->spec[i + 1] == 'l')
			all->ll = 1;
		else if (all->spec[i] == 'L' && all->type == 'f')
			all->l = 2;
		else if (all->type == 'f' && all->spec[i] == 'l')
			all->l = 1;
		i++;
	}
}
