/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asumerag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 12:09:58 by asumerag          #+#    #+#             */
/*   Updated: 2021/02/06 01:26:18 by asumerag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/cub3d.h"

static void	start_end_init(int sprite_h, int sprite_w, int sprite_screen)
{
	int	draw_startx;
	int	draw_starty;
	int	draw_endx;
	int	draw_endy;

	draw_starty = g_map.y / 2 - sprite_h / 2;
	draw_endy = g_map.y / 2 + sprite_h / 2;
	if (draw_starty < 0)
		draw_starty = 0;
	if (draw_endy >= g_map.y)
		draw_endy = g_map.y - 1;
	draw_startx = -sprite_w / 2 + sprite_screen;
	draw_endx = sprite_w / 2 + sprite_screen;
	if (draw_startx < 0)
		draw_startx = 0;
	if (draw_endx >= g_map.x)
		draw_endx = g_map.x - 1;
	g_drw_sprite.start_x = draw_startx;
	g_drw_sprite.end_x = draw_endx;
	g_drw_sprite.start_y = draw_starty;
	g_drw_sprite.end_y = draw_endy;
}

static void	pixel_print(double step)
{
	double	tex_x;
	double	tex_y;
	int		y;
	int		d;
	int		color;

	tex_x = (int)((g_drw_sprite.start_x - (-g_drw_sprite.width / 2 +
			g_drw_sprite.screen)) * g_poles.sprite.w / g_drw_sprite.width);
	y = g_drw_sprite.start_y;
	d = y * 256 - g_map.y * 128 + g_drw_sprite.height * 128;
	tex_y = ((d * g_poles.sprite.h) / g_drw_sprite.height) / 256;
	while (y < g_drw_sprite.end_y)
	{
		color = my_mlx_pixel_read(&g_poles.sprite, tex_x, tex_y);
		if (color != 0)
			my_mlx_pixel_put(&g_img, g_drw_sprite.start_x, y, color);
		y++;
		tex_y += step;
	}
}

static void	sprite_params_init(int i)
{
	double	invdet;

	g_drw_sprite.x = g_sprite[i].x - g_plr.x + 0.5;
	g_drw_sprite.y = g_sprite[i].y - g_plr.y + 0.5;
	invdet = 1 / (g_plr.planex * g_plr.diry - g_plr.dirx * g_plr.planey);
	g_drw_sprite.transformx = invdet *
		(g_plr.diry * g_drw_sprite.x - g_plr.dirx * g_drw_sprite.y);
	g_drw_sprite.transformy = invdet *
		(g_plr.planex * g_drw_sprite.y - g_plr.planey * g_drw_sprite.x);
	g_drw_sprite.screen = (int)((g_map.x / 2) *
					(1 + g_drw_sprite.transformx / g_drw_sprite.transformy));
	g_drw_sprite.width = abs((int)(g_map.y / g_drw_sprite.transformy));
	g_drw_sprite.height = abs((int)(g_map.y / g_drw_sprite.transformy));
}

void		sprite_pictures(double *zbuffer)
{
	int		i;
	double	step;

	i = 0;
	sprite_sort();
	while (g_sprite[i].id != -1)
	{
		sprite_params_init(i);
		start_end_init(g_drw_sprite.height,
						g_drw_sprite.width, g_drw_sprite.screen);
		step = g_poles.sprite.h / (double)g_drw_sprite.height;
		while (g_drw_sprite.start_x < g_drw_sprite.end_x)
		{
			if (g_drw_sprite.transformy > 0 && g_drw_sprite.start_x > 0 &&
				g_drw_sprite.start_x < g_map.x &&
				g_drw_sprite.transformy < zbuffer[g_drw_sprite.start_x])
				pixel_print(step);
			g_drw_sprite.start_x++;
		}
		i++;
	}
	free(g_sprite);
	g_sprite = NULL;
}
