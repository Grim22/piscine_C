/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 13:40:06 by bbrunet           #+#    #+#             */
/*   Updated: 2019/09/13 17:41:36 by bbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_l_cat(int size, char **strs, char *sep)
{
	int l_cat;
	int i;

	l_cat = 0;
	i = 0;
	while (i < size)
	{
		l_cat = l_cat + ft_strlen(*(strs + i));
		i++;
	}
	if (size)
		l_cat = l_cat + ft_strlen(sep) * (size - 1);
	else
		l_cat = 1;
	return (l_cat);
}

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = 0;
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*ptr;
	int		i;

	ptr = malloc(ft_l_cat(size, strs, sep) * sizeof(**strs));
	i = 0;
	if (size == 0)
		*ptr = 0;
	else
	{
		while (i < size - 1)
		{
			ptr = ft_strcat(ptr, ft_strcat(strs[i], sep));
			i++;
		}
		ptr = ft_strcat(ptr, strs[i]);
	}
	return (ptr);
}
