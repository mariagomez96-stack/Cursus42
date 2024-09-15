/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:39:32 by marigome          #+#    #+#             */
/*   Updated: 2024/09/15 18:47:19 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	src_draw_x(int x, int y, t_fdf *fdf)
{
	t_point	p1;
	t_point	p2;

	p1 = project(x, y, fdf);
	p2 = project(x + 1, y, fdf);
	ft_draw_line(p1, p2, fdf);
}

static void	src_draw_y(int x, int y, t_fdf *fdf)
{
	t_point	p1;
	t_point	p2;

	p1 = project(x, y, fdf);
	p2 = project(x, y + 1, fdf);
	ft_draw_line(p1, p2, fdf);
}

void	ft_draw(t_map *map, t_fdf *rol)
{
	int	x;
	int	y;

	mlx_delete_image(rol->mlx, rol->image);
	rol->image = mlx_new_image(rol->mlx, rol->win_width, rol->win_height);
	y = 0;
	if (rol->cam->x_ang > 0)
		y = map->lines - 1;
	while (y < map->lines && y >= 0)
	{
		x = 0;
		if (rol->cam->y_ang > 0)
			x = map->columns - 1;
		while (x < map->columns && x >= 0)
		{
			if (x != map->columns - 1)
				src_draw_x(x, y, rol);
			if (y != map->lines - 1)
				src_draw_y(x, y, rol);
			x += -2 * (rol->cam->y_ang > 0) + 1;
		}
		y += -2 * (rol->cam->x_ang > 0) + 1;
	}
	mlx_image_to_window(rol->mlx, rol->image, 0, 0);
}

/*t_point	project(int x, int y, t_fdf *rol)
{
	t_point	point;
	int		z;
	int		x_new;
	int		y_new;

	z = rol->map->map[y][x][0];
	point.x = (x - rol->map->columns / 2) * rol->cam->zoom;
	point.y = (y - rol->map->lines / 2) * rol->cam->zoom;
	z = z * rol->cam->z_height;
	x_new = (point.x - point.y) * cos(0.523599);
	y_new = (point.x + point.y) * sin(0.523599) - z;
	point.x = x_new + rol->cam->x_offset;
	point.y = y_new + rol->cam->y_offset;
	if (rol->map->map[y][x][1] >= 0)
		point.color = rol->map->map[y][x][1];
	else
	{
		point.color = ft_get_default_color(rol->map->map[y][x][0], \
		rol->map);
	}
	return (point);
}*/

t_point	project(int x, int y, t_fdf *rol)
{
	t_point	point;
	int		z;
	int		x_new;
	int		y_new;

	// Obtener el valor de z (altura)
	z = rol->map->map[y][x][0];

	// Calcular las nuevas coordenadas con base en el ángulo y zoom
	point.x = (x - rol->map->columns / 2) * rol->cam->zoom;
	point.y = (y - rol->map->lines / 2) * rol->cam->zoom;
	z = z * rol->cam->z_height;

	x_new = (point.x - point.y) * cos(0.523599); // Aplicar la proyección
	y_new = (point.x + point.y) * sin(0.523599) - z;

	point.x = x_new + rol->cam->x_offset;
	point.y = y_new + rol->cam->y_offset;

	// Asignar el color en función de la altura z si no tiene un color predefinido
	if (rol->map->map[y][x][1] >= 0)
		point.color = rol->map->map[y][x][1];
	else
	{
		point.color = ft_get_default_color(rol->map->map[y][x][0], rol->map);
	}

	return (point);
}

