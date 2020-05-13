/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imanoka- <imanoka-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 15:10:22 by imanoka-          #+#    #+#             */
/*   Updated: 2020/04/09 18:00:58 by imanoka-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"   
#include "./libft/libft.h"

char  *fill_0(t_spec *all)
{
    char *s;
    int i;
	
// do not forget to free
   i = 0;
   if (!(s = malloc(sizeof(char*) * all->space + 1)))
	//return (-1);
    while (i < all->space)
    {
        s[i] = '0';
        i++;
    }
    return (s);
}
char     *fill_space(t_spec *all)
{
    	char *s;
    	int i;

	i = 0;
	if (!(s = malloc(sizeof(char *) * all->space + 1)))
		//return (-1);
    	while (i < all->space)
   	{
        	s[i] = ' ';
       		i++;
   	 }
   	 return (s);
}

int 	int_in_str(t_spec *all)
{
	int i;

	i = 0;
	while (all->spec[i] != '\0')
	{
		if (ft_isdigit(all->spec[i]))
			all->n = all->n * 10 + (all->spec[i] - '0');
	  	i++;
	}
	return (all->n);

}
int 	check_binary(t_spec *all)
{
	if (all->n % 10 != 0 || all->n % 1 != 0)
		write(1,"a",1);
		//ft_itoa_base(all->n,8,c); //deux itoa diff ?
	return (1); 
}


