#include "libftprintf.h"


int specifiers_f(t_spec *all)
{
	int n;
	int nb; 
	int i = 0;
	char *n_str;
	char *nb_str;
	char *nb_float;
	char *nb_deci;
	int len;

	all->conv->f = va_arg(all->a_list, double);
	n = (int)all->conv->f; 
	//n_str = ft_itoa(n);
	nb = all->conv->f - n; //+0.001;
	//ici le truc fois 10 pour le mettre en int et pouvoir faire la suite
	nb_str = ft_itoa(nb);
	//ft_precision_float
	printf("conv_f : %f , n : %d\n", all->conv->f, n);
	printf("nb_tr : %s\n", nb_str);
	len = ft_strlen(nb_str);
	printf("len : %d\n",len);
	if (ft_strlen(nb_str) < 6 && all->precision == 0)
	       while (ft_strlen(nb_str) - i < 6)	
			all->filled_float[i++] = '0';
	else if (all->precision != 0)
	 	if (ft_strlen(nb_str) < all->precision)
			while (ft_strlen(nb_str) - i < all->precision)
					all->filled_float[i++] = '0';
		else if (ft_strlen(nb_str) > all->precision)
			ft_strsub(nb_str,0,all->precision);
	printf("3\n");
	nb_deci = ft_strjoin(nb_str,all->filled_float);
	nb_float = ft_strjoin(n_str, nb_deci);
	all->len_arg = ft_strlen(nb_float);
	//gérér la width comme dioux
	//et les autres flags
	return(1);
}
