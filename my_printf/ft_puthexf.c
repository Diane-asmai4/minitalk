/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malrandr <malrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:13:46 by malrandr          #+#    #+#             */
/*   Updated: 2025/04/25 15:16:58 by malrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexf(unsigned int nb, char *base)
{
	int	count;

	count = 0;
	if (nb < 16)
		count += ft_putcharf(base[nb]);
	else
	{
		count += ft_puthexf(nb / 16, base);
		count += ft_putcharf(base[nb % 16]);
	}
	return (count);
}
