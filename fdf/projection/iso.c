/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:06:35 by marigome          #+#    #+#             */
/*   Updated: 2024/09/11 14:52:46 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/* La proyección isométrica es una forma de representar un objeto tridimensional en un plano 2D, 
manteniendo la relación de los ángulos entre los ejes. 
Para la proyección isométrica, las coordenadas 3D (x, y, z) 
se transforman en coordenadas 2D (x', y') usando las siguientes fórmulas: */

void    iso_projection(int *x, int *y, int z, t_cam *cam)
{
    int prev_x;
    int prev_y;

    prev_x = *x;
    prev_y = *y;

    // Proyección //
    *x = (prev_x - prev_y) * cos(M_PI / 6);
    *y = (prev_x + prev_y) * cos(M_PI / 6) - z * cam->z_height;
}

void    put_pixel(mlx_image_t *image, int x, int y, uint32_t color)
{
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
        ((uint32_t *)image->pixels)[y * WIDTH + x] = color;
}

void	init_bresenham(t_point start, t_point end, t_bresenham *bres)
{
	bres->dx = abs(end.x - start.x);
	bres->dy = abs(end.y - start.y);
	bres->sx = (start.x < end.x) ? 1 : -1;
	bres->sy = (start.y < end.y) ? 1 : -1;
	bres->err = (bres->dx > bres->dy ? bres->dx : -bres->dy) / 2;
}


void    put_line_pixels(t_fdf *fdf, t_point start, t_point end, t_bresenham *bres)
{
    int e2;

    while (1)
    {
        put_pixel(fdf->image, start.x, start.y, start.color);
        if (start.x == end.x && start.y == end.y)
            break ;
        e2 = bres->err;
        if (e2 > -bres->dx)
        {
            bres->err -= bres->dy;
            start.x += bres->sx;
        }
        if (e2 < bres->dy)
        {
            bres->err += bres->dx;
            start.y += bres->sy;
        }
    }
}

void    draw_line(t_fdf *fdf, t_point start, t_point end)
{
    t_bresenham bres;

    init_bresenham(start, end, &bres);
    put_line_pixels(fdf, start, end, &bres);
}