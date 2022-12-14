/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldione <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:48:43 by ldione            #+#    #+#             */
/*   Updated: 2021/10/13 18:59:00 by ldione           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t count)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	i = 0;
	d = (unsigned char *) dst;
	s = (unsigned char *) src;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst > src)
		while (++i <= count)
			d[count - i] = s[count - i];
	else
	{
		while (count-- > 0)
			*(d++) = *(s++);
	}
	return (dst);
}
