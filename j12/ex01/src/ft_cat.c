#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 20

// manque la gestion du cas où pas d'argument

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
		ft_putstr("cat: ");
		ft_putstr(file);
		ft_putstr(": No such file or directory");
	}
	else if (errno == 13)
	{
		ft_putstr("cat: ");
		ft_putstr(file);
		ft_putstr(": Permission denied");
	}
	else if (errno == EISDIR)
	{
		ft_putstr("cat: ");
		ft_putstr(file);
		ft_putstr(": Is a directory");
	}
	
	ft_putchar('\n');
}

void ft_display_file(char *file)
{
	int fd;
	char buf[BUF_SIZE + 1];
	int ret;
	
	fd = open(file, O_RDWR);
	if (fd == -1)
		ft_display_error(file);
	else
	{
		ret = read(fd, buf, BUF_SIZE);
		while(ret)
		{
			buf[ret] = 0;
			write(1, buf, ret);
			ret = read(fd, buf, BUF_SIZE);
		}
	}
	close(fd);
}

int main(int ac, char **av)
{
	int i;

	i = 1;
	while (i < ac)
	{
		ft_display_file(av[i]);
		i++;
	}
}


