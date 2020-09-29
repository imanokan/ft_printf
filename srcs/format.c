/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imanoka- <imanoka-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 21:25:25 by imanoka-          #+#    #+#             */
/*   Updated: 2020/09/29 11:08:06 by imanoka-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include "libft/libft.h"
#include "../includes/libftprintf.h"
//#include "/mnt/c/Users/Audrey/Desktop/manoka/includes/libftprintf.h"


//percent specifier
int		cut_str_bis(const char *format, int *i, t_spec *all)
{
	int j;

	j = 0;
	while (format[*i] != '%')
		*i = *i + 1;
	j = *i;
	j += 1;
	while (format[j] != '%')
		j++;
	all->spec = ft_strsub(format, *i, j + 1);
	all->len_arg = 1;
	flag_exist(all);
	flag_corr(all);
	fill_width_diouxx(all);
	if (all->moins == 1)
	{
		ft_putstr("%");
		ft_putstr(all->s_filled_d);
	}
	if (all->moins == 0)
	{
		ft_putstr(all->s_filled_d);
		ft_putchar('%');
	}
	return (0);
}
