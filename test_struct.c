
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


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
int main()
{
	all *a;
	
	a = malloc(sizeof(all));
	a->c =(t_sol*)malloc(sizeof(t_sol));
	a->c->b = 2;
	printf("b : %d\n", a->c->b);
	return (0);
}
