/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_control.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozdemi <rbozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:00:55 by rbozdemi          #+#    #+#             */
/*   Updated: 2023/06/13 15:01:02 by rbozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	map_invalid_check(t_map *map, int y, int x)
{
	if (x < 0 || y < 0)
		return ;
	else if (y > map->height - 1 || x > (int)ft_strlen(map->tmp_map[y]) - 1)
		return ;
	else if (map->tmp_map[y][x] == 'k')
		return ;
	else if (map->tmp_map[y][x] == ' ')
		return ;
	map->tmp_map[y][x] = 'k';
	map_invalid_check(map, y, x + 1);
	map_invalid_check(map, y, x - 1);
	map_invalid_check(map, y + 1, x);
	map_invalid_check(map, y - 1, x);
}

void	check_invalid_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->tmp_map[i])
	{
		j = 0;
		while (map->tmp_map[i][j])
		{
			if (map->tmp_map[i][j] == ' ')
			{
				j++;
				continue ;
			}
			if (map->tmp_map[i][j] != 'k')
			{
				printf("Error\nMap is not closed\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
}
