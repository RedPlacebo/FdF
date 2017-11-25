/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:09:03 by ikarishe          #+#    #+#             */
/*   Updated: 2017/11/20 15:45:01 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "minilibx/mlx.h"

void draw_line(void *mlx, void *win, t_position p1, t_position p2, t_position center)
{
    int dx;
    int dy;
    int stepx;
    int stepy;
    int fraction;

    dx = p2.x - p1.x;
    dy = p2.y - p1.y;
    stepy = 1;
    stepx = 1;
    if (dy < 0)
    {
        dy = -dy;
        stepy = -1;
    }
    if (dx < 0)
    {
        dx = -dx;
        stepx = -1;
    }
    dy <<= 1;
    dx <<= 1;
    //if (in drawing range)
    mlx_pixel_put(mlx, win, p1.x + center.x, p1.y + center.y, 0x00FFFF00);
    if (dx > dy)
    {
        fraction = dy - (dx >> 1);
        while (p1.x != p2.x)
        {
            p1.x = p1.x + stepx;
            if (fraction >= 0)
            {
                p1.y = p1.y + stepy;
                fraction = fraction - dx;
            }
            fraction = fraction + dy;
            //if (in drawing range)
            mlx_pixel_put(mlx, win, p1.x + center.x, p1.y + center.y, 0x00FF00FF);
        }
    }
    else
    {
        fraction = dx - (dy >> 1);
        while (p1.y != p2.y)
        {
            if (fraction >= 0)
            {
                p1.x = p1.x + stepx;
                fraction = fraction - dy;
            }
        p1.y = p1.y + stepy;
        fraction = fraction + dx;
        //if (in drawing range)
        mlx_pixel_put(mlx, win, p1.x + center.x, p1.y + center.y, 0x0000FFFF);
        }
    }
}
