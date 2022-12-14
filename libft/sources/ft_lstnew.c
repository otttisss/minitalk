/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldione <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:51:23 by ldione            #+#    #+#             */
/*   Updated: 2021/10/21 15:51:24 by ldione           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*slist;

	slist = (t_list *) malloc(sizeof (*slist));
	if (!slist)
		return (NULL);
	slist->content = content;
	slist->next = NULL;
	return (slist);
}
