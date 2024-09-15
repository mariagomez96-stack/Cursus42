/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:39:32 by marigome          #+#    #+#             */
/*   Updated: 2024/09/15 10:15:54 by marigome         ###   ########.fr       */
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

void	ft_draw(t_map *map, t_fdf *fdf)
{
	int	x;
	int	y;

	mlx_delete_image(fdf->mlx, fdf->image);
	fdf->image = mlx_new_image(fdf->mlx, fdf->win_width, fdf->win_height);
	y = 0;
	if (fdf->cam->x_ang > 0)
		y = map->lines - 1;
	while (y < map->lines && y >= 0)
	{
		x = 0;
		if (fdf->cam->y_ang > 0)
			x = map->columns - 1;
		while (x < map->columns && x >= 0)
		{
			if (x != map->columns - 1)
				src_draw_x(x, y, fdf);
			if (y != map->lines - 1)
				src_draw_y(x, y, fdf);
			x += -2 * (fdf->cam->y_ang > 0) + 1;
		}
		y += -2 * (fdf->cam->x_ang > 0) + 1;
	}
	mlx_image_to_window(fdf->mlx, fdf->image, 0, 0);
}

t_point	project(int x, int y, t_fdf *fdf)
{
	t_point	point;
	int		z;
	int		iso_x;
	int		iso_y;

	z = fdf->map->map[y][x][0];
	point.x = (x - fdf->map->columns / 2) * fdf->cam->zoom;
	point.y = (y - fdf->map->lines / 2) * fdf->cam->zoom;
	z = z * fdf->cam->z_height;
	iso_x = (point.x - point.y) * cos(0.523599);
	iso_y = (point.x + point.y) * sin(0.523599) - z;
	point.x = iso_x + fdf->cam->x_offset;
	point.y = iso_y + fdf->cam->y_offset;
	if (fdf->map->map[y][x][1] >= 0)
		point.color = fdf->map->map[y][x][1];
	else
		point.color = ft_get_default_color(fdf->map->map[y][x][0], fdf->map);
	return (point);
}
