/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asumerag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 14:42:28 by asumerag          #+#    #+#             */
/*   Updated: 2021/02/06 03:41:39 by asumerag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/cub3d.h"

void			my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

unsigned int	my_mlx_pixel_read(t_texture *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	return (*(unsigned int*)dst);
}

void			free_mlx(void)
{
	if (g_img.img)
		mlx_destroy_image(g_img.mlx, g_img.img);
	if (g_poles.east.img)
		mlx_destroy_image(g_img.mlx, g_poles.east.img);
	if (g_poles.west.img)
		mlx_destroy_image(g_img.mlx, g_poles.west.img);
	if (g_poles.south.img)
		mlx_destroy_image(g_img.mlx, g_poles.south.img);
	if (g_poles.north.img)
		mlx_destroy_image(g_img.mlx, g_poles.north.img);
	if (g_poles.sprite.img)
		mlx_destroy_image(g_img.mlx, g_poles.sprite.img);
}

void			free_all(void)
{
	int	y;

	y = -1;
	if (g_map.map)
	{
		while (g_map.map[++y])
			free(g_map.map[y]);
		free(g_map.map);
	}
	if (g_map.east)
		free(g_map.east);
	if (g_map.west)
		free(g_map.west);
	if (g_map.south)
		free(g_map.south);
	if (g_map.north)
		free(g_map.north);
	if (g_map.sprite)
		free(g_map.sprite);
	if (g_sprite)
		free(g_sprite);
	free_mlx();
}

void			error_processing(int var)
{
	if (var == 1)
		ft_putstr_fd("\nERROR\nInvalid file path\n\n", 1);
	else if (var == 2)
		ft_putstr_fd("\nERROR\nWrong color parameter\n\n", 1);
	else if (var == 3)
		ft_putstr_fd("\nERROR\nWrong map parameter\n\n", 1);
	else if (var == 4)
		ft_putstr_fd("\nERROR\nOne or more map elements are missing\n\n", 1);
	else if (var == 5)
		ft_putstr_fd("\nERROR\nMemory allocation error\n\n", 1);
	else if (var == 6)
		ft_putstr_fd("\nERROR\nUnable to create or open file\n\n", 1);
	else if (var == 7)
		ft_putstr_fd("\nERROR\nToo many parameters\n\n", 1);
	else if (var == 8)
		ft_putstr_fd("\nERROR\nMlx if fault\n\n", 1);
	else if (var == 9)
		ft_putstr_fd("\nERROR\nToo many player positions\n\n", 1);
	else if (var == 10)
	{
		ft_putstr_fd("\nERROR\nWrong map format or ", 1);
		ft_putstr_fd("failed to open the .cub\n\n", 1);
	}
	free_all();
	exit(1);
}
