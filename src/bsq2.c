#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../lib/ft_lib.h"

int	check_obstacle(char **map,int x_pos,int y_pos)
{
	if (map[y_pos][x_pos] == 'o')
		return (1);
	else
		return (0);
}

int	min_num(int left, int top, int cross)
{
	if(left < top && left < cross)
	{
		return (left);
	}
	else if(top < cross)
	{
		return (top);
	}
	else
	{
		return(cross);
	}

}

int	check_lef_top_cros(char **sarry, int x_pos, int y_pos)
{
	int	left;
	int	top;
	int	cross;
	int min;

	left = sarry[(y_pos + 1)][x_pos] - 48;
	top = sarry[y_pos][(x_pos + 1)] - 48;
	cross = sarry[y_pos][x_pos] - 48;
	min = min_num(left, top, cross);
	return (min);
}

int	bigest_num_in_sarry(char **sarry)
{
	int	i;
	int	j;
	int	cmax;

	i = 0;
	j = 0;
	cmax = 0;
	while (sarry[i] != 0)
	{
		while (sarry[i][j] != 0 )
		{
			if ((sarry[i][j] - 48) > cmax)
			{
				cmax = sarry[i][j] - 48;
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (cmax);
}

s_point	first_bigest_num_in_sarry(char **sarry, int cmax)
{
	int	y;
	int	x;
	s_point loc;

	y = 0;
	x = 0;
	while (sarry[y] != 0)
	{
		while (sarry[y][x] != 0 )
		{
			if ((sarry[y][x] - 48) == cmax)
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
