/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyumak <muyumak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:39:27 by muyumak           #+#    #+#             */
/*   Updated: 2023/02/01 03:07:10 by muyumak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include "./minilibx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_map
{
	char	**lines;
	char	*wall_path;
	char	*player_path;
	char	*collectible_path;
	char	*escape_path;
	char	*c_move;
	void	*mlx_ptr;
	void	*mlx_win;
	void	*img_wall;
	void	*img_player;
	void	*img_collectible;
	void	*img_escape;
	int		width;
	int		height;	
	int		len_of_line;
	int		number_of_p;
	int		number_of_c;
	int		number_of_e;
	int		player_x;
	int		player_y;
	int		escape_x;
	int		escape_y;
	int		number_of_move;
}t_map;

int		split_len(char **lines);
int		check_filename(char *argv);
int		get_map_lines(t_map *map, char *filename);
int		check_map(t_map *map);
int		map_len(char *filename);
int		key_press(int key, t_map *map);
int		draw_images(t_map *map);
int		init_map(t_map *map);
int		check_map_lines(t_map *map);
int		check_walls(t_map *map);
void	check_escape_arrive(t_map *map, int x, int y);
int		key_p(t_map *map);
void	draw_helper(t_map *map, int i, int x, int y);
int		check_collectible(t_map *map);
int		check_escape(t_map *map, int y, int x);
void	find_player(t_map *map);
void	free_lines(t_map *map);
int		find_escape(t_map *map);
void	write_movement(t_map *map);
int		helper_func(t_map *map);
void	check_map_helper(t_map *map, int i);
void	write_movement_helper(t_map *map);

#endif
