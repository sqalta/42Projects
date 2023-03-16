/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyumak <muyumak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:10:51 by muyumak           #+#    #+#             */
/*   Updated: 2022/10/24 22:13:23 by muyumak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*strlink;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	strlink = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!strlink)
		return (NULL);
	while (s1[i])
	{
		strlink[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		strlink[i] = s2[j];
		i++;
		j++;
	}
	strlink[i] = 0;
	return (strlink);
}
