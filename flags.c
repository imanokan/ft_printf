#include <stdio.h>
#include "libft/libft.h"
#include <stdlib.h>
#include "libftprintf.h"

int  type_spec(char c)
{
    return (c == 'c' || c == 's' || c == 'p' | c == 'f'
    || c == 'd' || c == 'x' || c == 'X' || c == 'i' || c == 'o');
}

static int		ft_numlen(int n)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int recup_precision(char *s)
{
  int i;
  int x;
  i = 0;

  while (s[i] != '\0')
  {
    while (ft_isdigit(s[i + 1]))
    {
        x = ft_atoi(&s[i]);
        i = i + ft_numlen(x);
    }
    i++;
  }
  printf("x ; %d\n",x);
  return (x);
}
int main(void)
{
  char *s;
  s = "-85.5558";
  int i = 0;
  int j;
  int w;
  int p;
  int x;
  while (s[i] != '\0')
  {
    if (s[i] == '+')
        printf("+\n");
    if (s[i] == '-')
        printf("-\n");
        i++;
    if (s[i] == ' ' )
            printf("space\n");
    if (s[i] == '0' && ft_isdigit(s[i + 1]))
        printf("zero\n");
    if (s[i] == ' ')
        printf("space\n");
    if (s[i] == '#')
        printf("#\n");
    if (ft_isdigit(s[i])) //&& (s[i + 1] != '.' || s[i + 1] != type_spec(s[i]))))
      //printf("i : %d\n",i );
      w = ft_atoi(&s[i]);
      i = i + ft_numlen(w);
      printf("w : %d\n", w);
      //i++;
    if (s[i] == '.')
        p = ft_atoi(&s[i +1]);
        printf("p :%d\n", p);
    break;

    /*
    if (s[i] == '.')
      recup_precision(s);
    i++;*/
    }
  return(0);
  }
