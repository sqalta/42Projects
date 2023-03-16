/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozdemi <rbozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:56:39 by rbozdemi          #+#    #+#             */
/*   Updated: 2023/01/11 18:20:40 by rbozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	binary_to_print(int sig)
{
	static int	i;
	static char	c;

	c = c << 1;
	if (sig == SIGUSR1)
		c |= 1;
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	ft_printf("PID: %d\n", getpid());
	signal(SIGUSR1, binary_to_print);
	signal(SIGUSR2, binary_to_print);
	while (1)
		pause();
}
