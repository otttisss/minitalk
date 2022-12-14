/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmilagro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 19:29:14 by cmilagro          #+#    #+#             */
/*   Updated: 2022/03/15 19:29:18 by cmilagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <signal.h>
#include "ft_printf.h"

static void	action(int signal, siginfo_t *info, void *trash)
{
	static int				i = 0;
	static pid_t			client_pid = 0;
	static unsigned char	ltr = 0;

	(void)trash;
	if (!client_pid)
		client_pid = info->si_pid;
	ltr |= (signal == SIGUSR1);
	if (++i == 8)
	{
		i = 0;
		if (!ltr)
		{
			kill(client_pid, SIGUSR2);
			client_pid = 0;
			return ;
		}
		ft_printf("%c", ltr);
		ltr = 0;
		kill(client_pid, SIGUSR1);
	}
	else
		ltr <<= 1;
}

int	main(void)
{
	struct sigaction	act;

	ft_printf("Server PID: %d\n", getpid());
	act.sa_sigaction = action;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, 0);
	sigaction(SIGUSR2, &act, 0);
	while (1)
		pause();
	return (0);
}
