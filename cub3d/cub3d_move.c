/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyumak <muyumak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 23:41:57 by muyumak           #+#    #+#             */
/*   Updated: 2023/06/13 14:50:56 by muyumak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(t_map *map)
{
	if (map->map[(int)(map->pos_x + map->dir_x * map->move_speed)] \
	[(int)(map->pos_y)] != '1')
		map->pos_x += map->dir_x * map->move_speed;
	if (map->map[(int)(map->pos_x)] \
	[(int)(map->pos_y + map->dir_y * map->move_speed)] != '1')
		map->pos_y += map->dir_y * map->move_speed;
}

void	move_back(t_map *map)
{
	if (map->map[(int)(map->pos_x - map->dir_x * map->move_speed)] \
	[(int)(map->pos_y)] != '1')
		map->pos_x -= map->dir_x * map->move_speed;
	if (map->map[(int)(map->pos_x)] \
	[(int)(map->pos_y - map->dir_y * map->move_speed)] != '1')
		map->pos_y -= map->dir_y * map->move_speed;
}

void	move_left(t_map *map)
{
	if (map->map[(int)(map->pos_x - map->fov_x * map->move_speed)] \
	[(int)(map->pos_y)] != '1')
		map->pos_x -= map->fov_x * map->move_speed;
	if (map->map[(int)(map->pos_x)] \
	[(int)(map->pos_y - map->fov_y * map->move_speed)] != '1')
		map->pos_y -= map->fov_y * map->move_speed;
}

void	move_right(t_map *map)
{
	if (map->map[(int)(map->pos_x + map->fov_x * map->move_speed)] \
	[(int)(map->pos_y)] != '1')
		map->pos_x += map->fov_x * map->move_speed;
	if (map->map[(int)(map->pos_x)] \
	[(int)(map->pos_y + map->fov_y * map->move_speed)] != '1')
		map->pos_y += map->fov_y * map->move_speed;
}
