/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asumerag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 05:27:08 by asumerag          #+#    #+#             */
/*   Updated: 2021/02/06 00:14:17 by asumerag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/cub3d.h"

void	check_params(void)
{
	if (g_map.x <= 0 || g_map.y <= 0)
		error_processing(3);
	if (g_map.north == NULL || g_map.south == NULL
		|| g_map.west == NULL || g_map.east == NULL
		|| g_map.sprite == NULL || g_map.floor == -1
		|| g_map.ceiling == -1 || g_map.map == NULL)
		error_processing(4);
}

void	cub_parser(int fd)
{
	char *line;

	while (gnl(fd, &line) > 0)
	{
		map_elements(line, fd);
		free(line);
	}
	free(line);
	check_params();
}

int		map_entry(char *line)
{
	int i;

	i = -1;
	if (line[0] == '\0')
		return (0);
	while (line[++i])
		if (line[i] != ' ' && line[i] != '1')
			return (0);
	return (1);
}

void	map_elements(char *line, int fd)
{
	int i;

	i = 0;
	if (line[i++] == 'R')
	{
		while (line[i] == ' ')
			i++;
		g_map.x = ft_atoi(&line[i]);
		while (ft_isalnum(line[i]))
			i++;
		g_map.y = ft_atoi(&line[i]);
	}
	else if (ft_strnstr(line, "NO", 2) || ft_strnstr(line, "SO", 2)
			|| ft_strnstr(line, "WE", 2) || ft_strnstr(line, "EA", 2)
			|| line[0] == 'S')
		parse_texture(line);
	else if (ft_strnstr(line, "F", 1) || ft_strnstr(line, "C", 1))
		parse_fc(line);
	else if (map_entry(line))
		map_parser(line, fd);
	else if (line[0] != '\0')
		error_processing(0);
}
