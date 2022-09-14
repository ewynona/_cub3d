/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asumerag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 00:10:11 by asumerag          #+#    #+#             */
/*   Updated: 2021/02/06 00:16:27 by asumerag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/cub3d.h"

static int	count_of_sprite(void)
{
	int	x;
	int	y;
	int	count;

	x = 0;
	y = 0;
	count = 0;
	while (g_map.map[x])
	{
		y = 0;
		while (g_map.map[x][y])
		{
			if (g_map.map[x][y] == '2')
				count++;
			y++;
		}
		x++;
	}
	return (count);
}

static void	sprite_init(void)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	x = -1;
	y = 0;
	if (!(g_sprite = malloc(sizeof(t_sprite) * (count_of_sprite() + 1))))
		error_processing(5);
	while (g_map.map[++x])
	{
		y = 0;
		while (g_map.map[x][y])
		{
			if (g_map.map[x][y] == '2')
			{
				g_sprite[i].x = x;
				g_sprite[i].y = y;
				g_sprite[i].id = i;
				i++;
			}
			y++;
		}
	}
	g_sprite[i].id = -1;
}

static void	sprite_dist(void)
{
	int			i;

	i = 0;
	while (g_sprite[i].id != -1)
	{
		g_sprite[i].dist = pow(g_plr.x - g_sprite[i].x, 2) +
							pow(g_plr.y - g_sprite[i].y, 2);
		i++;
	}
}

void		sprite_sort(void)
{
	int			i;
	int			j;
	int			count;
	t_sprite	tmp;

	i = 0;
	j = 0;
	sprite_init();
	sprite_dist();
	count = count_of_sprite();
	while (j < count)
	{
		i = 0;
		while (g_sprite[i + 1].id != -1)
		{
			if (g_sprite[i].dist < g_sprite[i + 1].dist)
			{
				tmp = g_sprite[i];
				g_sprite[i] = g_sprite[i + 1];
				g_sprite[i + 1] = tmp;
			}
			i++;
		}
		j++;
	}
}
