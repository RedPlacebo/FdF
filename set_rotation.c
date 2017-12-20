/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rotation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 15:47:36 by ikarishe          #+#    #+#             */
/*   Updated: 2017/12/08 16:23:33 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		rotate_z(int keycode, t_info *info)
{
	if (keycode == 86)
	{
		info->data->theta_z = info->data->theta_z - 1;
		if (info->data->theta_z < 0)
			info->data->theta_z = 359;
	}
	else if (keycode == 88)
	{
		info->data->theta_z = info->data->theta_z + 1;
		if (info->data->theta_z > 359)
			info->data->theta_z = 0;
	}
}

void		rotate_x(int keycode, t_info *info)
{
	if (keycode == 87)
	{
		info->data->theta_x = info->data->theta_x - 1;
		if (info->data->theta_x < 0)
			info->data->theta_x = 359;
	}
	else if (keycode == 84)
	{
		info->data->theta_x = info->data->theta_x + 1;
		if (info->data->theta_x > 359)
			info->data->theta_x = 0;
	}
}

void		rotate_y(int keycode, t_info *info)
{
	if (keycode == 83)
	{
		info->data->theta_y = info->data->theta_y - 1;
		if (info->data->theta_y < 0)
			info->data->theta_y = 359;
	}
	else if (keycode == 85)
	{
		info->data->theta_y = info->data->theta_y + 1;
		if (info->data->theta_y > 359)
			info->data->theta_y = 0;
	}
}

void		rotate_world(t_info *info, t_pos **map_t)
{
	apply_z_rotation(info, map_t);
	apply_x_rotation(info, map_t);
	apply_y_rotation(info, map_t);
}
