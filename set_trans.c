/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_trans.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 14:43:53 by ikarishe          #+#    #+#             */
/*   Updated: 2017/12/05 15:16:22 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	trans_x(t_info *info, int scale)
{
	info->data->trans_x += scale;
}

void	trans_y(t_info *info, int scale)
{
	info->data->trans_y += scale;
}

void	translate_world(t_info *info, t_pos **map_t)
{
	int j;

	j = 0;
	while (j < (info->dim->x * info->dim->y))
	{
		(*map_t)[j].x = (*map_t)[j].x + info->data->trans_x;
		(*map_t)[j].y = (*map_t)[j].y + info->data->trans_y;
		j++;
	}
}
