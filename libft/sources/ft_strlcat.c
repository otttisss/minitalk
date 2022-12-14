/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldione <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 17:35:28 by ldione            #+#    #+#             */
/*   Updated: 2021/11/02 16:13:54 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t size)
{
	char	*s;
	size_t	dst_len;
	size_t	src_len;
	size_t	res;
	size_t	i;

	res = 0;
	i = 0;
	s = (char *)src;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(s);
	if (dst_len < size)
		res = dst_len + src_len;
	else
	{
		return (res = src_len + size);
	}
	while (s[i] && (dst_len + 1) < size)
	{
		dst[dst_len] = s[i];
		i++;
		dst_len++;
	}
	dst[dst_len] = '\0';
	return (res);
}
