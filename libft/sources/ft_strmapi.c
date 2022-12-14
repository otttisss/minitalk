/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldione <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:01:13 by ldione            #+#    #+#             */
/*   Updated: 2021/10/18 18:33:40 by ldione           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*src;
	char	*dst;
	int		count;

	if (!s || !(*f))
		return (NULL);
	src = (char *) s;
	count = ft_strlen (s);
	dst = (char *) malloc ((count + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	count = 0;
	while (src[count])
	{
		dst[count] = (*f)(count, src[count]);
		count++;
	}
	dst[count] = '\0';
	return (dst);
}
