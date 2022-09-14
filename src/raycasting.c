/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asumerag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 14:16:56 by asumerag          #+#    #+#             */
/*   Updated: 2021/02/06 02:19:57 by asumerag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/cub3d.h"

void		floor_and_ceil(void)
{
	int	h;
	int	w;

	h = 0;
	w = 0;
	while (h < g_map.y / 2)
	{
		w = 0;
		while (w < g_map.x)
		{
			my_mlx_pixel_put(&g_img, w, h, g_map.ceiling);
			w++;
		}
		h++;
	}
	while (h < g_map.y)
	{
		w = 0;
		while (w < g_map.x)
		{
			my_mlx_pixel_put(&g_img, w, h, g_map.floor);
			w++;
		}
		h++;
	}
}

void		raycasting(void)
{
	int			x;
	double		zbuffer[g_map.x];
	t_texture	image;

	x = 0;
	floor_and_ceil();
	while (x < g_map.x)
	{
		delta_side(x);
		find_wall();
		image = wall_texture();
		pillar_drawing(image, x);
		zbuffer[x] = g_ray.dist;
		x++;
	}
	sprite_pictures(zbuffer);
	if (g_save == 0)
		mlx_put_image_to_window(g_img.mlx, g_img.win, g_img.img, 0, 0);
}

void		check_screen_size(void)
{
	int	w;
	int	h;

	mlx_get_screen_size(g_img.mlx, &w, &h);
	if (g_map.x > w)
		g_map.x = w;
	if (g_map.y > h)
		g_map.y = h;
}
