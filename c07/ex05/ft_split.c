/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 23:35:07 by bbrunet           #+#    #+#             */
/*   Updated: 2019/09/18 11:23:16 by bbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_issep(char c, char *charset)
{
	int i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int		ft_num(char *str, char *charset)
{
	int i;
	int c;

	i = 0;
	c = 0;
	while (str[i])
	{
		while (ft_issep(str[i], charset) && str[i])
			i++;
		if (!str[i])
			return (c);
		while (!(ft_issep(str[i], charset)) && str[i])
			i++;
		c++;
	}
	return (c);
}

int		ft_index(char *str, char *charset, int **deb, int **fin)
{
	int i;
	int c;

	if (!(*deb = malloc((ft_num(str, charset)) * sizeof(**deb))) ||
			!(*fin = malloc((ft_num(str, charset)) * sizeof(**deb))))
		return (0);
	i = 0;
	c = 0;
	while (str[i])
	{
		while (ft_issep(str[i], charset) && str[i])
			i++;
		if (str[i])
		{
			(*deb)[c] = i;
			while (!(ft_issep(str[i], charset)) && str[i])
			{
				i++;
			}
			(*fin)[c] = i - 1;
			c++;
		}
	}
	return (0);
}

char	*ft_strdub(char *str, char *charset, int index)
{
	int		*deb;
	int		*fin;
	char	*ret;
	int		i;

	ft_index(str, charset, &deb, &fin);
	ret = malloc((fin[index] - deb[index] + 2) * sizeof(*ret));
	i = deb[index];
	while (i <= fin[index])
	{
		ret[i - deb[index]] = str[i];
		i++;
	}
	ret[i - deb[index]] = 0;
	return (ret);
}

char	**ft_split(char *str, char *charset)
{
	char	**ptab;
	int		num;
	int		i;

	num = ft_num(str, charset);
	if (!(ptab = malloc((num + 1) * sizeof(*ptab))))
		return (0);
	i = 0;
	while (i < num)
	{
		ptab[i] = ft_strdub(str, charset, i);
		i++;
	}
	ptab[num] = 0;
	return (ptab);
}
