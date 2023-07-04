/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upenv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:14:02 by mkarakul          #+#    #+#             */
/*   Updated: 2023/06/14 16:57:10 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	equal_counter(char *name)
{
	int	i;

	i = 0;
	while (name[i])
	{
		if (name[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

void	upenv(char **envp, int j, int flag)
{
	int		i;
	int		l;
	char	*force;

	i = 0;
	if (equal_counter(g_data.command[j]) == 0)
		return ;
	force = ft_strdup(g_data.command[j]);
	l = ft_path_founder(envp, g_data.command[j]);
	if (l != -1)
	{
		free(envp[l]);
		if (!flag)
			g_data.envp[l] = force;
		else
			g_data.ex_path[l] = force;
	}
	else
		return ;
}
