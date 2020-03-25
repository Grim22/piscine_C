/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 15:34:28 by bbrunet           #+#    #+#             */
/*   Updated: 2019/09/06 12:21:17 by bbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_char_is_printable(char c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

void	ft_convert(char *c)
{
	unsigned char	d;
	char			*hex;

	hex = "0123456789abcdef";
	d = (unsigned char)*c;
	write(1, "\\", 1);
	write(1, &hex[d / 16], 1);
	write(1, &hex[d % 16], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_char_is_printable(str[i]))
			write(1, (str + i), 1);
		else
			ft_convert(str + i);
		i++;
	}
}
