/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imanoka- <imanoka-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 21:06:43 by imanoka-          #+#    #+#             */
/*   Updated: 2020/09/29 12:09:14 by imanoka-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"
//#include "/mnt/c/Users/Audrey/Desktop/manoka/includes/libftprintf.h"
void flag_exist(t_spec *all) //28 lignes
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
		else if (all->spec[i] == '0'  && ft_isascii(all->spec[i + 1]))
			all->zero = 1;
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

void  flag_exist_1(t_spec *all)
{
	int i;

	i = 0;
	while (all->spec[i] != '\0')
	{
		if (all->spec[i] == ' ')
			all->esp = 1;
		else if (all->spec[i] == '#')
			all->hash = 1;
		else if (all->spec[i] == '.')
			all->point = 1;

		i++;
	}
}

void ft_precision(t_spec *all)
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
void    flag_corr(t_spec *all)
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

void	flag_exist_bis(const char *format, t_spec *all)
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
			all->L = 1;
		else if (all->type == 'f' && all->spec[i] == 'l')
			all->l = 2;
		i++;
	}
}

int	width_s_plus(t_spec *all, char *s)
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
		width_min_s(all,s);
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

int		width_precision_s(t_spec *all, char *s) //29 lines
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
	width_precision_s_moins(all,all->conv->tmp_str);
	//free function
	return (1);
}
void	width_precision_s_moins(t_spec *all,char *s)
{
	if (all->moins == 0)
	{
		ft_putstr(all->s_filled_d);
		ft_putstr(all->conv->tmp_str);
	}
}

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
