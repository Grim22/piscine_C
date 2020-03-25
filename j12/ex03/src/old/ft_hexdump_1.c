void ft_display_error(char *file)
{
	if (errno == 2)
	{
		//		ft_putstr("cat: ");
		ft_putstr(file);
		//		ft_putstr(": No such file or directory");
	}
	else if (errno == 13)
	{
		//		ft_putstr("cat: ");
		ft_putstr(file);
		//		ft_putstr(": Permission denied");
	}
	else if (errno == EISDIR)
	{
		//		ft_putstr("cat: ");
		ft_putstr(file);
		//		ft_putstr(": Is a directory");
	}

	ft_putstr("\n");
}

char *ft_fill_offset(int offset)
{
	int count_zero;
	int i;
	int tmp;
	char ret[9];

	count_zero = 8;
	tmp = offset;
	while (offset)
	{
		offset = offset / 16;
		count_zero--;
	}
	i = 0;
	while(i < count_zero)
	{
		ret[i] = '0';
		i++;
	}
	if (tmp)
		ft_putnbr_base(tmp, "0123456789abcdef", ret + i);
	ret[8] = 0;
}

char *ft_fill_hex(char *buf)
{


}

char *ft_fill_str(char *buf)
{


}


void fill_struct(s_bloc **bloc, char *file, int nb_bloc)
{
	int fd;
	char buf[BUF_SIZE + 1];
	int ret;
	int i;
	int offset;

	fd = open(file, O_RDWR);
	offset = 0;
	i = 0;
	ret = read(fd, buf, BUF_SIZE);
	while (i < nb_bloc)
	{
		buf[ret] = 0;
		bloc[i]->offset = ft_fill_offset(offset);
		bloc[i]->hexa = ft_fill_hex(buf);
		bloc[i]->str = ft_fill_str(buf);
		offset = offset + ret;
		ret = read(fd, buf, BUF_SIZE);
		i++;
	}
	close(fd);				
}

void ft_display_file(char *file)
{
	int nb_bloc;
	int i;
	int j;
	s_bloc *bloc;

	nb_bloc = ft_lenght(file) / 16;
	if (!(bloc = malloc(nb_bloc * sizeof(*bloc))))
		return;
	fill_struct(&bloc, file, nb_bloc);
	display_struct(bloc[0]);
	i = 1;
	while (i < size_struct)
	{	j = i;
		while (str_cmp(bloc[j].str, bloc[i-1].str) == 0)
			{
				write(1, "*\n", 2);
				j++;
			}
		i = j;
		display_struct(bloc[i]);
		i++;
	}
	//	ft_display_offset(offset + ret);
	//	write(1, "\n", 1);
	close(fd);				
}

int main(int ac, char **av)
{
	int i;
	int fd;

	i = 2;
	while (i < ac)
	{
		fd = open(av[i], O_RDWR);
		if (fd == -1)
			ft_display_error(file);
		else
			ft_display_file(av[i]);
		i++;
	}
}


