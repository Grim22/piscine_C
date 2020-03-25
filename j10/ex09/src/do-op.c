#include <unistd.h>
#include <stdio.h>
#include "header.h"
#include "ft_op.h"

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
	int i;
	i = a + b;
	i = 0;
	while (gl_opptab[i].c[0] != c)
		i++;
	i = (gl_opptab[i].fct)(a,b);
	ft_putnbr(i);
	write(1, "\n", 1);
}

int main(int ac, char **av)
{
	int a;
	int b;
	if (ac != 4)
	{
		ft_putstr("0\n");
		return (0);
	}
	a = ft_atoi(av[1]);
	b = ft_atoi(av[3]);
	if (ft_strcmp(av[2],"+") != 0 && ft_strcmp(av[2], "-") != 0 && ft_strcmp(av[2],"/") != 0 && ft_strcmp(av[2],"%") != 0 && ft_strcmp(av[2], "*") != 0)
	{
		ft_putstr("0\n");
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
	ft_doop(a, b, av[2][0]);
}
