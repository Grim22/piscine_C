/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 14:37:48 by bbrunet           #+#    #+#             */
/*   Updated: 2019/09/04 17:35:51 by bbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_nbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		ft_nbr(-nb);
	}
	else if (nb != 0)
	{
		ft_nbr(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_nbr(-214748364);
		ft_putchar('8');
	}
	else if (nb == 0)
	{
		ft_putchar('0');
	}
	else
		ft_nbr(nb);
}
