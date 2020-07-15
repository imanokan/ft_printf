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
	void *c; //long 

	i = 0;
	while(all->spec[i] != '\0')
	{
		if (all->spec[i] == '%' && all->spec[i + 1] == 'p')
		{
			c = va_arg(all->a_list, void*);
			all->len_arg = ft_strlen(c);
			ft_putstr(ft_strjoin("0x", ft_itoa_base(c, 16, 'm')));
		}
		i++;
	}
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
		if (all->plus)
			s = ft_strjoin(all->s_filled,c);
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
		printf(" v ision : %d\n", all->vision);
		//if (all->vision == 0)
		width_min(all);
	       	if (all->plus)	
			s = ft_strjoin(all->s_filled,c);
		else if (all->moins)
			s = ft_strjoin(c,all->s_filled);
		//while (i < all->vision)
			//ft_putchar(c[i++]);
		ft_putstr(s);
		//write(1, "\n",1);
		return (0);
} 
