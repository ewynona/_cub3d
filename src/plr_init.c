/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plr_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asumerag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 14:26:02 by asumerag          #+#    #+#             */
/*   Updated: 2021/02/06 00:40:26 by asumerag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/cub3d.h"

static void	south_north(char c)
{
	if (c == 'S')
	{
		g_plr.dirx = 1;
		g_plr.diry = 0;
		g_plr.planex = 0;
		g_plr.planey = -0.66;
	}
	else if (c == 'N')
	{
		g_plr.dirx = -1;
		g_plr.diry = 0;
		g_plr.planex = 0;
		g_plr.planey = 0.66;
	}
}

static void	east_west(char c)
{
	if (c == 'E')
	{
		g_plr.dirx = 0;
		g_plr.diry = 1;
		g_plr.planex = 0.66;
		g_plr.planey = 0;
	}
	else if (c == 'W')
	{
		g_plr.dirx = 0;
		g_plr.diry = -1;
		g_plr.planex = -0.66;
		g_plr.planey = 0;
	}
}

static void	pos_init(char c)
{
	south_north(c);
	east_west(c);
}

void		plr_init(void)
{
	int	y;
	int	x;
	int	tmp;

	y = 0;
	x = -1;
	tmp = 0;
	while (g_map.map[++x])
	{
		y = 0;
		while (g_map.map[x][y])
		{
			if (ft_strchr("WNES", g_map.map[x][y]) && g_map.map[x][y] != '\0')
			{
				g_plr.x = x + 0.5;
				g_plr.y = y + 0.5;
				pos_init(g_map.map[x][y]);
				g_map.map[x][y] = '0';
				tmp++;
			}
			y++;
		}
	}
	if (tmp != 1)
		error_processing(9);
}
