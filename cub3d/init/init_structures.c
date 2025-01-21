/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:02:20 by marigome          #+#    #+#             */
/*   Updated: 2025/01/21 21:21:34 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/* This functions initializes the info flags */

static void    ft_init_flags_images(t_texture*info)
{
    info->color_flag = 0;
    info->floor_flag = 0;
    info->no_flag = 0;
    info->so_flag = 0;
    info->we_flag = 0;
    info->ea_flag = 0;
}

/* This function initializes player information */

static void    ft_init_player(t_player *player)
{
    player->angle = 0;
    player->pos_x = 0;
    player->pos_y = 0;
}

/* This function initialize the rest info information */

static void    ft_init_images(t_texture *info)
{
    info->no_path = NULL;
    info->so_path = NULL;
    info->we_path = NULL;
    info->ea_path = NULL;
    info->no_texture = NULL;
    info->so_texture = NULL;
    info->we_texture = NULL;
    info->ea_texture = NULL;
    info->ceiling_color = 0;
    info->floor_color = 0;
    ft_init_flags_images(info);
}

int ft_info_update(t_data *info)
{
    ft_init_images(&info->textures);
    ft_init_player(&info->player);
    info->move = 0;
    info->file = NULL;
    info->mlx = NULL;
    info->image = NULL;
    info->walls = NULL;
    info->map.map = NULL;
    info->map.map_size_x = 0;
    info->map.map_size_y = 0;
    info->map.map_line = 0;
    info->ray_number = 0;
    return (SUCCESS);
}



