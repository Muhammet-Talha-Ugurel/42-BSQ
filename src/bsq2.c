#include <unistd.h>
#include <stdlib.h>
#include "../lib/ft_lib.h"

int	check_obstacle(char **map,int x_pos,int y_pos)
{
	if (map[x_pos][y_pos] == 'o')
		return (1);
	else
		return (0);
}
