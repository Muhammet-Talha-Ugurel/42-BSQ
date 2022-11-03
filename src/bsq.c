#include <unistd.h>
#include <stdlib.h>
#include "../lib/ft_lib.h"

char	**bsq_get_map(char *fd_name, char ***sarry)
{
	int		fd;
	int 	len_x;
	int 	len_y;
	char	**map;

	fd = ft_open_file(fd_name);
	len_y = ft_map_len_y(fd);
	ft_close_file(fd);
	fd = ft_open_file(fd_name);
	len_x = ft_map_len_x(fd);
	ft_close_file(fd);
	fd = ft_open_file(fd_name);
	map = ft_read_file(fd, len_x, len_y);
	ft_close_file(fd);
	*sarry = create_soliton_arry(len_x, len_y);
	return (map);
}

int	min_num(int left, int top, int cross)
{

}

int	chec_lef_top_cros(char **sarry, int x_pos, int y_pos)
{

}

char **solition_map_desing(char **map, char **sarry, int x_pos, int y_pos)
{
	int	min;

	if (check_obstacle(map, x_pos, y_pos) == 1)
		sarry[x_pos][y_pos] = '0';
	else
	{
		min = (chec_lef_top_cros(sarry, x_pos, y_pos)) + 1;
		sarry[x_pos][y_pos] = min + 48;
	}

}

void	find_bigest_square(char **map, char **sarry)
{
	int x_pos;
	int y_pos;

	x_pos = 0;
	y_pos = 0;
	while (map[y_pos])
	{
		while (map[y_pos][x_pos])
		{
			sarry = solition_map_desing(map, sarry, x_pos, y_pos);
			x_pos++;
		}
		y_pos++;
	}
}

void	mtu_bsq(char *fd_name)
{
	char	**map;
	char	**sarry;

	map = bsq_get_map(fd_name, &sarry);
	find_bigest_square(map, sarry);
}
