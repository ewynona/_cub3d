/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asumerag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:08:02 by asumerag          #+#    #+#             */
/*   Updated: 2021/02/06 00:25:46 by asumerag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/cub3d.h"

void	map_check(int size)
{
	size_t	x;
	size_t	y;

	x = -1;
	y = 1;
	while (g_map.map[y][++x])
		if (ft_strchr("02WESN", g_map.map[y][x]) && g_map.map[y - 1][x] != '1')
			error_processing(3);
	while (++y < (size_t)size)
	{
		x = -1;
		map_border(g_map.map[y]);
		while (g_map.map[y][++x])
		{
			if (ft_strchr("02WESN", g_map.map[y][x]) && g_map.map[y][x] != '\0')
				if (x > ft_strlen(g_map.map[y - 1] + 1)
					|| !ft_strchr("102WESN", g_map.map[y - 1][x]))
					error_processing(3);
			if (ft_strchr("02WESN", g_map.map[y][x]) && g_map.map[y][x] != '\0')
				if ((size_t)size == y + 1 || x > ft_strlen(g_map.map[y + 1] + 1)
					|| (!ft_strchr("102WESN", g_map.map[y + 1][x])))
					error_processing(3);
		}
	}
}

void	map_border(char *str)
{
	int x;

	x = ft_strlen(str);
	while (str[--x] == ' ')
		str[x] = 0;
	x = 0;
	while (str[x])
	{
		while (str[x] == ' ')
			x++;
		if (str[x] == '1')
		{
			while (str[x] == '1')
				x++;
			while (str[x] != '\0' && ft_strchr("02WESN", str[x]))
			{
				x++;
				if (!(ft_strchr("102WESN", str[x])) || str[x] == '\0')
					error_processing(3);
			}
		}
		else
			error_processing(3);
	}
}

void	ft_map(t_list *tmp)
{
	int	i;
	int	size;

	i = 0;
	size = ft_lstsize(tmp);
	if (!(g_map.map = ft_calloc(sizeof(char *), size + 1)))
		error_processing(5);
	while (tmp)
	{
		if (!(g_map.map[i] = ft_substr(tmp->content, 0,
							ft_strlen(tmp->content))))
		{
			ft_lstclear(&tmp, free);
			error_processing(5);
		}
		tmp = tmp->next;
		i++;
	}
	if ((g_map.lines = size) < 3)
	{
		ft_lstclear(&tmp, free);
		error_processing(3);
	}
}

void	map_parser(char *line, int fd)
{
	t_list	*tmp;

	if (!(tmp = ft_lstnew(ft_substr(line, 0, ft_strlen(line)))))
		error_processing(5);
	while (gnl(fd, &line) > 0)
	{
		ft_lstadd_back(&tmp, ft_lstnew(ft_substr(line, 0, ft_strlen(line))));
		free(line);
	}
	free(line);
	ft_map(tmp);
	ft_lstclear(&tmp, free);
	map_check(g_map.lines);
}
