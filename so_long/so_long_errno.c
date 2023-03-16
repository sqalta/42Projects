/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_errno.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyumak <muyumak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 00:41:17 by muyumak           #+#    #+#             */
/*   Updated: 2023/01/31 04:26:07 by muyumak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_escape_arrive(t_map *map, int y, int x)
{
	if (map->lines[y][x + 1] == '0' || map->lines[y][x + 1] == 'C')
	{
		map->lines[y][x + 1] = 'P';
		check_escape_arrive(map, y, x + 1);
	}
	if (map->lines[y][x - 1] == '0' || map->lines[y][x - 1] == 'C')
	{
		map->lines[y][x - 1] = 'P';
		check_escape_arrive(map, y, x - 1);
	}
	if (map->lines[y + 1][x] == '0' || map->lines[y + 1][x] == 'C')
	{
		map->lines[y + 1][x] = 'P';
		check_escape_arrive(map, y + 1, x);
	}
	if (map->lines[y - 1][x] == '0' || map->lines[y - 1][x] == 'C')
	{
		map->lines[y - 1][x] = 'P';
		check_escape_arrive(map, y - 1, x);
	}
}

int	check_collectible(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->lines[++i])
	{
		j = -1;
		while (map->lines[i][++j])
		{
			if (map->lines[i][j] == 'C')
			{
				write(2, "Error!", 6);
				return (0);
			}
		}
	}
	return (1);
}

int	check_escape(t_map *map, int y, int x)
{
	if (map->lines[y + 1][x] == 'P' || map->lines[y - 1][x] == 'P'
		|| map->lines[y][x + 1] == 'P' || map->lines[y][x - 1] == 'P')
		return (1);
	write(2, "Error!", 6);
	return (0);
}

void	find_player(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->lines[++i])
	{
		j = -1;
		while (map->lines[i][++j])
		{
			if (map->lines[i][j] == 'P')
			{
				check_escape_arrive(map, i, j);
				break ;
			}
		}
	}
}

int	find_escape(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->lines[++i])
	{
		j = -1;
		while (map->lines[i][++j])
		{
			if (map->lines[i][j] == 'E')
			{
				if (!check_escape(map, i, j))
					return (0);
				break ;
			}
		}
	}
	return (1);
}
