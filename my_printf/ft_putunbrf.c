/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbrf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malrandr <malrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:49:58 by malrandr          #+#    #+#             */
/*   Updated: 2025/04/25 15:17:03 by malrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbrf(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb < 10)
		count = ft_putcharf(nb + '0');
	else
	{
		count += ft_putunbrf(nb / 10);
		count += ft_putcharf((nb % 10) + '0');
	}
	return (count);
}
