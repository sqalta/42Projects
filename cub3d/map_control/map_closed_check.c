/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_closed_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozdemi <rbozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:58:48 by rbozdemi          #+#    #+#             */
/*   Updated: 2023/06/13 14:59:11 by rbozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	zero_all_check(char **map, int i, int j, int height)
{
	if (i - 1 < 0 || i + 1 > height || j - 1 < 0 || j
		+ 1 > (int)ft_strlen(map[i]) - 1)
	{
		printf("Error\nMap is not closed\n");
		exit(1);
	}
	if ((map[i - 1][j] == ' ' || map[i - 1][j] == '\0') || map[i + 1][j] == ' '
		|| map[i][j - 1] == ' ' || map[i][j + 1] == ' ')
	{
		printf("Error\nMap is not closed\n");
		exit(1);
	}
	if ((int)ft_strlen(map[i - 1]) < j || (int)ft_strlen(map[i + 1]) < j)
	{
		printf("Error\nMap is not closed\n");
		exit(1);
	}
}

void	map_closed_check(t_map *mapes)
{
	int	i;
	int	j;

	i = 0;
	while (mapes->map[i])
	{
		j = 0;
		while (mapes->map[i][j])
		{
			if (mapes->map[i][j] == '0')
				zero_all_check(mapes->map, i, j, mapes->height);
			j++;
		}
		i++;
	}
}
