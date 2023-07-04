/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resulbozdemir <resulbozdemir@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:20:34 by rbozdemi          #+#    #+#             */
/*   Updated: 2023/05/20 17:14:24 by resulbozdem      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*get_map(char *map)
{
	int		i;
	char	*line;
	char	*map_array;
	int		fd;

	line = NULL;
	map_array = NULL;
	fd = open(map, O_RDONLY);
	i = 0;
	while (line != NULL || i == 0)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		map_array = ft_strjoin2(map_array, line);
		if (line != NULL)
			free(line);
		i++;
	}
	return (map_array);
}
