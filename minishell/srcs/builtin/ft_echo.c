/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:04:59 by mkarakul          #+#    #+#             */
/*   Updated: 2023/06/17 17:19:19 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_echo_param_checker(char *str)
{
	int	i;

	i = 2;
	if (!str[0] || str[0] != '-')
		return (0);
	if (!str[1] || str[1] != 'n')
		return (0);
	while (str[i])
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

void	ft_echo(void)
{
	int	i;

	i = 1;
	if (g_data.command[i] == NULL)
	{
		ft_putstr_fd("\n", 1);
		return ;
	}
	while (ft_echo_param_checker(g_data.command[i]) == 1)
		i++;
	while (g_data.command[i])
	{
		ft_putstr_fd(g_data.command[i], 1);
		if (g_data.command[i + 1] != NULL)
			ft_putstr_fd(" ", 1);
		i++;
	}
	if (ft_echo_param_checker(g_data.command[1]) == 0)
		ft_putstr_fd("\n", 1);
}
