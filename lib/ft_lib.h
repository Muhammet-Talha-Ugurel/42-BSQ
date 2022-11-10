/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <muhammedtalhaugurel@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 21:24:41 by mugurel           #+#    #+#             */
/*   Updated: 2022/11/10 03:59:51 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIB_H
# define FT_LIB_H

typedef struct t_point
{
	int	max;
	int	x_pos;
	int	y_pos;
}				t_point;

typedef struct t_map
{
	char	**map;
	char	empty;
	char	obstacle;
	char	full;
	int		x;
	int		y;
}				t_map;

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_atoi(char *str);
int		ft_open_file(char *fd_name);
char	**ft_read_file(int fd, int len_x, int len_y, char **str);
void	ft_close_file(int fd);
int		ft_map_len_y(int fd);
int		ft_map_len_x(int fd);
char	**ft_create_map_arry(int fd, int len_x, int len_y);
void	mtu_bsq(char *fd_name);
int		**create_soliton_arry(int len_x, int len_y);
int		check_obstacle(t_map map, int x_pos, int y_pos);
int		min_num(int left, int top, int cross);
int		check_lef_top_cros(int **sarry, int x_pos, int y_pos);
int		bigest_num_in_sarry(int **sarry, t_map map);
t_point	first_bigest_num_in_sarry(int **sarry, int cmax, t_map map);
t_map	ft_read2_file(int fd, int len_x, int len_y, char **map);

#endif // FT_LIB_H
