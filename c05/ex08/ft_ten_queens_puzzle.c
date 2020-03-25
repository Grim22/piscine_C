#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define N 10

int	ft_lig_vide(int **tab, int lig)
{
	int col;
	col = 0;
	while (col < N)
	{
		if (tab[lig][col] != 0)
			return (0);
		else
			col++;
	}
	return (1);
}

int	ft_diag1_vide(int **tab, int col, int lig)
{
	int i;

	i = -N + 1;
	while (i < N)
	{
		if (lig + i < N && lig + i >= 0 && col + i < N && col + i >= 0)
		{
			if (tab[lig + i][col + i] != 0)
			{
				return (0);
			}
			else
				i++;
		}
		else
			i++;
	}
	return (1);
}

int	ft_diag2_vide(int **tab, int col, int lig)
{
	int i;

	i = -N + 1;
	while (i < N)
	{
		if (lig + i < N && lig +i >= 0 && col - i < N && col - i >= 0)
		{
			if (tab[lig + i][col - i] != 0)
			{
				return (0);
			}
			else
				i++;
		}
		else
			i++;
	}
	return (1);
}
int	ft_affichage(int **tab)
{
	int i;
	char c;
	int j;

	j = 0;
	while (j <= N - 1)
	{
		i = 0;
		while (i <= N - 1)
		{
			if (tab[i][j] != 0)
			{
				c = i + 48;
				write(1, &c, 1);
			}
			i++;
		}
		j++;
	}
		write(1, "\n", 1);
}



int	ft_create(int ***p_tab, int col)
{	
	int i;

	if (col == N)
		ft_affichage(*p_tab);
	i = 0;
	while(i < N)
	{
		if (ft_lig_vide(*p_tab, i) && ft_diag1_vide(*p_tab, col, i) && ft_diag2_vide(*p_tab, col, i))
		{
			(*p_tab)[i][col] = 1;
			if (ft_create(p_tab, col + 1))
				return (1);
			(*p_tab)[i][col] = 0;
		}
		i++;
	}
	return (0);
}

int	ft_ten_queens_puzzle(void)
{
	int i = 0;
	int j;
	int **tab;

	tab = malloc(N * sizeof(*tab));
	
	while (i < N)
	{
		tab[i] = malloc(N * sizeof(int));
		i++;
	}
	i = 0;
	j = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			tab[i][j] = 0;
			j++;
		}
		i++;
	}
	ft_create(&tab, 0);
}

int main()
{
	ft_ten_queens_puzzle();
}
