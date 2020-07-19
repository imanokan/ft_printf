#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"
#include <stdarg.h>

typedef struct		a_all
{
	char *c;
	t_ball *a;
	char *b;
	
}			all;

typedef struct 	b_all
{
	int d;
}		t_ball;
/*
int ft_printf(char *format,...)
{
	va_list a_list;
	int i;
	i = 0;
	all *all;

	all = malloc(sizeof(all));
	va_start(a_list, format);
	all->c = va_arg(a_list,char*);
	while (all->c[i] != '\0')
	{
		ft_putchar(all->c[i]);
		i++;
	}
	write(1,"\n",1);
	bis(all);
	ft_printf("%s",all->b);
	va_end(a_list);
	free(all);
	return(0);
}

int	bis(all *all)
{
	int i = 0;
	while (all->c[i] != '\0')
	{
		ft_putchar(all->c[i]);
		i++;
	}
	return (0);
}*/

int main()
{
	char *s;
	char *n;

	//char *format;
	all *all;
	t_ball *a;
	a = malloc(sizeof(t_ball));
	all = malloc(sizeof(all));
	all->a->d = 2;
	printf("d : %d\n",all->a->d);
	//format = "%s";
	s = "aud";
	n = "pop";
	all->b = "zee";
		
	//ft_printf("%s" "%s", s,n );
	//bis(all);
	//printf("%.2d\n",n);
	//printf("%+d\n",n);
	return (0);
}
/*
int main()
{
	char *s;
	int j; 
	int o;
	int i;
       	char c;	
	char *u;
	i = 0;
	j = 98; 
	o = -50;
	s = "s";
	u = "uuuu";
	c = 'q';
	//c = ft_strjoin(s,u);
	//ft_putchar(c);
	//ft_putstr(u);
	printf("s : %s\n", s);
	return (0);
}*/
		
