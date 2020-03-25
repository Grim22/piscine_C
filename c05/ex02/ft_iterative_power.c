/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:31:04 by bbrunet           #+#    #+#             */
/*   Updated: 2019/09/11 22:41:09 by bbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int i;
	int ret;

	ret = 1;
	if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	else
	{
		i = 0;
		while (i <= power - 1)
		{
			ret *= nb;
			i++;
		}
		return (ret);
	}
}
