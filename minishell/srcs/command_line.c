/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalta <spalta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 19:29:09 by mkarakul          #+#    #+#             */
/*   Updated: 2023/06/09 17:48:44 by spalta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_command_line2(t_arg *temp, int i, int j)
{
	while (temp && temp->type != PIPE)
	{
		if (temp->type == WORD || temp->type == DOLLAR)
			g_data.command[i++] = ft_strdup(temp->arg);
		else if (temp->type == DOUBLE_INPUT_RDR)
			temp = temp->next;
		else if (temp->type == OUTPUT_RDR || temp->type == INPUT_RDR
			|| temp->type == DOUBLE_OUTPUT_RDR)
		{
			g_data.redirection[j++] = ft_strdup(temp->arg);
			g_data.redirection[j++] = ft_strdup(temp->next->arg);
			temp = temp->next;
		}
		temp = temp->next;
	}
	g_data.list = temp;
	if (i > 0)
		g_data.command[i] = NULL;
	if (j > 0)
		g_data.redirection[j] = NULL;
	if (!temp)
		return ;
	if (g_data.list->type == PIPE)
		g_data.list = g_data.list->next;
}

void	ft_command_redirection_len(t_arg *temp, int i, int j)
{
	while (temp && temp->type != PIPE)
	{
		if (temp->type == WORD || temp->type == DOLLAR)
			i++;
		else if (temp->type == DOUBLE_INPUT_RDR)
			temp = temp->next;
		else if (temp->type == OUTPUT_RDR || temp->type == INPUT_RDR
			|| temp->type == DOUBLE_OUTPUT_RDR)
		{
			j += 2;
			temp = temp->next;
		}
		temp = temp->next;
	}
	g_data.list = temp;
	if (i > 0)
		g_data.command = malloc(sizeof(char *) * i + 1);
	if (j > 0)
		g_data.redirection = malloc(sizeof(char *) * j + 1);
	if (!temp)
		return ;
	if (g_data.list->type == PIPE)
		g_data.list = g_data.list->next;
}

void	ft_command_line(void)
{
	t_arg	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	temp = g_data.list;
	ft_command_redirection_len(temp, i, j);
	ft_command_line2(temp, i, j);
}
