/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asumerag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 00:43:22 by asumerag          #+#    #+#             */
/*   Updated: 2021/02/06 13:23:17 by asumerag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/cub3d.h"

void	game_loop(int fd)
{
	map_init();
	cub_parser(fd);
	g_img.mlx = mlx_init();
	check_screen_size();
	if (g_save == 0)
		if (!(g_img.win = mlx_new_window(g_img.mlx, g_map.x, g_map.y, "cub3d")))
			error_processing(8);
	if (!(g_img.img = mlx_new_image(g_img.mlx, g_map.x, g_map.y)))
		error_processing(8);
	g_img.addr = mlx_get_data_addr(g_img.img, &g_img.bpp, &g_img.line_len,
									&g_img.en);
	poles_init();
	plr_init();
	raycasting();
	if (g_save == 1)
	{
		bmp();
		free_all();
		exit(1);
	}
	mlx_hook(g_img.win, 2, 1L << 0, key_hook, &g_img);
	mlx_hook(g_img.win, 17, 1L << 17, close_win, &g_img);
	mlx_loop(g_img.mlx);
}

void	cub3d(char *str)
{
	int	fd;

	fd = 0;
	if (ft_strnstr(&str[ft_strlen(str) - 4], ".cub", 4))
	{
		if (!(fd = open(str, O_RDONLY)))
			error_processing(10);
	}
	else
		error_processing(10);
	game_loop(fd);
}

int		main(int ac, char *av[])
{
	if (ac == 2)
	{
		g_save = 0;
		cub3d(av[1]);
	}
	else if (ac == 3 && ft_strnstr(av[2], "--save", 6))
	{
		g_save = 1;
		cub3d(av[1]);
	}
	else
	{
		ft_putstr_fd("\n	<  ./cub3d .cub  >\n\n", 1);
		ft_putstr_fd("	<  ./cub3d .cub --save  >\n\n", 1);
	}
	return (0);
}
