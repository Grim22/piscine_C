int ft_strcmp(char *a, char *b);

void ft_sort_wordtab(char **tab)
{
	int i = 0;
	char *temp = 0;
	while (tab[i + 1])
	{
		if (ft_strcmp(tab[i], tab[i + 1]) > 0)
		{
			temp = tab[i + 1];
			tab[i + 1] = tab[i];
			tab[i] = temp;
			i = 0;
		}
		else
			i++;
	}
}



