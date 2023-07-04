/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:04:33 by mkarakul          #+#    #+#             */
/*   Updated: 2023/06/11 15:21:15 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_oldpwd_changer(void)
{
	char	*str;
	int		i;

	i = 0;
	while (g_data.envp[i])
	{
		if (ft_strncmp(g_data.envp[i], "OLDPWD=", 7) == 0)
		{
			free(g_data.envp[i]);
			str = getcwd(NULL, 0);
			g_data.envp[i] = ft_strjoin("OLDPWD=", str);
			free(str);
			break ;
		}
		i++;
	}
}

void	ft_pwd_changer(void)
{
	char	*str;
	int		i;

	i = 0;
	str = getcwd(NULL, 0);
	while (g_data.envp[i])
	{
		if (ft_strncmp(g_data.envp[i], "PWD=", 4) == 0)
		{
			free(g_data.envp[i]);
			g_data.envp[i] = ft_strjoin("PWD=", str);
			free(str);
			break ;
		}
		i++;
	}
}

void	ft_cd(void)
{
	ft_oldpwd_changer();
	if (g_data.command[1] && ft_strcmp(g_data.command[1], "~") == 0)
	{
		if (chdir(g_data.command[1]))
			perror("minishell ");
	}
	else if (chdir(getenv("HOME")))
		perror("minishell ");
	ft_pwd_changer();
}
