/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 09:49:29 by bbrunet           #+#    #+#             */
/*   Updated: 2019/09/10 12:24:38 by bbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;
	int lsrc;
	int lfind;

	lsrc = ft_strlen(str);
	lfind = ft_strlen(to_find);
	if (to_find[0] == 0)
		return (str);
	else
	{
		i = 0;
		while (i <= lsrc - lfind)
		{
			j = 0;
			while (to_find[j] && str[i + j] == to_find[j])
				j++;
			if (to_find[j] == 0)
				return (&str[i]);
			else
				i++;
		}
	}
	return (0);
}
