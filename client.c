/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malrandr <malrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 21:40:49 by malrandr          #+#    #+#             */
/*   Updated: 2025/08/13 11:26:11 by malrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "my_printf/ft_printf.h"

static int	check_args(int argc, char **argv)
{
	if (argc < 3 || !ft_isnumeric(argv[1]))
	{
		ft_printf("You must enter a valid PID and a message!\n");
		return (1);
	}
	if (argc > 3)
	{
		ft_printf("Too many arguments.\n");
		return (1);
	}
	return (0);
}

static void	ft_send_bit(int sig, int pid)
{
	if (kill(pid, sig) == -1)
	{
		ft_printf("Oops, could not send signal to server (×_×)⌒☆\n");
		exit(1);
	}
}

static void	ft_char_to_bits(char *s, int pid)
{
	int				bit;
	size_t			len;
	size_t			i;
	unsigned char	c;

	i = 0;
	len = ft_strlen(s);
	while (i <= len)
	{
		c = s[i];
		bit = 0;
		while (bit < 8)
		{
			if (c % 2 == 0)
				ft_send_bit(SIGUSR1, pid);
			else
				ft_send_bit(SIGUSR2, pid);
			c = c >> 1;
			usleep(700);
			bit++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int					dest_pid;

	if (check_args(argc, argv) == 1)
		exit(EXIT_FAILURE);
	dest_pid = ft_atoi(argv[1]);
	ft_char_to_bits(argv[2], dest_pid);
	return (0);
}
