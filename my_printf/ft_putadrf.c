/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadrf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malrandr <malrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:43:10 by malrandr          #+#    #+#             */
/*   Updated: 2025/04/25 15:16:53 by malrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexptr(unsigned long ad, char *base)
{
	int	count;

	count = 0;
	if (ad < 16)
		count = ft_putcharf(base[ad]);
	else
	{
		count += ft_hexptr(ad / 16, base);
		count += ft_putcharf(base[ad % 16]);
	}
	return (count);
}

int	ft_putadrf(void *ad)
{
	int				count;
	unsigned long	a;

	if (!ad)
		return (ft_putstrf("(nil)"));
	a = (unsigned long)ad;
	count = ft_putstrf("0x") + ft_hexptr(a, "0123456789abcdef");
	return (count);
}
