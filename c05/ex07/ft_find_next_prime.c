/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:40:25 by bbrunet           #+#    #+#             */
/*   Updated: 2019/09/12 09:31:05 by bbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_prime(int nb)
{
	int i;

	i = 5;
	if (nb <= 1)
		return (0);
	else if (nb == 2)
		return (1);
	else if (nb % 2 == 0)
		return (0);
	else if (nb == 3)
		return (1);
	else if (nb % 3 == 0)
		return (0);
	else
	{
		while (i <= nb - 1)
		{
			if (nb % i == 0)
				return (0);
			else
				i = i + 2;
		}
		return (1);
	}
}

int		ft_find_next_prime(int nb)
{
	int i;

	if (nb <= 2)
		return (2);
	else if (ft_is_prime(nb))
		return (nb);
	i = nb;
	while (!ft_is_prime(i))
		i++;
	return (i);
}
