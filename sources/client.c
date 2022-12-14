/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmilagro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 19:29:30 by cmilagro          #+#    #+#             */
/*   Updated: 2022/03/15 19:29:33 by cmilagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"

static void	send(int pid, char *msg)
{
	int		i;
	char	ltr;

	while (*msg)
	{
		i = 8;
		ltr = *msg++;
		while (i--)
		{
			if (ltr >> i & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
		}
	}
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR2);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("USAGE: <PID> <message>");
		return (0);
	}
	send(ft_atoi(argv[1]), argv[2]);
	return (0);
}
