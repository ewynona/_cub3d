/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asumerag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 11:32:11 by asumerag          #+#    #+#             */
/*   Updated: 2021/02/06 00:21:39 by asumerag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/cub3d.h"

void	map_init(void)
{
	g_map.x = 0;
	g_map.y = 0;
	g_map.north = NULL;
	g_map.south = NULL;
	g_map.west = NULL;
	g_map.east = NULL;
	g_map.sprite = NULL;
	g_map.floor = -1;
	g_map.ceiling = -1;
	g_map.map = NULL;
	g_map.lines = 0;
}

void	poles_init(void)
{
	if (!(g_poles.east.img = mlx_xpm_file_to_image(g_img.mlx,
			g_map.east, &g_poles.east.w, &g_poles.east.h)))
		error_processing(8);
	g_poles.east.addr = mlx_get_data_addr(g_poles.east.img,
			&g_poles.east.bpp, &g_poles.east.line_len, &g_poles.east.en);
	if (!(g_poles.west.img = mlx_xpm_file_to_image(g_img.mlx,
			g_map.west, &g_poles.west.w, &g_poles.west.h)))
		error_processing(8);
	g_poles.west.addr = mlx_get_data_addr(g_poles.west.img,
			&g_poles.west.bpp, &g_poles.west.line_len, &g_poles.west.en);
	if (!(g_poles.south.img = mlx_xpm_file_to_image(g_img.mlx,
			g_map.south, &g_poles.south.w, &g_poles.south.h)))
		error_processing(8);
	g_poles.south.addr = mlx_get_data_addr(g_poles.south.img,
			&g_poles.south.bpp, &g_poles.south.line_len, &g_poles.south.en);
	if (!(g_poles.north.img = mlx_xpm_file_to_image(g_img.mlx,
			g_map.north, &g_poles.north.w, &g_poles.north.h)))
		error_processing(8);
	g_poles.north.addr = mlx_get_data_addr(g_poles.north.img,
			&g_poles.north.bpp, &g_poles.north.line_len, &g_poles.north.en);
	if (!(g_poles.sprite.img = mlx_xpm_file_to_image(g_img.mlx,
			g_map.sprite, &g_poles.sprite.w, &g_poles.sprite.h)))
		error_processing(8);
	g_poles.sprite.addr = mlx_get_data_addr(g_poles.sprite.img,
			&g_poles.sprite.bpp, &g_poles.sprite.line_len, &g_poles.sprite.en);
}
