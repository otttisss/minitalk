/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldione <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 16:08:37 by ldione            #+#    #+#             */
/*   Updated: 2021/11/09 19:10:08 by ldione           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*p;

	p = NULL;
	if (lst)
	{
		if (*lst == NULL)
		{
			*lst = new;
		}
		else
		{
			p = ft_lstlast(*lst);
			p->next = new;
		}
	}
}
