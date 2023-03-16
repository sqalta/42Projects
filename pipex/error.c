/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyumak <muyumak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 01:01:09 by muyumak           #+#    #+#             */
/*   Updated: 2023/01/11 01:14:12 by muyumak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(char *err)
{
	perror(err);
	exit(1);
}

int	error_return(char *err)
{
	write(2, &err, sizeof(err));
	return (1);
}
