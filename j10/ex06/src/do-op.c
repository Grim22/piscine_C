#include <unistd.h>
#include <stdio.h>
#include "header.h"

int ft_add(int a, int b)
{
	return(a + b);
}

int ft_sub(int a, int b)
{
	return(a - b);
}

int ft_mul(int a, int b)
{
	return(a * b);
}

int ft_div(int a, int b)
{
	return(a / b);
}

int ft_mod(int a, int b)
{
	return(a % b);
}

void ft_doop(int a, int b, char c)
{
	int (*tab[5])(int a, int b);
	
	tab[0] = &ft_add;
	tab[1] = &ft_sub;
	tab[2] = &ft_mul;
	tab[3] = &ft_div;
	tab[4] = &ft_mod;

	if (c == '+')
		ft_putnbr((*tab[0])(a, b));
	if (c == '-')
		ft_putnbr((*tab[1])(a, b));
	if (c == '*')
		ft_putnbr((*tab[2])(a, b));
	if (c == '/')
		ft_putnbr((*tab[3])(a, b));
	if (c == '%')
		ft_putnbr((*tab[4])(a, b));
	write(1, "\n", 1);
}

int main(int ac, char **av)
{
	int a;
	int b;
	if (ac != 4)
	{
		ft_putstr("0\n");
		printf("Wrong num param\n");
		return (0);
	}
	a = ft_atoi(av[1]);
	b = ft_atoi(av[3]);
	if (ft_strcmp(av[2],"+") != 0 && ft_strcmp(av[2], "-") != 0 && ft_strcmp(av[2],"/") != 0 && ft_strcmp(av[2],"%") != 0 && ft_strcmp(av[2],"*") != 0)
	{
		ft_putstr("0\n");
		printf("Wrong sign\n");
		return (0);
	}
	if (av[2][0] == '/' && b == 0)
	{
		ft_putstr("Stop: division by zero\n");
		return (0);
	}
	if (av[2][0] == '%' && b == 0)
	{
		ft_putstr("Stop: modulo by zero\n");
		return (0);
	}
	printf("Doop\n");
	ft_doop(a, b, av[2][0]);
}
