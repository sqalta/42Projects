/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozdemi <rbozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:21:48 by resulbozdem       #+#    #+#             */
/*   Updated: 2023/06/13 12:24:19 by rbozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	file_check(t_map *mapes)
{
	int	a;
	int	b;
	int	c;
	int	d;

	a = open(mapes->no, O_RDONLY);
	b = open(mapes->so, O_RDONLY);
	c = open(mapes->we, O_RDONLY);
	d = open(mapes->ea, O_RDONLY);
	if (a < 0 || b < 0 || c < 0 || d < 0)
		return (1);
	return (0);
}
