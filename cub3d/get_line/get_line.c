/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozdemi <rbozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:21:21 by rbozdemi          #+#    #+#             */
/*   Updated: 2023/05/16 16:21:22 by rbozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*split_line(int fd, char *arr)
{
	char	*buff;
	int		readed_byte;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	readed_byte = 1;
	while (readed_byte != 0 && !(search_new_line(arr, '\n')))
	{
		readed_byte = read(fd, buff, BUFFER_SIZE);
		if (readed_byte == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[readed_byte] = '\0';
		arr = ft_strjoin2(arr, buff);
	}
	free(buff);
	return (arr);
}

static char	*make_line(char *arr)
{
	char	*a;
	int		i;

	i = 0;
	if (!arr[i])
		return (NULL);
	while (arr[i] != '\n' && arr[i])
		i++;
	a = malloc(sizeof(char) * (i + 2));
	if (!a)
		return (NULL);
	i = 0;
	while (arr[i] != '\n' && arr[i])
	{
		a[i] = arr[i];
		i++;
	}
	if (arr[i] == '\n')
	{
		a[i] = '\n';
		i++;
	}
	a[i] = '\0';
	return (a);
}

static char	*make_arr(char *arr)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	while (arr[i] && arr[i] != '\n')
		i++;
	if (!arr[i])
	{
		free(arr);
		return (NULL);
	}
	s = malloc(sizeof(char) * (ft_strlen2(arr) - i + 1));
	if (!s)
		return (NULL);
	j = 0;
	i++;
	while (arr[i])
		s[j++] = arr[i++];
	s[j] = '\0';
	free(arr);
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*arr;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	arr = split_line(fd, arr);
	if (!arr)
		return (NULL);
	line = make_line(arr);
	arr = make_arr(arr);
	return (line);
}
