#include "libftprintf.h"

int	specifiers_f(t_spec *all)
{
	//hh LL
	sep_int_deci(all);
	all->len_arg = ft_strlen(all->conv->fl_str);
	fill_width_diouxx(all);
	//if (all->isneg == 1)
		//ft_putchar(all->p);
	if (all->w == 1 && all->moins == 0)
	{

			ft_putstr(all->s_filled_d);
			if (all->vision == 0)
			{
				ft_putnbr(all->conv->ent);
				//printf(" ent %d\n", all->conv->ent);
			}
			else
				ft_putstr(all->conv->fl_str);
	}
	else if (all-> w == 1 && all->moins == 1)
	{
		ft_putstr(all->conv->fl_str);
		ft_putstr(all->s_filled_d);
	}
	else if (all->w == 0)
	{
		if (all->vision == 0)
			ft_putnbr(all->conv->ent);
		else
			ft_putstr(all->conv->fl_str);
	}
	return (1);
}

int	sep_int_deci(t_spec *all)
{
	int dix; // MACRO

	dix = 10;
	all->conv->f = va_arg(all->a_list,double);
	all->conv->ent = (int)all->conv->f;
	if (all->conv->ent < 0)
		all->isneg = 1;
	all->p = all->conv->ent < 0 ? '-' :  '+';
	all->conv->deci = all->conv->f - all->conv->ent;
	if (all->precision == 0)
		all->stop = 6;
	else if (all->precision != 0)
		all->stop = all->vision;
	all->conv->fl = all->conv->deci;
	round_up(all);
	round_up_bis(all);
	if (all->vision != 0)
		join_float(all);
	return (1);
}

char 	*join_float(t_spec *all)
{
	char *float_str;
	char *tmp_ent;
	char *tmp_float;
	char *point;


	float_str = malloc(sizeof(char*));
	point = ".";
	tmp_ent = ft_itoa(all->conv->ent);
	if (all->conv->fl_int < 0)
		all->conv->fl_int *= -1;
	tmp_float = ft_itoa(all->conv->fl_int);
	float_str = ft_strjoin(tmp_ent, point); //float_tmp
	all->conv->fl_str = ft_strjoin(float_str,tmp_float);
	free(float_str);
	//printf("final : %s\n", all->conv->fl_str);
	return (all->conv->fl_str);
}



int 	round_up(t_spec *all)
{
	double cp_float;
	int tmp_float; // to look at the next one if round up in necessaire or not
	double up;
	int a;
	int dix;

	cp_float = all->conv->fl;
	up = 1.0;
	a = 0;
	dix = 10;
	if (all->stop > 1)
	{
		while (a != all->stop)
		{
			cp_float *= 10;
			dix = dix * 10;
			up /= 10;
			a++;
		}
		all->conv->fl = cp_float + up;
		cp_float *= 10;
		tmp_float = (int)cp_float;
		if (tmp_float % 10 >= 5)
			all->conv->fl += 1;
		else if (tmp_float % 10 < 5)
			all->conv->fl = all->conv->fl;
		all->conv->fl_int = (int)all->conv->fl;

	}
	return (1);
}


int	 round_up_bis(t_spec *all)
{
	int tmp;

	if (all->stop == 1)
	{
		tmp = all->conv->deci * 100;
		if (tmp % 10 >= 5)
			all->conv->fl = all->conv->deci * 10 + 1;
		else if (tmp % 10 < 5)
			all->conv->fl = all->conv->deci * 10;
		all->conv->fl_int = (int)all->conv->fl; // faut un int
	}
	else if (all->vision == 0)
	{
		tmp = all->conv->deci * 10;

		if (tmp >= 5)
			all->conv->ent += 1;
		if (tmp < 5)
			all->conv->fl = all->conv->ent;
	}
	return (1);
}



// if all->deci est plus petit que 6 et precsion de 6 leave it as is
//if all->deci est plus petit que 6 et precision moins que 6 ok multiplication par 10
//if precision = 10 stop a 9 et arrondir


// if we don't want to round up than add 1 if round up 0
