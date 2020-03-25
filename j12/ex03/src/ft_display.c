/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 14:54:31 by bbrunet           #+#    #+#             */
/*   Updated: 2019/09/04 09:54:17 by bbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


void	ft_display_str(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 9 && str[i] <= 13)
			write(1, ".", 1);
		else
			write(1, (str + i), 1);
		i++;
	}
}

void ft_display_hex(char *buf)
{
	int i;
	int ascii;

	i = 0;
	ft_display_str("  ");
	while (buf[i] && i < 8)
	{
		ascii = buf[i] + 0;
		ft_putnbr_base(ascii, "0123456789abcdef");
		ft_display_str(" ");
		i++;
	}
	ft_display_str(" ");		
	while (buf[i])
	{
		ascii = buf[i] + 0;
		ft_putnbr_base(ascii, "0123456789abcdef");
		ft_display_str(" ");
		i++;
	}
	while (i < 16)
	{
		ft_display_str("   ");
		i++;
	}	
	ft_display_str(" ");		
}

void ft_display_offset(int offset)
{
	int count_zero;
	int i;
	int tmp;

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
		write(1, "0", 1);
		i++;
	}
	if (tmp)
		ft_putnbr_base(tmp, "0123456789abcdef");
}		

void ft_display_line(int offset, char *buf)
{
	ft_display_offset(offset);
	ft_display_hex(buf);
	write(1, "|", 1);
	ft_display_str(buf);
	write(1, "|", 1);
	write(1, "\n", 1);
}

void ft_display_error(char *file)
{
	ft_display_str("hexdump: ");
	ft_display_str(file);
	if (errno == 2)
		ft_display_str(": No such file or directory");
	else if (errno == 13)
		ft_display_str(": Permission denied");
	else if (errno == EISDIR)
		ft_display_str(": Is a directory");
	write(1,"\n", 1);
}
