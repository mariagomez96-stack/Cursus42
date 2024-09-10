/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:39:35 by marigome          #+#    #+#             */
/*   Updated: 2024/09/10 14:49:02 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void    move_map(t_fdf *fdf, mlx_key_data_t keydata)
{
    if (keydata.key == MLX_KEY_LEFT)
        fdf->cam->x_offset -= 10;
    else if (keydata.key == MLX_KEY_RIGHT)
        fdf->cam->x_offset += 10;
    else if (keydata.key == MLX_KEY_UP)
        fdf->cam->y_offset -= 10;
    else if (keydata.key == MLX_KEY_DOWN)
        fdf->cam->y_offset += 10;
}

void    zoom_map(t_fdf *fdf, mlx_key_data_t keydata)
{
    if (keydata.key == MLX_KEY_EQUAL)
        fdf->cam->zoom += 2;
    else if (keydata.key == MLX_KEY_MINUS)
        fdf->cam->zoom -= 2;
}

void    rotate_map(t_fdf *fdf, mlx_key_data_t keydata)
{
    if (keydata.key == MLX_KEY_A)
        fdf->cam->x_ang -= 0.1;
    else if (keydata.key == MLX_KEY_D)
        fdf->cam->x_ang += 0.1;
    else if (keydata.key == MLX_KEY_W)
        fdf->cam->y_ang -= 0.1;
    else if (keydata.key == MLX_KEY_S)
        fdf->cam->y_ang += 0.1;
}

void    handle_events(mlx_key_data_t keydata, void *param)
{
    t_fdf   *fdf;

    fdf = (t_fdf *)param;
    move_map(fdf, keydata);
    zoom_map(fdf, keydata);
    rotate_map(fdf, keydata);
    
}