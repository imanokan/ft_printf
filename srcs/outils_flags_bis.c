/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils_flags_bis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imanoka- <imanoka-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 21:27:21 by imanoka-          #+#    #+#             */
/*   Updated: 2020/09/30 12:06:03 by imanoka-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int			size_nb_unsigned(unsigned int n)
{
	int l;

	l = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		l++;
	}
	return (l);
}

int			size_nb(int n)
{
	int l;

	l = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		l++;
	}
	return (l);
}

void		flag_hh_ll_d(t_spec *all)
{
	if (all->h)
		all->conv->d = va_arg(all->a_list, int);
	else if (all->hh)
		all->conv->d = va_arg(all->a_list, int);
	else if (all->l)
		all->conv->d = va_arg(all->a_list, long int);
	else if (all->ll)
		all->conv->d = va_arg(all->a_list, long long int);
}

void		flag_hh_ll_u(t_spec *all)
{
	if (all->h)
		all->conv->u = va_arg(all->a_list, int);
	else if (all->hh)
		all->conv->u = va_arg(all->a_list, int);
	else if (all->l)
		all->conv->u = va_arg(all->a_list, long unsigned int);
	else if (all->ll)
		all->conv->u = va_arg(all->a_list, unsigned long long int);
}

int			round_up_bis(t_spec *all)
{
	int tmp;

	if (all->stop == 1)
	{
		tmp = all->conv->deci * 100;
		if (tmp % 10 >= 5)
			all->conv->fl = all->conv->deci * 10 + 1;
		else if (tmp % 10 < 5)
			all->conv->fl = all->conv->deci * 10;
		all->conv->fl_int = (int)all->conv->fl;
	}
	else if (all->vision == 0 && all->stop != 6)
	{
		tmp = all->conv->deci * 10;
		if (tmp >= 5)
		{
			all->conv->ent += 1;
			all->conv->fl_int = all->conv->ent;
		}
		if (tmp < 5)
			all->conv->fl = all->conv->ent;
	}
	return (1);
}
