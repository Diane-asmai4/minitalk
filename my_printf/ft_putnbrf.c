/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malrandr <malrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:44:07 by malrandr          #+#    #+#             */
/*   Updated: 2025/04/25 15:17:00 by malrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbrf(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (ft_putstrf("-2147483648"));
	if (n < 0)
	{
		count += ft_putcharf('-');
		n = -n;
	}
	if (n < 10)
		count += ft_putcharf(n + '0');
	else
	{
		count += ft_putnbrf(n / 10);
		count += ft_putcharf((n % 10) + '0');
	}
	return (count);
}
