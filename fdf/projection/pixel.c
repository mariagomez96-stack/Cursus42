/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:41:37 by marigome          #+#    #+#             */
/*   Updated: 2024/09/15 15:23:18 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

float	ft_abs1(float n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	ft_ipart(float n)
{
	return ((int)n);
}

float	ft_fpart(float n)
{
	if (n > 0.f)
		return (n - ft_ipart(n));
	return (n - (ft_ipart(n) + 1.f));
}

float	ft_rfpart(float n)
{
	return (1.f - ft_fpart(n));
}

void	ft_put_pixel(t_fdf *fdf, int x, int y, int color)
{
	if (x >= 0 && x < fdf->win_width && y >= 0 && y < fdf->win_height)
	{
		mlx_put_pixel(fdf->image, x, y, color);
	}
}
