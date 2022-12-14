/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldione <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 22:22:41 by ldione            #+#    #+#             */
/*   Updated: 2021/10/20 21:32:23 by ldione           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s, const char *t, size_t num)
{
	unsigned char	*ss;
	unsigned char	*tt;

	ss = (unsigned char *) s;
	tt = (unsigned char *) t;
	if (num == 0)
		return (0);
	if (*tt == 0 && num > 0 && *ss)
		return (1);
	else if (*ss == 0 && num > 0 && *tt)
		return (-1);
	else if ((*s == 0 || *t == 0) && num == 0)
		return (0);
	while (*ss && *tt && --num)
	{
		if (*ss == 0)
			return (0);
		if (*ss != *tt)
			return (*ss - *tt);
		tt++;
		ss++;
	}
	return (*ss - *tt);
}
