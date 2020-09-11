#include "libftprintf.h"

int	specifiers_f(t_spec *all)
{
	//hh LL
	sep_int_deci(all);
	//fill precision si necessaire
	//width et autres petit flag
	return (1);
}

int	sep_int_deci(t_spec *all)
{
	int dix; // MACRO
	int stop;
	int a;
	int tmp;
	double up;
	int i = 0;
	double cp_float;
	int tmp_float; // to look at the next one if round up in necessaire or not

	a = 0;
	up = 1.0;
	all->conv->f = va_arg(all->a_list,double);
	all->conv->ent = (int)all->conv->f;
	all->conv->deci = all->conv->f - all->conv->ent;
	dix = 10;
	printf("all->deci : %.15f\n",all->conv->deci);
	stop = all->vision != 0 ? all->vision : 6;
	printf("stop : %d, all->vision : %d\n",stop, all->vision);
	all->conv->fl = all->conv->deci;
	cp_float = all->conv->fl;
	if (stop > 1)
	{
		printf("in\n");
		while (a != stop)
	{
		cp_float *= 10;
		printf("all->conv->fl : %f, a: %d\n",cp_float,a);
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
	printf("tmp : %d\n", tmp_float);
	printf("fl : %f\n", all->conv->fl);
	printf("up : %f\n", up);
}

	else if (stop == 1)
	{
		printf("in\n");
		tmp = all->conv->deci * 100;
		if (tmp % 10 >= 5)
			all->conv->fl = all->conv->deci * 10 + 1;
		else if (tmp % 10 < 5)
			all->conv->fl = all->conv->deci * 10;
	}

	else if (all->vision == 0)
	{
		printf("in\n");
		tmp = all->conv->deci * 10;
		printf("tmp : %d\n", tmp);
		if (tmp >= 5)
			all->conv->ent += 1;
		printf("ent : %d\n",all->conv->ent);
		if (tmp < 5)
			all->conv->fl = all->conv->ent;
			//printf("conv : "\n", );
	}
	return (1);
}
// if all->deci est plus petit que 6 et precsion de 6 leave it as is
//if all->deci est plus petit que 6 et precision moins que 6 ok multiplication par 10
//if precision = 10 stop a 9 et arrondir


// if we don't want to round up than add 1 if round up 0
