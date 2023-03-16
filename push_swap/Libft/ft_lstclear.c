/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalta <spalta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 19:34:16 by spalta            #+#    #+#             */
/*   Updated: 2022/12/19 19:39:01 by spalta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*flag;

	if (!lst || !del)
		return ;
	while (*lst != NULL)
	{
		flag = (*lst)->next;
		ft_lstdelone(*lst, del);
		(*lst) = flag;
	}
	free(*lst);
}
