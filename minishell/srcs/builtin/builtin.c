/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:34:03 by mkarakul          #+#    #+#             */
/*   Updated: 2023/06/17 17:19:15 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	builtin(void)
{
	if (g_data.command == NULL)
		return (-1);
	if (ft_strcmp(g_data.command[0], "cd"))
		ft_cd();
	else if (ft_strcmp(g_data.command[0], "pwd"))
		ft_pwd();
	else if (ft_strcmp(g_data.command[0], "export") && g_data.command[1])
		ft_export();
	else if (ft_strcmp(g_data.command[0], "unset"))
		ft_unset();
	else if (ft_strcmp(g_data.command[0], "env"))
		ft_env();
	else
		return (-1);
	return (0);
}
