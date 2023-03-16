/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalta <spalta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 16:52:37 by spalta            #+#    #+#             */
/*   Updated: 2023/03/13 05:04:06 by spalta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_min_step(t_data *b)
{
	int	i;
	int	min;

	i = 0;
	min = b->total_step[i++];
	while (i < 4)
	{
		if (b->total_step[i] < min)
			min = b->total_step[i];
		i++;
	}
	b->min_step = min;
}

void	push_a_2(t_data *b, t_stack *stack)
{
	int	tmp;

	tmp = abs(b->up - b->target->up);
	if (b->up > b->target->up)
		while (b->target->up--)
			rr(stack);
	else
		while (b->up--)
			rr(stack);
	if (b->up == 0 || b->up == -1)
		while (tmp--)
			ra(stack, 1);
	else
		while (tmp--)
			rb(stack, 1);
}

void	push_a_1(t_data *b, t_stack *stack)
{
	int	tmp;

	tmp = abs(b->down - b->target->down);
	if (b->down > b->target->down)
		while (b->target->down--)
			rrr(stack);
	else
		while (b->down--)
			rrr(stack);
	if (b->down == 0 || b->down == -1)
		while (tmp--)
			rra(stack, 1);
	else
		while (tmp--)
			rrb(stack, 1);
}

void	push_a(t_stack *stack, t_data *b)
{
	int	i;

	i = -1;
	while (++i < 4)
		if (b->total_step[i] == b->min_step)
			break ;
	if (i == 0)
		push_a_1(b, stack);
	if (i == 1)
		push_a_2(b, stack);
	if (i == 2)
	{
		while (b->down--)
			rrb(stack, 1);
		while (b->target->up--)
			ra(stack, 1);
	}
	if (i == 3)
	{
		while (b->up--)
			rb(stack, 1);
		while (b->target->down--)
			rra(stack, 1);
	}
	pa(stack);
}

void	start_push(t_stack *stack)
{
	t_data	*tmp;
	int		min_step;

	tmp = stack->b;
	min_step = tmp->min_step;
	while (tmp)
	{
		if (tmp->min_step < min_step)
			min_step = tmp->min_step;
		tmp = tmp->next;
	}
	tmp = stack->b;
	while (tmp)
	{
		if (tmp->min_step == min_step)
			break ;
		tmp = tmp->next;
	}
	push_a(stack, tmp);
}
