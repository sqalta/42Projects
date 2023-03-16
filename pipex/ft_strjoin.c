/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyumak <muyumak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:10:51 by muyumak           #+#    #+#             */
/*   Updated: 2023/01/10 17:09:24 by muyumak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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
