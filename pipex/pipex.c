/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyumak <muyumak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 00:53:46 by muyumak           #+#    #+#             */
/*   Updated: 2023/01/11 02:18:57 by muyumak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

void	close_pipe(t_pipex pipex)
{
	close(pipex.tube[0]);
	close(pipex.tube[1]);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		return (error_return(ERR_INPUT));
	pipex.fd_infile = open(argv[1], O_RDONLY);
	pipex.fd_outfile = open(argv[4], O_CREAT | O_TRUNC | O_RDWR, 0777);
	if (pipex.fd_outfile < 0)
		error(ERR_INFILE);
	if (pipex.fd_infile < 0)
		error(ERR_OUTFILE);
	if (pipe(pipex.tube) < 0)
		error(ERR_PIPE);
	pipex.paths = find_path(envp);
	pipex.cmd_paths = ft_split(pipex.paths, ':');
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
		first_child_process(pipex, argv, envp);
	pipex.pid2 = fork();
	if (pipex.pid2 == 0)
		second_child_process(pipex, argv, envp);
	close_pipe(pipex);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
	parent_free(pipex);
	return (0);
}
