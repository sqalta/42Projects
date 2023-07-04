/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:13:45 by spalta            #+#    #+#             */
/*   Updated: 2023/06/17 17:58:56 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "../minishell.h"

t_arg	*p_lstlast(t_arg *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	p_lstadd_back(t_arg **lst, t_arg *new)
{
	t_arg	*list;

	list = p_lstlast((*lst));
	if (!list)
		*lst = new;
	else
		list->next = new;
}

void	p_lstadd_front(t_arg **lst, t_arg *new)
{
	new->next = *lst;
	*lst = new;
}

t_arg	*p_lstnew(int type, char *s)
{
	t_arg	*node;

	node = malloc (sizeof(t_arg));
	if (!node)
	{
		free(s);
		free(node);
		return (0);
	}
	node->arg = ft_strdup(s);
	node->type = type;
	node->next = NULL;
	free(s);
	return (node);
}

int	p_lstsize(t_arg *lst)
{
	int	i;

	i = 1;
	while (lst->next)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
