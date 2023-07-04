/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozdemi <rbozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:36:54 by rbozdemi          #+#    #+#             */
/*   Updated: 2022/10/21 15:36:57 by rbozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_set(const char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (s1[i] && check_set(s1[i], set))
		i++;
	j = ft_strlen(s1);
	while (j > i && check_set(s1[j - 1], set))
		j--;
	str = (char *)malloc(sizeof(char) * j - i + 1);
	if (!str)
		return (0);
	while (i < j)
	{
		str[k] = s1[i];
		k++;
		i++;
	}
	str[k] = '\0';
	return (str);
}
