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

char     *fill_space(t_spec *all)
{
    	int i;
	int j;

	i = 0;
	j = 0;

	all->s_filled = malloc(sizeof(char *) * all->space + 1);
		//return (-1);
	if (all->zero == 1)
  {
      while (i < all->space)
			   all->s_filled[i++] = '0';
    }

// separate the two fucntions for clarity
  else if (all->width == 1)
  {
    printf("in\n");
    if (all->plus == 1)
    {
      printf("in\n");
      all->space = all->space - 1;
      printf("all->space after %d\n", all->space);
    }
    while (i < all->space )
			all->s_filled[i++] = ' ';
	}

  //


	if ((all->type == 'd' ||all->type ==  'i' ||all->type ==  'o' ||all->type ==  'u' || all->type == 'x' || all->type == 'X') && all->vision)
	{
		all->pision = all->vision - all->len_arg;
		while (j < all->pision)
			all->s_filled[j++] = '0';
	}
  //printf("filled : %d\n", all->pision);
	//printf("filled : %s\n", all->s_filled);
   	return (all->s_filled);
}

int 	int_in_str(t_spec *all)
{
	int i;

	i = 0;
	while (all->spec[i] != '\0')
	{
		if (ft_isdigit(all->spec[i]))
			all->n = ft_atoi(all->spec,&i);
	  	i++;
	}
	return (all->n);

}
/*
int 	check_binary(t_spec *all)
{

	if (all->n % 10 != 0 || all->n % 1 != 0)
		write(1,"a",1);
		//ft_itoa_base(all->n,8,c); //deux itoa diff ?
	return (1);
}
 mignon but i don't think that it will be necessary:*/
