/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asumerag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 21:37:04 by asumerag          #+#    #+#             */
/*   Updated: 2020/11/05 18:49:30 by asumerag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_word(char const *s1, char c)
{
	size_t	size;
	size_t	i;

	i = 0;
	size = 0;
	while (s1[i] != '\0')
	{
		while (s1[i] == c && s1[i] != '\0')
			i++;
		while (s1[i] != c && s1[i] != '\0')
			i++;
		if (s1[i - 1] != '\0' && s1[i - 1] != c)
			size++;
	}
	return (size);
}

static char		*ft_strnchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str && *str == (char)c)
		str++;
	return (str);
}

static size_t	ft_lenword(char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	return (len);
}

static void		ft_freeall(char **arr, size_t count)
{
	while (count-- > 0)
		free(arr[count]);
	free(arr);
}

char			**ft_split(char const *s1, char c)
{
	char	**arr;
	char	*str;
	size_t	i;
	size_t	count;

	if (!s1)
		return (NULL);
	str = (char *)s1;
	i = 0;
	count = ft_count_word(s1, c);
	if (!(arr = malloc((count + 1) * sizeof(char*))))
		return (NULL);
	while (*str != '\0' && i < count)
	{
		str = ft_strnchr(str, c);
		if (str && !(arr[i] = ft_substr(str, 0, ft_lenword(str, c))))
		{
			ft_freeall(arr, count);
			return (NULL);
		}
		str += ft_lenword(str, c);
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
