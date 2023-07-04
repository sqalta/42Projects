/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 01:40:23 by mustafakara       #+#    #+#             */
/*   Updated: 2023/06/17 21:20:15 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	create_tubes(void)
{
	int	i;

	i = 0;
	g_data.all_pipe_fd = malloc(sizeof(int *) * (g_data.pipe_c));
	if (!g_data.all_pipe_fd)
		return ;
	while (i < g_data.pipe_c)
	{
		g_data.all_pipe_fd[i] = malloc(sizeof(int) * 2);
		pipe(g_data.all_pipe_fd[i]);
		i++;
	}
}

void	close_fd3(int k, int i, int id)
{
	while (++k < g_data.pipe_c)
	{
		while (++i != 2)
		{
			if (!(((i == 0 && k == id - 1)) || (i == 1 && k == id)))
			{
				close(g_data.all_pipe_fd[k][i]);
			}
		}
		i = -1;
	}
}

void	close_fd2(int k, int i)
{
	while (++k < g_data.pipe_c)
	{
		while (++i != 2)
		{
			if (!(i == 0 && (k == g_data.pipe_c - 1)))
			{
				close(g_data.all_pipe_fd[k][i]);
			}
		}
		i = -1;
	}
}

void	close_fd(int id)
{
	int	i;
	int	k;

	k = -1;
	i = -1;
	if (id == 0)
	{
		while (++k < g_data.pipe_c)
		{
			while (++i != 2)
				if (!(i == 1 && k == 0))
					close(g_data.all_pipe_fd[k][i]);
			i = -1;
		}
	}
	else if (id == g_data.pipe_c)
		close_fd2(k, i);
	else
		close_fd3(k, i, id);
}

void	ft_free_command_redirection(void)
{
	int	i;

	i = -1;
	while (g_data.command[++i])
		free(g_data.command[i]);
	free(g_data.command);
	i = -1;
	if (g_data.redirection)
	{
		while (g_data.redirection[++i])
			free(g_data.redirection[i]);
		free(g_data.redirection);
	}
	g_data.command = NULL;
	g_data.redirection = NULL;
}
