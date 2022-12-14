/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldione <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:38:42 by ldione            #+#    #+#             */
/*   Updated: 2021/10/12 15:57:45 by ldione           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void	*inp, size_t count)
{
	size_t			i;
	unsigned char	l;
	unsigned char	*srcs;

	srcs = inp;
	l = '\0';
	i = 0;
	while (i != count)
	{
		srcs[i] = l;
		i++;
	}
}
