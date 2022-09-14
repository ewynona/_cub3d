/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asumerag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 18:58:09 by asumerag          #+#    #+#             */
/*   Updated: 2020/11/05 20:07:56 by asumerag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;

	i = -1;
	if (!s)
		return (NULL);
	if (!(str = ft_calloc(sizeof(char), ft_strlen(s) + 1)))
		return (NULL);
	while (s[++i])
		str[i] = (*f)(i, s[i]);
	return (str);
}
