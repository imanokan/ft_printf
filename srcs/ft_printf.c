/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imanoka- <imanoka-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 19:04:06 by imanoka-          #+#    #+#             */
/*   Updated: 2020/10/02 12:52:48 by imanoka-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int			type_spec(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'f'
			|| c == 'd' || c == 'x' || c == 'X' || c == 'i' || c == 'o'
			|| c == 'u' );//|| c == '%');
}

void		initialisation(t_spec *all)
{
	all->zero = 0;
	all->space = 0;
	all->len_arg = 0;
	all->width = 0;
	all->s_filled_d = NULL;
	all->s_filled_p = NULL;
	all->pision = 0;
	all->w = 0;
	all->point = 0;
	all->plus = 0;
	all->wp = 0;
	all->check = 0;
	all->moins = 0;
	all->hash = 0;
	all->precision = 0;
	all->vision = 0;
	all->isneg = 0;
	all->esp = 0;
	all->count = 0;
	all->count_bis = 0;
}

int			cut_str(const char *format, int *i, t_spec *all)
{
	int j;


	if (format[*i] == '%' && format[*i + 1] != '%')
	{
		j = 0;
		while (format[*i] && !type_spec(format[*i]))
		{
			*i = *i + 1;
			j++;
		}
		//specifier_percent(format, all);
		all->type = format[*i];
		all->spec = ft_strsub(format, *i - j, j + 1);
		//printf("all->spec : %s", all->spec);
		flag_exist(all);
		ft_precision(all);
		flag_corr(all);
		ft_precision(all);
		//specifier_percent(format, all);
		conversion_specifier(all);
	}
	else
	{
		if (format[*i] == '%')
			*i = *i + 1;
		write(1, &format[*i], 1);
		all->count_bis += 1;
	}
	// rintf("all->spec : %s\n", all->spec);
	return (1);
}

int			ft_printf(const char *restrict format, ...)
{
	t_spec	*all;
	int		i;
	int		count;

	i = 0;
	all = malloc(sizeof(t_spec));
	initialisation(all);
	all->conv = (t_conv*)malloc(sizeof(t_conv));
	va_start(all->a_list, format);
	while (format[i])
	{
		cut_str(format, &i, all);
		i++;
	}
	va_end(all->a_list);
	count_return(all);
	count = all->count;
	free(all->conv);
	free(all);
	//free_all(all);
	return (count);
}
