/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyumak <muyumak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:38:36 by muyumak           #+#    #+#             */
/*   Updated: 2023/02/01 03:07:37 by muyumak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_p(t_map *map)
{
	mlx_destroy_window(map->mlx_ptr, map->mlx_win);
	exit(1);
}

void	draw_helper(t_map *map, int i, int x, int y)
{
	int	j;

	j = -1;
	while (map->lines[i][++j] && map->lines[i][j] != '\n')
	{
		if (map->lines[i][j] == '1')
			mlx_put_image_to_window(map->mlx_ptr, map->mlx_win,
				map->img_wall, x, y);
		else if (map->lines[i][j] == 'P')
		{
			mlx_put_image_to_window(map->mlx_ptr, map->mlx_win,
				map->img_player, x, y);
			map->player_x = x;
			map->player_y = y;
		}
		else if (map->lines[i][j] == 'C')
			mlx_put_image_to_window(map->mlx_ptr, map->mlx_win,
				map->img_collectible, x, y);
		else if (map->lines[i][j] == 'E')
			mlx_put_image_to_window(map->mlx_ptr, map->mlx_win,
				map->img_escape, x, y);
		x += 64;
	}
}

int	draw_images(t_map *map)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	while (map->lines[i])
	{
		draw_helper(map, i, x, y);
		x = 0;
		y += 64;
		i++;
	}
	return (1);
}

int	init_map(t_map *map)
{
	map->wall_path = "./textures/wall.xpm";
	map->player_path = "./textures/player.xpm";
	map->collectible_path = "./textures/collectible.xpm";
	map->escape_path = "./textures/escape.xpm";
	map->mlx_ptr = mlx_init();
	map->mlx_win = mlx_new_window(map->mlx_ptr, 64 * map->width,
			64 * map->height, "so_long");
	map->img_wall = mlx_xpm_file_to_image(map->mlx_ptr, map->wall_path,
			&map->width, &map->height);
	map->img_player = mlx_xpm_file_to_image(map->mlx_ptr, map->player_path,
			&map->width, &map->height);
	map->img_collectible = mlx_xpm_file_to_image(map->mlx_ptr,
			map->collectible_path, &map->width, &map->height);
	map->img_escape = mlx_xpm_file_to_image(map->mlx_ptr,
			map->escape_path, &map->width, &map->height);
	draw_images(map);
	mlx_hook(map->mlx_win, 17, 0, &key_p, map);
	mlx_hook(map->mlx_win, 2, 0, &key_press, map);
	map->c_move = ft_itoa(map->number_of_move);
	mlx_string_put(map->mlx_ptr, map->mlx_win, 29, 36, 0, map->c_move);
	mlx_loop(map->mlx_ptr);
	return (1);
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
	{
		ft_putstr_fd("Invalid number of arguments!\n", 2);
		return (1);
	}
	if (!check_filename(argv[1]))
		return (1);
	map.height = map_len(argv[1]);
	map.lines = malloc(sizeof(char *) * (map.height + 1));
	map.lines[map.height] = 0;
	if (!get_map_lines(&map, argv[1]))
		return (1);
	map.width = ft_strlen(map.lines[map.height - 1]);
	if (!check_map(&map))
		return (1);
	find_player(&map);
	if (!find_escape(&map) || !check_collectible(&map))
		return (1);
	free_lines(&map);
	get_map_lines(&map, argv[1]);
	write_movement_helper(&map);
	init_map(&map);
	return (0);
}
