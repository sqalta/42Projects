/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyumak <muyumak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 05:56:33 by muyumak           #+#    #+#             */
/*   Updated: 2023/01/31 04:33:44 by muyumak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_press_up(t_map *map)
{
	if (map->lines[map->player_y / 64 - 1][map->player_x / 64] != '1')
	{
		if (map->lines[map->player_y / 64 - 1][map->player_x / 64] == 'C')
			map->number_of_c--;
		if (map->lines[map->player_y / 64 - 1][map->player_x / 64]
			== 'E' && map->number_of_c != 0)
			return ;
		mlx_clear_window(map->mlx_ptr, map->mlx_win);
		map->lines[map->player_y / 64][map->player_x / 64] = '0';
		if (map->lines[map->player_y / 64 - 1][map->player_x / 64]
			== 'E' && map->number_of_c == 0)
		{
			write_movement(map);
			mlx_destroy_window(map->mlx_ptr, map->mlx_win);
			exit(1);
		}
		map->lines[map->player_y / 64 - 1][map->player_x / 64] = 'P';
		draw_images(map);
		write_movement(map);
	}
}

void	key_press_down(t_map *map)
{
	if (map->lines[map->player_y / 64 + 1][map->player_x / 64] != '1')
	{
		if (map->lines[map->player_y / 64 + 1][map->player_x / 64] == 'C')
			map->number_of_c--;
		if (map->lines[map->player_y / 64 + 1][map->player_x / 64]
			== 'E' && map->number_of_c != 0)
			return ;
		mlx_clear_window(map->mlx_ptr, map->mlx_win);
		map->lines[map->player_y / 64][map->player_x / 64] = '0';
		if (map->lines[map->player_y / 64 + 1][map->player_x / 64]
			== 'E' && map->number_of_c == 0)
		{
			write_movement(map);
			mlx_destroy_window(map->mlx_ptr, map->mlx_win);
			exit(1);
		}
		map->lines[map->player_y / 64 + 1][map->player_x / 64] = 'P';
		draw_images(map);
		write_movement(map);
	}
}

void	key_press_left(t_map *map)
{
	if (map->lines[map->player_y / 64][map->player_x / 64 - 1] != '1')
	{
		if (map->lines[map->player_y / 64][map->player_x / 64 - 1] == 'C')
			map->number_of_c--;
		if (map->lines[map->player_y / 64][map->player_x / 64 - 1]
			== 'E' && map->number_of_c != 0)
			return ;
		mlx_clear_window(map->mlx_ptr, map->mlx_win);
		map->lines[map->player_y / 64][map->player_x / 64] = '0';
		if (map->lines[map->player_y / 64][map->player_x / 64 - 1]
			== 'E' && map->number_of_c == 0)
		{
			write_movement(map);
			mlx_destroy_window(map->mlx_ptr, map->mlx_win);
			exit(1);
		}
		map->lines[map->player_y / 64][map->player_x / 64 - 1] = 'P';
		draw_images(map);
		write_movement(map);
	}
}

void	key_press_right(t_map *map)
{
	if (map->lines[map->player_y / 64][map->player_x / 64 + 1] != '1')
	{
		if (map->lines[map->player_y / 64][map->player_x / 64 + 1] == 'C')
			map->number_of_c--;
		if (map->lines[map->player_y / 64][map->player_x / 64 + 1]
			== 'E' && map->number_of_c == 0)
		{
			write_movement(map);
			mlx_destroy_window(map->mlx_ptr, map->mlx_win);
			exit(1);
		}
		if (map->lines[map->player_y / 64][map->player_x / 64 + 1]
			== 'E' && map->number_of_c != 0)
			return ;
		mlx_clear_window(map->mlx_ptr, map->mlx_win);
		map->lines[map->player_y / 64][map->player_x / 64] = '0';
		map->lines[map->player_y / 64][map->player_x / 64 + 1] = 'P';
		draw_images(map);
		write_movement(map);
	}
}

int	key_press(int key, t_map *map)
{
	if (key == 53)
	{
		mlx_destroy_window(map->mlx_ptr, map->mlx_win);
		exit(1);
	}
	else if (key == 13)
		key_press_up(map);
	else if (key == 1)
		key_press_down(map);
	else if (key == 0)
		key_press_left(map);
	else if (key == 2)
		key_press_right(map);
	return (0);
}
