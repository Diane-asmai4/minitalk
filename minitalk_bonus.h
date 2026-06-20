/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malrandr <malrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 09:16:08 by malrandr          #+#    #+#             */
/*   Updated: 2025/08/13 09:17:52 by malrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

int		ft_isnumeric(char *s);
int		ft_atoi(char *nbr);
size_t	ft_strlen(char *s);
char	*ft_append(char *s, int c);

#endif