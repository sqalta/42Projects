/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 20:24:40 by mkarakul          #+#    #+#             */
/*   Updated: 2023/06/18 21:22:32 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "parse.h"

void	split_line(char *s, t_arg *line)
{
	int	st;
	int	len;
	int	quo;

	st = 0;
	len = 1;
	quo = 0;
	split_line2(st, len, s, line);
}

int	check_quotation2(char *s)
{
	char	handle;
	int		i;
	int		len;

	handle = '\'';
	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == handle)
			len++;
		i++;
	}
	if (len % 2)
	{
		g_data.error_flag = -1;
		return (-1);
	}
	else
		return (len);
}
