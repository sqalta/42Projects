/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resulbozdemir <resulbozdemir@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:04:51 by rbozdemi          #+#    #+#             */
/*   Updated: 2023/06/11 19:48:43 by resulbozdem      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	map_size(char **map)
{
	int	i;
	int	j;
	int	b;

	b = 0;
	i = 0;
	j = 0;
	while (map[i][0] != '1' && map[i][0] != '0')
	{
		while (map[i][b] == ' ' || map[i][b] == '\t')
			b++;
		if (map[i][b] == '1' || map[i][b] == '0')
			break ;
		i++;
	}
	j = 0;
	while (map[i])
	{
		j++;
		i++;
	}
	return (j);
}

void	map_height_weidth(t_map *mapes)
{
	int	i;
	int	j;

	i = 0;
	while (mapes->map[i])
	{
		j = 0;
		while (mapes->map[i][j])
			j++;
		if (j > mapes->width)
			mapes->width = j;
		else
			mapes->width = j;
		i++;
	}
	mapes->height = i;
}
