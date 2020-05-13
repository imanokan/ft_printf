#include <stdio.h>
#include "libft/libft.h"
int type_spec(char c)
{
	return (c == 's' || c =='d');
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
		}
		else
	i++;		printf("r\n");
	}
	return (0);
}
int main(void)
{
	char *str;
	str = "adrey %34.d";
	ft_printf(str);
	return (0);
}
