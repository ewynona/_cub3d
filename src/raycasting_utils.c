/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asumerag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 02:18:46 by asumerag          #+#    #+#             */
/*   Updated: 2021/02/06 02:19:22 by asumerag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/cub3d.h"

void		delta_side(int screen_x)
{
	g_ray.camerax = 2 * screen_x / (double)(g_map.x) - 1;
	g_ray.dirx = g_plr.dirx + g_plr.planex * g_ray.camerax;
	g_ray.diry = g_plr.diry + g_plr.planey * g_ray.camerax;
	g_ray.mapx = (int)g_plr.x;
	g_ray.mapy = (int)g_plr.y;
	g_ray.dx = fabs(1 / g_ray.dirx);
	g_ray.dy = fabs(1 / g_ray.diry);
	g_ray.stepx = 1;
	g_ray.stepy = 1;
	if (g_ray.dirx < 0)
	{
		g_ray.stepx = -1;
		g_ray.x = fabs((g_plr.x - g_ray.mapx) * g_ray.dx);
	}
	else
		g_ray.x = fabs((g_ray.mapx + 1 - g_plr.x) * g_ray.dx);
	if (g_ray.diry < 0)
	{
		g_ray.stepy = -1;
		g_ray.y = fabs((g_plr.y - g_ray.mapy) * g_ray.dy);
	}
	else
		g_ray.y = fabs((g_ray.mapy + 1 - g_plr.y) * g_ray.dy);
}

void		find_wall(void)
{
	g_ray.hit = 0;
	while (g_ray.hit != 1)
	{
		g_ray.side = (g_ray.x > g_ray.y) ? 1 : 0;
		if (g_ray.x > g_ray.y)
		{
			g_ray.y += g_ray.dy;
			g_ray.mapy += g_ray.stepy;
		}
		else
		{
			g_ray.x += g_ray.dx;
			g_ray.mapx += g_ray.stepx;
		}
		if (g_map.map[g_ray.mapx][g_ray.mapy] == '1')
			g_ray.hit = 1;
	}
	if (g_ray.side == 0)
		g_ray.dist = (g_ray.mapx - g_plr.x +
											(1 - g_ray.stepx) / 2) / g_ray.dirx;
	else
		g_ray.dist = (g_ray.mapy - g_plr.y +
											(1 - g_ray.stepy) / 2) / g_ray.diry;
	g_ray.wall_height = (g_ray.dist < 0.00001) ?
						100000 : (int)(g_map.y / g_ray.dist);
}

t_texture	wall_texture(void)
{
	t_texture	wall;

	if (g_ray.side && g_ray.diry > 0)
		wall = g_poles.east;
	else if (g_ray.side && g_ray.diry < 0)
		wall = g_poles.west;
	else if (!g_ray.side && g_ray.dirx > 0)
		wall = g_poles.south;
	else
		wall = g_poles.north;
	return (wall);
}

double		tex_x_init(t_texture image)
{
	double	wall_x;
	double	tex_x;

	if (g_ray.side == 0)
		wall_x = g_plr.y + g_ray.dist * g_ray.diry;
	else
		wall_x = g_plr.x + g_ray.dist * g_ray.dirx;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)image.w);
	if (g_ray.side == 0 && g_ray.dirx > 0)
		tex_x = image.w - tex_x - 1;
	if (g_ray.side == 1 && g_ray.diry < 0)
		tex_x = image.w - tex_x - 1;
	return (tex_x);
}

void		pillar_drawing(t_texture image, int screen_x)
{
	double	tex_x;
	double	tex_y;
	double	offset;
	double	color;

	g_ray.start = g_map.y / 2 - g_ray.wall_height / 2;
	g_ray.end = g_map.y / 2 + g_ray.wall_height / 2;
	if (g_ray.start < 0)
		g_ray.start = 1;
	if (g_ray.end >= g_map.y)
		g_ray.end = g_map.y - 1;
	offset = image.w / (double)g_ray.wall_height;
	tex_x = tex_x_init(image);
	tex_y = (g_ray.start - g_map.y / 2 + g_ray.wall_height / 2) * offset;
	while (g_ray.start < g_ray.end)
	{
		tex_y += offset;
		color = my_mlx_pixel_read(&image, tex_x, tex_y - 1);
		my_mlx_pixel_put(&g_img, screen_x, g_ray.start, color);
		g_ray.start++;
	}
}
