/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 20:12:34 by mkarakul          #+#    #+#             */
/*   Updated: 2023/06/17 17:56:24 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	pipe_counter(void)
{
	t_arg	*temp;
	int		i;

	temp = g_data.list;
	i = 0;
	while (temp)
	{
		if (temp->type == PIPE)
			i++;
		temp = temp->next;
	}
	g_data.pipe_c = i;
	if (g_data.pipe_c == 0)
		return (-1);
	return (0);
}

int	initialize_pipe(void)
{
	if (pipe_counter() == -1)
		return (-1);
	create_tubes();
	initialize_fork();
	return (0);
}
