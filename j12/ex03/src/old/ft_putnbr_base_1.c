/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 22:47:59 by bbrunet           #+#    #+#             */
/*   Updated: 2019/09/11 17:22:39 by bbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_checkbase(char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i])
	{
		if (base[i] == 45 || base[i] == 43)
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
	return (i);
}

void	ft_putnbr(long int nbr, char *base, int base_num)
{
	if (nbr != 0)
	{
		ft_putnbr(nbr / base_num, base, base_num);
		write(1, base + (nbr % base_num), 1);
	}
}

void	ft_putnbr_0(long int nbr, char *base, int base_num, char **ret)
{
	int len_nbr;

	len_nbr = ft_len_base(nbr);
	*ret = malloc((len_nbr + 1) * sizeof
	if (nbr < base_num)
	{
		*ret[0] = '0';
		*ret[1] = 
		ft_putnbr(nbr, base, base_num, ret);
}

char	*ft_putnbr_base(int nbr, char *base)
{
	int			base_num;
	long int	l_nbr;
	char *ret;

	l_nbr = (long)nbr;
	if (ft_checkbase(base) != 0)
	{
		base_num = ft_strlen(base);
		if (nbr < 0)
		{
			write(1, "-", 1);
			ft_putnbr_0(-l_nbr, base, base_num, &ret);
		}
		else if (nbr == 0)
			write(1, base, 1);
		else
			ft_putnbr_0(l_nbr, base, base_num, &ret);
	}
}
