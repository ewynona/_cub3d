/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asumerag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 02:00:43 by asumerag          #+#    #+#             */
/*   Updated: 2021/02/06 02:01:56 by asumerag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/cub3d.h"

int	key_hook(int keycode)
{
	move_up_down(keycode, 0.2);
	move_right_left(keycode, 0.2);
	turn(keycode, M_PI / 36);
	if (keycode == KEY_ESC)
		exit(1);
	raycasting();
	return (0);
}

int	close_win(void)
{
	exit(1);
	return (0);
}
