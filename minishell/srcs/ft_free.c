/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 19:12:24 by mkarakul          #+#    #+#             */
/*   Updated: 2023/06/18 19:02:54 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_free_all2(void)
{
	int	i;

	i = 0;
	if (g_data.redirection)
	{
		while (g_data.redirection[i])
			free(g_data.redirection[i++]);
		free(g_data.redirection);
	}
	if (g_data.count_type)
		free(g_data.count_type);
	i = 0;
	if (g_data.heredoc)
	{
		while (g_data.heredoc[i])
			free(g_data.heredoc[i++]);
		free(g_data.heredoc);
	}
}

void	ft_free_all(void)
{
	int	i;

	ft_free_all2();
	i = 0;
	if (g_data.command)
	{
		while (g_data.command[i])
			free(g_data.command[i++]);
		free(g_data.command);
	}
}

void	freeliazer(t_arg *temp)
{
	t_arg	*tmp;

	tmp = NULL;
	ft_free_all();
	if (g_data.here_fd)
	{
		free(g_data.here_fd);
	}
	if (temp)
	{
		while (temp)
		{
			tmp = temp;
			free(tmp->arg);
			temp = temp->next;
			free(tmp);
		}
	}
}
