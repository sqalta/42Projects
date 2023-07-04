/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_counter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:06:55 by mkarakul          #+#    #+#             */
/*   Updated: 2023/06/13 14:07:24 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	env_counter(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
		i++;
	return (i);
}
