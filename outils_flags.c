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

int fill_width_plus(t_spec *all)
{
    int corr; // corrected because of the sign
    int i;

    i = 0;
    corr = 0;
    all->s_filled = (char*)malloc(sizeof(char));
    printf("%s\n", "in");
    corr = all->space - 1;
    while (i < corr)
		{
      if (all->zero == 1)
          all->s_filled[i++] = '0';
      else
          all->s_filled[i++] = ' ';

    }
    //printf("filled : %s", all->s_filled);
    return (1);
}
int fill_width(t_spec *all)
{
      int i;
      i = 0;
      all->s_filled = (char*)malloc(sizeof(char));
      while (i < all->space)
      {
	      all->s_filled[i] = 'A';
	      i++;
	     }
       printf("fillled : %d\n", all->space);
      return (1);
}
int fill_zero(t_spec *all)
{
	int i;
	i = 0;
	all->s_filled = (char*)malloc(sizeof(char));
	while (i < all->space)
		all->s_filled[i++] = '0';
	return (1);
}

char  *fill_precision(t_spec *all)
{
    int j;
    j = 0;
    all->s_filled_p = (char*)malloc(sizeof(char));
    if (all->precision == 1) // le mettre en deuxième position
    {
		    all->pision = all->vision - all->len_arg;
		    while (j < all->pision)
			    all->s_filled_p[j++] = '0';
	}
   /* if (all->precision == 1 && all->type == 's')
	    all->pision = all->vision - all->len_arg;
            while ( i < all->pision)
		    ft_putchar(s[i])*/
  //printf("filled : %d\n", all->pision);
 // printf("filled : %s\n", all->s_filled_p);
  return (all->s_filled_p);
}
void fnct_output(t_spec *all)
{
  if (all->plus == 1 && all->width == 1 && all->precision != 1)
  {
     ft_putchar(all->p);
     ft_putstr(all->s_filled);
     //ft_putchar(all->p);
  }
  else if (all->plus == 1 && all->precision == 1)
  {
      ft_putchar(all->p);
      ft_putstr(all->s_filled_p);
  }
  /*else if (all->moins == 1)
	{
    ft_putstr(all->s_filled);
    ft_pustr(all->s);
  }*/
  /*
  else if (all->width == 1)
		f = ft_strjoin(all->s_filled,s);
	else if (all->precision == 1) autre fonction parce que flag - a prendre en compte
			f = ft_strjoin(all->s_filled_p,s);*/
  //else if (all->space)
      //printf("%s\n", "in"); verfier ce space
   //write(1," ", 1);
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
