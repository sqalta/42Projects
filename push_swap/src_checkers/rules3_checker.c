/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules3_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalta <spalta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 05:20:15 by spalta            #+#    #+#             */
/*   Updated: 2023/03/14 19:02:38 by spalta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rrr(t_stack	*stack)
{
	rra(stack);
	rrb(stack);
}

void	print_error(int i)
{
	if (i == 3)
		get_next_line(0);
	else if (i != 3)
	{
		write (1, "Error\n", 6);
		exit (1);
	}
	exit(0);
}

int	p_atoi(const char *str)
{
	int			i;
	int			sign;
	long int	result;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == 32 || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = (result * 10) + str[i++] - 48;
	result *= sign;
	if (!(result <= 2147483647 && result >= -2147483648))
		print_error(1);
	return ((int)result);
}
