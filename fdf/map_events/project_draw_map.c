/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_draw_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:51:57 by marigome          #+#    #+#             */
/*   Updated: 2024/09/10 14:57:24 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	project_point(t_point *point, t_cam *cam)
{
	int	previous_x;
	int	previous_y;

	previous_x = point->x;
	previous_y = point->y;
	point->x = (previous_x - previous_y) * cos(M_PI / 6) + cam->x_offset;
	point->y = (previous_x + previous_y) * sin(M_PI / 6) - point->z * cam->z_height + cam->y_offset;
}

void	draw_map_line(t_fdf *fdf, t_point start, t_point end)
{
	project_point(&start, fdf->cam);
	project_point(&end, fdf->cam);
	draw_line(fdf, start, end);  // Llamada a la función de Bresenham
}

void	draw_horizontal_lines(t_fdf *fdf, int y)
{
	t_point start;
	t_point end;
	int x;

    x = 0;

	while (x < fdf->map->columns - 1)
	{
		start.x = x * fdf->cam->zoom;
		start.y = y * fdf->cam->zoom;
		start.z = fdf->map->map[y][x][1];
		start.color = 0xFFFFFF;

		end.x = (x + 1) * fdf->cam->zoom;
		end.y = y * fdf->cam->zoom;
		end.z = fdf->map->map[y][x + 1][1];

		draw_map_line(fdf, start, end);
        x++;
	}
}

void	draw_vertical_lines(t_fdf *fdf, int x)
{
	t_point start;
	t_point end;
	int y;

    y = 0;
	while (y < fdf->map->lines - 1)
	{
		start.x = x * fdf->cam->zoom;
		start.y = y * fdf->cam->zoom;
		start.z = fdf->map->map[y][x][1];
		start.color = 0xFFFFFF;

		end.x = x * fdf->cam->zoom;
		end.y = (y + 1) * fdf->cam->zoom;
		end.z = fdf->map->map[y + 1][x][1];

		draw_map_line(fdf, start, end);
        y++;
	}
}

void	project_and_draw_map(t_fdf *fdf)
{
	int	y;
	int	x;

    y = 0;
    x = 0;
	while (y < fdf->map->lines)
	{	
        draw_horizontal_lines(fdf, y);
        y++;
    }
	while (x < fdf->map->columns)
	{	
        draw_vertical_lines(fdf, x);
        x++;
    }
}


