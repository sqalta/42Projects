/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozdemi <rbozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:21:57 by rbozdemi          #+#    #+#             */
/*   Updated: 2023/06/19 12:59:35 by rbozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./mlx/mlx.h"
# include "get_line/get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

typedef struct s_map
{
	void	*mlx_ptr;
	void	*mlx_win;
	char	*floor_path;
	char	*sky_path;
	void	*img_floor;
	void	*img_blue;
	void	*img_grey;
	void	*img_red;
	void	*img_purple;
	void	*img_screen;
	int		*blue_data;
	int		*grey_data;
	int		*red_data;
	int		*purple_data;
	int		*screen_data;
	void	*img_sky;
	char	*img_addr;
	char	**fullmap;
	char	*so;
	char	*no;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
	int		f_int;
	int		c_int;
	char	**map;
	char	*map_line;
	char	**tmp_map;
	int		player_x;
	int		player_y;
	int		width;
	int		height;

	int		bpp;
	int		size_line;
	int		endian;

	int		img_width;
	int		img_height;
	double	pos_x;
	double	pos_y;
	int		map_x;
	int		map_y;
	double	dir_x;
	double	dir_y;
	double	raydir_x;
	double	raydir_y;
	double	plane_x;
	double	plane_y;
	double	fov_x;
	double	fov_y;
	double	camera_x;
	double	camera_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	time;
	double	oldtime;
	double	side_dist_x;
	double	side_dist_y;
	double	perp_wall_dist;
	double	wall_x;
	double	step;
	double	tex_pos;
	double	move_speed;
	double	rotate_speed;
	int		hit;
	int		side;
	int		step_x;
	int		step_y;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		next_pos;
	int		tex_x;
	int		tex_y;
	int		color;
	char	direction;
	int		x_resolution;
	int		y_resolution;
}			t_map;

int			map_space_control(char *map);
int			check_map_name(char *str);
int			map_control(char *map, int type, t_map *mapes);
int			map_size(char **map);
void		free_map(char **map);
char		*get_map(char *map);
void		map_error(int type);
void		fill_map(t_map *mapes);
void		map_height_weidth(t_map *mapes);
int			map_param_check(char **fillmap);
int			not_value_check(char *str, char *type);
void		full_map_space_trim(t_map *mapes);
int			rgb_check(t_map *mapes);
int			empty_map(char *map);
void		rgb_to_hex(t_map *mapes);
int			file_check(t_map *mapes);
void		map_check(t_map *mapes);
void		closed_game(t_map *mapes);
char		**double_str_copy(t_map *mapes);
void		hex_to_decimal(t_map *mapes);
void		map_closed_check(t_map *mapes);
void		map_invalid_check(t_map *map, int y, int x);
void		check_invalid_map(t_map *map);

int			key_p(t_map *map);
int			key_press(int key, t_map *map);
void		draw_background(t_map *map);
void		get_image_data(t_map *map);
void		move_forward(t_map *map);
void		move_back(t_map *map);
void		move_right(t_map *map);
void		move_left(t_map *map);
void		rotate_left(t_map *map);
void		rotate_right(t_map *map);
void		get_pos_dir(t_map *map);
int			raycasting(t_map *map);
void		get_direction(t_map *map);
void		calculate_distance_of_ray(t_map *map);
void		calculate_step(t_map *map);
void		set_screen_data(t_map *map, int x);
void		hit_check(t_map *map);

#endif