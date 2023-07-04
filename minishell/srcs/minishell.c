/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:59:02 by mkarakul          #+#    #+#             */
/*   Updated: 2023/06/18 20:37:37 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_data	g_data;

void	exec_shell(int status)
{
	if (status == 0)
		ft_execve();
	else
		perror("minishell");
}

void	ft_struct_initilaize(char **envp, int flag)
{
	if (flag)
	{
		g_data.ex_path = create_cpy_env(envp);
		g_data.envp = create_cpy_env(envp);
	}
	g_data.signal_status = 0;
	g_data.list = NULL;
	g_data.command = NULL;
	g_data.redirection = NULL;
	g_data.count_type = NULL;
	g_data.heredoc = NULL;
	g_data.line = NULL;
	g_data.sig_flag = 0;
	g_data.error_flag = 0;
	g_data.here_fd = 0;
}

int	start2(t_arg *temp)
{
	if (error_check() == -1)
	{
		temp = NULL;
		return (-1);
	}
	if (g_data.count_type->dollar > 0)
		ft_dollars_line();
	if (g_data.count_type->heredoc > 0)
		ft_heredoc_line();
	if (ft_strcmp(g_data.list->arg, "exit"))
	{
		ft_exit(temp);
		return (-1);
	}
	if (initialize_pipe() == -1)
		execute();
	return (0);
}

void	start(void)
{
	t_arg	*cpy_g_data_list;
	int		flag;

	flag = 0;
	while (1)
	{
		ft_struct_initilaize(g_data.envp, 0);
		g_data.line = readline("minishell-$ ");
		if (g_data.sig_flag == 1)
		{
			free(g_data.line);
			continue ;
		}
		if (!g_data.line)
			signal_exit();
		ft_parse();
		cpy_g_data_list = g_data.list;
		add_history(g_data.line);
		free(g_data.line);
		start2(cpy_g_data_list);
		freeliazer(cpy_g_data_list);
	}
}

int	main(int ac, char **av, char **envp)
{
	if (ac > 1)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(av[1], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		exit(127);
	}
	av = NULL;
	signal(SIGINT, ft_sig_handler);
	signal(SIGQUIT, SIG_IGN);
	g_data.exit_status = 1;
	ft_struct_initilaize(envp, 1);
	start();
	return (0);
}
