#include "libftprintf.h"

void flag_exist(t_spec *all)
{
 	int i;
	i = 0;

	while (all->spec[i] != '\0')
	{

		if (all->spec[i] == '+')
       		all->plus = 1;
		else if (all->spec[i] == '-')
      		all->moins = 1;
		else if (all->spec[i] == '0' && ft_isdigit(all->spec[i + 1]))
       		all->zero = 1;
    	else if (all->spec[i] == '0'  && ft_isascii(all->spec[i + 1]))
      		all->zero = 1;
     	else if (all->spec[i] == ' ')
      		all->esp = 1;
		 else if (all->spec[i] == '#')
      		all->hash = 1;
		 else if (all->spec[i] == '.')
      		all->point = 1;
	   else if ((ft_isdigit(all->spec[i]) && all->point != 1))// all->spec[i - 1] != '.'))
	   {
			all->w = 1;
			all->width = ft_atoi(&all->spec[i]);
			break;
		}
		i++;

	}
}

void ft_precision(t_spec *all)
{
	int i;
	i = 0;
	while (all->spec[i] !=  '\0')
	{
		if (all->spec[i] == '.')
		{
			all->precision = 1;
			all->vision = ft_atoi(&all->spec[i + 1]);
		}
		i++;
	}
}
void    flag_corr(t_spec *all)
{
  if (all->moins == 1 && all->zero == 1)
   	  all->zero = 0;
  if (all->plus == 1 && all->esp == 1)
	  all->esp = 0;
  if (all->zero == 1 && all->precision == 1 && all->type != 'f')
	  all->zero = 0;
  if (all->w == 1 && all->precision == 1)
  	  all->wp = 1;
  if (all->plus == 1 && all->moins == 1)
		all->plus = 1;
 }
void	flag_exist_bis(const char *format, t_spec *all)
{
	int i;
	i = 0;
	while (format[i] != '\0')
	{
		if (all->spec[i] == 'h')
			all->h = 1;
		else if (all->spec[i] == 'l')
			all->l = 1;
		else if (all->spec[i] == 'h' && all->spec[i + 1] == 'h')
			all->hh = 1;
		else if (all->spec[i] == 'l' && all->spec[i + 1] == 'l')
			all->ll = 1;
		else if (all->spec[i] == 'L' && all->type == 'f')
			all->L = 1;
		else if (all->type == 'f' && all->spec[i] == 'l')
			all->l = 2;
		// add condition float
		i++;
	}
}
/*
int 	width_min(t_spec *all)
{
	all->space = all->width - all->len_arg;
	if (all->len_arg  < all->space)
	{
		if (all->type == 's')
						 fill_width(all);
		if (all->w == 1)
						fill_width_diouxx(all);
		//if (all->zero == 1)
						//fill_zero(all);
		else if (all->precision == 1 )//|| all->zero == 1)
						fill_precision(all);
	}
	return (0);

}*/


int  width_s(t_spec *all, char *s)
{
	//width_min(all);
	all->space = all->width - all->len_arg;
	if (all->len_arg < all->width)
		fill_width_diouxx(all);
	if (all->moins == 1)
	{
		printf("is\n");
		ft_putstr(s);
		ft_putstr(all->s_filled_d);
	}
	else if (all->moins != 1)
	{
		//printf("in\n");
		ft_putstr(all->s_filled_d);
		ft_putstr(s);
	}
	return (0);
}

int precision_s(t_spec *all, char *s)
{
	int i;

	i = 0;
	if (all->len_arg >= all->vision)
	{
		while (i != all->vision)
			ft_putchar(s[i++]);
	}
	else if (all->vision > all->len_arg)
			ft_putstr(s);
	return (0);
}

int width_precision_s(t_spec *all, char *s)
{
	char *tmp_s;
	int i;

	i = 0;
	fill_precision(all);
	tmp_s = ft_strsub(s,0,all->vision);
	all->len_arg = ft_strlen(tmp_s);
	all->space = all->width - all->len_arg;

	if (all->len_arg <  all->width)
      fill_width(all);
	if (all->moins == 1)
	{
  //  printf("in\n");
		ft_putstr(tmp_s);
		ft_putstr(all->s_filled_d);
	}
	else if (all->moins == 0)
	{
    //printf("in5\n");
    //ft_putstr(tmp_s);
		ft_putstr(all->s_filled_d);
		ft_putstr(tmp_s);
	}
	//free(tmp_s);
	return (0);
}

int   precision_ox(t_spec *all, char *s)
{
  fill_precision(all);
  space_plus_p(all);
  if (all->vision > 0)
      ft_putstr(all->s_filled_p);
  ft_putstr(s);
 // if (all->isneg == 1)
  //{
	//ft_putchar(all->p);
    //ft_putnbr_long(all->conv->d * -1);
    return (1);
}
int width_precision_ox(t_spec *all, char *s) //same signed unsigned
{
  fill_precision(all);
  fill_width_diouxx(all);
 if (all->moins == 1)
	{
		   space_plus(all);
		  // if (all->isneg == 1)
			//   ft_putchar(all->p);
			ft_putstr(all->s_filled_p);
			ft_putstr(s);
		  // all->isneg == 1 ? ft_putnbr_long(all->conv->d * -1) : ft_putnbr_long(all->conv->d);
		   ft_putstr(all->s_filled_d);
	}
	else if (all->moins == 0)
	{
	   ft_putstr(all->s_filled_d);
	   space_plus(all);
	 //  if (all->isneg == 1)
	   //{
		//	   ft_putchar(all->p);
			  // ft_putstr(all->s_filled_p);
			//   ft_putnbr_long(nb * -1);


			   ft_putstr(all->s_filled_p);
			  	ft_putstr(s);

		}
  return(1);
 }
