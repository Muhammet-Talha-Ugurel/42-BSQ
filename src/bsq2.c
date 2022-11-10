/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <muhammedtalhaugurel@gmai...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 01:51:10 by mugurel           #+#    #+#             */
/*   Updated: 2022/11/10 03:59:53 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../lib/ft_lib.h"

int	check_obstacle(t_map map, int x_pos, int y_pos)
{
	if (map.map[y_pos][x_pos] == map.obstacle)
		return (1);
	else
		return (0);
}

int	min_num(int left, int top, int cross)
{
	if (left < top && left < cross)
	{
		return (left);
	}
	else if (top < cross)
	{
		return (top);
	}
	else
	{
		return (cross);
	}
}

int	check_lef_top_cros(int **sarry, int x_pos, int y_pos)
{
	int	left;
	int	top;
	int	cross;
	int	min;

	left = sarry[(y_pos + 1)][x_pos];
	top = sarry[y_pos][(x_pos + 1)];
	cross = sarry[y_pos][x_pos];
	min = min_num(left, top, cross);
	return (min);
}

int	bigest_num_in_sarry(int **sarry, t_map map)
{
	int	i;
	int	j;
	int	cmax;

	i = 0;
	j = 0;
	cmax = 0;
	while (i <= map.y)
	{
		while (j <= map.x)
		{
			if (sarry[i][j] > cmax)
			{
				cmax = sarry[i][j];
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (cmax);
}

t_point	first_bigest_num_in_sarry(int **sarry, int cmax, t_map map)
{
	int		y;
	int		x;
	t_point	loc;

	y = 0;
	x = 0;
	while (y <= map.y)
	{
		while (x <= map.x)
		{
			if (sarry[y][x] == cmax)
			{
				loc.x_pos = x;
				loc.y_pos = y;
				loc.max = cmax;
				return (loc);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (loc);
}
