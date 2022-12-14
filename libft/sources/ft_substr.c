/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldione <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 16:44:14 by ldione            #+#    #+#             */
/*   Updated: 2022/03/07 18:58:49 by ldione           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	fact_count(const char *s, unsigned int start, size_t len)
{
	size_t	i;

	i = 0;
	if (start == 0 && len == 0)
		return (0);
	while (s[start++])
		i++;
	if (len < i)
		return (len);
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ss;
	size_t	i;
	char	*dst;

	ss = (char *) s;
	i = 0;
	dst = (char *) malloc(((fact_count(s, start, len) + 1) * sizeof(char)));
	if (!dst || !s)
		return (0);
	if (start >= (unsigned int) ft_strlen(ss))
	{
		dst[i] = '\0';
		return (dst);
	}
	len = start + fact_count(s, start, len);
	while (start <= len - 1 && len != 0)
	{
		dst[i] = ss[start];
		i++;
		start++;
	}
	dst[i] = 0;
	return (dst);
}
