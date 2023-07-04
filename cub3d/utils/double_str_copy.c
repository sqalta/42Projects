/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_str_copy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozdemi <rbozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:19:41 by rbozdemi          #+#    #+#             */
/*   Updated: 2023/06/13 12:23:37 by rbozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	**double_str_copy(t_map *mapes)
{
	int		i;
	char	**map;

	i = 0;
	map = malloc(sizeof(char *) * (map_size(mapes->fullmap) + 1));
	while (mapes->map[i])
	{
		map[i] = ft_strdup(mapes->map[i]);
		i++;
	}
	map[i] = NULL;
	return (map);
}
