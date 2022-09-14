/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asumerag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 17:03:35 by asumerag          #+#    #+#             */
/*   Updated: 2021/01/20 17:46:17 by asumerag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **list, void (*del)(void *))
{
	t_list	*p;
	t_list	*tmp;

	p = *list;
	while (p)
	{
		tmp = p;
		p = p->next;
		ft_lstdelone(tmp, del);
	}
	*list = NULL;
}
