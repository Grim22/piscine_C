/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 09:45:32 by bbrunet           #+#    #+#             */
/*   Updated: 2019/09/03 14:37:28 by bbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_comb(char a, char b, char c)
{
	if (a != '7')
	{
		ft_putchar(a);
		ft_putchar(b);
		ft_putchar(c);
		ft_putchar(',');
		ft_putchar(' ');
	}
	else
	{
		ft_putchar(a);
		ft_putchar(b);
		ft_putchar(c);
	}
}

void	ft_print_comb(void)
{
	char i;
	char j;
	char k;

	i = '0';
	while (i < '9')
	{
		j = '1';
		while (j <= '9')
		{
			if (j > i)
			{
				k = '2';
				while (k <= '9')
				{
					if (k > j)
						ft_comb(i, j, k);
					k++;
				}
			}
			j++;
		}
		i++;
	}
}
