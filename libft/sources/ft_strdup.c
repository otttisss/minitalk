/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldione <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:39:18 by ldione            #+#    #+#             */
/*   Updated: 2021/10/15 16:11:14 by ldione           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*str_c;
	size_t	start;
	size_t	count;

	start = 0;
	count = 0;
	while (str[count] != '\0')
		count++;
	str_c = (char *) malloc ((count * sizeof(char)) + 1);
	if (!str_c)
		return (0);
	while (start < count)
	{
		str_c[start] = str[start];
		start++;
	}
	str_c[start] = '\0';
	return (str_c);
}
