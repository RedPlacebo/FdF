/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_rotation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:04:54 by ikarishe          #+#    #+#             */
/*   Updated: 2017/12/05 16:12:12 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	apply_z_rotation(t_info *info, t_pos **map_t)
{
	int		j;
	t_rot	rot;

	rot.s = sin(info->data->theta_z * M_PI / 180);
	rot.c = cos(info->data->theta_z * M_PI / 180);
	rot.centx = info->dim->x * info->data->scale_x / 2;
	rot.centy = info->dim->y * info->data->scale_y / 2;
	j = 0;
	while (j < (info->dim->x * info->dim->y))
	{
		(*map_t)[j].x = (*map_t)[j].x - rot.centx;
		(*map_t)[j].y = (*map_t)[j].y - rot.centy;
		rot.xnew = (*map_t)[j].x * rot.c - (*map_t)[j].y * rot.s;
		rot.ynew = (*map_t)[j].y * rot.c + (*map_t)[j].x * rot.s;
		(*map_t)[j].x = rot.xnew + rot.centx;
		(*map_t)[j].y = rot.ynew + rot.centy;
		j++;
	}
}

void	apply_x_rotation(t_info *info, t_pos **map_t)
{
	int		j;
	t_rot	rot;

	rot.s = sin(info->data->theta_x * M_PI / 180);
	rot.c = cos(info->data->theta_x * M_PI / 180);
	rot.centy = info->dim->y * info->data->scale_y / 2;
	j = 0;
	while (j < (info->dim->x * info->dim->y))
	{
		(*map_t)[j].y = (*map_t)[j].y - rot.centy;
		rot.ynew = (*map_t)[j].y * rot.c - (*map_t)[j].z * rot.s;
		rot.znew = (*map_t)[j].y * rot.s + (*map_t)[j].z * rot.c;
		(*map_t)[j].y = rot.ynew + rot.centy;
		(*map_t)[j].z = rot.znew;
		j++;
	}
}

void	apply_y_rotation(t_info *info, t_pos **map_t)
{
	int		j;
	t_rot	rot;

	rot.s = sin(info->data->theta_y * M_PI / 180);
	rot.c = cos(info->data->theta_y * M_PI / 180);
	rot.centx = info->dim->x * info->data->scale_x / 2;
	j = 0;
	while (j < (info->dim->x * info->dim->y))
	{
		(*map_t)[j].x = (*map_t)[j].x - rot.centx;
		rot.znew = (*map_t)[j].z * rot.c - (*map_t)[j].x * rot.s;
		rot.xnew = (*map_t)[j].z * rot.s + (*map_t)[j].x * rot.c;
		(*map_t)[j].x = rot.xnew + rot.centx;
		(*map_t)[j].z = rot.znew;
		j++;
	}
}
