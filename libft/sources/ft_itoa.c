/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldione <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 19:31:49 by ldione            #+#    #+#             */
/*   Updated: 2021/10/18 17:58:47 by ldione           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>

static int	counter(int i)
{
	int	n;

	n = 0;
	while (i > 9)
	{
		i = i / 10;
		n++;
	}
	n++;
	return (n);
}

static char	*if_non_standard(int n, char *buf)
{
	char	*dst;
	int		i;

	i = 0;
	if (n == 0 || n == -0)
	{
		dst = (char *) malloc(2 * sizeof(char));
		if (!dst)
			return (NULL);
		dst[0] = '0';
		dst[1] = '\0';
	}
	else
	{
		dst = (char *) malloc(12 * sizeof(char));
		if (!dst)
			return (NULL);
		while (i < 12)
		{
			dst[i] = buf[i];
			i++;
		}
	}
	return (dst);
}

static char	*if_pos(int src, int count)
{
	char	*dst;

	dst = (char *) malloc((count + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	count--;
	dst[count + 1] = '\0';
	while ((count + 1) > 0)
	{
		dst[count] = (src % 10) + '0';
		src /= 10;
		count--;
	}
	return (dst);
}

static char	*if_neg(int src, int count)
{
	char	*dst;

	dst = (char *) malloc((count + 2) * sizeof(char));
	if (!dst)
		return (NULL);
	dst[count + 1] = '\0';
	dst[0] = '-';
	while ((count) > 0)
	{
		dst[count] = (src % 10) + '0';
		src /= 10;
		count--;
	}
	return (dst);
}

char	*ft_itoa(int n)
{
	char	*buf;
	int		i;
	char	*dst;

	buf = "-2147483648\0";
	if (n == 0 || n == -0 || n == -2147483648)
	{
		dst = if_non_standard(n, buf);
	}
	else if (n > 0)
	{
		i = counter(n);
		dst = if_pos(n, i);
	}
	else
	{
		n = n * (-1);
		i = counter(n);
		dst = if_neg(n, i);
	}
	return (dst);
}
