/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldione <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:58:54 by ldione            #+#    #+#             */
/*   Updated: 2021/10/12 17:06:20 by ldione           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *source, size_t count)
{
	size_t			i;
	unsigned char	*dest_cp;
	unsigned char	*src_cp;

	dest_cp = dest;
	src_cp = (unsigned char *) source;
	if (!count || dest_cp == src_cp)
		return (dest);
	i = 0;
	while (i != count)
	{
		dest_cp[i] = src_cp[i];
		i++;
	}
	return (dest_cp);
}
