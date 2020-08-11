
#include "libftprintf.h"

int     conversion_specifier(t_spec *all)
{
    if (all->type == 'c')
        specifier_c(all);
    else if (all->type  == 's')
	specifier_s(all);
    else if (all->type == 'p')
         specifier_p(all);
    else if (all->type == 'd' || all->type == 'i')
	    specifier_d(all);
    else if (all->type == 'u')
             specifier_u(all);
    else if (all->type == 'o')
         specifier_o(all);
    else if (all->type == 'x' )
         specifier_x(all);
  /*
    else if (all->type == 'f')
         specifier_f(all);*/
      return (0);
}
