/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyumak <muyumak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 00:25:25 by muyumak           #+#    #+#             */
/*   Updated: 2023/01/31 03:26:24 by muyumak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr_gnl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return ((str + i));
		i++;
	}
	return (0);
}

size_t	ft_strlen_gnl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *str, char *buff)
{
	char	*strlink;
	int		i;
	int		j;

	if (!str)
	{
		str = malloc(1);
		str[0] = 0;
	}
	if (!str || !buff)
		return (0);
	strlink = malloc(sizeof(char) * (ft_strlen_gnl(str)
				+ ft_strlen_gnl(buff) + 1));
	if (!strlink)
		return (0);
	i = -1;
	if (str)
		while (str[++i])
			strlink[i] = str[i];
	j = 0;
	while (buff[j])
		strlink[i++] = buff[j++];
	strlink[ft_strlen_gnl(str) + ft_strlen_gnl(buff)] = 0;
	free(str);
	return (strlink);
}

char	*ft_get_line(char *filetext)
{
	char	*line;
	int		i;

	i = 0;
	if (!filetext[i])
		return (0);
	while (filetext[i] && filetext[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (0);
	i = 0;
	while (filetext[i] && filetext[i] != '\n')
	{
		line[i] = filetext[i];
		i++;
	}
	if (filetext[i] == '\n')
	{
		line[i] = filetext[i];
		i++;
	}
	line[i] = 0;
	return (line);
}

char	*ft_get_next_filetext(char *filetext)
{
	char	*newtext;
	int		i;
	int		j;

	i = 0;
	while (filetext[i] && filetext[i] != '\n')
		i++;
	if (!filetext[i])
	{
		free(filetext);
		return (0);
	}
	newtext = malloc(ft_strlen_gnl(filetext) - i + 1);
	if (!newtext)
		return (0);
	i++;
	j = 0;
	while (filetext[i])
	{
		newtext[j++] = filetext[i++];
	}
	newtext[j] = 0;
	free(filetext);
	return (newtext);
}
