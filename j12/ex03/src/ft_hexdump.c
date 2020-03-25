#include "header.h"
#include <stdio.h>

int ft_is_identical(char **tab_bloc, int index)
{
	if (index == 0)
		return(0);
	if (ft_strcmp(tab_bloc[index], tab_bloc[index - 1]) == 0)
		return(1);
	return(0);
}

int ft_file_len(char *file)
{
	int fd;
	char buf[1000];
	int ret;

	fd = open(file, O_RDWR);
	ret = read(fd, buf, 1000);
	while (read(fd,buf, 1000))
		ret = ret + read(fd, buf, 1000);
	close (fd);
	return(ret);	
}

void ft_alloc_assign_tab_bloc(char *file, char ***tab_bloc)
{
	int nb;
	int fd;
	char buf[17];
	int ret;
	int i;
	int j;

	nb = ft_file_len(file) / 16;
	if (!(*tab_bloc = malloc((nb + 1) * sizeof(**tab_bloc))))
		return;
	fd = open(file, O_RDWR);
	ret = read(fd, buf, 16);
	i = 0;
	while(ret)
	{
		if (!(tab_bloc[0][i] = malloc(17 * sizeof(char))))
			return;
		buf[ret] = 0;
		j = 0;
		while (buf[j])
		{
			tab_bloc[0][i][j] = buf[j];
			j++;
		}
		tab_bloc[0][i][16] = 0;
		ret = read(fd, buf, 16);
		i++;
	}
	tab_bloc[0][i] = 0;
	close(fd);
}

void ft_free_tab(char **tab_bloc)
{
	int i;

	while (tab_bloc[i])
	{
		free(tab_bloc[i]);
		i++;
	}
	free(tab_bloc);
}

void ft_display_file(char *file)
{
	int fd;
	char buf[17];
	int tmp;
	int offset;
	char **tab_bloc;
	int index;

	ft_alloc_assign_tab_bloc(file, &tab_bloc);	
	fd = open(file, O_RDWR);
	offset = 0;
	index = 0;
	tmp = read(fd, buf, 16);
	while (tmp)
	{
		buf[tmp] = 0;
		if (ft_is_identical(tab_bloc, index))
			write(1, "*\n", 2);
		else
			ft_display_line(offset, buf);
		index++;
		offset = offset + tmp;
		tmp = read(fd, buf, 16);
	}
	ft_display_offset(offset + tmp);
	write(1, "\n", 1);
	ft_free_tab(tab_bloc);
	close(fd);
}
// si on doit gérer plusieurs parametres, il faut améliorer le programme: commencer par concatener le contenu des fichiers passé en parametre, puis envoyer a ft_display_file le résultat de cette concatenation
int main(int ac, char **av)
{
	int i;
	int fd;

	i = 2;
	while (i < ac)
	{
		fd = open(av[i], O_RDWR);
		if (fd == -1)
		{
			ft_display_error(av[i]);
			return (0);
		}
		close(fd);
		ft_display_file(av[i]);
		i++;
	}
}

