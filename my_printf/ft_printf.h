/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malrandr <malrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:07:10 by malrandr          #+#    #+#             */
/*   Updated: 2025/04/25 15:16:51 by malrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putf(const char format, va_list args);
int	ft_putcharf(int c);
int	ft_putstrf(char *s);
int	ft_putadrf(void *ad);
int	ft_putnbrf(int n);
int	ft_putunbrf(unsigned int n);
int	ft_puthexf(unsigned int n, char *base);

#endif