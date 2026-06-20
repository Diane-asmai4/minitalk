/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malrandr <malrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:02:47 by malrandr          #+#    #+#             */
/*   Updated: 2025/04/25 15:16:56 by malrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putf(const char format, va_list args)
{
	int	count;

	count = 0;
	if (format == 'c')
		count = (ft_putcharf(va_arg(args, int)));
	else if (format == 's')
		count = (ft_putstrf(va_arg(args, char *)));
	else if (format == 'p')
		count = (ft_putadrf(va_arg(args, void *)));
	else if (format == 'd' || format == 'i')
		count = (ft_putnbrf(va_arg(args, int)));
	else if (format == 'u')
		count = (ft_putunbrf(va_arg(args, unsigned int)));
	else if (format == 'x')
		count = (ft_puthexf(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (format == 'X')
		count = (ft_puthexf(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (format == '%')
		count = (ft_putcharf('%'));
	return (count);
}
