#include "libftprintf.h"


int specifiers_f(t_spec *all)
{
	int n;
	double nb; 
	int i = 0;
	
	all->conv->f = va_arg(all->a_list, double);
	n = (int)all->conv->f; //ft_atoi 
	nb = all->conv->f - n + 0.001; //ft_atoi
	while (n < 6)
		filled_float_[i++] = '0';
	// Tu rajoutes les 0
	// tu les g

	printf("nb : %f\n",nb);
	return(1);
}
