/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imanoka- <imanoka-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 12:10:13 by imanoka-          #+#    #+#             */
/*   Updated: 2020/10/03 22:00:32 by imanoka-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		specifier_d(t_spec *all)
{
	//printf("ll : %d\n", all->ll);
	all->conv->d = check_l_ll_h_hh(all->conv->d, all);
//	printf("d : %jd\n",all->conv->d );
	all->conv->d_str = ft_itoa_base(all->conv->d, 10);
//	printf("d44 : %s\n",all->conv->d_str );
	all->len_arg = size_nb(all->conv->d);
	if (all->esp == 1 || all->plus == 1)
			all->len_arg += 1;
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
		//ft_putstr(all->conv->d_str);
	}
	return (0);
}

int		specifier_x(t_spec *all)
{
	int i;
	//char *s;

	i = 0;
	all->conv->x = check_l_ll_h_hh_unsigned(all->conv->x, all);
	all->conv->x_str = ft_itoa_base(all->conv->x, 16);
	if (all->type == 'X')
		ft_toupper_string(all->conv->x_str);
	all->len_arg = ft_strlen(all->conv->x_str);
	if (all->w == 1 && all->precision == 0)
 		width_x(all);
	else if (all->w == 0 && all->precision == 1)
		precision_x(all);
	else if (all->w == 1 && all->precision == 1)
		width_precision_x(all);
	else
	{
		if (all->hash == 1 && all->conv->x_str[0] != '0')
			all->type == 'X' ? write(1, "0X", 2) : write(1, "0x", 2);
		ft_putstr(all->conv->x_str);
	}
	return (0);
}

int		specifier_o(t_spec *all)
{
	all->conv->o = check_l_ll_h_hh_unsigned(all->conv->o, all);
	all->conv->o_str = ft_itoa_base(all->conv->o, 8);
	if (all->hash == 1 && all->conv->o_str[0] != '0')
		all->conv->o_str = ft_strjoin("0", all->conv->o_str);
	all->len_arg = ft_strlen(all->conv->o_str);
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
