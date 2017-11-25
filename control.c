/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:10:36 by ikarishe          #+#    #+#             */
/*   Updated: 2017/11/25 15:12:55 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "minilibx/mlx.h"
#include <stdio.h>
#include <math.h>

void	set_scale(t_info *info, t_position **map, t_position **map_o)
{
	int j;

	j = 0;
	(void)info;
	if (*info->scale > 0)
	{
		while (j < (info->dim->x * info->dim->y))
		{
			(*map)[j].x = (*map_o)[j].x * *info->scale;
			(*map)[j].y = (*map_o)[j].y * *info->scale;
			(*map)[j].z = (((*map_o)[j].z * *info->scale) / info->z_scale);
			j++;
		}
	}
}

void	rotate_z_right(t_info *info, t_position **map, t_position **map_o, double theta)
{
	int j;
	double s = sin(theta);
	double c = cos(theta);
	j = 0;
	int centx;
	int centy;

	centx = info->dim->x * *info->scale / 2;
	centy = info->dim->y * *info->scale / 2;

	(void)info;
	(void)map_o;
	while (j < (info->dim->x * info->dim->y))
	{
		(*map)[j].x = (*map)[j].x - centx;
		(*map)[j].y = (*map)[j].y - centy;
		int xnew = (*map)[j].x * c - (*map)[j].y * s;
		int ynew = (*map)[j].y * c + (*map)[j].x * s;
		(*map)[j].x = xnew + centx;
		(*map)[j].y = ynew + centy;
		j++;
	}
}

void	rotate_x_right(t_info *info, t_position **map, t_position **map_o, double theta)
{
	int j;
	double s = sin(theta);
	double c = cos(theta);
	j = 0;

	int centy;
	centy = info->dim->y * *info->scale / 2;

	(void)info;
	(void)map_o;
	while (j < (info->dim->x * info->dim->y))
	{
		(*map)[j].y = (*map)[j].y  - centy;
		int ynew = (*map)[j].y * c - (*map)[j].z * s;
		int znew = (*map)[j].y * s + (*map)[j].z * c;
		(*map)[j].y = ynew + centy;
		(*map)[j].z = znew;
		j++;
	}
}

void    rotate_y_right(t_info *info, t_position **map, t_position **map_o, double theta)
{
	int j;
	double s = sin(theta);
	double c = cos(theta);
	j = 0;

	int centx;
	centx = info->dim->x * *info->scale / 2;

	(void)info;
	(void)map_o;
	while (j < (info->dim->x * info->dim->y))
	{
		(*map)[j].x = (*map)[j].x  - centx;
		int znew = (*map)[j].z * c - (*map)[j].x * s;
		int xnew = (*map)[j].z * s + (*map)[j].x * c;
		(*map)[j].x = xnew + centx;
		(*map)[j].z = znew;
		j++;
	}
}

int     my_loop_hook(t_info *info)
{
	(void)info;
	if (info->theta_z >= 360)
		info->theta_z = 0;
	if (info->theta_x >= 360)
		info->theta_x = 0;
	if (info->theta_y >= 360)
		info->theta_y = 0;
	if (info->spin == 1)
		info->theta_z = info->theta_z + 1;
	if (info->spin2 == 1)
		info->theta_x = info->theta_x + 1;
	if (info->spin3 == 1)
		info->theta_y = info->theta_y + 1;
//	printf("(%d, %d, %d)\n", info->theta_z, info->theta_x, info->theta_y);
	draw_all(*info->mlx, *info->win, *info->map, info->dim, *info->center, info);
//	my_key_funct(65, info);

	return (0);
}

int		my_key_funct(int keycode, t_info *info)
{
	(void)info;
//	printf("key event %d\n", keycode);
	if (keycode == 65)
		return (0);
	if (keycode == 69)
		*info->scale += 1;
	else if (keycode == 78)
		*info->scale -= 1;
	if (keycode == 91)
		info->center->y = info->center->y - 10;
	else if (keycode == 84)
		info->center->y = info->center->y + 10;
	else if (keycode == 86)
		info->center->x = info->center->x - 10;
	else if (keycode == 88)
		info->center->x = info->center->x + 10;
	else if (keycode == 92)
	{	
		info->theta_z = info->theta_z + 10;
		if (info->theta_z > 359)
			info->theta_z = 0;
	}
	else if (keycode == 85)
	{
		info->theta_x = info->theta_x + 10;
		if (info->theta_x > 359)
			info->theta_x = 0;
	}
	else if (keycode == 89)
	{
		info->theta_y = info->theta_y + 10;
		if (info->theta_y > 359)
			info->theta_y = 0;
	}
	else if (keycode == 87)
		info->spin = 1;
	else if (keycode == 82)
		info->spin = 0;
	else if (keycode == 116)
		info->spin2 = 1;
	else if (keycode == 121)
		info->spin2 = 0;
	else if (keycode == 115)
		info->spin3 = 1;
	else if (keycode == 119)
		info->spin3 = 0;
	else if (keycode == 75)
		info->z_scale = info->z_scale + 1;
	else if (keycode == 67)
	{
		if (info->z_scale > 1)
			info->z_scale = info->z_scale - 1;
	}
	else if (keycode == 53)
		exit(0);
	return (0);
}
