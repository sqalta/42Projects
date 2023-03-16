/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalta <spalta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:52:23 by spalta            #+#    #+#             */
/*   Updated: 2023/03/13 05:21:32 by spalta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack	*stack)
{
	t_data	*tmp;

	if (!stack->b)
		return ;
	tmp = stack->b;
	stack->b = stack->b->next;
	tmp->next = NULL;
	p_lstadd_front(&stack->a, tmp);
	ft_printf("pa\n");
}

void	pb(t_stack	*stack)
{
	t_data	*tmp;

	if (!stack->a)
		return ;
	tmp = stack->a;
	stack->a = stack->a->next;
	tmp->next = NULL;
	p_lstadd_front(&stack->b, tmp);
	ft_printf("pb\n");
}

void	ra(t_stack *stack, int i)
{
	t_data	*tmp;
	t_data	*tmp1;

	if (!stack->a)
		return ;
	tmp1 = stack->a;
	tmp = p_lstnew(stack->a->nbr, stack->a->inx);
	p_lstadd_back(&(tmp1), tmp);
	stack->a = stack->a->next;
	free(tmp1);
	if (i)
		ft_printf("ra\n");
}

void	rb(t_stack	*stack, int i)
{
	t_data	*tmp;
	t_data	*tmp1;

	if (!stack->b)
		return ;
	tmp1 = stack->b;
	tmp = p_lstnew(stack->b->nbr, stack->b->inx);
	p_lstadd_back(&(tmp1), tmp);
	stack->b = stack->b->next;
	free(tmp1);
	if (i)
		ft_printf("rb\n");
}

void	rr(t_stack	*stack)
{
	ra(stack, 0);
	rb(stack, 0);
	ft_printf("rr\n");
}
