/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalta <spalta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:47:01 by spalta            #+#    #+#             */
/*   Updated: 2022/12/27 14:11:02 by spalta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check(va_list *list, char a, int *result)
{
	if (a == 'c')
		ft_putchar(va_arg(*list, int), result);
	else if (a == '%')
		ft_putchar('%', result);
	else if (a == 's')
		ft_putstr(va_arg(*list, char *), result);
	else if (a == 'd' || a == 'i')
		ft_putnbr(va_arg(*list, int), result);
	else if (a == 'x')
		ft_hexa(va_arg(*list, unsigned int), "0123456789abcdef", result);
	else if (a == 'X')
		ft_hexa(va_arg(*list, unsigned int), "0123456789ABCDEF", result);
	else if (a == 'u')
		ft_unsigned(va_arg(*list, unsigned int), result);
	else if (a == 'p')
	{
		ft_putstr("0x", result);
		ft_pointer(va_arg(*list, unsigned long long), result);
	}
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		result;
	va_list	list;

	result = 0;
	i = 0;
	va_start(list, s);
	while (s[i] && s)
	{
		if (s[i] == '%')
			ft_check(&list, s[++i], &result);
		else
			ft_putchar(s[i], &result);
		i++;
	}
	va_end (list);
	return (result);
}
