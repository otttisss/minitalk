/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldione <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 15:35:07 by ldione            #+#    #+#             */
/*   Updated: 2021/10/13 22:25:29 by ldione           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *buf1, const void *buf2, size_t count)
{
	unsigned char	*buf11;
	unsigned char	*buf22;

	buf11 = (unsigned char *) buf1;
	buf22 = (unsigned char *) buf2;
	while (count-- > 0)
	{
		if (*buf11 != *buf22)
			return (*buf11 - *buf22);
		buf11++;
		buf22++;
	}
	return (0);
}
