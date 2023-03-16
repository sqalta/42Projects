/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozdemi <rbozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:56:42 by rbozdemi          #+#    #+#             */
/*   Updated: 2023/01/11 18:25:05 by rbozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	string_to_binary(pid_t pid, char *s)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = 8;
		while (j--)
		{
			if ((s[i] >> j) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
		return (0);
	pid = ft_atoi(argv[1]);
	string_to_binary(pid, argv[2]);
	return (0);
}
