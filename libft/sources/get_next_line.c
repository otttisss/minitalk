/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldione <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 18:55:41 by ldione            #+#    #+#             */
/*   Updated: 2021/11/23 16:25:57 by ldione           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*get_answ(char *reminder)
{
	int		i;
	char	*str;

	i = 0;
	if (!reminder[i])
		return (NULL);
	while (reminder[i] && reminder[i] != '\n')
		i++;
	str = (char *)malloc(sizeof (char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (reminder[i] && reminder[i] != '\n')
	{
		str[i] = reminder[i];
		i++;
	}
	if (reminder[i] == '\n')
	{
		str[i] = reminder[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*new_reminder(char *reminder)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (reminder[i] && reminder[i] != '\n')
		i++;
	if (!reminder[i])
	{
		free (reminder);
		return (NULL);
	}
	str = (char *) malloc(sizeof (char) * (ft_strlen(reminder) - i + 1));
	if (!str)
		return (NULL);
	j = 0;
	while (reminder[i])
	{
		i++;
		str[j] = reminder[i];
		j++;
	}
	str[j] = '\0';
	free (reminder);
	return (str);
}

char	*new_read(int fd, char *reminder)
{
	char	*buff;
	int		bts;

	buff = malloc((BUFFER_SIZE + 1) * sizeof (char));
	if (!buff)
		return (NULL);
	bts = 1;
	while (!ft_strchr(reminder, '\n') && bts != 0)
	{
		bts = read(fd, buff, BUFFER_SIZE);
		if (bts == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[bts] = '\0';
		reminder = ft_strjoin(reminder, buff);
	}
	free (buff);
	return (reminder);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*reminder;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	reminder = new_read(fd, reminder);
	if (!reminder)
		return (NULL);
	line = get_answ(reminder);
	reminder = new_reminder(reminder);
	return (line);
}
