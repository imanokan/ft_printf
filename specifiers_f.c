#include "libftprintf.h"

int	specifiers_f(t_spec *all)
{
	int i = 0;
	all->conv->f = check_l_lupper(all);
	sep_int_deci(all);
	all->len_arg = ft_strlen(all->conv->fl_str);
	//fill_width(all);
	//printf("final1: %s\n", all->conv->fl_str);
	//printf("esp : %d\n",all->esp);
	if ((all->plus == 1 && all->conv->f > 0 )|| (all->esp == 1 && all->conv->f > 0))
			all->len_arg += 1;

	fill_width_diouxx(all);
	//fill_width(all);
		//printf("final3 : %s\n", all->conv->fl_str);
	//printf("f f: %s\n", all->conv->fl_str);
	if (all->plus == 1 && all->p == '+')
		ft_putchar(all->p);
	else if (all->esp == 1 && all->conv->f > 0)
		write(1," ",1);
	//	all->len_arg

	if (all->w == 1 && all->moins == 0)
	{
			//printf("final3 : %s\n", all->s_filled_d);
			if (all->conv->f < 0)
				ft_putchar('-');
			ft_putstr(all->s_filled_d);
			if (all->vision == 0 && all->precision == 1)
				{
						if (all->conv->f  < 0)
							ft_putnbr(all->conv->ent * -1);
						else
							ft_putnbr(all->conv->ent);
}
			else //if (all->vision != 0)
			{
		//		printf("ind\n" );
				ft_putstr(all->conv->fl_str);
			}
		//printf("dd\n" );
		}
	else
		ft_putstr(all->conv->fl_str);

	return (1);
}

int	sep_int_deci(t_spec *all)
{
	int dix; // MACRO

	dix = 10;
	//all->conv->f = va_arg(all->a_list,double);
	all->conv->ent = (int)all->conv->f;
	//printf("fl_ent : %d\n", all->conv->ent);
	all->p = all->conv->ent < 0 ? '-' : '+';
	if (all->conv->ent < 0)
		all->isneg = 1;
	all->conv->deci = all->conv->f - all->conv->ent;
	if (all->precision == 0)
		all->stop = 6;
	else if (all->precision != 0)
		all->stop = all->vision;
	all->conv->fl = all->conv->deci;
	round_up(all);
	round_up_bis(all);
	//if (all->vision != 0)
	join_float(all);
	return (1);
}

char 	*join_float(t_spec *all)
{
	char *float_str;
	char *tmp_ent;
	char *tmp_float;
	char *point;


	float_str = malloc(sizeof(char*) + 1);
	all->conv->fl_str = malloc(sizeof(char*) + 1);
	point = ".";
	tmp_ent = ft_itoa(all->conv->ent);
	if (all->conv->fl_int < 0)
		all->conv->fl_int *= -1;
	tmp_float = ft_itoa(all->conv->fl_int);
	float_str = ft_strjoin(tmp_ent, point);
	//if (all->vision == 0 && all-> == 1)
	 //all->conv->fl_str = ft_strjoin(float_str,tmp_float);
	if (all->vision == 0 && all->hash == 1)
	{
			//printf("flag: %d  %d\n",all->vision, all->hash);
			//printf("%s\n", "IN" );
			//printf("float : %s\n",float_str );
			//ft_strcpy(all->conv->fl_str,float_str);
			all->conv->fl_str = float_str;
}
	else if (all->vision > 0 )
	{
		//printf("float : %s\n",tmp_float );
		all->conv->fl_str = ft_strjoin(float_str,tmp_float);
	}
	else if (all->vision == 0)
		all->conv->fl_str = tmp_float;
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
		if (tmp_float % 10 == 9)
			tmp_float += 1;
		if (tmp_float % 10 >= 5)
				all->conv->fl += 1;
		else if (tmp_float % 10 < 5)
		{
			if (all->conv->f > 0)
				all->conv->fl = all->conv->fl;
			else
				all->conv->fl -=1;
		}
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
		all->conv->fl_int = (int)all->conv->fl;
	}
	else if (all->vision == 0)
	{
		//positif
		all->conv->deci *= -1;
		tmp = all->conv->deci * 10;
		printf("tmp : %f\n",all->conv->deci);
		if (tmp >= 5)
			all->conv->ent += 1;
			all->conv->fl_int = all->conv->ent;
		if (tmp < 5)
			printf("dd\n" );
			all->conv->fl = all->conv->ent;
		//all->conv->fl_int = (int)all->conv->fl; maybe


		//same but negative
		//if f one digit 
	}
	return (1);
}
