/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imanoka- <imanoka-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 21:25:25 by imanoka-          #+#    #+#             */
/*   Updated: 2020/09/29 17:43:18 by imanoka-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include "libft/libft.h"
#include "../includes/libftprintf.h"
//#include "/mnt/c/Users/Audrey/Desktop/manoka/includes/libftprintf.h"


int		specifier_percent(const char *format,t_spec *all)
{
	int j;
	int i;

	j = 0;
	i = 0;

	while (format[i] != '%')
		i += 1;
	j = i;
	j += 1;
	while (format[j] != '%')
	{
		j++;
 		if (ft_isdigit(format[i]) && all->point != 1)
		{
			all->w = 1;
			all->width = ft_atoi(&all->spec[i]);
			break ;
		}
	}
	//all->spec = ft_strsub(format, i, j + 1);
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

void 	free_all(t_spec *all)
{
	free(all->s_filled_d);
	free(all->s_filled_p);
	free(all->s_filled);
	free(all->conv);
	free(all);
}
