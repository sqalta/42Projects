/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyumak <muyumak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:20:48 by rbozdemi          #+#    #+#             */
/*   Updated: 2023/06/13 16:06:45 by muyumak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	map_error(int type)
{
	if (type == 1)
		printf("Error Wrong map name\n");
	else if (type == 2)
		printf("Error Wrong map\n");
	exit(0);
}

int	check_map_name(char *str)
{
	int	i;
	int	fd;

	i = ft_strlen(str) - 1;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (1);
	if (str[i] != 'b')
		return (1);
	else if (str[i - 1] != 'u')
		return (1);
	else if (str[i - 2] != 'c')
		return (1);
	else if (str[i - 3] != '.')
		return (1);
	if (ft_strlen(str) == 4)
		return (1);
	return (0);
}
