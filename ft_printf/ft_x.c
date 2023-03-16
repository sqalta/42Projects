/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resulbozdemir <resulbozdemir@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:39:39 by resulbozdem       #+#    #+#             */
/*   Updated: 2022/10/27 18:48:50 by resulbozdem      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_x(unsigned int nbr, int *i, char *base)
{
	if (nbr < 16)
	{
		if (nbr < 10)
			*i += ft_putchar_fd(nbr + '0', 1);
		else
			*i += ft_putchar_fd(base[nbr % 16], 1);
	}
	if (nbr >= 16)
	{
		ft_x(nbr / 16, i, base);
		ft_x(nbr % 16, i, base);
	}
	return (*i);
}
