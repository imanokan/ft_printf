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

	a = 0; 
	all->conv->f = va_arg(all->a_list,double);
	all->conv->ent = (int)all->conv->f;
	all->conv->deci = all->conv->f - all->conv->ent;
       	dix = 10;
	printf("all->deci : %f\n",all->conv->deci);
	stop = all->vision != 0 ? all->vision : 6;
	while (a != stop)
	{
		all->conv->fl = all->conv->deci * dix;
		dix = dix * 10;
		a++;
	}
	printf("deci : %d\n",all->conv->fl);
	if (stop == 6)
		round_up(all);
	// stop < 6
	// cut from the moment str[i] == 00 ou 10  
	printf("fl : %d\n", all->conv->fl);
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
int num_after_deci(t_spec *all)
{
	int after_deci; //

	after_deci = 0;
}
		
