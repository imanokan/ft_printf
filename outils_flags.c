/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imanoka- <imanoka-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 15:10:22 by imanoka-          #+#    #+#             */
/*   Updated: 2020/09/14 12:15:01 by imanoka-         ###   ########.fr       */
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
	  if ((all->isneg == 1 && all->plus == 1 ) || (all->plus == 1)
    || (all->moins == 1))
		 {
      
       all->space = all->space - 1;
      all->s_filled_d = (char*)malloc(sizeof(char));
    }
      while (i < all->space)
      {
        if (all->zero == 1 )
			all->s_filled_d[i++] = '0';
		else if (all->zero != 1)
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
    all->s_filled_p = (char*)malloc(sizeof(char));
    ft_bzero(all->s_filled_p, all->pision);
    while (j < all->pision)
    {
          all->s_filled_p[j] = '0';
          j++;
    }
    all->s_filled_p[j] ='\0';
  //  printf("filled :%s\n", all->s_filled_p);
    //j = all->vision;
    all->len_arg = all->len_arg + j;
    return (1);
}
void space_plus(t_spec *all)
{
  if (all->plus == 1 && all->isneg != 1)
{
    ft_putchar(all->p);
    all->check1 = 1;
  }
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
  fill_width_diouxx(all);
  //space_plus(all);
  //printf("%s\n","widht");
  if (all->moins == 1) //avec plus un char en trop
  {
    //printf("%s\n","w4idht");

    space_plus(all);
    if (all->check1 != 1 && all->isneg == 1)
      ft_putchar(all->p);
      check_type(all);
    ft_putstr(all->s_filled_d);
    all->check = 1;
  }
  //printf("%s\n","widh4t");
  else if (all->moins != 1)
  {

    //same but all different types
    ft_putstr(all->s_filled_d);
    space_plus(all);
    if (all->check1 != 1 && all->isneg == 1)
      ft_putchar(all->p);
  }
return (1);
}
int   precision(t_spec *all)
{
  if (all->vision > 0)
  {
        fill_precision(all);
        space_plus(all);
        if (all->isneg == 1)
          ft_putchar(all->p);
        ft_putstr(all->s_filled_p);
    }
    else if (all->vision == 0)
      space_plus(all);
    return(1);
}

int width_precision(t_spec *all)
{

  fill_precision(all);
  fill_width_diouxx(all);
  //if (all->width >= all->len_arg)
 // {
	  //fill_width_diouxx(all);
	  if (all->moins == 1)
 	 {

    		space_plus(all);
   			 ft_putstr(all->s_filled_p);
    		check_type(all);
    		ft_putstr(all->s_filled_d);
   			all->check = 1;
	 }
 	 else if (all->moins == 0)
 	 {
   	 //types
    	ft_putstr(all->s_filled_d);
		//ft_putstr(all->s_filled_p);
    	space_plus(all);
    	if (all->isneg == 1)
      	ft_putchar(all->p);
  	 	ft_putstr(all->s_filled_p);
	 }

  //}
  return(1);
 }

/*int 	int_in_str(t_spec *all)
{
	int i;

	i = 0;
	while (all->spec[i] != '\0')
	{
		if (ft_isdigit(all->spec[i]))
			all->n = ft_atoi_bis(all->spec,&i);
	  	i++;
	}
	return (all->n);
}*/
