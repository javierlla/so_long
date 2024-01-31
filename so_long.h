/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jllarena <jllarena@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:53:12 by jllarena          #+#    #+#             */
/*   Updated: 2024/01/29 18:36:50 by jllarena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>
# include <string.h>
# include "./minilibx_opengl/mlx.h"

typedef struct s_map
{
	int		map_parameter_len;
	void	*mlx;
	void	*window;
	int		len_map;
	char	*map;
	char	**str;
	ssize_t	num_lines;
	int		i;
	int		j;
	ssize_t	c;
	ssize_t	y;
	ssize_t	width;
	int		move;
	int		coin;
	int		c_coin;
	int		exit;
	int		position;
	int		new_x;
	int		new_y;
	int		player_x;
	int		player_y;
	int		x_exit;
	int		y_exit;
	void	*fire;
	void	*mouse;
	void	*cheese;
	void	*snow;
	void	*house;
	int		img_width;
	int		img_height;
	int		total;
}	t_map;
//so_long_utils.c
int		ft_mapcheck_malloc_error(void);
int		ft_put_lines(t_map *m);
int		ft_count_lines(t_map *m);
size_t	ft_strlen(const char *s);
void	ft_init_m(t_map *m);
//so_long_check_maps.c
int		ft_checkmap_wall(t_map *m);
int		ft_checkmap_num_comps(t_map *m);
int		ft_checkmap_comps(t_map *m);
int		ft_checkmap_form(t_map *m);
//so_long_floodfill.c
int		ft_checkmap_path_findpos(t_map *m);
int		ft_checkmap_path_findexit(t_map *m);
void	ft_flood_fill(t_map *m, int x, int y);
int		ft_check_flood_fill(t_map *m, int x, int y);
void	ft_revert_flood_fill(t_map *m);
//so_long_graphics.c
void	ft_put_image_window(t_map *m);
void	ft_render_window(t_map *m);
void	ft_start_window(t_map *m);
int		ft_exit_rb(t_map *m);
int		ft_keyhook(int keycode, t_map *m);
//so_long_moves.c
void	ft_print_moves(t_map *m);
void	ft_move_right(t_map *m);
void	ft_move_down(t_map *m);
void	ft_move_left(t_map *m);
void	ft_move_up(t_map *m);
//so_long_moves_utils.c
void	ft_change_img(char *x, char *y);
void	ft_change_exit2(char *x, char *y);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
//so_long.c
int		ft_check_arg(char *argv);
char	*ft_open_map(char *argv, t_map *m);
char	*ft_read(int fd, char *argv, t_map *m);
char	*ft_second_read_map(char *argv, int total, t_map *m);
#endif
