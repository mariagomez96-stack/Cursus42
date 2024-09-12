/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:39:32 by marigome          #+#    #+#             */
/*   Updated: 2024/09/12 16:24:13 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*static void	ft_rotate_x(int *y, int *z, double x_angle)
{
	int	prev_y;

	prev_y = *y;
	*y = prev_y * cos(x_angle) + *z * sin(x_angle);
	*z = prev_y * -sin(x_angle) + *z * cos(x_angle);
}

static void	ft_rotate_y(int *x, int *z, double y_angle)
{
	int	prev_x;

	prev_x = *x;
	*x = prev_x * cos(y_angle) + *z * sin(y_angle);
	*z = prev_x * -sin(y_angle) + *z * cos(y_angle);
}

static void	ft_rotate_z(int *x, int *y, double z_angle)
{
	t_point	prev;

	prev.x = *x;
	prev.y = *y;
	*x = prev.x * cos(z_angle) - prev.y * sin(z_angle);
	*y = prev.x * sin(z_angle) + prev.y * cos(z_angle);
}*/
/*static int	get_default_color(int z, t_map *map)
{
	double			percent;
	unsigned int	max;

	max = map->max_z - map->min_z;
	if (max == 0)
		return (0x432371);
	percent = ((double)(z - map->min_z) / max);
	if (percent < 0.2)
		return (0x432371);
	else if (percent < 0.4)
		return (0x714674);
	else if (percent < 0.6)
		return (0x9F6976);
	else if (percent < 0.8)
		return (0xCC8B79);
	else
		return (0xFAAE7B);
}*/


/*t_point	project(int x, int y, t_fdf *rol)
{
	t_point	point;

	point.z = rol->map->map[y][x][0];
	if (rol->map->map[y][x][1] >= 0)
		point.color = rol->map->map[y][x][1];
	else
		point.color = get_default_color(rol->map->map[y][x][0], \
		rol->map);
	point.x = x * rol->cam->zoom;
	point.y = y * rol->cam->zoom;
	point.z *= rol->cam->zoom / rol->cam->z_height;
	point.x -= (rol->map->columns * rol->cam->zoom) / 2;
	point.y -= (rol->map->lines * rol->cam->zoom) / 2;
	ft_rotate_x(&point.y, &point.z, rol->cam->x_ang);
	ft_rotate_y(&point.x, &point.z, rol->cam->y_ang);
	ft_rotate_z(&point.x, &point.y, rol->cam->z_ang);
	point.x += WIDTH / 2 + rol->cam->x_offset;
	point.y += (HEIGHT + rol->map->lines / 2 * rol->cam->zoom) / 2
		+ rol->cam->y_offset;
	point.reverse = 0;
	return (point);
}*/

t_point project(int x, int y, t_fdf *fdf)
{
    t_point point;

    // Obtener el valor z del mapa
    int z = fdf->map->map[y][x][0];

    // Aplicar zoom y traslación
    point.x = (x - fdf->map->columns / 2) * fdf->cam->zoom;
    point.y = (y - fdf->map->lines / 2) * fdf->cam->zoom;
    point.z = z * fdf->cam->z_height; // Ajustar la altura según la configuración de la cámara

    // Aplicar el ángulo de rotación (simple rotación en el eje z)
    float x_new = point.x * cos(fdf->cam->x_ang) - point.y * sin(fdf->cam->x_ang);
    float y_new = point.x * sin(fdf->cam->x_ang) + point.y * cos(fdf->cam->x_ang);

    point.x = x_new + fdf->cam->x_offset; // Trasladar
    point.y = y_new + fdf->cam->y_offset;

    // Establecer un color (puedes ajustarlo según tu implementación)
    point.color = 0xffffff;

    return point;
}
