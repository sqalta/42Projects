/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:35:20 by mkarakul          #+#    #+#             */
/*   Updated: 2023/06/17 16:56:48 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_pwd(void)
{
	char	*path;

	path = getcwd(NULL, 0);
	ft_putstr_fd(path, 1);
	ft_putstr_fd("\n", 1);
	free(path);
}

void	ft_env(void)
{
	int	i;

	i = 0;
	while (g_data.envp[i])
	{
		ft_putstr_fd(g_data.envp[i], 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
}

char	**create_cpy_env(char **envp)
{
	int		i;
	char	**cpy_env;

	i = 0;
	while (envp[i])
		i++;
	cpy_env = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (envp[i])
	{
		cpy_env[i] = ft_strdup(envp[i]);
		i++;
	}
	cpy_env[i] = NULL;
	return (cpy_env);
}
