/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malrandr <malrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 08:22:43 by malrandr          #+#    #+#             */
/*   Updated: 2025/08/04 15:22:33 by malrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

int		ft_isnumeric(char *s);
int		ft_atoi(char *nbr);
size_t	ft_strlen(char *s);
char	*ft_append(char *s, int c);

#endif