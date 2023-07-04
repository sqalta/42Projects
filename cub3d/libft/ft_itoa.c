/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozdemi <rbozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:17:53 by rbozdemi          #+#    #+#             */
/*   Updated: 2022/10/21 15:37:54 by rbozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	intlen(int n)
{
	int	i;

	i = 0;
	if (n < 0 || n == 0)
		i = 1;
	while (n != 0)
	{
		i++;
		n = n / 10;
		if (n == 0)
			break ;
	}
	return (i);
}

static int	numcreate(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = intlen(n);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (0);
	str[i] = '\0';
	if (n < 0)
		str[0] = '-';
	else if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		i--;
		str[i] = numcreate(n % 10) + '0';
		n = n / 10;
	}
	return (str);
}
