/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldione <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:25:50 by ldione            #+#    #+#             */
/*   Updated: 2021/10/18 20:16:36 by ldione           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	kek;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		kek = (unsigned int)(n * -1);
	}
	else
		kek = (unsigned int)n;
	if (kek >= 10)
		ft_putnbr_fd(kek / 10, fd);
	ft_putchar_fd((char)(kek % 10 + 48), fd);
}
