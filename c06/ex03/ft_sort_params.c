/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:44:25 by bbrunet           #+#    #+#             */
/*   Updated: 2019/09/12 13:33:40 by bbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap(char **a, char **b)
{
	char *swap;

	swap = *a;
	*a = *b;
	*b = swap;
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_sort_tab(char **tab, int size)
{
	int		j;
	char	*tmp;

	j = 1;
	tmp = 0;
	while (j < size - 1)
	{
		if (ft_strcmp(tab[j], tab[j + 1]) > 0)
		{
			ft_swap(&tab[j], &tab[j + 1]);
			j = 1;
		}
		else
			j++;
	}
}

int		main(int argc, char *argv[])
{
	int i;
	int j;

	i = 1;
	ft_sort_tab(argv, argc);
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			write(1, &argv[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
