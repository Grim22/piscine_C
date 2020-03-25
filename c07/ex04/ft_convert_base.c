/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 23:15:49 by bbrunet           #+#    #+#             */
/*   Updated: 2019/09/15 16:47:12 by bbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_isbase(char *c, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (*c == base[i])
			return (1);
		i++;
	}
	return (0);
}

int		ft_checkbase(char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i])
	{
		if ((base[i] >= 9 && base[i] <= 13) || base[i] == 32
				|| base[i] == 43 || base[i] == 45)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i == 1 || i == 0)
		return (0);
	return (1);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_baseindex(char *c, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (*c == base[i])
			return (i);
		i++;
	}
	return (0);
}

int		ft_atoi_base(char *str, char *base)
{
	int i;
	int c;
	int ret;

	if (ft_checkbase(base) != 0)
	{
		i = 0;
		c = 1;
		while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			i++;
		while (str[i] == 43 || str[i] == 45)
		{
			if (str[i] == 45)
				c = c * (-1);
			i++;
		}
		ret = 0;
		while (ft_isbase(str + i, base))
		{
			ret = ft_strlen(base) * ret + ft_baseindex(str + i, base);
			i++;
		}
		return (c * ret);
	}
	return (0);
}
