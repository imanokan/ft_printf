/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imanoka- <imanoka-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 13:30:01 by imanoka-          #+#    #+#             */
/*   Updated: 2020/03/12 15:47:54 by imanoka-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libftprintf.h"

int		specifier_p(t_spec *all, ...)
{	
	int i;
	long long c; 
	char *s;
	char *f;

	i = 0;
	c = va_arg(all->a_list, long long);
	s = ft_itoa_base(c,16);
	f = ft_strjoin("0x",s);
	all->len_arg = ft_strlen(c);
	width_min(all);
	ft_putstr(f);

	write (1,"\n",1);
	return (0);
}


int			specifier_c(t_spec *all, ...)
{
		int i;
		char *c;
		char *s;

		i = 0;
		c = va_arg(all->a_list, char*);
		all->len_arg = 1;
		width_min(all);
		if (all->moins)
			s = ft_strjoin(c, all->s_filled);
		ft_putstr(s);
		write(1,"\n",1);
		return (0);
}


int 	specifier_s(t_spec *all, ...)
{
		char *c;
		char *s; // malloc 
		int i; 
		
		i = 0;
		c = va_arg(all->a_list, char*); //mettre dans la structure
		all->len_arg = ft_strlen(c);
		width_min(all);
		printf("ok\n");
		//if (all->moins)
			//s = ft_strjoin(c,all->s_filled);
		printf("ok\n");
		printf("%s\n",s);
		ft_putstr(s);
		//write(1, "\n",1);
		return (0);
} 
