/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asumerag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 16:29:16 by asumerag          #+#    #+#             */
/*   Updated: 2021/02/06 14:30:52 by asumerag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <math.h>
# include "../lib/minilibx_mms_20200219/mlx.h"
# include <stdio.h>
# include "../lib/libft/libft.h"
# include "gnl.h"
# include <fcntl.h>

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53
# define KEY_LEFT 123
# define KEY_RIGHT 124

typedef struct	s_data {
	void	*win;
	void	*mlx;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		en;
}				t_data;

typedef struct	s_ray {
	double	x;
	double	y;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	double	camerax;
	double	dx;
	double	dy;
	double	start;
	double	end;
	double	dist;
	int		wall_height;
	int		mapx;
	int		mapy;
	int		hit;
	int		side;
	int		stepx;
	int		stepy;
}				t_ray;

typedef struct	s_plr {
	double	x;
	double	y;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
}				t_plr;

typedef struct	s_map {
	int		x;
	int		y;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*sprite;
	int		floor;
	int		ceiling;
	char	**map;
	int		lines;
}				t_map;

typedef struct	s_texture {
	void	*img;
	void	*addr;
	int		bpp;
	int		line_len;
	int		en;
	int		w;
	int		h;
}				t_texture;

typedef struct	s_sprite {
	int			x;
	int			y;
	int			id;
	int			dist;
}				t_sprite;

typedef struct	s_drw_sprite {
	double	invdet;
	double	x;
	double	y;
	double	transformx;
	double	transformy;
	double	tex_x;
	double	tex_y;
	int		screen;
	int		height;
	int		width;
	int		start_x;
	int		end_x;
	int		start_y;
	int		end_y;
}				t_drw_sprite;

typedef struct	s_poles {
	t_texture west;
	t_texture east;
	t_texture south;
	t_texture north;
	t_texture sprite;
}				t_poles;

typedef struct	s_bmp_file
{
	char			byte_type[2];
	unsigned int	byte_size;
	unsigned int	byte_reserved[0];
	unsigned int	byte_offset;
	unsigned int	header_size;
	int				width;
	int				height;
	unsigned short	planes;
	unsigned short	bits_per_pixel;
	unsigned int	compression;
	unsigned int	image_size;
	int				bits_xpels_per_meter;
	int				bits_ypels_per_meter;
	unsigned int	total_colors;
	unsigned int	important_colors;
}				t_bmp_file;

t_map			g_map;
t_data			g_img;
t_plr			g_plr;
t_ray			g_ray;
t_poles			g_poles;
t_sprite		*g_sprite;
t_drw_sprite	g_drw_sprite;
int				g_save;

void			sprite_rend(int p_len);
void			map_init(void);
void			cub_parser(int fd);
int				map_entry(char *line);
void			map_elements(char *line, int fd);
void			parse_texture(char *line);
int				color_fl_ce(int *color, char *line);
void			parse_fc(char *line);
void			map_check(int size);
void			map_border(char *str);
void			ft_map(t_list *tmp);
void			map_parser(char *line, int fd);
void			error_processing(int var);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
unsigned int	my_mlx_pixel_read(t_texture *data, int x, int y);
void			plr_init(void);
void			poles_init(void);
void			sprite_sort(void);
void			sprite_pictures(double *zbuffer);
void			raycasting(void);
int				key_hook(int keycode);
void			bmp(void);
void			map_init(void);
void			check_screen_size(void);
void			free_all(void);
int				close_win(void);
void			move_right_left(int keycode, double step);
void			move_up_down(int keycode, double step);
void			turn(int keycode, double step);
void			pillar_drawing(t_texture image, int screen_x);
double			tex_x_init(t_texture image);
t_texture		wall_texture(void);
void			find_wall(void);
void			check_floor_ceil(char *line);
void			delta_side(int screen_x);

#endif
