/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cntrl_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalta <spalta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:05:10 by spalta            #+#    #+#             */
/*   Updated: 2023/03/14 18:31:23 by spalta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_list	*create_a(char **st, int ac)
{
	char	**buff;
	t_list	*ret;
	t_list	*tmp;
	int		i;
	int		j;

	j = -1;
	i = 1;
	ret = NULL;
	buff = ft_split(st[i], ' ');
	while (i < ac)
	{
		j = -1;
		while (buff[++j])
		{
			tmp = ft_lstnew(buff[j]);
			ft_lstadd_back(&ret, tmp);
		}
		i++;
		free(buff);
		buff = ft_split(st[i], ' ');
	}
	return (ret);
}

int	ct_integer(char *str)
{
	int	i;

	i = 0;
	if (!(str[i] == '-' || str[i] == '+'
			|| (str[i] >= '0' && str[i] <= '9')))
		return (0);
	if ((str[i] == '-' || str[i] == '+') && !(str[++i]))
		return (0);
	i--;
	while (str[++i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
	}
	return (1);
}

t_data	*convert_int(t_list *stack)
{
	t_data	*stack_a;
	t_data	*tmp;
	t_list	*tmp1;

	stack_a = NULL;
	tmp1 = stack;
	while (stack)
	{
		tmp = p_lstnew(p_atoi(stack->content), -1);
		p_lstadd_back(&stack_a, tmp);
		stack = stack->next;
	}
	return (stack_a);
}

void	is_sort(t_data	*stack_a, int flag)
{
	int		book;
	t_data	*tmp;
	t_data	*tmp1;

	tmp = stack_a;
	if (!tmp)
		exit (1);
	tmp1 = stack_a->next;
	while (tmp->next)
	{
		book = tmp->nbr;
		while (tmp1)
		{
			if (book > tmp1->nbr)
				flag = 1;
			if (book == tmp1->nbr)
				print_error(4);
			tmp1 = tmp1->next;
		}
		tmp = tmp->next;
		tmp1 = tmp->next;
	}
	if (!flag)
		print_error(3);
}

int	ct_av(int ac, char **str, t_stack *p_stack)
{
	t_list	*t_stack;
	t_list	*tmp;
	t_data	*stack_a;

	t_stack = create_a(str, ac);
	tmp = t_stack;
	while (tmp)
	{
		if (!(ct_integer(tmp->content)))
			print_error(155);
		tmp = tmp->next;
	}
	stack_a = convert_int(t_stack);
	ft_lstclear(&t_stack, free);
	is_sort(stack_a, 0);
	p_stack->a = stack_a;
	return (1);
}
