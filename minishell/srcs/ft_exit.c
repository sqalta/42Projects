/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 03:53:07 by mkarakul          #+#    #+#             */
/*   Updated: 2023/06/18 19:01:24 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	signal_exit(void)
{
	write(1, "\033[2D", 4);
	write(1, "\033[0mexit\n", 9);
	exit(0);
}

int	ft_check_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			break ;
	}
	if (str[i] == '\0')
		return (0);
	else
		return (-1);
}

void	ft_exit2(t_arg *temp)
{
	if (ft_check_digit(temp->next->arg) == 0 && temp->next->next == NULL)
	{
		ft_putstr_fd("exit\n", 1);
		exit(ft_atoi(temp->next->arg));
	}
	else if (ft_check_digit(temp->next->arg) == -1)
	{
		printf("minishell: exit: %s: numeric argument required\n",
			temp->next->arg);
		exit(255);
	}
}

void	ft_exit(t_arg *data)
{
	t_arg	*temp;

	temp = data;
	if (temp->next == NULL)
	{
		ft_putstr_fd("exit\n", 1);
		exit(0);
	}
	else if (temp->next != NULL && temp->next->next == NULL)
	{
		ft_exit2(temp);
	}
	else
	{
		ft_putstr_fd("exit\n", 1);
		printf("minishell: exit: too many arguments\n");
		g_data.exit_status = 1;
	}
}
