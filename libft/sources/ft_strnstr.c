/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldione <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 16:46:50 by ldione            #+#    #+#             */
/*   Updated: 2021/10/20 18:37:34 by ldione           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *lit, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (*big != '\0' && *lit != '\0' && len != 0)
	{
		while (big[i] != '\0' && len != 0)
		{
			if (big[i] == lit[0])
			{
				j = 1;
				while (big[i + j] == lit[j] && lit[j] != '\0' && i <= len + 1)
					++j;
				if (lit[j] == '\0')
					return ((char *) &big[i]);
			}
			i++;
			len--;
		}
	}
	else if (*lit == '\0')
		return ((char *) big);
	return (0);
}
