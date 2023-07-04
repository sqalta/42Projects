/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dollars_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 17:46:34 by mustafakara       #+#    #+#             */
/*   Updated: 2023/06/18 20:17:02 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*ft_parse_dollars2(char **line, char *src)
{
	int		i;
	char	*temp;

	i = 0;
	while (line[i])
	{
		if (i == 0)
			src = ft_strdup(line[i]);
		else
		{
			temp = src;
			src = ft_strjoin(src, line[i]);
			free(temp);
		}
		free(line[i]);
		i++;
	}
	free(line);
	return (src);
}

int	special_parse(void)
{
	if (g_data.list->arg[1] == '?')
	{
		free(g_data.list->arg);
		g_data.list->arg = ft_itoa(g_data.exit_status);
		return (0);
	}
	else if (g_data.list->arg[1] == '0')
	{
		free(g_data.list->arg);
		g_data.list->arg = ft_strdup("minishell");
		return (0);
	}
	return (-1);
}

void	ft_parse_dollars(void)
{
	char	*src;
	char	**line;
	int		i;

	i = 0;
	src = g_data.list->arg;
	line = ft_split(src, '$');
	free(src);
	while (line[i])
	{
		line[i] = ft_find_env(line[i]);
		i++;
	}
	src = ft_parse_dollars2(line, src);
	g_data.list->arg = src;
}

void	dollar_prs(char *str)
{
	int	len;
	int	i;
	int	j;

	i = 0;
	j = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (str[i] != '"' && str[i] != '\'')
		{
			str[j] = str[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
}

void	ft_dollars_line(void)
{
	t_arg	*temp_s;
	int		flag;

	temp_s = g_data.list;
	while (g_data.list)
	{
		if (g_data.list->type == DOLLAR)
		{
			flag = quot_parse(g_data.list->arg);
			dollar_prs(g_data.list->arg);
			g_data.list->type = WORD;
			if (flag != -1)
			{
				if (special_parse() == -1)
					ft_parse_dollars();
			}
		}
		g_data.list = g_data.list->next;
	}
	g_data.list = temp_s;
}
