/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 09:30:14 by bbrunet           #+#    #+#             */
/*   Updated: 2019/09/06 10:18:59 by bbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_char_is_lowercase(char *c)
{
	if (*c >= 97 && *c <= 122)
		return (1);
	else
		return (0);
}

int		ft_char_is_not_alphanum(char *c)
{
	if ((*c >= 97 && *c <= 122) || (*c >= 65 && *c <= 90) ||
		(*c >= 48 && *c <= 57))
		return (0);
	else
		return (1);
}

char	*ft_strowcase(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 65 && str[i] <= 90)
		{
			str[i] = str[i] + 32;
		}
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int i;

	ft_strowcase(str);
	if (ft_char_is_lowercase(&str[0]))
		str[0] = str[0] - 32;
	i = 0;
	while (str[i])
	{
		if (ft_char_is_not_alphanum(&str[i]))
		{
			if (ft_char_is_lowercase(&str[i + 1]))
				str[i + 1] = str[i + 1] - 32;
		}
		i++;
	}
	return (str);
}
