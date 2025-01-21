/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:38:05 by marigome          #+#    #+#             */
/*   Updated: 2025/01/21 21:32:56 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <errno.h> // To use perror, errno
# include <fcntl.h> // To use open, close
# include <math.h>  // Math functions
# include <stdio.h>
# include <stdlib.h> // To use malloc, free
# include <string.h> // To use strlen, strdup
# include <unistd.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "get_next_line_bonus.h"
# include "colors.h"
# include "macro.h"
# include "../MLX42/include/MLX42/MLX42.h"


typedef struct s_texture
{
	char			*no_path;		// the path of the north texture
	char			*so_path;		// the path of the south texture
	char			*we_path;		// the path of the west texture
	char			*ea_path;		// the path of the east texture
	int				no_flag;		// the flag of the north texture
	int				so_flag;		// the flag of the south texture
	int				we_flag;		// the flag of the west texture
	int				ea_flag;		// the flag of the east texture
	int				color_flag;			// the flag of the ceiling color
	int				floor_flag;			// the flag of the floor color
	unsigned int	ceiling_color;		// the color of the ceiling
	unsigned int	floor_color;		// the color of the floor
	mlx_texture_t	*no_texture;	// the north texture
	mlx_texture_t	*so_texture;	// the south texture
	mlx_texture_t	*we_texture;	// the west texture
	mlx_texture_t	*ea_texture;	// the east texture
}	t_texture;

typedef struct s_point
{
	int	x;							//the x coordinate of the point to draw
	int	y;							//the y coordinate of the point to draw
}	t_point;

typedef struct s_line
{
	int	x;				// the x coordinate of line relative to screen
	int	y;				// the current pixel index of the line (along y axis)
	int	y_start;		// y start index of drawing texture
	int	y_end;			// y end index of drawing texture
	int	texture_x;			// x coordinate of texture to draw
	int	texture_y;			// y coordinate of texture to draw
}	t_line;

typedef struct s_ray
{
    int     flag_wall;                  // Indica si el rayo golpeó una pared
    int     map_x, map_y;               // Coordenadas del mapa donde impacta
    double  angle;                      // Ángulo del rayo en radianes
    double  pos_x, pos_y;               // Posición del jugador (puede eliminarse si ya está en `t_player`)
    double  ray_dir_x, ray_dir_y;       // Dirección del rayo
    double  delta_dist_x, delta_dist_y; // Distancias a los lados del grid
    double  side_dist_x, side_dist_y;   // Distancia a la siguiente intersección
    double  perp_wall_dist;             // Distancia perpendicular a la pared
    double  step_x, step_y;             // Dirección del paso en X/Y (-1 o 1)
}   t_ray;

typedef struct s_player
{
    double  angle;              // Ángulo de visión del jugador
    double  pos_x, pos_y;       // Posición en coordenadas del mundo
}   t_player;


typedef struct s_map
{
	char	**map;					// the map of the game
	int		map_size_x;				// the size of the map in x
	int		map_size_y;				// the size of the map in y
	int		map_line;				// the line of the map
}	t_map;

typedef struct s_data
{
    int			 ray_number;     // Número de rayos usados para dibujar las paredes
	bool            move;           // Flag de movimiento
    char            *file;          // Archivo del mapa
    t_map           map;            // Información del mapa
    t_player        player;         // Jugador
    t_texture       textures;       // Texturas del juego
    t_ray           *rays;          // Arreglo de rayos dinámico (se asignará con malloc)
    mlx_t           *mlx;           // Instancia MLX
    mlx_image_t     *image;         // Imagen del fondo
    mlx_image_t     *walls;         // Imagen de las paredes
}   t_data;

// ----- Functions ---------------------------------------------------------- //

/* INIT STRUCTURES */
int ft_info_update(t_data *info);


/* WALLS & RAYS */
void ft_walls(t_data *data, mlx_image_t **img);

/* MAP */
void ft_calculate_map_size(t_map *map);
int ft_validate_map(t_data *data);
int ft_process_map(t_data *info, char *map_str);
char *ft_read_map(int fd);
int ft_open_map_file(char *file);
int ft_checker_extension(char *file);
char	*ft_strjoin_free(char *s1, char *s2);
char	*ft_trim_str(char *s1, char *set);
char	*ft_strtrim(const char *s1, const char *set);
int	ft_split_map(t_data *info, char *map);
int	ft_check_extra(char *map);
int	ft_split_len(char **str);
int	ft_check_start_and_end(char **map, int end);
int	ft_check_first_last(t_data *info, char **map);
int	ft_check_map_closed(t_data *info);
int	ft_check_spaces_map(char **map, int i, int j, int res);
int	ft_check_spaces_map_2(char **map, int i, int j, int res);
int	ft_check_spaces(char **map);
void	ft_error_bad_spc(int line, int i);
int	ft_players_num(char **map);
int ft_load_map(char *file, t_data *info);
int ft_check_inside(char **map);


#endif