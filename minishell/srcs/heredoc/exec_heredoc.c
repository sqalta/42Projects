/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:58:02 by mkarakul          #+#    #+#             */
/*   Updated: 2023/06/18 19:04:27 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_heredoc_start(int i)
{
	while (1)
	{
		g_data.here_line = readline("> ");
		if (ft_strcmp(g_data.here_line, g_data.heredoc[i]))
			break ;
		else
		{
			if (g_data.count_type->heredoc == (((i - 1) / 2) + 1))
			{
				ft_putstr_fd(g_data.here_line, g_data.here_fd[1]);
				ft_putstr_fd("\n", g_data.here_fd[1]);
				g_data.main_here_size += ft_strlen(g_data.here_line);
			}
			free(g_data.here_line);
		}
	}
	close(g_data.here_fd[1]);
}

void	ft_heredoc(void)
{
	int	i;
	int	status;

	i = 0;
	while (i == 0 || g_data.heredoc[i])
	{
		status = fork();
		if (status == 0)
		{
			close(g_data.here_fd[0]);
			ft_heredoc_start(i + 1);
			exit(0);
		}
		else
			waitpid(status, &g_data.exit_status, 0);
		i += 2;
	}
	close(g_data.here_fd[1]);
}

void	init_pipe(void)
{
	g_data.here_fd = malloc(sizeof(int) * 2);
	pipe(g_data.here_fd);
}

void	ft_heredoc_line(void)
{
	t_arg	*temp;
	int		i;

	temp = g_data.list;
	init_pipe();
	if (g_data.count_type->heredoc > 0)
		g_data.heredoc = malloc(sizeof(char *)
				* (g_data.count_type->heredoc * 2 + 1));
	i = 0;
	while (temp)
	{
		if (temp->type == DOUBLE_INPUT_RDR && temp->next)
		{
			g_data.heredoc[i++] = ft_strdup(temp->arg);
			g_data.heredoc[i++] = ft_strdup(temp->next->arg);
		}
		temp = temp->next;
	}
	g_data.heredoc[i] = NULL;
	if (i > 0)
	{
		ft_heredoc();
	}
	else
		return ;
}
