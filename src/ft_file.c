/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <muhammedtalhaugurel@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 21:53:40 by mugurel           #+#    #+#             */
/*   Updated: 2022/11/03 17:43:04 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../lib/ft_lib.h"

int	ft_open_file(char *fd_name)
{
	int	fd;

	fd = open(fd_name, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Dict Error");
		exit(1);
	}
	return (fd);
}

int	ft_map_len_x(int fd)
{
	int		i;
	char	c[1];

	i = 0;
	while (read(fd, c, 1) != 0)
	{
		if (c[0] == '\n')
			break ;
		i++;
	}
	return (i);
}

int	ft_map_len_y(int fd)
{
	int		i;
	char	c[1];

	i = 0;
	while (read(fd, c, 1) != 0)
	{
		if (c[0] == '\n')
			i++;
	}
	return (i);
}

char	**ft_read_file(int fd, int len_x, int len_y)
{
	char	c[1];
	char	**str;
	int		x;
	int		y;

	x = 0;
	y = 0;
	str = ft_create_map_arry(fd, len_x, len_y);
	while (len_y > y)
	{
		while (len_x > x)
		{
			read(fd, c, 1);
			if (c[0] != '\n')
			{
				str[y][x] = c[0];
				x++;
			}
		}
		x = 0;
		y++;
	}
	return (str);
}

void	ft_close_file(int fd)
{
	close(fd);
}
