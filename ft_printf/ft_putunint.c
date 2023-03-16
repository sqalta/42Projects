/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resulbozdemir <resulbozdemir@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:39:36 by resulbozdem       #+#    #+#             */
/*   Updated: 2022/10/27 18:39:52 by resulbozdem      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunint(unsigned int number)
{
	int	i;

	i = 0;
	if (number > 9)
		i += ft_putunint(number / 10);
	write(1, &"0123456789"[number % 10], 1);
	i++;
	return (i);
}
