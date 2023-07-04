/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozdemi <rbozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:11:36 by rbozdemi          #+#    #+#             */
/*   Updated: 2023/06/13 18:09:58 by rbozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_isnumber_str(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	rgb_check2(char **rgb_c)
{
	int	one;
	int	two;
	int	three;

	one = ft_atoi(rgb_c[0]);
	two = ft_atoi(rgb_c[1]);
	three = ft_atoi(rgb_c[2]);
	if (!ft_isnumber_str(rgb_c[0]) || !ft_isnumber_str(rgb_c[1])
		|| !ft_isnumber_str(rgb_c[2]))
		return (1);
	if (one < 0 || one > 255 || two < 0 || two > 255 || three < 0
		|| three > 255)
		return (1);
	return (0);
}

int	rgb_check(t_map *mapes)
{
	int		one;
	int		two;
	int		three;
	char	**rgb_f;
	char	**rgb_c;

	rgb_f = ft_split(mapes->f, ',');
	rgb_c = ft_split(mapes->c, ',');
	if (!rgb_f[0] || !rgb_f[1] || !rgb_f[2] || !rgb_c[0] || !rgb_c[1]
		|| !rgb_c[2])
		return (1);
	one = ft_atoi(rgb_f[0]);
	two = ft_atoi(rgb_f[1]);
	three = ft_atoi(rgb_f[2]);
	if (!ft_isnumber_str(rgb_f[0]) || !ft_isnumber_str(rgb_f[1])
		|| !ft_isnumber_str(rgb_f[2]))
		return (1);
	if (one < 0 || one > 255 || two < 0 || two > 255 || three < 0
		|| three > 255)
		return (1);
	if (rgb_check2(rgb_c))
		return (1);
	free_map(rgb_f);
	free_map(rgb_c);
	return (0);
}
