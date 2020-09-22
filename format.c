#include <stdio.h>
#include "libft/libft.h"

int main ()
{
	char *s = "%%";
	char *str = "%4%";
	char *jo = "%%%";
	char *a = "%05.4%";
	int i = 0;
	int j = 0;
	char *spec;

	if (a[i] == '%')
		j = i;
	j +=  1;
	while (a[j] != '%')
		j++;
	spec = ft_strsub(a, i, j + 1);
	printf(" spec : %s\n", spec);
//	if spec = "%"
//		print spec;
	return (0);
}
