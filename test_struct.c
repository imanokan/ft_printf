
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

typedef struct  t_best
{
	int b;
}		t_sol;
typedef struct 		t_test
{
	int a;
	t_sol *c;
}			all;
/*
typedef struct 		t_best
{
	int b;
}			t_sol;
*/
int 	verif(char *s)
{
	int i;
	i = 5; 
	if (i = 3)
		toupper(s[i]);
	return (1);
}
int main()
{
	all *a;
	char *s;
	int j; 
	s = "audrey";
	//j = verif(s);
	printf("retour :%d\n",verif(s));
	if (verif(s) != 1)
		printf("ok : %d\n", verif(s));

	/*a = malloc(sizeof(all));
	a->c =(t_sol*)malloc(sizeof(t_sol));
	a->c->b = 2;
	printf("b : %d\n", a->c->b);*/
	return (0);
}
