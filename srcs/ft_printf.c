/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imanoka- <imanoka-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 19:04:06 by imanoka-          #+#    #+#             */
/*   Updated: 2020/09/29 15:51:14 by imanoka-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include "./libft/libft.h"
#include "../includes/libftprintf.h"
//#include "/mnt/c/Users/Audrey/Desktop/manoka/includes/libftprintf.h"
int  type_spec(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'f'
			|| c == 'd' || c == 'x' || c == 'X' || c == 'i' || c == 'o' || c == 'u' );
}
void initialisation(t_spec *all)
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
	all->check1  = 0;
	all->esp = 0;
}
int       cut_str(const char *format, int *i,  t_spec *all)
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
	}
	return (1);
}
int 	ft_printf(const char *format, ...)
{
	t_spec *all;
	int i;

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
	free(all->conv);
	free(all);
	return (0);
}


int main()
{



	//printf("|%-.5d| |%-.0d| |%-.i|\n",-587,-21,44 );
	//ft_printf("|%-.5d| |%-.0d| |%-.i|\n",-587,-21,44 );


	//printf("|%-.5d|\n",-144 );
	//ft_printf("|%-.5d|\n",-144 );


	ft_printf("|%5%|\n");
	//printf("\n");
	printf("|%5%|\n");
	//printf("\n");
	//printf("%5%\n");
	//printf ("printf23        :|%-0#5f|%-0#5.10f|%-0#5.9f|%-0#5.8f|%-0#5.7f|%-0#5.6f|%-0#5.5f|%-0#5.4f|%-0#5.3f|%-0#5.2f|%-0#5.1f|%-0#5.0f|%-0#5.f|\n\n", 999.7999999,999.7999999,999.7999999,999.7999999,999.7999999,999.7999999,999.7999999,999.7999999,999.7999999,999.7999999,999.7999999,999.7999999,999.7999999);
	//ft_printf ("ft_printf23     :|%-0#5f|%-0#5.10f|%-0#5.9f|%-0#5.8f|%-0#5.7f|%-0#5.6f|%-0#5.5f|%-0#5.4f|%-0#5.3f|%-0#5.2f|%-0#5.1f|%-0#5.0f|%-0#5.f|\n", 999.7999999,999.7999999,999.7999999,999.7999999,999.7999999,999.7999999,999.7999999,999.7999999,999.7999999,999.7999999,999.7999999,999.7999999,999.7999999);

	//printf("|%5%| \n");
	//ft_printf("|%%5| \n");


	//printf("|%5d|\n",-44);
	//ft_printf("|%5d|\n",-44);

	//printf("|%+ 5i|%+ 5.3i|%+ 5.1i|%+ 5.0i|%+ 5.i|\n", 5,5,5,5,5);
	//ft_printf ("|%+ 5i|%+ 5.3i|%+ 5.1i|%+ 5.0i|%+ 5.i|\n", 5,5,5,5,5);

	//printf("Salut %-+10.4d  %-+12.5d |%-.5d| |%-.0d| |%-.ibipboup|\n", 50, 140, -587, -21, 44);
	//ft_printf("Salut %-+10.4d  %+-12.5d |%-.5d| |%-.0d| |%-.ibipboup|\n", 50, 140, -587, -21, 44);

	//printf("printf|%-0#5.1f|\n",d);
	//ft_printf("ft_printf|%-0#5.1f|\n",d);

	//printf ("printf7     :|%-#5f|%-#5.3f|%-#5.1f|%-#5.0f|%-#5.f|\n", 15.4,15.4,15.4,15.4,15.4);
	//ft_printf ("ft_printf7  :|%-#5f|%-#5.3f|%-#5.1f|%-#5.0f|%-#5.f|\n", 15.4,15.4,15.4,15.4,15.4);
	//printf ("printf9     :|%-0#5f|%-0#5.3f|%-0#5.1f|%-0#5.0f|%-0#5.f|\n", 0,0,0,0,0);
	//ft_printf ("ft_printf9  :|%-0#5f|%-0#5.3f|%-0#5.1f|%-0#5.0f|%-0#5.f|\n", 0,0,0,0,0);
	return (0);
}
