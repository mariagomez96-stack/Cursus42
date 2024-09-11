/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:50:11 by marigome          #+#    #+#             */
/*   Updated: 2024/09/11 13:36:36 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_cam   *init_cam(t_cam *cam, t_map *map)
{
    cam = (t_cam *)malloc(sizeof(t_cam));
    if (!cam)
    {
        ft_error("Error cam\n");
        exit (EXIT_FAILURE);
    }    
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
        cam->zoom = (DEF_WIDTH / map->columns) / 2;
        cam->x_offset = DEF_WIDTH / 2;
        cam->y_offset = DEF_HEIGHT / 2;
    }
    return (cam);
}