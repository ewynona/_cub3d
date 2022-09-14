/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asumerag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 17:36:02 by asumerag          #+#    #+#             */
/*   Updated: 2020/11/07 17:10:15 by asumerag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *lstlist;
	t_list *new;

	lstlist = NULL;
	new = NULL;
	if (!lst)
		return (NULL);
	while (lst)
	{
		if (!(new = ft_lstnew(f(lst->content))))
			ft_lstclear(&lstlist, del);
		ft_lstadd_back(&lstlist, new);
		lst = lst->next;
	}
	return (lstlist);
}
