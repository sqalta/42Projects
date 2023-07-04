/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozdemi <rbozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:21:09 by rbozdemi          #+#    #+#             */
/*   Updated: 2023/05/16 16:21:10 by rbozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		x;

	if (s1 == NULL)
	{
		s1 = malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	str = (char *)malloc((ft_strlen2(s1) + ft_strlen2(s2) + 1) * sizeof(char));
	if (!str)
		return (0);
	i = 0;
	x = -1;
	while (s1[++x])
		str[i++] = s1[x];
	x = -1;
	while (s2[++x])
		str[i++] = s2[x];
	str[i] = '\0';
	free(s1);
	return (str);
}

int	ft_strlen2(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	search_new_line(char *buff, char c)
{
	int	i;

	i = 0;
	if (!buff)
		return (0);
	while (buff[i])
	{
		if (buff[i] == c)
			return (1);
		i++;
	}
	return (0);
}
