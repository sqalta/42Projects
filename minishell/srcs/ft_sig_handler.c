/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sig_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 18:30:37 by mkarakul          #+#    #+#             */
/*   Updated: 2023/06/17 17:52:21 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_sig_handler(int sig)
{
	if (sig == SIGINT)
	{
		(void)sig;
		g_data.signal_status = -1;
		g_data.exit_status = 1;
		g_data.sig_flag = 1;
		write(1, "\033[A", 3);
		ioctl(STDIN_FILENO, TIOCSTI, "\n");
	}
}
