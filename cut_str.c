#include <stdio.h>
#include "./libft/libft.h"

int  type_spec(char c)
{
    return (c == 'c' || c == 's' || c == 'p' | c == 'f'
    || c == 'd' || c == 'x' || c == 'X' || c == 'i' || c == 'o');
}

int       ft_printf(char *str)
{
    int i;
    int j;
    char *spec;

    i = 0;
    j = 0;
    printf("begin\n");
    while (str[i] != '\0')
    {
        if (str[i] == '%' && str[i + 1] != '%') {
            j = 0;
            while (str[i] && !type_spec(str[i])) {
                i++;
                j++;
            }
            spec = ft_strsub(str, i - j, j + 1);
            printf("spec : %s\n", spec);
            //flags
            free(spec);
        }
            else
            {
                if (str[i] == '%')
		{
		      	i++;
		}
                write(1, &str[i], 1);
            }
            i++;
        }
        return (0);
}
int main(void)
{
	char *s;
	int d;
	int c;

	s = "% 12c ";
	d = 45;
	c = -34;
	printf("space:%+d\n",d);
	printf("space neg:%+d\n",c);
	ft_printf(s);
	return(0);
}
