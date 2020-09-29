/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils_flags_bis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imanoka- <imanoka-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 21:27:21 by imanoka-          #+#    #+#             */
/*   Updated: 2020/09/29 11:08:41 by imanoka-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"
//#include "/mnt/c/Users/Audrey/Desktop/manoka/includes/libftprintf.h"
int		size_nb_unsigned (unsigned int n)
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

int size_nb(int n)
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

void  flag_hh_ll_d(t_spec *all)
{
	if (all->h)
		all->conv->d = va_arg(all->a_list, int);
	else if (all->hh)
		all->conv->d = va_arg(all->a_list, int );
	else if (all->l)
		all->conv->d = va_arg(all->a_list, long int);
	else if (all->ll)
		all->conv->d = va_arg(all->a_list, long long int);
}

void  flag_hh_ll_u(t_spec *all)
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
