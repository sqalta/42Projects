/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resulbozdemir <resulbozdemir@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:39:15 by resulbozdem       #+#    #+#             */
/*   Updated: 2022/10/27 18:47:31 by resulbozdem      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	s_control(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	else
		i = ft_putstr_fd(str, 1);
	return (i);
}

static int	ft_check(va_list arg, const char c)
{
	int	i;

	i = 0;
	if (c == 'c')
		i += ft_putchar_fd(va_arg(arg, int), 1);
	else if (c == 's')
		i += s_control(va_arg(arg, char *));
	else if (c == 'p')
	{
		ft_putstr_fd("0x", 1);
		i += ft_pointer(va_arg(arg, unsigned long)) + 2;
	}
	else if (c == 'd' || c == 'i')
		i += ft_putnbr_fd(va_arg(arg, int), 1);
	else if (c == 'u')
		i += ft_putunint(va_arg(arg, unsigned int));
	else if (c == 'x')
		ft_x(va_arg(arg, unsigned int), &i, "0123456789abcdef");
	else if (c == 'X')
		ft_x(va_arg(arg, unsigned int), &i, "0123456789ABCDEF");
	else if (c == '%')
		i += ft_putchar_fd('%', 1);
	return (i);
}

int	ft_printf(const char *s, ...)
{
	va_list	arg;
	int		i;
	int		len;

	va_start(arg, s);
	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == '%' && s[i])
		{
			i++;
			len += ft_check(arg, s[i]);
		}
		else
			len += ft_putchar_fd(s[i], 1);
		i++;
	}
	va_end(arg);
	return (len);
}
