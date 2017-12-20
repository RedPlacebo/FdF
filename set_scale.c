/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_scale.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 13:27:52 by ikarishe          #+#    #+#             */
/*   Updated: 2017/12/08 18:51:53 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	scale_x(t_info *info, int scale)
{
	info->data->scale_x += scale;
}

void	scale_y(t_info *info, int scale)
{
	info->data->scale_y += scale;
}

void	scale_z(t_info *info, int scale)
{
	info->data->scale_z += scale;
}

void	set_scale(t_info *info, t_pos **map_o, t_pos **map_t)
{
	int j;

	j = 0;
	while (j < (info->dim->x * info->dim->y))
	{
		(*map_t)[j].x = (*map_o)[j].x * info->data->scale_x;
		(*map_t)[j].y = (*map_o)[j].y * info->data->scale_y;
		(*map_t)[j].z = (*map_o)[j].z * info->data->scale_z;
		j++;
	}
}
