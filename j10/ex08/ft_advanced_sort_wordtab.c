void ft_advanced_sort_wordtab(char **tab, int(*cmp)(char *, char *))
{	
	int i = 0;
	char *temp = 0;

	while (tab[i + 1])
	{
		if ((*cmp)(tab[i], tab[i + 1]) > 0)
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
