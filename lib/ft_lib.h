/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <muhammedtalhaugurel@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 21:24:41 by mugurel           #+#    #+#             */
/*   Updated: 2022/11/03 17:43:10 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIB_H
# define FT_LIB_H

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_atoi(char *str);
int		ft_open_file(char *fd_name);
char	**ft_read_file(int fd, int len_x, int len_y);
void	ft_close_file(int fd);
int		ft_map_len_y(int fd);
int		ft_map_len_x(int fd);
char	**ft_create_map_arry(int fd, int len_x, int len_y);
void	mtu_bsq(char *fd_name);
char	**create_soliton_arry(int len_x, int len_y);
int		check_obstacle(char **map,int x_pos,int y_pos);

#endif // FT_LIB_H
