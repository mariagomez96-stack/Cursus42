/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:50:11 by marigome          #+#    #+#             */
/*   Updated: 2024/09/10 13:54:55 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void    init_cam(t_cam *cam, t_map *map)
{
    cam->zoom = 20; //zoom basico inicial
    cam->x_ang = 0.0;
    cam->y_ang = 0.0;
    cam->z_ang = 0.0;
    cam->x_offset = 0;
    cam->y_offset = 0;
    cam->z_height = 1.0;
    cam->iso = 1; //Proyeccion isometrica

    if (map->lines > 0 && map->columns > 0)
    {
        cam->zoom = (WIDTH / map->columns) / 2;
        cam->x_offset = WIDTH / 2;
        cam->y_offset = HEIGHT / 2;
    }
}