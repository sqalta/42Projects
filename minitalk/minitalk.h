/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozdemi <rbozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:58:31 by rbozdemi          #+#    #+#             */
/*   Updated: 2023/01/11 18:22:50 by rbozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "ft_printf/ft_printf.h"
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_atoi(const char *str);
void	string_to_binary(pid_t pid, char *s);
void	binary_to_print(int sig);

#endif