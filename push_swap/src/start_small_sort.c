/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_small_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalta <spalta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 05:47:42 by spalta            #+#    #+#             */
/*   Updated: 2023/03/14 18:00:31 by spalta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	start_small_sort(t_stack *stack)
{
	t_data	*tmp;
	int		diff;

	tmp = stack->a;
	diff = tmp->inx - tmp->next->inx;
	if (diff == 2)
		ra (stack, 1);
	else if (diff == 1)
	{
		if (tmp->inx == 2)
			sa(stack);
		else
		{
			sa(stack);
			rra(stack, 1);
		}
	}
	else if (diff == -2)
	{
		rra(stack, 1);
		sa (stack);
	}
	else
		rra (stack, 1);
}

void	start_small_sort2(t_stack *stack)
{
	t_data	*tmp;

	tmp = stack->a;
	while (p_lstsize(stack->a) > 3)
	{
		if (stack->a->inx < 3)
			pb(stack);
		else
			ra(stack, 1);
	}
	index_stacka(stack);
	if (!((stack->a->inx < stack->a->next->inx)
			&& (stack->a->next->inx < stack->a->next->next->inx)))
		start_small_sort(stack);
	pa(stack);
	pa(stack);
	if (stack->a->inx == 2)
		sa(stack);
}
