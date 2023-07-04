/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quot_cleaner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 21:33:51 by mkarakul          #+#    #+#             */
/*   Updated: 2023/06/17 21:34:16 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "parse.h"

void	quot_cleaner(t_arg **prompt)
{
	t_arg	*iter;
	char	*s;

	iter = *prompt;
	while (iter)
	{
		if (contains_quot(iter->arg))
		{
			if (iter->type != DOLLAR)
			{
				s = iter->arg;
				iter->arg = trim_quot(iter->arg);
				free(s);
			}
		}
		iter = iter->next;
	}
}
