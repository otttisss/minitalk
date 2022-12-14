/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldione <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 19:27:58 by ldione            #+#    #+#             */
/*   Updated: 2021/10/15 16:15:37 by ldione           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *restrict s1, const char *restrict s2, size_t l)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s2[i] != '\0')
	{
		count++;
		i++;
	}
	if (l == 0)
		return (count);
	i = 0;
	while (i != l - 1 && s2[i] != '\0')
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (count);
}
