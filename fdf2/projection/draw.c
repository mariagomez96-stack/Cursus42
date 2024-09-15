/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 13:40:57 by marigome          #+#    #+#             */
/*   Updated: 2024/09/15 19:31:02 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_lerp(int first, int second, double p)
{
	if (first == second)
		return (first);
	return ((int)((double)first + (second - first) * p));
}

/*static int	ft_get_color(int x, t_point s, t_point e, float factor)
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
	r *= fabs(factor);
	g *= fabs(factor);
	b *= fabs(factor);
	return ((0xFF << 24) |(r << 16) | (g << 8) | b);
}*/

/*static int ft_get_color(int x, t_point s, t_point e)
{
    int r, g, b;
    float percent;

    // Evitamos división por cero y verificamos los valores de s.x y e.x
	if (e.x != s.x)
    	percent = (float)(x - s.x) / (e.x - s.x);
    
	
	else
		percent = 1.0f;


    // Interpolación de los componentes de color (RGB)
    r = ft_lerp((s.color >> 16) & 0xFF, (e.color >> 16) & 0xFF, percent);
    g = ft_lerp((s.color >> 8) & 0xFF, (e.color >> 8) & 0xFF, percent);
    b = ft_lerp(s.color & 0xFF, e.color & 0xFF, percent);

    return ((0xFF << 24) | (r << 16) | (g << 8) | b);
}*/

uint32_t	grad_color(uint32_t start, uint32_t end, float step)
{
	int			j;
	uint32_t	color;
	uint8_t		byte_start;
	uint8_t		byte_end;

	color = 0;
	j = 24;  // Para iterar sobre los 4 bytes (RGBA)
	while (j >= 0)
	{
		// Desplazamos para obtener el byte correspondiente (R, G o B)
		byte_start = (start >> j) & 0xFF;   // Extrae el componente de `start`
		byte_end = (end >> j) & 0xFF;       // Extrae el componente de `end`

		// Interpolación del color en cada componente (R, G o B)
		if (byte_start > byte_end)
			byte_end = byte_start - (byte_start - byte_end) * step;
		else
			byte_end = byte_start + (byte_end - byte_start) * step;

		// Construir el color final
		color = (color << 8) + byte_end;  // Desplazar a la izquierda y añadir byte
		j -= 8;  // Mover al siguiente componente
	}
	return (color);
}




static void	ft_swap(t_point *a, t_point *b)
{
	t_point	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/*static void ft_draw_line_loop(t_point s, t_point e, float gradient, t_fdf *rol)
{
    float inter_y;
    int x;

    inter_y = (float)s.y;
    x = s.x;
    while (x <= e.x)
    {
        if (rol->steep)
        {
            ft_put_pixel(rol, ft_ipart(inter_y), x, ft_get_color(x, s, e));
            ft_put_pixel(rol, ft_ipart(inter_y) + 1, x, ft_get_color(x, s, e));
        }
        else
        {
            ft_put_pixel(rol, x, ft_ipart(inter_y), ft_get_color(x, s, e));
            ft_put_pixel(rol, x, ft_ipart(inter_y) + 1, ft_get_color(x, s, e));
        }
        inter_y += gradient;
        x++;
    }
}*/


/*void	ft_draw_line(t_point s, t_point e, t_fdf *rol)
{
	float	dy;
	float	dx;
	float	gradient;

	if ((s.x < 0 || s.x >= rol->win_width || s.y < 0 || \
	s.y >= rol->win_height) && \
	(e.x < 0 || e.x >= rol->win_width || e.y < 0 || e.y >= rol->win_height))
		return ;
	rol->steep = ft_abs1(e.y - s.y) > ft_abs1(e.x - s.x);
	if (rol->steep)
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
	ft_draw_line_loop(s, e, gradient, rol);
}*/

void ft_draw_line(t_point start, t_point end, t_fdf *fdf)
{
    float   m;    // pendiente
    int     b;    // intercepto
    int     i;    // contador

    // Calcular la pendiente
    m = (float)(end.y - start.y) / (float)(end.x - start.x);

    // Intercambia los puntos si es necesario
    if ((m <= 1.0 && m >= -1.0 && start.x > end.x)
        || ((m > 1.0 || m < -1.0) && start.y > end.y))
        ft_swap(&start, &end);

    // Calcula el intercepto de la recta
    b = (start.y - m * start.x);

    // Si la pendiente es menor o igual a 1 (el cambio en x es mayor que en y)
    if (m <= 1.0 && m >= -1.0)
    {
        i = start.x;
        // Dibuja los píxeles para los valores de x desde start.x a end.x
        while (i <= end.x)
        {
            int pixel_y = i * m + b; // Calcula la coordenada y correspondiente para el pixel

            if (i >= 0 && i < fdf->win_width && pixel_y >= 0 && pixel_y < fdf->win_height) // Asegura que el pixel esté dentro de los límites de la ventana
                mlx_put_pixel(fdf->image, i, pixel_y, grad_color(start.color, end.color, (float)(i - start.x) / (float)(end.x - start.x)));
            i++;
        }
    }
    else
    {
        i = start.y;
        // Dibuja los píxeles para los valores de y desde start.y a end.y
        while (i <= end.y)
        {
            int pixel_x = (i - b) / m; // Calcula la coordenada x correspondiente para el pixel

            if (pixel_x >= 0 && pixel_x < fdf->win_width && i >= 0 && i < fdf->win_height) // Asegura que el pixel esté dentro de los límites de la ventana
                mlx_put_pixel(fdf->image, pixel_x, i, grad_color(start.color, end.color, (float)(i - start.y) / (float)(end.y - start.y)));
            i++;
        }
    }
}

void	plot_map(t_fdf *fdf)
{
	int	i;
	int	j;
	t_point p1;
	t_point p2;

	i = 0;
	while (i < fdf->map->columns)
	{
		j = 0;
		while (j < fdf->map->lines)
		{
			// Obtener punto actual y sus vecinos en el mapa
			// Línea horizontal: del punto actual al siguiente en la columna
			if (i < fdf->map->columns - 1)
			{
				p1 = project(i, j, fdf);       // Proyecta el punto actual
				p2 = project(i + 1, j, fdf);   // Proyecta el siguiente punto en la columna
				ft_draw_line(p1, p2, fdf);     // Dibuja la línea entre p1 y p2
			}

			// Línea vertical: del punto actual al siguiente en la fila
			if (j < fdf->map->lines - 1)
			{
				p1 = project(i, j, fdf);       // Proyecta el punto actual
				p2 = project(i, j + 1, fdf);   // Proyecta el siguiente punto en la fila
				ft_draw_line(p1, p2, fdf);     // Dibuja la línea entre p1 y p2
			}
			j++;
		}
		i++;
	}
}

