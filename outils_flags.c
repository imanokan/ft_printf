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
      return (1);
}
int fill_width_diouxx(t_spec *all)
{
      int i;
      int j;
      i = 0;
      all->space = all->width - all->len_arg;
      all->s_filled_d = (char*)malloc(sizeof(char));// * all->space);
      ft_bzero(all->s_filled_d, all->space);
      while (i < all->space)
      {
        if (all->zero == 1)
            all->s_filled_d[i] = '0';
        if (all->zero != 1)
              all->s_filled_d[i] = ' ';
        i++;
	     }
       all->s_filled_d[i] ='\0';
       //printf("filled:[%s] %zu\n",all->s_filled_d, ft_strlen(all->s_filled_d));
       //j = ft_strlen(all->s_filled_d);
       //all->len_arg = all->len_arg + j;
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
    //all->s_filled_p[i] ='\0';
    //printf("filled :%s\n", all->s_filled_p);
    //j = all->vision;
    all->len_arg = all->len_arg + j;
    return (1);
}
void fnct_output_d(t_spec *all)
{
  if (all->plus == 1 && all->w == 1) // ok sans le ft_putnbr
  {
    all->check = 1;
    all->len_arg = all->len_arg + 1;
    fill_width_diouxx(all);
    ft_putstr(all->s_filled_d);
    if (all->plus == '+')
        ft_putchar(all->p);
    //ft_putstr(all->s_filled_d);
    //ft_putnbr(all->conv->d);
  }
  else if (all->plus == 1 && all->precision == 1)
  {
      fill_precision(all);
      if (all->plus == '+')
          ft_putchar(all->p); // si neg faut le mettre devant
      ft_putstr(all->s_filled_p);
      //ft_putnbr(all->conv->d);
  }
  else if (all->space == 1 && all->w == 1) // to check avec  moins et doublons
  {
      //printf("in4\n");
      write(1," ",1);
      all->len_arg = all->len_arg + 1;
      fill_width_diouxx(all);
      ft_putstr(all->s_filled_d);
      //ft_putnbr(all->conv->d);
  }
else if (all->space == 1 && all->precision == 1)
  {
      //printf("in5\n");
      write(1," ", 1);
      fill_precision(all);
      ft_putstr(all->s_filled_p);
      //ft_putnbr(all->conv->d);
  }
}
void fnct_output_d_bis(t_spec *all)
{
  if (all->w != 1 && all->precision != 1) //ok
  {
    //printf("in6\n");
     if (all->space == 1)
        write (1, " ", 1);
    else if (all->plus == 1)
        ft_putchar(all->p);
    //ft_putnbr(all->conv->d);
  }
  else if (all->w == 1 && all->precision == 1) //ok
  {
    fill_precision(all);
    fill_width_diouxx(all);
    ft_putstr(all->s_filled_d);
    ft_putstr(all->s_filled_p);
    //ft_putnbr(all->conv->d);
}
  else if (all->w == 1 && all->precision != 1 && all->check != 1 ) //ok
  {
    //printf("in48\n");
    fill_width_diouxx(all);
    if (all->moins != 1)
    {
      //printf("im\n");
      ft_putstr(all->s_filled_d);
      //ft_putnbr(all->conv->d); //fonctionne ainsi
    }
    else if (all->moins == 1) // ici fonctionne pas
    {
      //printf("i\n");
        ft_putnbr(all->conv->d); //double d
        ft_putstr(all->s_filled_d);
    }
  }
  /*else if (all->precision == 1 && all->w != 1)
  {
    printf("in9\n");
    fill_precision(all);
    ft_putstr(all->s_filled_p);
    ft_putnbr(all->conv->d);
  }*/

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
