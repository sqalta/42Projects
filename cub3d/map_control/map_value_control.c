/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_value_control.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozdemi <rbozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:37:16 by rbozdemi          #+#    #+#             */
/*   Updated: 2023/06/13 20:34:44 by rbozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	not_value_check(char *str, char *type)
{
	int	i;

	i = 0;
	if (ft_strncmp(str, type, ft_strlen(type)))
		return (1);
	if (ft_strlen(type) == 1)
		return (0);
	str += ft_strlen(type);
	while (str[i])
	{
		if (str[i] == '.' && str[i + 1] == '/')
			return (0);
		if (str[i] != ' ' && str[i] != '\t')
			return (1);
		i++;
	}
	return (1);
}

int	map_param_count_check(int one, int two, int three)
{
	if (one > 1 || two > 1 || three > 1)
		return (1);
	if (one == 0 || two == 0 || three == 0)
		return (1);
	return (0);
}

int	map_param_check2(char **fillmap)
{
	int	i;
	int	j;
	int	no;
	int	so;
	int	we;

	i = 6;
	no = 0;
	so = 0;
	we = 0;
	j = 0;
	while (i && fillmap[j])
	{
		if (!not_value_check(fillmap[j], "NO"))
			no++;
		else if (!not_value_check(fillmap[j], "SO"))
			so++;
		else if (!not_value_check(fillmap[j], "WE"))
			we++;
		i--;
		j++;
	}
	if (map_param_count_check(no, so, we))
		return (1);
	return (0);
}

int	map_param_check3(char **fillmap)
{
	int	i;
	int	j;
	int	ea;
	int	f;
	int	c;

	i = 6;
	ea = 0;
	f = 0;
	c = 0;
	j = 0;
	while (i && fillmap[j])
	{
		if (!not_value_check(fillmap[j], "EA"))
			ea++;
		else if (!not_value_check(fillmap[j], "F"))
			f++;
		else if (!not_value_check(fillmap[j], "C"))
			c++;
		i--;
		j++;
	}
	if (map_param_count_check(ea, f, c))
		return (1);
	return (0);
}

int	map_param_check(char **fillmap)
{
	if (map_param_check2(fillmap))
		return (1);
	if (map_param_check3(fillmap))
		return (1);
	if (fillmap[6] == NULL || (fillmap[6][0] != '1' && fillmap[6][0] != ' '
			&& fillmap[6][0] != '\t' && fillmap[6][0] != '0'))
		return (1);
	return (0);
}
