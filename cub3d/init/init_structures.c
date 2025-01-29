/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:02:20 by marigome          #+#    #+#             */
/*   Updated: 2025/01/29 11:32:37 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/* Esta función inicializa las banderas relacionadas con la configuración de texturas
    y colores del juego */

static void    ft_init_flags_images(t_texture *info)
{
    info->color_flag = 0;   // Flag para verificar si los colores han sido configurados
    info->floor_flag = 0;   // Flag para verificar si el color del suelo ha sido configurado
    info->no_flag = 0;      // Flag para verificar la textura norte (NO)
    info->so_flag = 0;      // Flag para verificar la textura sur (SO)
    info->we_flag = 0;      // Flag para verificar la textura oeste (WE)
    info->ea_flag = 0;      // Flag para verificar la textura este (EA)
}

/* Esta función inicializa y almacena la información del jugador */

static void    ft_init_player(t_player *player)
{
    player->angle = 0;  // Ángulo de dirección del jugador (Se cambiará según el mapa)
    player->pos_x = 0;  // Posición x del jugador en el mapa
    player->pos_y = 0;  // Posición y del jugador en el mapa
}

/* Esta función inicializa toda la estructura de textures (Colores e imágenes) */

static void    ft_init_images(t_texture *info)
{
    ft_init_flags_images(info);
    info->no_path = NULL;       // Path que almacena ruta de las imágenes de las texturas norte (Muros)
    info->so_path = NULL;       // Path que almacena ruta de las imágenes de las texturas sur (Muros)
    info->we_path = NULL;       // Path que almacena ruta de las imágenes de las texturas oeste (Muros)
    info->ea_path = NULL;       // Path que almacena ruta de las imágenes de las texturas este (Muros)
    info->no_texture = NULL;    // Almacena las imágenes convertidas a texturas con MLX
    info->so_texture = NULL;    // Almacena las imágenes convertidas a texturas con MLX
    info->we_texture = NULL;    // Almacena las imágenes convertidas a texturas con MLX
    info->ea_texture = NULL;    // Almacena las imágenes convertidas a texturas con MLX
    info->ceiling_color = 0;    // Color del techo (Info en el mapa: C)
    info->floor_color = 0;      // Color del suelo (Info en el mapa F)
}
/* Función central de inicialización*/

int ft_init_info_game(t_data *info)
{
    ft_init_images(&info->textures);
    ft_init_player(&info->player);
    info->move = 0;     		// Almacena información sobre el movimiento del jugador
    info->file = NULL;  		// Almacena el archivo del mapa
    info->mlx = NULL;   		// Instancia de MLX -> Se inicializa con mlx_init()
    info->image = NULL; 		// Imagen sobre la que vamos a renderizar el cielo y el suelo
    info->walls = NULL; 		// Imagen sobre la que vamos a renderizar las paredes
    info->map.map = NULL;   	// Matriz del mapa
    info->map.map_size_x = 0;	// Tamaño del mapa en x
    info->map.map_size_y = 0;	// Tamaño del mapa en y
    info->map.map_line = 0;		// Líneas del mapa
    info->ray_number = 0;		// Número de rayos usados para dibujar las paredes
    return (SUCCESS);
}



