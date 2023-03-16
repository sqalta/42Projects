/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resulbozdemir <resulbozdemir@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:39:11 by resulbozdem       #+#    #+#             */
/*   Updated: 2022/10/27 18:46:31 by resulbozdem      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointer(unsigned long ptr)
{
	int	res;

	res = 0;
	if (ptr > 15)
		res += ft_pointer(ptr / 16);
	res += ft_putchar_fd("0123456789abcdef"[ptr % 16], 1);
	return (res);
}
