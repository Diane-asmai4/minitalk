/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malrandr <malrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 21:40:37 by malrandr          #+#    #+#             */
/*   Updated: 2025/08/13 11:28:20 by malrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "my_printf/ft_printf.h"

static void	ft_push_back(char **s, int c)
{
	char	*tmp;

	tmp = *s;
	*s = ft_append(tmp, c);
	if (tmp)
		free(tmp);
}

static void	ft_pong(int sig, siginfo_t *info, void *context)
{
	static char				*mes = NULL;
	static unsigned char	c = 0;
	static int				bit = 0;

	(void)context;
	(void)info;
	c = c | ((sig == SIGUSR2) << bit);
	bit++;
	if (bit == 8)
	{
		if (c == 0)
		{
			if (mes)
			{
				ft_printf("%s\n", mes);
				free(mes);
				mes = NULL;
			}
		}
		else
			ft_push_back(&mes, c);
		c = 0;
		bit = 0;
	}
}

static void	sa_init(struct sigaction *sa, int sig)
{
	sigemptyset(&sa->sa_mask);
	if (sig == SIGUSR1)
		sigaddset(&sa->sa_mask, SIGUSR2);
	else
		sigaddset(&sa->sa_mask, SIGUSR1);
	sa->sa_sigaction = &ft_pong;
	sa->sa_flags = SA_SIGINFO;
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sa_one;
	struct sigaction	sa_two;

	if (argc > 1)
	{
		ft_printf("Server takes no arguments!\n");
		exit(1);
	}
	pid = getpid();
	sa_init(&sa_one, SIGUSR1);
	sa_init(&sa_two, SIGUSR2);
	sigaction(SIGUSR1, &sa_one, NULL);
	sigaction(SIGUSR2, &sa_two, NULL);
	ft_printf("%s %d running...\n", &argv[0][2], pid);
	while (1)
	{
		pause();
	}
	return (0);
}
