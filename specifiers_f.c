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
	int up;
	int i = 0;


	a = 0;
	all->conv->f = va_arg(all->a_list,double);
	all->conv->ent = (int)all->conv->f;
	all->conv->deci = all->conv->f - all->conv->ent;
	dix = 10;
	printf("all->deci : %.15f\n",all->conv->deci);
	stop = all->vision != 0 ? all->vision : 6;
	while (a != stop + 1)
	{
		all->conv->fl = all->conv->deci * dix;
		printf("all->conv->fl : %d, a: %d\n",all->conv->fl,a);
		dix = dix * 10;
		up = 0;
		a++;
	}
	printf("up : %d\n", *up);
	//if (tmp >= 5)

	if (all->vision == 1)
	{
		tmp = all->conv->deci * 100;
		printf("tmp ; %d\n", tmp);
		if (tmp % 10 >= 5)
		{
			all->conv->fl = all->conv->deci * 10 + 1;
		}
		else if (tmp % 10 < 5)
		{
			printf("in\n");
			all->conv->fl = all->conv->deci * 10;
		}
	}
	else if (all->vision == 0)
	{
		tmp = all->conv->deci * 10;
		printf("tmp : %d\n", tmp);
		if (tmp >= 5)
			all->conv->ent += 1;
		printf("ent : %d\n",all->conv->ent);
		if (tmp < 5)
			all->conv->fl = all->conv->ent;
	}
	/*else if (all->vision > 1)
	{
		tmp = all->conv->deci * dix;

	}*/
	//printf("deci : %d\n",all->conv->fl);
	//if (stop == 6)
		//round_up(all);
	// stop < 6
	// cut from the moment str[i] == 00 ou 10
	//printf("fl : %d\n", all->conv->fl);
	return (1);
}
void round_up(t_spec *all)
{
	int count = 0;
	int new;

	new = all->conv->fl % 10;
	while (new != 10)
	{
		new +=1;
		count += 1;
	}
	all->conv->fl = all->conv->fl + count;
}
// if all->deci est plus petit que 6 et precsion de 6 leave it as is
//if all->deci est plus petit que 6 et precision moins que 6 ok multiplication par 10
//if precision = 10 stop a 9 et arrondir

/*
int num_after_deci(t_spec *all)
{
	int after_deci; //

	after_deci = 0;
}*/
