/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imanoka- <imanoka-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 15:10:22 by imanoka-          #+#    #+#             */
/*   Updated: 2020/09/29 16:01:03 by imanoka-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "./libft/libft.h"
#include "../includes/libftprintf.h"
//#include "/mnt/c/Users/Audrey/Desktop/manoka/includes/libftprintf.h"

int		fill_width_diouxx(t_spec *all)
{
	int i;

	i = 0;
	all->space = all->width - all->len_arg;
	all->s_filled_d = (char*)malloc(sizeof(char));
	while (i < all->space)
	{
		if (all->zero == 1 )
			all->s_filled_d[i++] = '0';
		else if (all->zero == 0)
			all->s_filled_d[i++] = ' ';
	}
	all->s_filled_d[i] ='\0';
	return (1);
}

int fill_precision(t_spec *all)
{
	int j;

	j = 0;
	all->pision = all->vision - all->len_arg;
	if (all->conv->d < 0 || all->plus == 1)
		all->pision += 1;
	all->s_filled_p = (char*)malloc(sizeof(char));
	while (j < all->pision)
		all->s_filled_p[j++] = '0';
	all->s_filled_p[j] ='\0';
	all->len_arg = all->len_arg + j;
	return (1);
}

void space_plus(t_spec *all)
{
	if ((all->type != 'u') || (all->type != 'x'))
	{
		if (all->plus == 1 && all->isneg != 1 && all->precision == 1)
			ft_putchar(all->p);
		//all->check1 = 1; // perturbe
		if (all->esp == 1)
			write(1," ",1);
	}
}

void check_type(t_spec *all)
{
	if (all->type == 'd' || all->type == 'i')
		ft_putnbr_long(all->conv->d);
	if (all->type == 'u')
		ft_putnbr_long(all->conv->u);
	if (all->type == 'o')
		ft_putnbr_long(all->conv->o);
}


void space_plus_p(t_spec *all)
{

	if (all->esp == 1 && all->isneg == 0)
		write(1, " ", 1);
	if ((all->plus == 1) || (all->isneg == 1))
		ft_putchar(all->p);
}