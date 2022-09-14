/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parametrs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asumerag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 16:53:33 by asumerag          #+#    #+#             */
/*   Updated: 2021/02/06 14:32:22 by asumerag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/cub3d.h"

void	check_map_element(char **src, char *str)
{
	int	fd;

	if ((fd = open(str, O_RDONLY)) < 0 ||
		!ft_strnstr(&str[ft_strlen(str) - 4], ".xpm", 4))
	{
		close(fd);
		free(str);
		error_processing(1);
	}
	close(fd);
	if (*src != NULL)
	{
		free(str);
		error_processing(7);
	}
	else
		*src = ft_substr(str, 0, ft_strlen(str));
}

void	parse_texture(char *line)
{
	int		i;
	char	*tex;

	i = (ft_strnstr(line, "S", 1)) ? 2 : 3;
	if (!(tex = ft_strtrim(&line[i], " ")))
		error_processing(5);
	if (ft_strnstr(line, "NO", 2))
		check_map_element(&g_map.north, tex);
	else if (ft_strnstr(line, "SO", 2))
		check_map_element(&g_map.south, tex);
	else if (ft_strnstr(line, "WE", 2))
		check_map_element(&g_map.west, tex);
	else if (ft_strnstr(line, "EA", 2))
		check_map_element(&g_map.east, tex);
	else if (ft_strnstr(line, "S", 1))
		check_map_element(&g_map.sprite, tex);
	free(tex);
}

int		color_fl_ce(int *color, char *line)
{
	int i;
	int hex;

	hex = 0;
	i = -1;
	check_floor_ceil(line);
	while (++i < 3)
		hex = (hex << 8) | color[i];
	if (line[0] == 'F' && g_map.floor == -1)
		g_map.floor = hex;
	else if (line[0] == 'C' && g_map.ceiling == -1)
		g_map.ceiling = hex;
	else
		error_processing(7);
	return (hex);
}

void	fc_free_error(int **color)
{
	free(*color);
	error_processing(2);
}

void	parse_fc(char *line)
{
	int *color;
	int i;
	int j;

	i = 1;
	j = -1;
	if (!(color = malloc(sizeof(int) * 4)))
		error_processing(5);
	while (++j < 3)
	{
		while (line[i] == ' ' || line[i] == ',')
			i++;
		if (line[i] < '0' || line[i] > '9')
			fc_free_error(&color);
		color[j] = ft_atoi(&line[i]);
		if (color[j] < 0 || color[j] > 255)
			fc_free_error(&color);
		while (ft_isalnum(line[i]))
			i++;
	}
	color_fl_ce(color, line);
	free(color);
}
