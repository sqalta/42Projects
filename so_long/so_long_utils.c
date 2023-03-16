/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyumak <muyumak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 01:23:26 by muyumak           #+#    #+#             */
/*   Updated: 2023/02/01 02:53:23 by muyumak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	split_len(char **lines)
{
	int	i;

	i = 0;
	while (lines[i])
		i++;
	return (i);
}

int	map_len(char *filename)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd <= 0)
		return (0);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (i);
}

int	get_map_lines(t_map *map, char *filename)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd <= 0)
	{
		ft_putstr_fd("Error!", 2);
		return (0);
	}
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		map->lines[i] = line;
		if (map->lines[i][ft_strlen(map->lines[i]) - 1] == '\n')
			map->lines[i][ft_strlen(line) - 1] = 0;
		line = get_next_line(fd);
		i++;
	}
	if (!helper_func(map))
		return (0);
	close(fd);
	return (1);
}

int	check_map_lines(t_map *map)
{
	int		i;
	size_t	len;

	i = -1;
	len = ft_strlen(map->lines[0]);
	while (map->lines[++i])
	{
		if (ft_strlen(map->lines[i]) != len)
		{
			write(2, "Error!", 6);
			return (0);
		}
	}
	return (1);
}

int	check_walls(t_map *map)
{
	int	i;

	i = -1;
	while (map->lines[0][++i])
		if (map->lines[0][i] != '1')
			return (0);
	i = -1;
	while (map->lines[split_len(map->lines) - 1][++i])
		if (map->lines[split_len(map->lines) - 1][i] != '1')
			return (0);
	i = -1;
	while (map->lines[++i])
		if (map->lines[i][0] != '1'
			|| map->lines[i][ft_strlen(map->lines[i]) - 1] != '1')
			return (0);
	return (1);
}
