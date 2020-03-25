/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:26:28 by bbrunet           #+#    #+#             */
/*   Updated: 2019/09/10 14:27:39 by bbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int i;
	int ret;

	if (nb == 0)
		return (1);
	else if (nb < 0)
		return (0);
	else
	{
		i = 1;
		ret = 1;
		while (i != nb + 1)
		{
			ret = ret * i;
			i++;
		}
		return (ret);
	}
}
