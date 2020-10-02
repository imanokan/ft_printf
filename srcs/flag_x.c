/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imanoka- <imanoka-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 18:00:00 by imanoka-          #+#    #+#             */
/*   Updated: 2020/10/02 20:45:47 by imanoka-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int 	width_x(t_spec *all)
{
	if (all->hash == 1 && all->conv->x_str[0] != '0')
		all->len_arg += 2;
	if (all->len_arg < all->width)
		fill_width_diouxx(all);
	if (all->moins == 1)
	{
		if (all->hash == 1 && all->conv->x_str[0] != '0')
			all->type == 'X' ? write(1, "0X", 2) : write(1, "0x", 2);
		ft_putstr(all->conv->x_str);
		ft_putstr(all->s_filled_d);
	}
	else if (all->moins == 0)
	{
		if (all->zero == 0)
		{
				ft_putstr(all->s_filled_d);
				if (all->hash == 1 && all->conv->x_str[0] != '0')
					all->type == 'X' ? write(1, "0X", 2) : write(1, "0x", 2);
				//ft_putstr(all->s_filled_d);
				ft_putstr(all->conv->x_str);
		}
		else
		{
			//ft_putstr(all->s_filled_d);
			if (all->hash == 1 && all->conv->x_str[0] != '0')
				all->type == 'X' ? write(1, "0X", 2) : write(1, "0x", 2);
			ft_putstr(all->s_filled_d);
			ft_putstr(all->conv->x_str);
		}
	}
	return (0);
}

int 	precision_x(t_spec *all)
{
	if (all->hash == 1 && all->conv->x_str[0] != '0')
		all->len_arg += 2;
	if (all->hash == 1 && all->conv->x_str[0] != '0')
		all->type == 'X' ? write(1, "0X", 2) : write(1, "0x", 2);
	fill_precision(all);
	if (all->vision > 0)
		ft_putstr(all->s_filled_p);
	ft_putstr(all->conv->x_str);
	return(0);

}
int 	width_precision_x(t_spec *all)
{
	if (all->hash == 1 && all->conv->x_str[0] != '0')
		all->len_arg += 2;
	fill_precision(all);
	fill_width_diouxx(all);
	if (all->moins == 1)
	{
		if (all->hash == 1 && all->conv->x_str[0] != '0')
			all->type == 'X' ? write(1, "0X", 2) : write(1, "0x", 2);
		ft_putstr(all->s_filled_p);
		ft_putstr(all->conv->x_str);
		ft_putstr(all->s_filled_d);
	}
	else if (all->moins == 0)
	{
		ft_putstr(all->s_filled_d);
		if (all->hash == 1 && all->conv->x_str[0] != '0')
			all->type == 'X' ? write(1, "0X", 2) : write(1, "0x", 2);
		ft_putstr(all->s_filled_p);
		ft_putstr(all->conv->x_str);
	}
	return(0);
}
