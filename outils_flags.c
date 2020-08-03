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
/*
int fill_width_plus(t_spec *all)
{
    int corr; // corrected because of the sign
    int i;

    i = 0;
    corr = 0;
    all->s_filled = (char*)malloc(sizeof(char));
    //printf("%s\n", "in");
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
}*/
int fill_width(t_spec *all)
{
      int i;
      i = 0;
      all->s_filled = (char*)malloc(sizeof(char));
      while (i < all->space)
      {
	      all->s_filled[i] = ' ';
	      i++;
	     }
      //printf("filled : %s", all->s_filled);
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
        //printf("i : %i\n", i);
	      all->s_filled_d[i] = ' ';
	      i++;
	     }
       j = ft_strlen(all->s_filled_d);
       all->len_arg = all->len_arg + j;
      return (1);
}
int fill_zero(t_spec *all)
{
	int i;
  int j;
	i = 0;
  all->space = all->width - all->len_arg;
	all->s_filled = (char*)malloc(sizeof(char));
	while (i < all->space)
		all->s_filled[i++] = '0';
  j = ft_strlen(all->s_filled);
  all->len_arg = all->len_arg + j;
	return (1);
}

int fill_precision(t_spec *all)
{
    int i;
    int j;
    j = 0;
    all->s_filled_p = (char*)malloc(sizeof(char));
    all->pision = all->vision - all->len_arg;
	  while (j < all->pision)
    {
          all->s_filled_p[j] = '0';
          j++;
    }
    j = ft_strlen(all->s_filled_p);
    all->len_arg = all->len_arg + j;
  //printf("filled : %d\n", all->pision);
  //printf("filled : %s\n", all->s_filled_p);
  return (1);
}
void fnct_output_d(t_spec *all)
{
  if (all->plus == 1 && all->w == 1 && all->precision != 1)
  {
    printf("in2\n");
     ft_putstr(all->s_filled_d);
     ft_putchar(all->p);
     ft_putnbr(all->conv->d);

  }
  else if (all->plus == 1 && all->precision == 1)
  {
      printf("in1\n");
      fill_precision(all);
      ft_putchar(all->p);
      ft_putstr(all->s_filled_p);
      ft_putnbr(all->conv->d);
  }
  if (all->w == 1)
  {

    fill_width_diouxx(all);
    ft_putstr(all->s_filled_d);
    ft_putnbr(all->conv->d);
  }
  else if (all->precision == 1)
  {
    printf("in4\n");
    fill_precision(all);
    ft_putstr(all->s_filled_p);
    ft_putnbr(all->conv->d);
  }
  else if (all->w && all->precision == 1)
  {
    fill_precision(all);
  /*in the struct*/  s = ft_strjoin(all->s_filled_p, all->conv->d);
    fill_width_diouxx(all);


    
}

}
int 	int_in_str(t_spec *all)
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

}
