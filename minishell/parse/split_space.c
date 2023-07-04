/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 17:52:09 by mkarakul          #+#    #+#             */
/*   Updated: 2023/06/18 21:21:10 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "parse.h"

int	is_quotation(char *s)
{
	if (*s == '\"')
		return (1);
	else if (*s == '\'')
		return (2);
	return (0);
}

int	type_quotation(char s)
{
	if (s == '\'')
		return (1);
	else if (s == '\"')
		return (2);
	else
		return (0);
}

int	is_space(char s)
{
	if (s == 32)
		return (1);
	return (0);
}

void	split_line2(int st, int len, char *s, t_arg *line)
{
	int	i;

	i = -1;
	while (++i || 1)
	{
		if (is_quotation(&s[i]) == 1 && len++)
			while (!(is_quotation(&s[++i]) == 1) && s[i])
				len++;
		else if (is_quotation(&s[i]) == 2 && len++)
			while (!(is_quotation(&s[++i]) == 2) && s[i])
				len++;
		if (is_space(s[i]) || !s[i])
		{
			if (len != 1)
				p_lstadd_back(&line, p_lstnew(0, ft_substr(s, st, len - 1)));
			st = i + 1;
			len = 0;
		}
		if (!s[i])
			break ;
		len++;
	}
	free(s);
}

void	split_by_space(char *s, t_arg **line)
{
	int		i;
	int		len;
	char	*prompt;
	t_arg	*line_f;

	prompt = NULL;
	i = 0;
	len = 0;
	check_quotation(s);
	check_quotation2(s);
	if (g_data.error_flag == -1)
		return ;
	s = ft_strtrim(s, " ");
	split_line(s, *line);
	line_f = *line;
	*line = (*line)->next;
	free(line_f);
}
