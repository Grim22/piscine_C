/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 21:43:50 by bbrunet           #+#    #+#             */
/*   Updated: 2019/09/15 17:02:26 by bbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_atoi_base(char *str, char *base);
int		ft_strlen(char *str);
int		ft_checkbase(char *base);

int		ft_size_alloc(int nb, char *base)
{
	int i;
	int l_base;
	int ret;

	l_base = ft_strlen(base);
	i = 0;
	ret = nb;
	while (ret)
	{
		ret = ret / l_base;
		i++;
	}
	if (nb > 0)
		return (i + 1);
	else
		return (i + 2);
}

void	ft_assign(int n, char *base, char **ptr, int size_char)
{
	int			l_base;
	long int	long_n;
	int			i;

	long_n = (long)n;
	l_base = ft_strlen(base);
	ptr[0][size_char - 1] = 0;
	if (long_n < 0)
	{
		*ptr[0] = '-';
		long_n = -long_n;
	}
	if (long_n == 0)
		ptr[0][0] = base[0];
	i = size_char - 2;
	while (long_n)
	{
		ptr[0][i] = base[long_n % l_base];
		long_n = long_n / l_base;
		i--;
	}
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		n;
	char	*ptr;
	int		size;

	ptr = 0;
	if (ft_checkbase(base_from) != 0 && ft_checkbase(base_to) != 0)
	{
		n = ft_atoi_base(nbr, base_from);
		size = ft_size_alloc(n, base_to);
		if (!(ptr = malloc(size * sizeof(*ptr))))
			return (0);
		ft_assign(n, base_to, &ptr, size);
		return (ptr);
	}
	return (0);
}
