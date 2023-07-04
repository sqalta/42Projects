/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyumak <muyumak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:12:14 by muyumak           #+#    #+#             */
/*   Updated: 2023/06/13 12:58:19 by muyumak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_p(t_map *map)
{
	mlx_destroy_window(map->mlx_ptr, map->mlx_win);
	closed_game(map);
	exit(0);
}

int	key_press(int key, t_map *map)
{
	if (key == 53)
	{
		mlx_destroy_window(map->mlx_ptr, map->mlx_win);
		closed_game(map);
		exit(0);
	}
	if (key == 13)
		move_forward(map);
	if (key == 1)
		move_back(map);
	if (key == 0)
		move_left(map);
	if (key == 2)
		move_right(map);
	if (key == 123)
		rotate_left(map);
	if (key == 124)
		rotate_right(map);
	return (0);
}
