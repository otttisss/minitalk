/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldione <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:16:13 by ldione            #+#    #+#             */
/*   Updated: 2021/10/15 15:12:10 by ldione           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_atoi(const char *s)
{
	int		minp;
	int		answ;
	int		count;

	count = 0;
	minp = 1;
	answ = 0;
	while (*s && (*s == ' ' || *s == '\n' || *s == '\v' \
				|| *s == '\f' || *s == '\r' || *s == '\t'))
		s++;
	if (*s == '-')
		minp = -1;
	if (*s == '-' || *s == '+')
		s++;
	while (*s >= '0' && *s <= '9' && *s)
	{
		answ = answ * 10 + *s - 48;
		count++;
		s++;
	}
	if (count > 10 && minp == -1)
		return (0);
	else if (count > 10 && minp == 1)
		return (-1);
	return (minp * answ);
}
