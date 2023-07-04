/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:16:00 by mkarakul          #+#    #+#             */
/*   Updated: 2023/06/17 18:32:26 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	name_error(int j)
{
	int	i;

	i = 0;
	if (g_data.command[j][0] == '=')
		return (-1);
	if (ft_isdigit(g_data.command[j][i]) == 1)
		return (-1);
	while (g_data.command[j][i])
	{
		if (g_data.command[j][i] == '=')
			return (0);
		if (ft_isalnum(g_data.command[j][i]) == 0
			&& g_data.command[j][i] != '_')
			return (-1);
		i++;
	}
	return (0);
}

void	*ft_export_path(void)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (g_data.ex_path[i])
	{
		j = 0;
		while (g_data.ex_path[i][j])
			j++;
		tmp = ft_substr(g_data.ex_path[i], 0, j);
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(tmp, 1);
		ft_putstr_fd("\n", 1);
		free(tmp);
		i++;
	}
	return (NULL);
}

int	ft_env_controller(int j)
{
	int	i;

	i = 0;
	while (g_data.command[j][i] != '\0')
	{
		if (g_data.command[j][i] == '=')
			return (1);
		i++;
	}
	return (0);
}

void	ft_export2(int line, int line_exp, int j)
{
	while (g_data.command[j])
	{
		if (name_error(j) == -1)
		{
			printf("minishell: export: %s : not a valid identifier\n",
				g_data.command[j++]);
			continue ;
		}
		line = ft_path_founder(g_data.envp, g_data.command[j]);
		line_exp = ft_path_founder(g_data.ex_path, g_data.command[j]);
		if (line != -1)
			upenv(g_data.envp, j, 0);
		if (line_exp != -1)
			upenv(g_data.ex_path, j, 1);
		if (line == -1 && ft_env_controller(j))
			ft_addenv(g_data.envp, j, 0);
		if (line_exp == -1)
			ft_addenv(g_data.ex_path, j, 1);
		j++;
	}
}

void	ft_export(void)
{
	int	j;
	int	line;
	int	line_exp;

	line = 0;
	line_exp = 0;
	j = 1;
	ft_export2(line, line_exp, j);
}
