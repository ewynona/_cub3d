/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_c_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asumerag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 14:29:58 by asumerag          #+#    #+#             */
/*   Updated: 2021/02/06 14:33:47 by asumerag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/cub3d.h"

void	check_floor_ceil(char *line)
{
	int	i;
	int	check;

	i = 1;
	check = 0;
	while (line[i])
	{
		while (line[i] == ' ' || line[i] == ',')
			i++;
		while (line[i] >= '0' && line[i] <= '9')
			i++;
		while (line[i] == ' ' || line[i] == ',')
			i++;
		if ((line[i] >= '0' && line[i] <= '9') || line[i] == '\0')
			check++;
		else
			error_processing(3);
	}
	if (check != 3)
		error_processing(3);
}
