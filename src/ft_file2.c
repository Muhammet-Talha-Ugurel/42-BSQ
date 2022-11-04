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

char	**create_soliton_arry(int len_x, int len_y)
{
	char	**str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = (char **)malloc(sizeof(char *) * (len_y + 2));
	str[len_y] = 0;
	while ((len_y + 1) > i)
	{
		str[i] = (char *)malloc(sizeof(char) * (len_x + 2));
		i++;
	}
	i = 0;
	while (len_x > i)
	{
		str[0][i] = '0';
		i++;
	}
	i = 0;
	while (len_y > i)
	{
		str[i][0] = '0';
		i++;
	}
	return (str);
}
