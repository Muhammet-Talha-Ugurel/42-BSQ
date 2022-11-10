/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <muhammedtalhaugurel@gmai...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 01:50:53 by mugurel           #+#    #+#             */
/*   Updated: 2022/11/10 04:01:51 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../lib/ft_lib.h"

char	**ft_create_map_arry(int fd, int len_x, int len_y)
{
	char	**str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = (char **)malloc(sizeof(char *) * (len_y + 1));
	str[len_y] = 0;
	while (len_y > i)
	{
		str[i] = (char *)malloc(sizeof(char) * (len_x + 1));
		i++;
	}
	return (str);
}

int	**create_soliton_arry(int len_x, int len_y)
{
	int	**str;
	int	i;

	i = 0;
	str = (int **)malloc(sizeof(int *) * (len_y + 2));
	str[len_y] = 0;
	while ((len_y + 1) > i)
	{
		str[i] = (int *)malloc(sizeof(int) * (len_x + 2));
		i++;
	}
	i = 0;
	while (len_x > i)
	{
		str[0][i] = 0;
		i++;
	}
	i = 0;
	while (len_y > i)
	{
		str[i][0] = 0;
		i++;
	}
	return (str);
}

t_map	ft_read2_file(int fd, int len_x, int len_y, char **map)
{
	char	c[1];
	char	**str;
	int		x;
	int		y;
	t_map	mapi;

	x = -1;
	y = -1;
	mapi.x = len_x;
	mapi.y = len_y;
	read(fd, c, 1);
	while (c[0] != '\n')
	{
		read(fd, c, 1);
		if (c[0] < 48 || c[0] > 57)
		{
				mapi.empty = c[0];
				read(fd, c, 1);
				mapi.obstacle = c[0];
				read(fd, c, 1);
				mapi.full = c[0];
				break ;
		}
	}
	mapi.map = map;
	return (mapi);
}
