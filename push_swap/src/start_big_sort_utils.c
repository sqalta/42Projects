/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_big_sort_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalta <spalta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 05:06:30 by spalta            #+#    #+#             */
/*   Updated: 2023/03/13 06:58:02 by spalta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	begin_stacka(t_stack *stack)
{
	int	len;
	int	i;

	len = p_lstsize(stack->a);
	i = 0;
	while (i < len)
	{
		if (stack->a->push_flag == 1)
			ra(stack, 1);
		else
			pb(stack);
		i++;
	}
}

int	check_sort_len_2(t_stack *m_stack, t_data *find, t_data *f_next, int len)
{
	int		tmp_find;

	tmp_find = find->inx;
	while (f_next)
	{
		if (tmp_find < f_next->inx)
		{
			len++;
			tmp_find = f_next->inx;
		}
		f_next = f_next->next;
	}
	f_next = m_stack->a;
	while (f_next->inx != find->inx)
	{
		if (tmp_find < f_next->inx)
		{
			len++;
			tmp_find = f_next->inx;
		}
		f_next = f_next->next;
	}
	return (len);
}

int	check_sort_len(t_stack	*m_stack, t_data *find)
{
	t_data	*f_next;
	int		len;

	f_next = NULL;
	if (!find->next)
		return (0);
	else
		f_next = find->next;
	len = check_sort_len_2(m_stack, find, f_next, 0);
	return (len);
}

t_data	*find_start_list(t_stack	*stack, int	*len)
{
	t_data	*a;
	int		i;
	int		big;

	a = stack->a;
	i = -1;
	big = 0;
	while (++i < p_lstsize(stack->a))
		if (len[i] > big)
			big = len[i];
	i = -1;
	while (++i < p_lstsize(stack->a))
		if (len[i] == big)
			break ;
	big = 0;
	while (i > 0)
	{
		i--;
		a = a->next;
	}
	return (a);
}
