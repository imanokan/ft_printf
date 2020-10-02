/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imanoka- <imanoka-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 12:10:13 by imanoka-          #+#    #+#             */
/*   Updated: 2020/10/02 13:32:03 by imanoka-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		specifier_d(t_spec *all)
{
	all->conv->d = check_l_ll_h_hh(all->conv->d, all);
	all->len_arg = size_nb(all->conv->d);
	//if (all->esp == 1 || all->plus == 1 || all->conv->d < 0)
		//all->len_arg += 1;
	//printf("len : %d\n",all->len_arg);
	all->p = all->conv->d < 0 ? '-' : '+';
	all->isneg = all->conv->d < 0 ? 1 : 0;
	if (all->isneg == 1)
		all->len_arg += 1;
	if (all->w == 1 && all->precision == 0)
		width_signed(all, all->conv->d);
	else if (all->w == 0 && all->precision == 1)
		precision_signed(all, all->conv->d);
	else if (all->w == 1 && all->precision == 1)
		width_precision_signed(all, all->conv->d);
	else if (all->w == 0 && all->precision == 0)
	{
		space_plus(all);
		ft_putnbr_long(all->conv->d);
	}
	return (0);
}

int		specifier_x(t_spec *all)
{
	int i;
	char *s;

	i = 0;
	all->conv->x = check_l_ll_h_hh_unsigned(all->conv->x, all);
	s = ft_itoa_base(all->conv->x, 16);
	if (all->type == 'X')
		while (s[i] != '\0')
			ft_toupper_string(&s[i++]);
	//fill number if needed et space en precision puis le ar
	all->len_arg = ft_strlen(s);
	/*if (all->hash == 1 && s[0] != '0')
	{
		if (all->type == 'X')
			all->conv->x_str = ft_strjoin("0X", s);
		else if (all->type == 'x')
			all->conv->x_str = ft_strjoin("0x",s);
		//free(s);
	}
	else
		all->conv->x_str = s;
	free(s); autre fonction */
	all->len_arg = ft_strlen(all->conv->x_str) + 1;
	if (all->w == 1 && all->precision == 0)
		width_s_plus(all, all->conv->x_str);
	else if (all->w == 0 && all->precision == 1)
		precision_ox(all, all->conv->x_str);
	else if (all->w == 1 && all->precision == 1)
		width_precision_ox(all, all->conv->x_str);
	else
		ft_putstr(all->conv->x_str);
	return (0);
}

int		specifier_o(t_spec *all)
{
	all->conv->o = check_l_ll_h_hh_unsigned(all->conv->o, all);
	all->conv->o_str = ft_itoa_base(all->conv->o, 8);
	all->len_arg = size_nb(all->conv->o);
	if (all->w == 1 && all->precision == 0)
		width_s_plus(all, all->conv->o_str);
	else if (all->w == 0 && all->precision == 1)
		precision_ox(all, all->conv->o_str);
	else if (all->w == 1 && all->precision == 1)
		width_precision_ox(all, all->conv->o_str);
	else
		ft_putstr(all->conv->o_str);
	return (0);
}

int		specifier_u(t_spec *all)
{
	all->conv->u = check_l_ll_h_hh_unsigned(all->conv->u, all);
	if (all->conv->u < 0)
		all->conv->u = UINT_MAX - all->conv->u;
	else if (all->conv->u > UINT_MAX)
		all->conv->u = UINT_MAX + all->conv->u;
	all->conv->u_str= ft_itoa_base(all->conv->u, 10);
	all->len_arg = ft_strlen(all->conv->u_str);
	if (all->w == 1 && all->precision == 0)
		width_unsigned(all, all->conv->u);
	else if (all->w == 0 && all->precision == 1)
		precision_unsigned(all, all->conv->u);
	else if (all->w == 1 && all->precision == 1)
		width_precision_unsigned(all, all->conv->u);
	else
		ft_putnbr_long(all->conv->u);
	return (0);
}
