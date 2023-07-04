/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pipe_dollar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 00:50:42 by serif             #+#    #+#             */
/*   Updated: 2023/06/17 17:46:52 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "parse.h"

int	is_pipe(char *s)
{
	if (*s == '|')
		return (1);
	return (0);
}

void	split_by_pipe(t_arg **prompt)
{
	t_arg	*iter;

	iter = *prompt;
	while (iter)
	{
		if (handle_character(&iter, &is_pipe))
			iter = iter->next;
		else
			iter = iter->next;
		if (!iter)
			break ;
		if (!iter->next)
		{
			handle_character(&iter, &is_pipe);
			iter = iter->next;
		}
	}
}
