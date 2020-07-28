#include <stdio.h>
#include "libft/libft.h"

int main(void)
{
  char *s;
  s = " + - 895214.05";
  int i = 0;
  while (s[i] != '\0')
  {
    if (s[i] == '+')
        printf("+\n");
    if (s[i] == '-')
        printf("-\n");
    if (s[i] == ' ' )// ft_isalnum(s[i + 1]))
            printf("space\n");
    if (s[i] == '0' && ft_isdigit(s[i + 1]))
        printf("zero\n");
    //if (s[i] == ' ')
        //printf("space\n");
    if (s[i] == '#')
        printf("#\n");
    while (ft_isdigit(s[i])) //&& j != 1)
    {
      printf("width : %d\n",s[i]);
      i++;
    }
    if (s[i] == '.')
    {    printf(".\n");
          while(ft_isdigit(s[i + 1]))
          {
            printf("precision\n");
            i++;
          }
    }
    i++;
  }
  return(0);
}
