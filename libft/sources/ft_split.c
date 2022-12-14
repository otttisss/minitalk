/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 18:40:52 by aalien            #+#    #+#             */
/*   Updated: 2022/03/07 18:56:54 by ldione           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	**ft_free(char **s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

static int	count(char const *s, char c)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static char	*new_str(char const *s, char c)
{
	int		i;
	char	*dst;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	dst = (char *)malloc(sizeof(char) * (i + 1));
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s, i + 1);
	return (dst);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		strs_len;
	char	**dst;

	if (!s)
		return (NULL);
	strs_len = count(s, c);
	dst = (char **)malloc(sizeof(char *) * (strs_len + 1));
	if (!dst)
		return (NULL);
	i = -1;
	while (++i < strs_len)
	{
		while (s[0] == c)
			s++;
		dst[i] = new_str(s, c);
		if (!(dst[i]))
		{
			return (ft_free(dst));
		}
		s = s + ft_strlen(dst[i]);
	}
	dst[i] = 0;
	return (dst);
}
