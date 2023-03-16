/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resulbozdemir <resulbozdemir@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:39:29 by resulbozdem       #+#    #+#             */
/*   Updated: 2022/10/27 18:39:54 by resulbozdem      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	ft_putnbr_fd(int n, int fd)
{
	int	i;

	i = intlen(n);
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if (n < 0)
		{
			n = n * -1;
			ft_putchar_fd('-', fd);
		}
		if (n > 9)
		{
			ft_putnbr_fd(n / 10, fd);
		}
		ft_putchar_fd(n % 10 + 48, fd);
	}
	return (i);
}
