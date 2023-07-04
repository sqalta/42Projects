/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyumak <muyumak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 17:13:50 by melih             #+#    #+#             */
/*   Updated: 2023/06/13 14:50:42 by muyumak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_pos_dir(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'N' || map->map[i][j] == 'S'
				|| map->map[i][j] == 'E' || map->map[i][j] == 'W')
			{
				map->pos_x = i;
				map->pos_y = j;
				map->direction = map->map[i][j];
			}
			j++;
		}
		i++;
	}
}

void	get_direction(t_map *map)
{
	if (map->direction == 'N')
	{
		map->dir_x = -1;
		map->fov_y = 0.90;
	}
	if (map->direction == 'W')
	{
		map->dir_y = -1;
		map->fov_x = -0.90;
	}
	if (map->direction == 'S')
	{
		map->dir_x = 1;
		map->fov_y = -0.90;
	}
	if (map->direction == 'E')
	{
		map->dir_y = 1;
		map->fov_x = 0.90;
	}
}

void	get_image_data(t_map *map)
{
	int	bpp;
	int	size_line;
	int	endian;

	bpp = 0;
	size_line = 0;
	endian = 0;
	map->img_blue = mlx_xpm_file_to_image(map->mlx_ptr,
			map->no, &map->width, &map->height);
	map->img_grey = mlx_xpm_file_to_image(map->mlx_ptr,
			map->so, &map->width, &map->height);
	map->img_red = mlx_xpm_file_to_image(map->mlx_ptr,
			map->we, &map->width, &map->height);
	map->img_purple = mlx_xpm_file_to_image(map->mlx_ptr,
			map->ea, &map->width, &map->height);
	map->blue_data = (int *)mlx_get_data_addr(map->img_blue,
			&bpp, &size_line, &endian);
	map->grey_data = (int *)mlx_get_data_addr(map->img_grey,
			&bpp, &size_line, &endian);
	map->red_data = (int *)mlx_get_data_addr(map->img_red,
			&bpp, &size_line, &endian);
	map->purple_data = (int *)mlx_get_data_addr(map->img_purple,
			&bpp, &size_line, &endian);
}

void	rotate_left(t_map *map)
{
	double	old_dir_x;
	double	old_fov_x;

	old_dir_x = map->dir_x;
	map->dir_x = map->dir_x * cos(map->rotate_speed) \
	- map->dir_y * sin(map->rotate_speed);
	map->dir_y = old_dir_x * sin(map->rotate_speed) \
	+ map->dir_y * cos(map->rotate_speed);
	old_fov_x = map->fov_x;
	map->fov_x = map->fov_x * cos(map->rotate_speed) \
	- map->fov_y * sin(map->rotate_speed);
	map->fov_y = old_fov_x * sin(map->rotate_speed) \
	+ map->fov_y * cos(map->rotate_speed);
}

void	rotate_right(t_map *map)
{
	double	old_dir_x;
	double	old_fov_x;

	old_dir_x = map->dir_x;
	map->dir_x = map->dir_x * cos(-map->rotate_speed) \
	- map->dir_y * sin(-map->rotate_speed);
	map->dir_y = old_dir_x * sin(-map->rotate_speed) \
	+ map->dir_y * cos(-map->rotate_speed);
	old_fov_x = map->fov_x;
	map->fov_x = map->fov_x * cos(-map->rotate_speed) \
	- map->fov_y * sin(-map->rotate_speed);
	map->fov_y = old_fov_x * sin(-map->rotate_speed) \
	+ map->fov_y * cos(-map->rotate_speed);
}
