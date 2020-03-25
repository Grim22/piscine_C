/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 15:08:16 by bbrunet           #+#    #+#             */
/*   Updated: 2019/09/11 13:30:21 by bbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isspace(char *c)
{
	if (*c == 32 || *c == 9 || *c == 10 || *c == 11 || *c == 12 || *c == 13)
		return (1);
	return (0);
}

int		ft_issign(char *c)
{
	if (*c == 43 || *c == 45)
		return (1);
	return (0);
}

int		ft_isnum(char *c)
{
	int i;

	i = 0;
	while (i <= 9)
	{
		if (*c == 48 + i)
			return (1);
		i++;
	}
	return (0);
}

int		ft_atoi(char *str)
{
	int i;
	int c;
	int ret;

	i = 0;
	c = 0;
	while (ft_isspace(str + i))
		i++;
	while (ft_issign(str + i))
	{
		if (str[i] == 45)
			c++;
		i++;
	}
	ret = 0;
	while (ft_isnum(str + i))
	{
		ret = ret * 10 + str[i] - 48;
		i++;
	}
	if (c % 2 == 0)
		return (ret);
	return (-ret);
}
