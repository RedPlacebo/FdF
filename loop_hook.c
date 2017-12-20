/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:39:29 by ikarishe          #+#    #+#             */
/*   Updated: 2017/12/08 16:25:12 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		my_loop_hook(t_info *info)
{
	info->data->theta_z = info->data->theta_z + info->data->spin_z;
	if ((info->data->theta_z > 359) || (info->data->theta_z < 1))
		info->data->theta_z = 0;
	info->data->theta_y = info->data->theta_y + info->data->spin_y;
	if ((info->data->theta_y > 359) || (info->data->theta_y < 1))
		info->data->theta_y = 0;
	info->data->theta_x = info->data->theta_x + info->data->spin_x;
	if ((info->data->theta_x > 359) || (info->data->theta_x < 1))
		info->data->theta_x = 0;
	draw_all(info);
	return (0);
}
