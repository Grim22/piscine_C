/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 16:14:45 by bbrunet           #+#    #+#             */
/*   Updated: 2019/09/03 14:33:59 by bbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_duo(int i)
{
	ft_putchar(i / 10 + '0');
	ft_putchar(i % 10 + '0');
}

void	print_comb(int i, int j)
{
	if (i != 98)
	{
		ft_duo(i);
		ft_putchar(' ');
		ft_duo(j);
		ft_putchar(',');
		ft_putchar(' ');
	}
	else
	{
		ft_duo(i);
		ft_putchar(' ');
		ft_duo(j);
	}
}

void	ft_print_comb2(void)
{
	int i;
	int j;

	i = 0;
	while (i <= 99)
	{
		j = 0;
		while (j <= 99)
		{
			if (i < j)
			{
				print_comb(i, j);
			}
			j++;
		}
		i++;
	}
}
