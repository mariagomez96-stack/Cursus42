/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_walls_and_rays.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:26:20 by marigome          #+#    #+#             */
/*   Updated: 2025/01/21 21:17:04 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void ft_walls(t_data *data, mlx_image_t **img)
{
    if (!(*img = mlx_new_image(data->mlx, WIDTH, HEIGHT)))
    {    
        ft_printf("Error creating image\n");
        exit(FAILURE);
    }
    if (mlx_image_to_window(data->mlx, *img, 0, 0) == FAILURE)
    {    
        ft_printf("Error creating image\n");
        exit(FAILURE);
    }
}