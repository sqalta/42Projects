/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozdemi <rbozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:12:46 by rbozdemi          #+#    #+#             */
/*   Updated: 2023/05/16 14:52:03 by rbozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		x;

	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (0);
	i = 0;
	x = -1;
	while (s1[++x])
	{
		str[i] = s1[x];
		i++;
	}
	x = -1;
	while (s2[++x])
	{
		str[i] = s2[x];
		i++;
	}
	str[i] = '\0';
	return (str);
}
