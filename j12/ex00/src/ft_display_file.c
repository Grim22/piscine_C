#include <fcntl.h>
#include <unistd.h>


#define BUF_SIZE 100

void ft_display_file(char *file)
{
	int fd;
	char buf[BUF_SIZE + 1];
	int ret;

	fd = open(file, O_RDONLY);
	if (fd != -1)
	{
		ret = read(fd, buf, BUF_SIZE);
		while(ret)
		{
			buf[ret] = 0;
			write(1, buf, ret + 1);
			ret = read(fd, buf, BUF_SIZE);
		}
	}
	close(fd);
}

int main(int ac, char **av)
{
	if (ac == 1)
		write(2, "File name missing\n", 19);
	if (ac >= 3)
		write(2, "Too many arguments\n", 19);
	else
		ft_display_file(av[1]);
}


