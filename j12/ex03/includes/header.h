#ifndef __HEADER_H__
#define __HEADER_H_
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
void	ft_display_line(int offset, char *buf);
void	ft_display_offset(int offset);
void	ft_putnbr_base(int nbr, char *base);
int	ft_strcmp(char *a, char *b);
void	ft_display_error(char *file);
typedef		struct s_bloc
{
char *offset;
char *hexa;
char *str;
}	 	s_bloc;
#endif
