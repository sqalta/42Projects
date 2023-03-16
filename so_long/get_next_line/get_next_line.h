/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyumak <muyumak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 00:25:34 by muyumak           #+#    #+#             */
/*   Updated: 2023/01/29 01:08:02 by muyumak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

char	*ft_strchr_gnl(char *str);
char	*ft_strjoin_gnl(char *str, char *buff);
char	*ft_get_line(char *filetext);
char	*ft_get_next_filetext(char *filetext);
char	*get_next_line(int fd);
char	*ft_read(int fd, char *filetext);
size_t	ft_strlen_gnl(char *str);

#endif