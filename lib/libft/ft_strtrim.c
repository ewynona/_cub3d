/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asumerag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:41:02 by asumerag          #+#    #+#             */
/*   Updated: 2020/11/04 21:48:29 by asumerag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	check_char(char const *s1, int c)
{
	int	i;

	i = -1;
	while (s1[++i])
		if (s1[i] == (unsigned char)c)
			return (s1[i]);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *s2)
{
	int		start;
	int		end;
	int		size;

	start = 0;
	if (!s1)
		return (NULL);
	end = ft_strlen(s1);
	while (check_char(s2, s1[start]) == s1[start] && s1[start] != '\0')
		start++;
	while (check_char(s2, s1[end]) == s1[end] && end > 0)
		end--;
	size = (end > 0) ? end - start + 1 : 0;
	return (ft_substr(s1, start, size));
}
