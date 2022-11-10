/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <muhammedtalhaugurel@gmai...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 01:51:32 by mugurel           #+#    #+#             */
/*   Updated: 2022/11/10 04:01:11 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../lib/ft_lib.h"

t_map	bsq_get_map(char *fd_name, int ***sarry)
{
	int		fd;
	int		len_x;
	int		len_y;
	char	**map;
	t_map	imap;

	fd = ft_open_file(fd_name);
	len_y = ft_map_len_y(fd);
	ft_close_file(fd);
	fd = ft_open_file(fd_name);
	len_x = ft_map_len_x(fd);
	ft_close_file(fd);
	map = ft_create_map_arry(fd, len_x, len_y);
	fd = ft_open_file(fd_name);
	map = ft_read_file(fd, len_x, len_y, map);
	ft_close_file(fd);
	fd = ft_open_file(fd_name);
	imap = ft_read2_file(fd, len_x, len_y, map);
	ft_close_file(fd);
	*sarry = create_soliton_arry(len_x, len_y);
	return (imap);
}

int	**solition_map_desing(t_map map, int **sarry, int x_pos, int y_pos)
{
	int	min;

	min = 0;
	if (check_obstacle(map, x_pos, y_pos) == 1)
	{
		sarry[y_pos + 1][x_pos + 1] = 0;
	}
	else
	{
		min = check_lef_top_cros(sarry, x_pos, y_pos) + 1;
		sarry[y_pos + 1][x_pos + 1] = min;
	}
	return (sarry);
}

void	draw_the_solition_from_mtu(t_map map, t_point loc)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	x = loc.x_pos - 1;
	y = loc.y_pos - 1;
	while (y >= (loc.y_pos - loc.max))
	{
		while (x >= (loc.x_pos - loc.max))
		{
			map.map[y][x] = map.full;
			x--;
		}
		x = loc.x_pos - 1;
		y--;
	}
	while (map.map[i] != 0)
	{
		ft_putstr(map.map[i]);
		ft_putchar('\n');
		i++;
	}
}

void	find_bigest_square(t_map map, int **sarry)
{
	int		x_pos;
	int		y_pos;
	t_point	loc;

	x_pos = 0;
	y_pos = 0;
	while (y_pos < map.y)
	{
		while (x_pos < map.x)
		{
			sarry = solition_map_desing(map, sarry, x_pos, y_pos);
			x_pos++;
		}
		x_pos = 0;
		y_pos++;
	}
	loc = first_bigest_num_in_sarry(sarry, bigest_num_in_sarry(sarry, map), map);
	draw_the_solition_from_mtu(map, loc);
}

void	mtu_bsq(char *fd_name)
{
	t_map	map;
	int		**sarry;

	map = bsq_get_map(fd_name, &sarry);
	find_bigest_square(map, sarry);
}
