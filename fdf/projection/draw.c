/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 13:40:57 by marigome          #+#    #+#             */
/*   Updated: 2024/09/16 10:55:31 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_clamp(int value, int min, int max)
{
	if (value < min)
		return min;
	if (value > max)
		return max;
	return value;
}

static int	ft_get_color(int x, t_point s, t_point e, float factor)
{
	int		r;
	int		g;
	int		b;
	float	percent;


	percent = ft_abs1(x - s.x) / ft_abs1(e.x - s.x);


	/*if (percent < 0 || percent > 1 || s.color == 0 || e.color == 0)
		return (0xFFFFFF);  // Color blanco*/

	if (s.reverse)
	{
		r = ft_lerp((e.color >> 24) & 0xFF, (s.color >> 24) & 0xFF, percent);
		g = ft_lerp((e.color >> 16) & 0xFF, (s.color >> 16) & 0xFF, percent);
		b = ft_lerp((e.color >> 8) & 0xFF, (s.color >> 8) & 0xFF, percent);
		//a = ft_lerp(e.color & 0xFF, s.color & 0xFF, percent);
	}
	else
	{
		r = ft_lerp((s.color >> 16) & 0xFF, (e.color >> 16) & 0xFF, percent);
		g = ft_lerp((s.color >> 8) & 0xFF, (e.color >> 8) & 0xFF, percent);
		b = ft_lerp(s.color & 0xFF, e.color & 0xFF, percent);
		//a = ft_lerp(e.color & 0xFF, s.color & 0xFF, percent);
	}

	r *= factor;
	g *= factor;
	b *= factor;


	/*if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (0xFFFFFF);  // 0xRRGGBBAA*/

	return (0xFF | (r << 24) | (g << 16) | (b << 8));
}


static void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	ft_lerp(int first, int second, double p)
{
	if (first == second)
		return (first);
	return ((int)((double)first + (second - first) * p));
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
		
		// Puedes agregar estas líneas para depuración
			ft_get_color(x, s, e, ft_rfpart(inter_y));
		
		inter_y += gradient;
		x++;
	}
}

void	ft_draw_line(t_point s, t_point e, t_fdf *fdf)
{
	float	dy;
	float	dx;
	float	gradient;
	
	if ((s.x < 0 || s.x >= fdf->win_width || s.y < 0 || s.y >= fdf->win_height)
	&& (e.x < 0 || e.x >= fdf->win_width || e.y < 0 || e.y >= fdf->win_height))
		return ;
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
}
