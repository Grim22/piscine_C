#ifndef HEADER_H
#define HEADER_H
int ft_atoi(char *str);
void ft_putnbr(int a);
void ft_putstr(char *str);
int ft_strcmp(char *s1, char *s2);
int ft_add(int a, int b);
int ft_mul(int a, int b);
int ft_div(int a, int b);
int ft_mod(int a, int b);
int ft_sub(int a, int b);

typedef struct t_opp
{
	char *c;
	int (*fct)(int a, int b);
} t_opp;
#endif
