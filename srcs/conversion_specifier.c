/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_specifier.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imanoka- <imanoka-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 21:00:43 by imanoka-          #+#    #+#             */
/*   Updated: 2020/09/30 15:57:16 by imanoka-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int					conversion_specifier(t_spec *all)
{
	if (all->type == 'c')
		specifier_c(all);
	else if (all->type == 's')
		specifier_s(all);
	else if (all->type == 'p')
		specifier_p(all);
	else if (all->type == 'd' || all->type == 'i')
		specifier_d(all);
	else if (all->type == 'u')
		specifier_u(all);
	else if (all->type == 'o')
		specifier_o(all);
	else if (all->type == 'x' || all->type == 'X')
		specifier_x(all);
	else if (all->type == 'f')
		specifiers_f(all);
	return (0);
}

intmax_t			check_l_ll_h_hh(intmax_t nb, t_spec *all)
{
	if (all->l == 1)
		nb = va_arg(all->a_list, long int);
	else if (all->ll == 1)
		nb = va_arg(all->a_list, long long int);
	else if (all->h == 1)
		nb = (short int)va_arg(all->a_list, int);
	else if (all->hh == 1)
		nb = (char)va_arg(all->a_list, int);
	else
		nb = va_arg(all->a_list, int);
	return (nb);
}

uintmax_t			check_l_ll_h_hh_unsigned(uintmax_t nb, t_spec *all)
{
	if (all->l == 1)
		nb = va_arg(all->a_list, unsigned long int);
	else if (all->ll == 1)
		nb = va_arg(all->a_list, unsigned long long int);
	else if (all->h == 1)
		nb = (unsigned short int)va_arg(all->a_list, int);
	else if (all->hh == 1)
		nb = (unsigned char)va_arg(all->a_list, int);
	else
		nb = va_arg(all->a_list, unsigned int);
	return (nb);
}

long double			check_l_lupper(t_spec *all)
{
	long double nb;

	if (all->l == 1 || all->l == 2)
		nb = va_arg(all->a_list, long double);
	else
		nb = va_arg(all->a_list, double);
	return (nb);
}
int			count_return(t_spec *all)
{
	//printf("all->count : %d\n", all->count);
	if (all->w == 1 && all->precision == 0)
	{
		all->count = all->width;
		//printf("all->count 1 : %d\n", all->count);
	}
	else if (all->w == 0 && all->precision == 1)
		all->count = all->precision;
	else if (all->w == 1 && all->precision == 1)
		all->count = all->width;
	if (all->esp == 1 && all->plus == 1)
	 	all->count = all->count+ 1;
		//printf("all->count 2: %d\n",all->count);

	//if (all->esp == 1 || all->isneg == 1 || all->plus == 1)
	//	all->count += 1;

	return (all->count);
}
