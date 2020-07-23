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

char  *fill_width(t_spec *all)
{
    int corr; // corrected because of the sign
    int i;

    i = 0;
    corr = 0;
    all->s_filled = (char*)malloc(sizeof(char));
    if (all->plus == 1)
    {
       corr = all->space - 1;
       while (i < corr)
		    {
          if (all->zero == 1)
            all->s_filled[i++] = '0';
          else
            all->s_filled[i++] = ' ';
        }
    }
    else
      while (i < all->space)
      {
        if (all->zero == 1)
          all->s_filled[i++] = '0';
        else
          all->s_filled[i++] = ' ';
      }
    return (all->s_filled);
}

char  *fill_precision(t_spec *all)
{
    int j;
    j = 0;
    all->s_filled_p = (char*)malloc(sizeof(char));
    if (all->precision == 1)
    {
		    all->pision = all->vision - all->len_arg;
		    while (j < all->pision)
			    all->s_filled_p[j++] = '0';
	 }
  //printf("filled : %d\n", all->pision);
	//printf("filled : %s\n", all->s_filled_p);
  return (all->s_filled_p);
}
/*
char  *fnct_output(t_spec *all)
{
  char c;
  if (all->plus == 1)

  }
  if (all->plus == 1)

}*/
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
