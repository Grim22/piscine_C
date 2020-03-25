/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 19:43:48 by bbrunet           #+#    #+#             */
/*   Updated: 2019/09/13 10:48:54 by bbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int *ft_range(int min, int max)
{
	int *tab;
	int i;

	if (min >= max)
		return (0);
	if (!(tab = malloc(sizeof(*tab) * (max - min))))
		return (0);
	i = 0;
	while (i < max - min -1)
	{
		tab[i] = min + 1 + i;
		i++;
	}
	tab[i] = 0;
	return (tab);
}
