/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_check_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyumak <muyumak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 01:29:38 by muyumak           #+#    #+#             */
/*   Updated: 2023/02/01 03:07:03 by muyumak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_filename(char *filename)
{
	int		len_of_filename;

	len_of_filename = ft_strlen(filename);
	if (filename[len_of_filename - 1] != 'r'
		|| filename[len_of_filename - 2] != 'e'
		|| filename[len_of_filename - 3] != 'b'
		|| filename[len_of_filename - 4] != '.')
	{
		write(2, "Error!", 6);
		return (0);
	}
	return (1);
}

void	check_map_helper(t_map *map, int i)
{
	int	j;

	j = 0;
	while (map->lines[i][j])
	{
		if (map->lines[i][j] == 'P')
			map->number_of_p += 1;
		else if (map->lines[i][j] == 'E')
			map->number_of_e += 1;
		else if (map->lines[i][j] == 'C')
			map->number_of_c += 1;
		else if (map->lines[i][j] != '1' && map->lines[i][j] != '0')
		{
			ft_putstr_fd("Error!", 2);
			exit(1);
		}
		j++;
	}
}

int	check_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->lines[i])
	{
		check_map_helper(map, i);
		i++;
	}
	if (map->number_of_c < 1 || map->number_of_p != 1 || map->number_of_e != 1)
	{
		write(2, "Error!", 6);
		return (0);
	}
	return (1);
}

void	write_movement_helper(t_map *map)
{
	ft_putstr_fd("Number of movement: ", 1);
	ft_putnbr_fd(map->number_of_move, 1);
	ft_putchar_fd('\n', 1);
}
