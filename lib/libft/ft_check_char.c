/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asumerag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 22:25:18 by asumerag          #+#    #+#             */
/*   Updated: 2020/11/04 22:27:13 by asumerag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_check_char(char const *s1, int c)
{
	int i;

	i = -1;
	while (s1[++i])
		if (s1[i] == (unsigned char)c)
			return (s1[i]);
	return (0);
}