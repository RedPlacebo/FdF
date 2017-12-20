/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:01:47 by ikarishe          #+#    #+#             */
/*   Updated: 2017/12/08 19:05:31 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Bresenham Line Drawing algorithm. Finds the slope of the line to be drawn
** Goes from p1.x to p2.x, deciding if the next pixel should be placed above,
** below, or on the same line as the previous.
**
** Full explanation and pseudocode:
** https://csustan.csustan.edu/~tom/Lecture-Notes/Graphics/Bresenham-Line/
** 		Bresenham-Line.pdf
*/

#include "fdf.h"
#include <stdio.h>

void	setstep(t_pos *dxdy, t_pos *stepxy)
{
	if (dxdy->y < 0)
	{
		dxdy->y = -(dxdy->y);
		stepxy->y = -1;
	}
	if (dxdy->x < 0)
	{
		dxdy->x = -(dxdy->x);
		stepxy->x = -1;
	}
	dxdy->y = dxdy->y * 2;
	dxdy->x = dxdy->x * 2;
}

void	setcolor(t_pos *p1, t_pos *p2, t_line *line)
{
	if (p1->color >= p2->color)
		line->p_color = p1->color;
	else
		line->p_color = p2->color;
	line->distance = sqrt(pow(fabs(line->p1.x - line->p2.x), 2) +
			(pow(fabs(line->p1.y - line->p2.y), 2)));
	pixel_steps(line);
}

void	put_side(t_info *info, t_pos *dxdy, t_pos *stepxy, t_line *line)
{
	int fraction;

	fraction = dxdy->y - (dxdy->x * 2);
	while (line->p1.x != line->p2.x)
	{
		line->p1.x = line->p1.x + stepxy->x;
		if (fraction >= 0)
		{
			line->p1.y = line->p1.y + stepxy->y;
			fraction = fraction - dxdy->x;
		}
		fraction = fraction + dxdy->y;
		mlx_pixel_put(info->mlx, info->win, (int)line->p1.x,
				(int)line->p1.y, pixel_color(line));
	}
}

void	put_up(t_info *info, t_pos *dxdy, t_pos *stepxy, t_line *line)
{
	int fraction;

	fraction = dxdy->x - (dxdy->y * 2);
	while ((int)line->p1.y != (int)line->p2.y)
	{
		if (fraction >= 0)
		{
			line->p1.x = (int)line->p1.x + (int)stepxy->x;
			fraction = fraction - dxdy->y;
		}
		line->p1.y = (int)line->p1.y + (int)stepxy->y;
		fraction = fraction + (int)dxdy->x;
		mlx_pixel_put(info->mlx, info->win, (int)line->p1.x,
				(int)line->p1.y, pixel_color(line));
	}
}

void	draw_line(t_info *info, t_pos *p1, t_pos *p2)
{
	t_pos	dxdy;
	t_pos	stepxy;
	t_line	line;

	line.p1 = *p1;
	line.p2 = *p2;
	line.mult = 1;
	dxdy.x = p2->x - p1->x;
	dxdy.y = p2->y - p1->y;
	stepxy.x = 1;
	stepxy.y = 1;
	setstep(&dxdy, &stepxy);
	setcolor(p1, p2, &line);
	mlx_pixel_put(info->mlx, info->win, (int)p1->x,
			(int)p1->y, pixel_color(&line));
	if (dxdy.x > dxdy.y)
		put_side(info, &dxdy, &stepxy, &line);
	else
		put_up(info, &dxdy, &stepxy, &line);
}
