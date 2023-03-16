/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalta <spalta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:36:42 by spalta            #+#    #+#             */
/*   Updated: 2022/12/26 20:56:00 by spalta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hexa(unsigned int a, char *s, int *result)
{
	char	*base;

	base = s;
	if (a >= 16)
	{
		ft_hexa(a / 16, s, result);
		ft_hexa(a % 16, s, result);
	}
	else
		ft_putchar(base[a], result);
}

void	ft_pointer(unsigned long long a, int *result)
{
	char	*base_p;

	base_p = "0123456789abcdef";
	if (a >= 16)
	{
		ft_pointer(a / 16, result);
		ft_pointer(a % 16, result);
	}
	else
		ft_putchar(base_p[a], result);
}
