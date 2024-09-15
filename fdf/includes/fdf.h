/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:27:05 by marigome          #+#    #+#             */
/*   Updated: 2024/09/15 19:47:30 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "get_next_line_bonus.h"
# include "colors.h"
# include "ft_macros.h"
# include <unistd.h>		// for write...
# include <stdlib.h>		// for typedef, malloc...
# include <math.h>			// for PI, etc.
# include <fcntl.h>	        // open, close ...
# include <limits.h>

# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_point
{
	int				x; // __ //
	int				y; // || //
	int				z;
	int				reverse; // height //
	unsigned long	color;
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
	int	columns;	// width //
	int	lines;		// height //
	int	min_z;		// z_min //
	int	max_z;		// z_max //
	int	***map;			// (x, y, z) //
}	t_map;

typedef struct s_fdf
{
	mlx_t		*mlx;		// mlx conexion //
	mlx_image_t	*image;
	t_map		*map;
	t_mouse		*mouse;
	t_cam		*cam;
	void		*imgstatic;
	int			win_width;	//window width:   -	//
	int			win_height;
	int			steep;	// window height: |	//
}	t_fdf;

// CHECKERS && MANAGEMENT ERRORS //
int		ft_checker_args(int argc, char **argv);
void	ft_error(char *src);
void	ft_free_columns(char **columns);
void	ft_free_split(char **argv);
void	free_map(t_map *map);

// MLX INIT //
void	init(t_fdf *pointer, const char *map_name);
t_fdf	*init_mlx(char *name);

// INIT MAP //
int		ft_columns_counter(char *line);
char	**split_lines_in_columns(char *line);
void	columns_to_map(t_map *map, char **columns, int row);
int		create_map_row(t_map *map, int row);
t_map	*init_map(const char *map_name);

int		open_map_file(const char *map_name);
int		read_lines(t_map *map, int fd);
t_map	*initialize_map(void);

// CONFIG MAP_EVENTS //
void	ft_press_scape(mlx_key_data_t keydata, void *param);
void	manage_moves(t_fdf *fdf);

// PROJECTION //
double	ft_reset_ang(double *angle);
void	ft_draw(t_map *map, t_fdf *fdf);
t_point	project(int x, int y, t_fdf *rol);
void	ft_draw_line(t_point s, t_point e, t_fdf *fdf);

// PIXEL //
float	ft_abs1(float n);
int		ft_ipart(float n);
float	ft_fpart(float n);
float	ft_rfpart(float n);
void	ft_put_pixel(t_fdf *fdf, int x, int y, int color);
int		ft_lerp(int first, int second, double p);
int	ft_get_default_color(int z, t_map *map);

t_cam	*init_cam(t_fdf *fdf);

#endif