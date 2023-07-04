/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quot_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 20:12:49 by mkarakul          #+#    #+#             */
/*   Updated: 2023/06/18 20:20:03 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	quot_parse(char *str)
{
	int	i;
	int	c_q;
	int	t_q;

	i = 0;
	c_q = 0;
	t_q = 0;
	while (str[i])
	{
		if (str[i] == 34)
			c_q++;
		else if (str[i] == 39)
			t_q++;
		i++;
	}
	if (t_q == 2)
		return (-1);
	else if (c_q == 2)
		return (0);
	else
		return (0);
}
