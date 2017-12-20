/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 16:37:32 by ikarishe          #+#    #+#             */
/*   Updated: 2017/12/08 16:25:41 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fdf.h"

void	pixel_steps(t_line *line)
{
	if (line->distance > 0)
	{
		line->r_step = (((line->p2.color >> 16) & 0xFF) -
				((line->p1.color >> 16) & 0xFF)) / line->distance;
		line->g_step = (((line->p2.color >> 8) & 0xFF) -
				((line->p1.color >> 8) & 0xFF)) / line->distance;
		line->b_step = ((line->p2.color & 0xFF) -
				(line->p1.color & 0xFF)) / line->distance;
	}
	else
	{
		line->r_step = 0;
		line->g_step = 0;
		line->b_step = 0;
	}
}

int		pixel_color(t_line *line)
{
	int r_temp;
	int g_temp;
	int b_temp;

	r_temp = ((line->p1.color >> 16) & 0xFF);
	g_temp = ((line->p1.color >> 8) & 0xFF);
	b_temp = (line->p1.color & 0xFF);
	line->p_color = ((int)(r_temp + (line->r_step * line->mult)) * 65536) +
			((int)(g_temp + line->g_step * line->mult) * 256) +
			(int)(b_temp + line->b_step * line->mult);
	line->mult = line->mult + 1;
	if (line->p_color < 0)
		line->p_color = line->p2.color;
	return (line->p_color);
}
