/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldione <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 17:32:21 by ldione            #+#    #+#             */
/*   Updated: 2021/10/23 17:32:22 by ldione           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*p;
	t_list	*buf;

	p = NULL;
	p = *lst;
	while (p != NULL)
	{
		buf = p->next;
		if (del)
		{
			(*del)(p->content);
		}
		free(p);
		p = buf;
	}
	*lst = NULL;
}
