
#include "libftprintf.h"

int     conversion_specifier(t_spec *all)
{
    if (all->type == 'c')
        specifier_c(all);
    else if (all->type  == 's')
	specifier_s(all);
    else if (all->type == 'p')
         specifier_p(all);
    /*
    else if (spec == 'd' || spec == 'i') 
         specifier_d;
    else if (spec == 'o')
         specifier_o;
    else if (spec == 'u')
         specifier_u;
    else if (spec == 'x' ) 
         specifier_x;
    else if (spec == 'X')
         specifier_X;
    else if (spec == 'f')
         specifier_f;*/
      return (0);
}
