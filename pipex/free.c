/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyumak <muyumak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 01:13:14 by muyumak           #+#    #+#             */
/*   Updated: 2023/01/11 01:14:28 by muyumak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_free(t_pipex pipex)
{
	int	i;

	i = 0;
	while (pipex.cmd_args[i])
	{
		free(pipex.cmd_args[i]);
		i++;
	}
	free(pipex.cmd_args);
	free(pipex.cmd);
}

void	parent_free(t_pipex pipex)
{
	int	i;

	i = 0;
	close(pipex.fd_infile);
	close(pipex.fd_outfile);
	while (pipex.cmd_paths[i])
	{
		free(pipex.cmd_paths[i]);
		i++;
	}
	free(pipex.cmd_paths);
}
