/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:09:02 by mkarakul          #+#    #+#             */
/*   Updated: 2023/06/18 20:47:20 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_addenv(char **envp, int j, int flag)
{
	int		i;
	char	*force;
	char	**new_envp;

	i = 0;
	force = ft_strdup(g_data.command[j]);
	new_envp = (char **)malloc(sizeof(char *) * (env_counter(envp) + 2));
	while (envp[i])
	{
		new_envp[i] = ft_strdup(envp[i]);
		free(envp[i]);
		i++;
	}
	new_envp[i] = force;
	new_envp[i + 1] = NULL;
	if (!flag)
		g_data.envp = new_envp;
	else
		g_data.ex_path = new_envp;
	free(envp);
}
