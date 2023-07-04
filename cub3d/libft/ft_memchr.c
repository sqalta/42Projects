/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resulbozdemir <resulbozdemir@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:33:51 by rbozdemi          #+#    #+#             */
/*   Updated: 2022/10/20 19:15:10 by resulbozdem      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	int				i;

	i = 0;
	str = (unsigned char *)s;
	if (n == 0)
		return (0);
	while (n > 0)
	{
		if (str[i] == (unsigned char)c)
			return (&str[i]);
		i++;
		n--;
	}
	if (c == '\0')
		return (&str[i]);
	return (0);
}
