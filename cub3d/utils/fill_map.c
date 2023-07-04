/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozdemi <rbozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:42:56 by rbozdemi          #+#    #+#             */
/*   Updated: 2023/06/13 12:07:00 by rbozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	full_map_space_trim(t_map *mapes)
{
	int		i;
	char	*tmp;

	i = 0;
	while (i < 6 && mapes->fullmap[i])
	{
		tmp = mapes->fullmap[i];
		mapes->fullmap[i] = ft_strtrim(tmp, " ");
		free(tmp);
		i++;
	}
}

void	fill_map(t_map *mapes)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (mapes->fullmap[i])
	{
		if (!ft_strncmp(mapes->fullmap[i], "NO", 2))
			mapes->no = ft_strtrim(mapes->fullmap[i] + 2, " ");
		else if (!ft_strncmp(mapes->fullmap[i], "SO", 2))
			mapes->so = ft_strtrim(mapes->fullmap[i] + 2, " ");
		else if (!ft_strncmp(mapes->fullmap[i], "WE", 2))
			mapes->we = ft_strtrim(mapes->fullmap[i] + 2, " ");
		else if (!ft_strncmp(mapes->fullmap[i], "EA", 2))
			mapes->ea = ft_strtrim(mapes->fullmap[i] + 2, " ");
		else if (!ft_strncmp(mapes->fullmap[i], "F", 1))
			mapes->f = ft_strtrim(mapes->fullmap[i] + 1, " ");
		else if (!ft_strncmp(mapes->fullmap[i], "C", 1))
			mapes->c = ft_strtrim(mapes->fullmap[i] + 1, " ");
		else
			mapes->map[j++] = ft_strdup(mapes->fullmap[i]);
		i++;
	}
	mapes->map[j] = NULL;
}
