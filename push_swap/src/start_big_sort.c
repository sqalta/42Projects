/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_big_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalta <spalta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:32:36 by spalta            #+#    #+#             */
/*   Updated: 2023/03/13 07:00:14 by spalta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Oluşturacağım stacka için list yapıma bir integer koyup 
b stackine göndermeyeceklerimi işaretleyeceğim.!*/
void	mark_stack_a(t_stack *stack, t_data *first_a)
{
	t_data	*f_next;
	int		tmp_find;

	tmp_find = first_a->inx;
	f_next = first_a->next;
	first_a->push_flag = 1;
	while (f_next)
	{
		if (tmp_find < f_next->inx)
		{
			f_next->push_flag = 1;
			tmp_find = f_next->inx;
		}
		f_next = f_next->next;
	}
	f_next = stack->a;
	while (f_next->inx != first_a->inx)
	{
		if (tmp_find < f_next->inx)
		{
			f_next->push_flag = 1;
			tmp_find = f_next->inx;
		}
		f_next = f_next->next;
	}
}

/*listede en uzun artarak giden listeyi oluşturuyorum. 
2 boyutlu arrayda her bir sayının artarak ne kadar gidebildiğine bakıyorum.*/
void	find_big_a(t_stack	*stack)
{
	t_data	*st;
	t_data	*first_a;
	int		i;
	int		*len;

	len = malloc(sizeof(int) * p_lstsize(stack->a));
	st = stack->a;
	i = 0;
	while (st)
	{
		len[i++] = check_sort_len(stack, st);
		st = st->next;
	}
	first_a = find_start_list(stack, len);
	mark_stack_a(stack, first_a);
	free(len);
}

void	create_sort_stacka(t_stack	*stack)
{
	t_data	*a;
	int		down;
	int		up;
	int		i;
	int		total_size;

	a = stack->a;
	i = 0;
	while (a)
	{
		i++;
		if (a->inx == 1)
			break ;
		a = a->next;
	}
	total_size = p_lstsize(stack->a);
	down = p_lstsize(a);
	up = total_size - down;
	if (up < down)
		while (up--)
			ra(stack, 1);
	else
		while (down--)
			rra(stack, 1);
}

void	start_big_sort(t_stack	*stack)
{
	find_big_a(stack);
	begin_stacka(stack);
	while (p_lstsize(stack->a) != p_lstsize(stack->a_cpy))
	{
		calculation_data(stack);
		start_push(stack);
	}
	create_sort_stacka(stack);
}
