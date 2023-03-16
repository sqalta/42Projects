/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_source.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalta <spalta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:22:38 by spalta            #+#    #+#             */
/*   Updated: 2022/12/27 12:44:21 by spalta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char a, int *result)
{
	write (1, &a, 1);
	*result += 1;
}

void	ft_putstr(char *s, int *result)
{
	int	i;

	i = 0;
	if (!s)
	{
		ft_putstr("(null)", result);
		result += 6;
		return ;
	}
	while (s[i])
	{
		ft_putchar (s[i], result);
		i++;
	}
}

void	ft_putnbr(int a, int *result)
{
	if (a == -2147483648)
	{
		return (ft_putstr ("-2147483648", result));
	}
	if (a < 0)
	{
		ft_putchar('-', result);
		a *= -1;
	}
	if (a >= 10)
	{
		ft_putnbr(a / 10, result);
		ft_putchar(a % 10 + '0', result);
	}
	else
		ft_putchar(a + '0', result);
}

void	ft_unsigned(unsigned int a, int *result)
{
	if (a >= 10)
	{
		ft_putnbr(a / 10, result);
		ft_putnbr(a % 10, result);
	}
	else
		ft_putchar((a + '0'), result);
}
