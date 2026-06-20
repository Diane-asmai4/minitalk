/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malrandr <malrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:25:15 by malrandr          #+#    #+#             */
/*   Updated: 2025/04/28 18:49:39 by malrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_valid_arg(int c)
{
	if (c == 'c' || c == 'd' || c == 'u' || c == 'p' || c == 'i'
		|| c == 's' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, format);
	if (!format)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%' && ft_valid_arg(format[i + 1]))
		{
			count += ft_putf(format[i + 1], args);
			i++;
		}
		else if (format[i] == '%' && !(ft_valid_arg(format[i + 1])))
			i++;
		else
			count += ft_putcharf(format[i]);
		if (format[i])
			i++;
	}
	va_end(args);
	return (count);
}
