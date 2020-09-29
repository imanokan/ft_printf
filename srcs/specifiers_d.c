
#include "../includes/libftprintf.h"
//#include "/mnt/c/Users/Audrey/Desktop/manoka/includes/libftprintf.h"
int specifier_d(t_spec *all)
{
	all->conv->d = check_l_ll_h_hh(all->conv->d,all);
	all->len_arg = size_nb(all->conv->d);
 	if (all->esp == 1 || all->plus == 1 || all->conv->d < 0)
    	all->len_arg += 1;
	all->p = all->conv->d < 0 ? '-' :  '+';
	if (all->conv->d < 0)
		all->isneg = 1;
	if (all->w == 1 && all->precision == 0)
			width_signed(all,all->conv->d);
 	else if (all->w == 0 && all->precision == 1)
		precision_signed(all, all->conv->d);
	else if (all->w == 1 && all->precision == 1)
			width_precision_signed(all, all->conv->d);
  else if (all->wp == 0)
  {
    space_plus(all);
    ft_putnbr_long(all->conv->d);
  }
  	return (0);
}

int specifier_x(t_spec *all)
{
	int i;
	i = 0;

	all->conv->x = check_l_ll_h_hh_unsigned(all->conv->x,all);
	all->conv->x_str = ft_itoa_base(all->conv->x,16);
	if (all->type == 'X')
			while (all->conv->x_str[i] != '\0')
					ft_toupper(all->conv->x_str[i++]);
	//fill number if needed et space en precision puis le ar
	all->len_arg = ft_strlen(all->conv->x_str);
	if (all->w == 1 && all->precision == 0)
				width_s_plus(all, all->conv->x_str);
 	else if (all->w == 0 && all->precision == 1)
				precision_ox(all,all->conv->x_str);
	else if (all->w == 1 && all->precision == 1)
			width_precision_ox(all,all->conv->x_str);
	else
			ft_putstr(all->conv->x_str);
	return (0);
}

int specifier_o(t_spec *all)
{
	all->conv->o = check_l_ll_h_hh_unsigned(all->conv->o, all);
 	all->conv->o_str= ft_itoa_base(all->conv->o,8);
	all->len_arg = size_nb(all->conv->o);
	if (all->w == 1 && all->precision == 0)
			width_s_plus(all,all->conv->o_str);
	else if (all->w == 0 && all->precision == 1)
			precision_ox(all,all->conv->o_str); //
	else if (all->w == 1 && all->precision == 1)
			width_precision_ox(all,all->conv->o_str);
	else
		ft_putstr(all->conv->o_str);

	return (0);
}

int specifier_u(t_spec *all)
{
	all->conv->u = check_l_ll_h_hh_unsigned(all->conv->u, all);
	if (all->conv->u < 0)
		all->conv->u = UINT_MAX - all->conv->u;
	all->len_arg = size_nb_unsigned(all->conv->u);
	if (all->w == 1 && all->precision == 0)
			width_unsigned(all, all->conv->u);
	else if (all->w == 0 && all->precision == 1)
			precision_unsigned(all, all->conv->u);
	else if (all->w == 1 && all->precision == 1)
			width_precision_unsigned(all,all->conv->u);
	else
		ft_putnbr_long(all->conv->u);
	return (0);
}
