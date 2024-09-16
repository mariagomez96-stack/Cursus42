/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:27:05 by marigome          #+#    #+#             */
/*   Updated: 2024/09/16 13:34:21 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "get_next_line_bonus.h"
# include "colors.h"
# include "macro.h"
# include <unistd.h>		// for write...
# include <stdlib.h>		// for typedef, malloc...
# include <math.h>			// for PI, etc.
# include <fcntl.h>	        // open, close ...
# include <limits.h>

# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_point
{
	int32_t			x; // __ //
	int32_t			y; // || //
	int32_t			z;
	int32_t			reverse; // height //
	long			color;
}	t_point;

typedef struct s_cam
{
	int32_t			zoom;
	double			x_ang;
	double			y_ang;
	double			z_ang;
	float			z_height;
	int32_t			x_offset;
	int32_t			y_offset;
	int32_t			prev_x;
	int32_t			prev_y;
	int32_t			iso;
}	t_cam;

typedef struct s_mouse
{
	int32_t			button;
	int32_t			x;
	int32_t			y;
	int32_t			current_x;
	int32_t			current_y;
	int32_t			prev_x;
	int32_t			prev_y;
}	t_mouse;

typedef struct s_line_params
{
	int32_t			delta[2];
	int32_t			sign[2];
	int32_t			error;
}	t_line_params;

typedef struct s_map
{
	int32_t			columns;	// width //
	int32_t			lines;		// height //
	int32_t			min_z;		// z_min //
	int32_t			max_z;		// z_max //
	int32_t			***map;			// (x, y, z) //
}	t_map;

typedef struct s_fdf
{
	mlx_t		*mlx;		// mlx conexion //
	mlx_image_t	*image;
	t_map		*map;
	t_mouse		*mouse;
	t_cam		*cam;
	int32_t		win_width;	//window width:   -	//
	int32_t		win_height;
	int32_t		steep;	// window height: |	//
}	t_fdf;

// CHECKERS && MANAGEMENT ERRORS //
int		ft_checker_args(int argc, char **argv);
void	ft_manage_err(const char *err);
void	ft_free_split(char **columns);
void	ft_cleanup(t_map *map, char *line, char **split_line, int32_t row);
void	ft_free_map(t_map *map);
void	ft_free_sub(int32_t **sub, int32_t size);
void	ft_free_superarray(t_map *map, int32_t rows);
void	clean_fdf(t_fdf *fdf);
void	ft_control_map(char **argv, t_map *map);

// MLX INIT //
void	init(t_fdf *pointer, const char *map_name);
t_fdf	*init_mlx(char *name);

// INIT MAP //
t_map	*init_map(const char *map_name);

// CONFIG MAP && MANAGE EVENTS //
void	manage_moves(t_fdf *fdf);
void	ft_move_img(int key, t_fdf *fdf);
void	ft_move_height(int key, t_fdf *fdf);
void	ft_move_projection(t_fdf *fdf);
void	ft_reset(t_fdf *fdf);
void	ft_move_zoom(mlx_key_data_t keydata, void *param);

// PROJECTION //
double	ft_reset_ang(double *angle);
void	ft_draw(t_map *map, t_fdf *fdf);
t_point	project(int x, int y, t_fdf *rol);
void	ft_draw_line(t_point s, t_point e, t_fdf *fdf);
float	ft_abs1(float n);
int		ft_ipart(float n);
float	ft_fpart(float n);
float	ft_rfpart(float n);
void	ft_put_pixel(t_fdf *fdf, int x, int y, int color);
int		ft_lerp(int first, int second, double p);

// INIT CAM //
t_cam	*init_cam(t_fdf *fdf);
int32_t	ft_get_min(int32_t nbr1, int32_t nbr2);

#endif