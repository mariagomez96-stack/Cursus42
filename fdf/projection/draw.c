/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 13:40:57 by marigome          #+#    #+#             */
/*   Updated: 2024/09/12 16:15:58 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*static uint32_t grad_color(uint32_t start, uint32_t end, float step)
{
    int         j;
    uint32_t    color;
    uint8_t     byte_start;
    uint8_t     byte_end;

    color = 0;
    j = 24;
    while (j >= 0)
    {
        byte_start = start >> j;
        byte_end = end >> j;
        color = color * 256;
        if (byte_start > byte_end)
            byte_end = byte_start - (byte_start - byte_end) * step;
        else
            byte_end = byte_start + (byte_end - byte_start) * step;
        color = color + byte_end;
        j -= 8;
    }
    return (color);
}
static void swap_points(t_point *start, t_point *end)
{
    t_point swap;

    swap = *start;
    *start = *end;
    *end = swap;
}

static void plot_line(t_point start, t_point end, mlx_image_t *img, t_fdf *fdf)
{
    float   m;
    int     b;
    int     i;

    m = (float)(end.y - start.y) / (float)(end.x - start.x);
    if ((m <= 1.0 && m >= -1.0 && start.x > end.x)
        || ((m > 1.0 || m < -1.0) && start.y > end.y))
        swap_points(&start, &end);

    b = (start.y - m * start.x) * fdf->cam->zoom;
    
    if (m <= 1.0 && m >= -1.0)
    {
        i = start.x * fdf->cam->zoom;
        while (i++ < end.x * fdf->cam->zoom)
        {
            mlx_put_pixel(img, i + fdf->cam->x_offset, i * m + fdf->cam->y_offset + b,
                grad_color(start.color, end.color, (i - start.x * fdf->cam->zoom)
                    / ((end.x - start.x) * fdf->cam->zoom)));
        }
        return ;
    }

    i = start.y * fdf->cam->zoom;
    while (i++ < end.y * fdf->cam->zoom)
    {
        mlx_put_pixel(img, (i - b) / m + fdf->cam->x_offset, i + fdf->cam->y_offset,
            grad_color(start.color, end.color, (i - start.y * fdf->cam->zoom)
                / ((end.y - start.y) * fdf->cam->zoom)));
    }
}
// Función para crear un t_point a partir de los datos de la matriz
t_point create_point(t_fdf *fdf, int i, int j)
{
    t_point point;

    // Verificar que estamos dentro de los límites de la matriz
    if (i < 0 || i >= fdf->map->columns || j < 0 || j >= fdf->map->lines)
    {
        ft_error("Error: índice fuera de los límites en create_point\n");
        exit(EXIT_FAILURE);  // Sale si el índice está fuera de los límites
    }

    point.x = i;
    point.y = j;

    // Verificar que fdf->map->map[i][j] es válido antes de acceder a él
    if (!fdf->map->map[i] || !fdf->map->map[i][j])
    {
        ft_error("Error: puntero nulo en el mapa\n");
        exit(EXIT_FAILURE);
    }

    // Acceder a la coordenada z (asumiendo que está en el primer índice)
    point.z = fdf->map->map[i][j][0]; 

    point.color = 0xFFFFFF; // Puedes ajustar este color si es necesario
    return (point);
}


void plot_map(t_fdf *fdf)
{
    int i;
    int j;
    t_point start;
    t_point end;

    i = 0;
    while (i < fdf->map->columns)
    {
        j = 0;
        while (j < fdf->map->lines)
        {
            start = create_point(fdf, i, j);

            // Dibujar la línea hacia la derecha
            if (i < fdf->map->columns - 1)
            {
                end = create_point(fdf, i + 1, j);
                plot_line(start, end, fdf->image, fdf);
            }

            // Dibujar la línea hacia abajo
            if (j < fdf->map->lines - 1)
            {
                end = create_point(fdf, i, j + 1);
                plot_line(start, end, fdf->image, fdf);
            }
            j++;
        }
        i++;
    }
}*/

static int	ft_ipart(float n)
{
	return ((int)n);
}

static float	ft_fpart(float n)
{
	if (n > 0.f)
		return (n - ft_ipart(n));
	return (n - (ft_ipart(n) + 1.f));
}

static float	ft_rfpart(float n)
{
	return (1.f - ft_fpart(n));
}

static void	ft_put_pixel(t_fdf *fdf, int x, int y, int color)
{
    if (x >= 0 && x < fdf->win_width && y >= 0 && y < fdf->win_height)
    {
        mlx_put_pixel(fdf->image, x, y, color);
    }
}

static float	ft_abs1(float n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	ft_lerp(int first, int second, double p)
{
	if (first == second)
		return (first);
	return ((int)((double)first + (second - first) * p));
}

static int	ft_get_color(int x, t_point s, t_point e, float factor)
{
	int		r;
	int		g;
	int		b;
	float	percent;

	percent = ft_abs1(x - s.x) / ft_abs1(e.x - s.x);
	if (s.reverse)
	{
		r = ft_lerp((e.color >> 16) & 0xFF, (s.color >> 16) & 0xFF, percent);
		g = ft_lerp((e.color >> 8) & 0xFF, (s.color >> 8) & 0xFF, percent);
		b = ft_lerp(e.color & 0xFF, s.color & 0xFF, percent);
	}
	else
	{
		r = ft_lerp((s.color >> 16) & 0xFF, (e.color >> 16) & 0xFF, percent);
		g = ft_lerp((s.color >> 8) & 0xFF, (e.color >> 8) & 0xFF, percent);
		b = ft_lerp(s.color & 0xFF, e.color & 0xFF, percent);
	}
	r *= factor;
	g *= factor;
	b *= factor;
	return ((r << 16) | (g << 8) | b);
}

static void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	ft_draw_line_loop(t_point s, t_point e, float gradient, t_fdf *fdf)
{
    float	inter_y;
    int		x;

    inter_y = (float)s.y;
    x = s.x;
    while (x <= e.x)
    {
        if (fdf->steep)
        {
            ft_put_pixel(fdf, ft_ipart(inter_y), x,
                ft_get_color(x, s, e, ft_rfpart(inter_y)));
            ft_put_pixel(fdf, ft_ipart(inter_y) + 1, x,
                ft_get_color(x, s, e, ft_fpart(inter_y)));
        }
        else
        {
            ft_put_pixel(fdf, x, ft_ipart(inter_y),
                ft_get_color(x, s, e, ft_rfpart(inter_y)));
            ft_put_pixel(fdf, x, ft_ipart(inter_y) + 1,
                ft_get_color(x, s, e, ft_fpart(inter_y)));
        }
        inter_y += gradient;
        x++;
    }
}


static void	ft_draw_line(t_point s, t_point e, t_fdf *fdf)
{
    float	dy;
    float	dx;
    float	gradient;

    ft_printf("Empezamos a pintar las lineas: Start(%d, %d) End(%d, %d)\n", s.x, s.y, e.x, e.y);

	// Verificar si los puntos están dentro de los límites de la ventana
	if ((s.x < 0 || s.x >= fdf->win_width || s.y < 0 || s.y >= fdf->win_height) &&
	    (e.x < 0 || e.x >= fdf->win_width || e.y < 0 || e.y >= fdf->win_height))
	{
		ft_printf("Los puntos están fuera de los límites de la ventana, no se dibuja la línea\n");
		return; // No dibujamos si ambos puntos están fuera de la ventana
	}

	fdf->steep = ft_abs1(e.y - s.y) > ft_abs1(e.x - s.x);
    if (fdf->steep)
    {
        ft_swap(&s.x, &s.y);
        ft_swap(&e.x, &e.y);
    }
    if (s.x > e.x)
    {
        ft_swap(&s.x, &e.x);
        ft_swap(&s.y, &e.y);
        s.reverse = 1;
    }
    dx = (float)(e.x - s.x);
    dy = (float)(e.y - s.y);
    gradient = dy / dx;
    if (dx == 0.0f)
        gradient = 1.f;
    ft_draw_line_loop(s, e, gradient, fdf);
    ft_printf("Terminamos de pintar las lineas\n");
}


void	ft_draw(t_map *map, t_fdf *fdf)
{
    int	x;
    int	y;

    mlx_delete_image(fdf->mlx, fdf->image); // Borrar imagen anterior
    ft_printf("Se ha borrado la imagen anterior\n");
    fdf->image = mlx_new_image(fdf->mlx, fdf->win_width, fdf->win_height); // Crear nueva imagen
    ft_printf("Añadimos imagen\n");

    y = 0;
    if (fdf->cam->x_ang > 0)
        y = map->lines - 1;  // Asegúrate de que map->lines es el alto y no el ancho
    while (y < map->lines && y >= 0)  // Corregir bucle para líneas
    {
        x = 0;
        if (fdf->cam->y_ang > 0)
            x = map->columns - 1;  // Asegúrate de que map->columns es el ancho y no el alto
        while (x < map->columns && x >= 0)  // Corregir bucle para columnas
        {
            if (x != map->columns - 1)
            {
                t_point p1 = project(x, y, fdf);
                t_point p2 = project(x + 1, y, fdf);
                ft_printf("Dibujando línea de (%d, %d) a (%d, %d)\n", p1.x, p1.y, p2.x, p2.y);
                ft_draw_line(p1, p2, fdf);
            }
            if (y != map->lines - 1)
            {
                t_point p1 = project(x, y, fdf);
                t_point p2 = project(x, y + 1, fdf);
                ft_printf("Dibujando línea de (%d, %d) a (%d, %d)\n", p1.x, p1.y, p2.x, p2.y);
                ft_draw_line(p1, p2, fdf);
            }
            x += -2 * (fdf->cam->y_ang > 0) + 1;
        }
        y += -2 * (fdf->cam->x_ang > 0) + 1;
    }
    mlx_image_to_window(fdf->mlx, fdf->image, 0, 0);  // Mostrar la nueva imagen en la ventana
    ft_printf("Añadimos la imagen a la ventana\n");
}





