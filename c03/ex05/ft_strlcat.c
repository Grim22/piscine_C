/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 09:51:18 by bbrunet           #+#    #+#             */
/*   Updated: 2019/09/10 21:43:29 by bbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *s)
{
	unsigned int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int nb)
{
	unsigned int i;
	unsigned int j;
	unsigned int ldest;
	unsigned int lsrc;

	ldest = ft_strlen(dest);
	lsrc = ft_strlen(src);
	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (src[j] && j < nb - 1)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = 0;
	if (lsrc <= nb)
		return (ldest + lsrc);
	else
		return (ldest + nb);
}
