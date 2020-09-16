/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imanoka- <imanoka-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 15:10:22 by imanoka-          #+#    #+#             */
/*   Updated: 2020/09/16 14:13:08 by imanoka-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "libftprintf.h"

int fill_width(t_spec *all)
{
      int i;
      i = 0;
      all->s_filled = (char*)malloc(sizeof(char) + 1);
      while (i < all->space)
      {
	      all->s_filled[i] = ' ';
	      i++;
	  }

      return (1);
}
int fill_width_diouxx(t_spec *all)
{
      int i;
      int j;
      i = 0;

      all->space = all->width - all->len_arg;
      all->s_filled_d = (char*)malloc(sizeof(char));
      while (i < all->space)
      {
        if (all->zero == 1 )
             all->s_filled_d[i++] = '0';
		else if (all->zero == 0)
		 	      all->s_filled_d[i++] = ' ';
	}
      all->s_filled_d[i] ='\0';

      return (1);
}

int fill_precision(t_spec *all)
{
    int i;
    int j;
    j = 0;
    all->pision = all->vision - all->len_arg;
	if (all->conv->d < 0 || all->plus == 1)
		all->pision += 1;
    all->s_filled_p = (char*)malloc(sizeof(char));
    while (j < all->pision)
    {
          all->s_filled_p[j] = '0';
          j++;
    }
    all->s_filled_p[j] ='\0';
    all->len_arg = all->len_arg + j;

    return (1);
}
void space_plus(t_spec *all)
{

 if (all->plus == 1 && all->isneg != 1 && all->precision == 1)
    ft_putchar(all->p);
    all->check1 = 1; // perturbe
if (all->esp == 1)
  write(1," ",1);
}

void check_type(t_spec *all)
{
  if (all->type == 'd' || all->type == 'i')
      ft_putnbr(all->conv->d);
  if (all->type == 'u')
      ft_putnbr(all->conv->u);
  if (all->type == 'o')
      ft_putnbr(all->conv->o);
}

int     width(t_spec *all)
{
 	//printf("zero :%d\n",all->esp );
 	if (all->conv->d > 0)
	{
		space_plus(all);
		fill_width_diouxx(all);
		/*if (all->plus == 1  && all->check1 == 1)
		{
				ft_putchar(all->p);
		}*/
		all->moins == 1 ? ft_putnbr(all->conv->d) : ft_putstr(all->s_filled_d);
		if (all->plus == 1 ) //&& all->check1 == 1)
				//printf("inds\n");
				ft_putchar(all->p);
		all->moins == 1 ? ft_putstr(all->s_filled_d) : ft_putnbr(all->conv->d);
	}
	else if (all->conv->d < 0)
	{
		fill_width_diouxx(all);
	if (all->moins == 1)
	{
	//	space_plus(all);

		all->isneg == 1 ? ft_putchar(all->p) : ft_putnbr(all->conv->d);
		if (all->isneg == 1)
			ft_putnbr(all->conv->d * -1);
		ft_putstr(all->s_filled_d);
	}
	else if (all->moins == 0)
	{
		//space_plus(all);
		ft_putstr(all->s_filled_d);
		all->isneg == 1 ? ft_putchar(all->p) : ft_putnbr(all->conv->d);
		if (all->isneg == 1)
			ft_putnbr(all->conv->d * -1);

	}
	}
	return(1);
}
void space_plus_p(t_spec *all)
{
  if (all->esp == 1)
    write(1, " ", 1);
  if ((all->plus == 1) || (all->isneg == 1))
 	ft_putchar(all->p);
}
int   precision(t_spec *all)
{
  fill_precision(all);
  space_plus_p(all);
  if (all->vision > 0)
      ft_putstr(all->s_filled_p);
  if (all->isneg == 1)
    ft_putnbr(all->conv->d * -1);
  else
    ft_putnbr(all->conv->d);
      return (1);
}

int width_precision(t_spec *all)
{
  fill_precision(all);
  fill_width_diouxx(all);
	  if (all->moins == 1)
 	 {
    		space_plus(all);
			if (all->isneg == 1)
				ft_putchar(all->p);
   			ft_putstr(all->s_filled_p);
			all->isneg == 1 ? ft_putnbr(all->conv->d * -1) : ft_putnbr(all->conv->d);
    		ft_putstr(all->s_filled_d);
	 }
 	 else if (all->moins == 0)
 	 {
    	ft_putstr(all->s_filled_d);
    	space_plus(all);
    	if (all->isneg == 1)
      	{
				ft_putchar(all->p);
  	 			ft_putstr(all->s_filled_p);
				ft_putnbr(all->conv->d * -1);
			}
			else if (all->isneg == 0)
			{
				ft_putstr(all->s_filled_p);
				ft_putnbr(all->conv->d);
			}
	 }
  return(1);
 }
