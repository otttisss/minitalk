/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldione <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 19:46:35 by ldione            #+#    #+#             */
/*   Updated: 2021/10/12 15:58:16 by ldione           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *src, int sym, size_t count)
{
	unsigned char	*srcs;
	size_t			i;

	srcs = src;
	i = 0;
	while (i < count)
	{
		srcs[i] = sym;
		i++;
	}
	return (srcs);
}
