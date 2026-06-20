/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malrandr <malrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 13:17:31 by malrandr          #+#    #+#             */
/*   Updated: 2025/08/04 17:48:55 by malrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

size_t	ft_strlen(char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_append(char *s, int c)
{
	char	*new;
	size_t	i;

	i = 0;
	new = malloc(sizeof(char) * (ft_strlen(s) + 2));
	while (s && s[i])
	{
		new[i] = s[i];
		i++;
	}
	new[i] = c;
	new[i + 1] = 0;
	return (new);
}

int	ft_isnumeric(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!(s[i] >= 48 && s[i] <= 57))
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(char *nbr)
{
	int		nb;
	size_t	i;
	int		sign;

	i = 0;
	nb = 0;
	sign = 1;
	while ((nbr[i] >= 9 && nbr[i] <= 13) || nbr[i] == 32)
		i++;
	if (nbr[i] == '+' || nbr[i] == '-')
	{
		if (nbr[i] == '-')
			sign = sign * (-1);
		i++;
	}
	while (nbr[i] >= 48 && nbr[i] <= 57)
	{
		nb = 10 * nb + (nbr[i] - '0');
		i++;
	}
	return (nb);
}
