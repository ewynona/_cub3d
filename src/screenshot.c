/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asumerag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 13:54:49 by asumerag          #+#    #+#             */
/*   Updated: 2021/02/06 00:16:57 by asumerag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/cub3d.h"

static unsigned int	pixel_read(t_data *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	return (*(unsigned int*)dst);
}

static void			create_header(t_bmp_file *bmp_file)
{
	bmp_file->byte_type[0] = 0x42;
	bmp_file->byte_type[1] = 0x4D;
	bmp_file->byte_size = (4 * g_map.x * g_map.y) + 54;
	bmp_file->byte_reserved[0] = 0;
	bmp_file->byte_reserved[1] = 0;
	bmp_file->byte_offset = 54;
	bmp_file->header_size = 40;
	bmp_file->width = g_map.x;
	bmp_file->height = -g_map.y;
	bmp_file->planes = 1;
	bmp_file->bits_per_pixel = 32;
	bmp_file->compression = 0;
	bmp_file->image_size = (g_map.x * g_map.y) * 4 + 54;
	bmp_file->bits_xpels_per_meter = 0;
	bmp_file->bits_xpels_per_meter = 0;
	bmp_file->total_colors = 0;
	bmp_file->important_colors = 0;
}

static void			write_header(int fd, t_bmp_file bmp_file)
{
	write(fd, &bmp_file.byte_type, 2);
	write(fd, &bmp_file.byte_size, 4);
	write(fd, &bmp_file.byte_reserved, 4);
	write(fd, &bmp_file.byte_offset, 4);
	write(fd, &bmp_file.header_size, 4);
	write(fd, &bmp_file.width, 4);
	write(fd, &bmp_file.height, 4);
	write(fd, &bmp_file.planes, 2);
	write(fd, &bmp_file.bits_per_pixel, 2);
	write(fd, &bmp_file.compression, 4);
	write(fd, &bmp_file.image_size, 4);
	write(fd, &bmp_file.bits_xpels_per_meter, 4);
	write(fd, &bmp_file.bits_ypels_per_meter, 4);
	write(fd, &bmp_file.total_colors, 4);
	write(fd, &bmp_file.important_colors, 4);
}

void				bmp(void)
{
	t_bmp_file		bmp_file;
	int				w;
	int				h;
	int				fd;
	unsigned int	dst;

	if (!(fd = open("cub3D.bmp", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU)))
		error_processing(3);
	create_header(&bmp_file);
	write_header(fd, bmp_file);
	w = 0;
	h = 0;
	while (h < g_map.y)
	{
		w = 0;
		while (w < g_map.x)
		{
			dst = pixel_read(&g_img, w, h);
			write(fd, &dst, 4);
			w++;
		}
		h++;
	}
	close(fd);
}
