/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozdemi <rbozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:37:11 by resulbozdem       #+#    #+#             */
/*   Updated: 2023/06/14 16:40:03 by rbozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	player_count_check(t_map *mapes)
{
	int	i;
	int	j;
	int	player_count;

	i = 0;
	player_count = 0;
	while (mapes->map[i])
	{
		j = 0;
		while (mapes->map[i][j])
		{
			if (mapes->map[i][j] == 'N' || mapes->map[i][j] == 'S'
				|| mapes->map[i][j] == 'E' || mapes->map[i][j] == 'W')
				player_count++;
			j++;
		}
		i++;
	}
	if (player_count != 1)
	{
		printf("Error\nPlayer count is not 1\n");
		exit(1);
	}
}

void	map_charecter_check(t_map *mapes)
{
	int	i;
	int	j;

	i = 0;
	while (mapes->map[i])
	{
		j = 0;
		while (mapes->map[i][j])
		{
			if (mapes->map[i][j] != '0' && mapes->map[i][j] != '1'
				&& mapes->map[i][j] != 'N' && mapes->map[i][j] != 'S'
				&& mapes->map[i][j] != 'E' && mapes->map[i][j] != 'W'
				&& mapes->map[i][j] != ' ')
			{
				printf("Error\nMap has invalid charecters\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	player_position_check(t_map *mapes)
{
	int	i;
	int	j;

	i = 0;
	while (mapes->map[i])
	{
		j = 0;
		while (mapes->map[i][j])
		{
			if (mapes->map[i][j] == 'N' || mapes->map[i][j] == 'S'
				|| mapes->map[i][j] == 'E' || mapes->map[i][j] == 'W')
			{
				mapes->player_x = j;
				mapes->player_y = i;
			}
			j++;
		}
		i++;
	}
}

void	map_check(t_map *mapes)
{
	map_height_weidth(mapes);
	map_closed_check(mapes);
	player_count_check(mapes);
	map_charecter_check(mapes);
	player_position_check(mapes);
	mapes->tmp_map = double_str_copy(mapes);
	map_invalid_check(mapes, mapes->player_y, mapes->player_x);
	check_invalid_map(mapes);
	hex_to_decimal(mapes);
}
