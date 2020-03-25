#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define SIZE 1000

// améliorations possibles: gérer l'input du nombre de bytes fourni après le '-c'
// Cas 1) ca n'est pas un nombre (ex: -c xyz) -> afficher message d'erreur 'invalid number of bytes'
// Cas 2) il y a un '-' devant (ex: -c -20) -> tail fait comme si le '-' n'existait pas (faire * -1)
// Cas 3) il y a un '+' devant (ex: -c +20) -> A confirmer mais il semblerait que tail affiche tout le fichier



int ft_atoi(char *str);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, (str + i), 1);
		i++;
	}
}

void ft_display_error(char *file)
{
	if (errno == 2)
	{
		ft_putstr("tail: cannot open '");
		ft_putstr(file);
		ft_putstr("' for reading: No such file or directory");
	}
	else if (errno == 13)
	{
		ft_putstr("tail: cannot open '");
		ft_putstr(file);
		ft_putstr("' for reading: Permission denied");
	}
	else if (errno == EISDIR)
	{
		ft_putstr("tail: error reading '");
		ft_putstr(file);
		ft_putstr("': Is a directory");
	}

	ft_putchar('\n');
}

void ft_display_tail(int lim, int size, char *file)
{
	int fd;
	int ret;
	char *buf;
	char *buf2;
	int offset;

	if(!(buf2 = malloc(size * sizeof(char))))
		return;
	if (!(buf = malloc((lim + 1) * sizeof(char))))
		return;
	fd = open(file, O_RDWR);
	if (lim >= size)
		offset = 0;
	else
		offset = size - lim;
	read(fd, buf2, offset);
	ret = read(fd, buf, lim);
	buf[ret] = 0;
	write(1, buf, ret);
	free(buf);
	free(buf2);
}

void ft_display(int lim, char *file)
{
	int fd;
	char buf[SIZE + 1];
	int ret;
	int i = 0;

	fd = open(file, O_RDWR);
	if (fd == -1)
		ft_display_error(file);
	else
	{
		ret = read(fd, buf, SIZE);
		while (ret)
		{
			i = i + ret;
			buf[ret] = 0;
			ret = read(fd, buf, SIZE);
		}
		close(fd);
		ft_display_tail(lim, i, file);
	}
}

int main(int ac, char **av)
{	
	int i;

	i = 3;
	if (ac >= 4)
	{
		while (i < ac)
		{
			ft_display(ft_atoi(av[2]), av[i]);
			i++;
		}
	}
}

