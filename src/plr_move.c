/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plr_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asumerag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 00:43:52 by asumerag          #+#    #+#             */
/*   Updated: 2021/02/06 02:29:00 by asumerag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/cub3d.h"

void	turn(int keycode, double step)
{
	double	tmp_dir;
	double	tmp_plane;

	tmp_dir = 0;
	tmp_plane = 0;
	if (keycode == KEY_LEFT)
	{
		tmp_dir = g_plr.dirx;
		g_plr.dirx = g_plr.dirx * cos(step) - g_plr.diry * sin(step);
		g_plr.diry = tmp_dir * sin(step) + g_plr.diry * cos(step);
		tmp_plane = g_plr.planex;
		g_plr.planex = g_plr.planex * cos(step) - g_plr.planey * sin(step);
		g_plr.planey = tmp_plane * sin(step) + g_plr.planey * cos(step);
	}
	else if (keycode == KEY_RIGHT)
	{
		tmp_dir = g_plr.dirx;
		g_plr.dirx = g_plr.dirx * cos(-step) - g_plr.diry * sin(-step);
		g_plr.diry = tmp_dir * sin(-step) + g_plr.diry * cos(-step);
		tmp_plane = g_plr.planex;
		g_plr.planex = g_plr.planex * cos(-step) - g_plr.planey * sin(-step);
		g_plr.planey = tmp_plane * sin(-step) + g_plr.planey * cos(-step);
	}
}

void	move_right_left(int keycode, double step)
{
	if (keycode == KEY_A)
	{
		if (g_map.map[(int)(g_plr.x - g_plr.planex * step)][(int)(g_plr.y)]
																	== '0')
			g_plr.x -= g_plr.planex * step;
		if (g_map.map[(int)(g_plr.x)][(int)(g_plr.y - g_plr.planey * step)]
																	== '0')
			g_plr.y -= g_plr.planey * step;
	}
	else if (keycode == KEY_D)
	{
		if (g_map.map[(int)(g_plr.x + g_plr.planex * step)][(int)(g_plr.y)]
																	== '0')
			g_plr.x += g_plr.planex * step;
		if (g_map.map[(int)(g_plr.x)][(int)(g_plr.y + g_plr.planey * step)]
																	== '0')
			g_plr.y += g_plr.planey * step;
	}
}

void	move_up_down(int keycode, double step)
{
	if (keycode == KEY_W)
	{
		if (g_map.map[(int)(g_plr.x + g_plr.dirx * step)][(int)(g_plr.y)]
																== '0')
			g_plr.x += g_plr.dirx * step;
		if (g_map.map[(int)(g_plr.x)][(int)(g_plr.y + g_plr.diry * step)]
																== '0')
			g_plr.y += g_plr.diry * step;
	}
	else if (keycode == KEY_S)
	{
		if (g_map.map[(int)(g_plr.x - g_plr.dirx * step)][(int)(g_plr.y)]
																== '0')
			g_plr.x -= g_plr.dirx * step;
		if (g_map.map[(int)(g_plr.x)][(int)(g_plr.y - g_plr.diry * step)]
																== '0')
			g_plr.y -= g_plr.diry * step;
	}
}
