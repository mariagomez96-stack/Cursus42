/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:52:37 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/09/11 14:52:42 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/**
 * The function "ft_draw" draw the map on the screen, managing the drawing 
 * process and updating the window.
 * 
 * @param t_map *map 				map to read.
 * @param t_fdf *rol 				rol instance created in fdf.c.
 * 
 * 
 * Thew function "ft_draw_grid" Loop through the map coordinates and call 
 * ft_draw_horizvert to draw the lines.
 * 
 * @param t_map *map 				map to read.
 * @param t_fdf *rol 				rol instance created in fdf.c.
 * 
 * The function "ft_draw_horizvert" They handle the logic of drawing horizontal
 * and vertical lines.
 * 
 * @param int x						x coordinate passed from ft_draw_grid.
 * @param int y						y coordinate passed from ft_draw_grid.
 * @param t_map *map				map to read.
 * @param t_fdf *rol				rol instance created in fdf.c.
 * 
 * 
 * The function "ft_draw_line" draw a line between two points.
 * 
 * @param t_point start				starting point.
 * @param t_point end				final point.
 * @param t_fdf *rol				rol instance created in fdf.c.
 * 
 * 
 * The function "ft_draw_line_params" xxx
 * 
 * @param t_point start				starting point.
 * @param t_point end				final point.
 * @param t_line_params *params		struct with data (delta, sign, error).
 * 
 * 
 */

typedef struct s_point1 {
	int x;
	int y;
} t_point1;

t_point	ft_project_iso(int x, int y, int z, t_fdf *rol)
{
	t_point	point;

	point.x = (x - y) * cos(0.523599);
	point.y = (x + y) * sin(0.523599) - z;
	// point.x = 50 * point.x + rol->cam->x_offset;
	// point.y = 50 * point.y + rol->cam->y_offset;
	point.x = point.x * rol->cam->zoom + rol->cam->x_offset;
	point.y = point.y * rol->cam->zoom + rol->cam->y_offset;
	return (point);
}

static void	ft_draw_line_params(t_point start, t_point end, \
t_line_params *params)
{
	params->delta[0] = abs(end.x - start.x);
	params->delta[1] = abs(end.y - start.y);
	if (start.x < end.x)
		params->sign[0] = 1;
	else
		params->sign[0] = -1;
	if (start.y < end.y)
		params->sign[1] = 1;
	else
		params->sign[1] = -1;
	params->error = params->delta[0] - params->delta[1];
}

void	ft_draw_line(t_point start, t_point end, t_fdf *rol)
{
	t_line_params	params;
	int				start_int[2];

	ft_draw_line_params(start, end, &params);
	while (start.x != end.x || start.y != end.y)
	{
		if (start.x >= 0 && start.x < DEF_WIDTH && start.y >= 0 \
		&& start.y < DEF_HEIGHT)
			mlx_put_pixel(rol->image, start.x, start.y, 0xFFFFFF);
		start_int[0] = start.x;
		start_int[1] = start.y;
		bresenham(start_int, &params.error, params.delta, params.sign);
		start.x = start_int[0];
		start.y = start_int[1];
	}
	if (start.x >= 0 && start.x < DEF_WIDTH && start.y >= 0 \
	&& start.y < DEF_HEIGHT)
		mlx_put_pixel(rol->image, start.x, start.y, 0xFFFFFF);
}

void	ft_draw_horizvert(int x, int y, t_map *map, t_fdf *rol)
{
	t_point	p1;
	t_point	p2;

	p1 = ft_project_iso(x, y, map->columns[y][x][0], rol);
	if (x + 1 < map->columns)
	{
		p2 = ft_project_iso(x + 1, y, map->map[y][x + 1][0], rol);
		ft_draw_line(p1, p2, rol);
	}
	if (y + 1 < map->columns)
	{
		p2 = ft_project_iso(x, y + 1, map->map[y + 1][x][0], rol);
		ft_draw_line(p1, p2, rol);
	}
}

void	ft_draw_grid(t_map *map, t_fdf *rol)
{
	int		x;
	int		y;

	y = 0;
	while (y < map->lines)
	{
		x = 0;
		while (x < map->columns)
		{
			ft_draw_horizvert(x, y, map, rol);
			x++;
		}
		y++;
	}
}

void	ft_draw(t_map *map, t_fdf *rol)
{
	ft_printf(ORANGE "Starting " RESET GREEN "drawing process...\n");
	ft_draw_grid(map, rol);
	if (mlx_image_to_window(rol->mlx, rol->image, 0, 0) == -1)
	{
		ft_printf("Error updating image to window\n");
		mlx_terminate(rol->mlx);
		ft_error("Error de imagen");
	}
	ft_printf(ORANGE "Drawing completed. " RESET GREEN "Image updated to" \
	GREEN " window successfully.\n" RESET);
}
