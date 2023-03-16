/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalta <spalta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:23:57 by spalta            #+#    #+#             */
/*   Updated: 2023/03/14 19:03:00 by spalta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_error(int i)
{
	if (i != 3)
	{
		write (2, "Error\n", 6);
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

void	print_list(t_data *st)
{
	int	i;

	i = 0;
	while (st)
	{
		i++;
		ft_printf("%d\n", st->nbr);
		if (!st->next)
			break ;
		st = st->next;
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (ac >= 2)
	{
		if (ac == 2 && ft_strlen(av[1]) == 0)
			return (0);
		ct_av (ac, av, stack);
		index_stacka(stack);
		if (p_lstsize(stack->a) > 3)
		{
			if (p_lstsize(stack->a) == 5)
				start_small_sort2(stack);
			else
				start_big_sort(stack);
		}
		else if (p_lstsize(stack->a) == 2)
			sa(stack);
		else if (p_lstsize(stack->a) == 3)
			start_small_sort(stack);
		else if (p_lstsize(stack->a) == 1)
			print_error(155);
	}
	return (0);
}
