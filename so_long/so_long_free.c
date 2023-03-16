/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyumak <muyumak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 02:51:48 by muyumak           #+#    #+#             */
/*   Updated: 2023/02/01 03:03:52 by muyumak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_lines(t_map *map)
{
	int	i;

	i = -1;
	while (map->lines[++i])
		free(map->lines[i]);
}

void	write_movement(t_map *map)
{
	map->number_of_move++;
	free(map->c_move);
	map->c_move = ft_itoa(map->number_of_move);
	mlx_string_put(map->mlx_ptr, map->mlx_win, 29, 36, 0, map->c_move);
	ft_putstr_fd("Number of movement: ", 1);
	ft_putnbr_fd(map->number_of_move, 1);
	ft_putchar_fd('\n', 1);
}

int	helper_func(t_map *map)
{
	if (!check_map_lines(map))
		return (0);
	if (!check_walls(map))
	{
		write(2, "Error!", 6);
		return (0);
	}
	return (1);
}
