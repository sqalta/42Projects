/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalta <spalta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:38:15 by spalta            #+#    #+#             */
/*   Updated: 2022/12/20 14:53:11 by spalta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*pt;
	int		a;
	size_t	i;

	a = ft_strlen(s1) + 1;
	pt = ft_calloc(a, sizeof(char ));
	if (!pt)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		pt[i] = s1[i];
		i++;
	}
	return (pt);
}
