/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:27:53 by mkarakul          #+#    #+#             */
/*   Updated: 2023/06/18 20:39:22 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	env_founder(char *envp, char *name, int len)
{
	int	i;

	i = 0;
	while (envp[i] == name[i] && i < len)
		i++;
	if (envp[i] == '=' || envp[i] == '\0')
		return (1);
	else
		return (0);
}

int	ft_path_counter(char *name)
{
	int	i;

	i = 0;
	while (name[i])
	{
		if (name[i] == '=')
			return (i);
		i++;
	}
	return (i);
}

int	ft_path_founder(char **envp, char *name)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (env_founder(envp[i], name, ft_path_counter(name)) == 1)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_unset(void)
{
	int	i;
	int	j;
	int	l;

	j = 1;
	if (g_data.command[j] == NULL)
		return ;
	while (g_data.command[j])
	{
		i = ft_path_founder(g_data.envp, g_data.command[j]);
		l = ft_path_founder(g_data.ex_path, g_data.command[j]);
		if (i != -1)
			ft_delenv(g_data.envp, i, 0);
		if (l != -1)
			ft_delenv(g_data.ex_path, l, 1);
		j++;
	}
}
