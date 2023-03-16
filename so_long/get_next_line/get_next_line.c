/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyumak <muyumak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 00:25:07 by muyumak           #+#    #+#             */
/*   Updated: 2023/01/29 02:25:56 by muyumak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *filetext)
{
	char	*buff;
	int		rd_byte;

	rd_byte = 1;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (0);
	while (!ft_strchr_gnl(filetext) && rd_byte != 0)
	{
		rd_byte = read(fd, buff, BUFFER_SIZE);
		if (rd_byte == -1)
		{
			free(buff);
			return (0);
		}
		buff[rd_byte] = 0;
		filetext = ft_strjoin_gnl(filetext, buff);
	}
	free(buff);
	return (filetext);
}

char	*get_next_line(int fd)
{
	static char	*filetext;
	char		*line;

	if (fd < 0 && BUFFER_SIZE <= 0)
		return (0);
	filetext = ft_read(fd, filetext);
	if (!filetext)
		return (0);
	line = ft_get_line(filetext);
	filetext = ft_get_next_filetext(filetext);
	return (line);
}
