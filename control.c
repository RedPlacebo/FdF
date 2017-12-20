/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:26:47 by ikarishe          #+#    #+#             */
/*   Updated: 2017/12/05 14:37:06 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	control_scale(int keycode, t_info *info)
{
	if (keycode == 279)
		scale_x(info, 1);
	if (keycode == 115)
		scale_y(info, 1);
	if (keycode == 116)
		scale_z(info, 1);
	if (keycode == 117)
		scale_x(info, -1);
	if (keycode == 119)
		scale_y(info, -1);
	if (keycode == 121)
		scale_z(info, -1);
}

void	control_trans(int keycode, t_info *info)
{
	if (keycode == 123)
		trans_x(info, -10);
	if (keycode == 124)
		trans_x(info, 10);
	if (keycode == 126)
		trans_y(info, -10);
	if (keycode == 125)
		trans_y(info, 10);
}

void	control_rotation(int keycode, t_info *info)
{
	if (keycode == 86 || keycode == 88)
		rotate_z(keycode, info);
	if (keycode == 87 || keycode == 84)
		rotate_x(keycode, info);
	if (keycode == 83 || keycode == 85)
		rotate_y(keycode, info);
}

void	toggle_spin(int keycode, t_info *info)
{
	if (keycode == 71)
		info->data->spin_z = 1;
	if (keycode == 81)
		info->data->spin_y = 1;
	if (keycode == 75)
		info->data->spin_x = 1;
	if (keycode == 89)
		info->data->spin_z = 0;
	if (keycode == 91)
		info->data->spin_y = 0;
	if (keycode == 92)
		info->data->spin_x = 0;
	if (keycode == 106)
		info->data->spin_z = -1;
	if (keycode == 64)
		info->data->spin_y = -1;
	if (keycode == 79)
		info->data->spin_x = -1;
}

int		my_key_funct(int keycode, t_info *info)
{
	if (keycode == 53)
	{
		mlx_destroy_window(info->mlx, info->win);
		exit(0);
	}
	if (keycode == 279 || keycode == 115 || keycode == 116
			|| keycode == 117 || keycode == 119 || keycode == 121)
		control_scale(keycode, info);
	if (keycode == 123 || keycode == 124 || keycode == 126 || keycode == 125)
		control_trans(keycode, info);
	if (keycode == 86 || keycode == 87 || keycode == 88 ||
			keycode == 83 || keycode == 84 || keycode == 85)
		control_rotation(keycode, info);
	if (keycode == 71 || keycode == 81 || keycode == 75 ||
			keycode == 89 || keycode == 91 || keycode == 92 ||
			keycode == 106 || keycode == 64 || keycode == 79)
		toggle_spin(keycode, info);
	return (0);
}
