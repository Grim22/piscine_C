/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 21:05:33 by bbrunet           #+#    #+#             */
/*   Updated: 2019/09/13 13:40:01 by bbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int i;

	if (min >= max)
	{
		range = 0;
		return(0);
	}
	if (!(*range = malloc(sizeof(int) * (max - min))))
		return(-1);
	i = 0;
	while (i < max - min - 1)
	{
		*(*range + i) = min + 1 + i;
		i++;
	}
	*(*range + i) = 0;
	return (i);
}


