/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:27:05 by marigome          #+#    #+#             */
/*   Updated: 2024/09/10 19:19:47 by marigome         ###   ########.fr       */
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
	int				x; // __ //
	int				y; // || //
	int				z; // height //
	unsigned long	color;
}	t_point;

typedef struct s_map
{
	int	columns;	// width //
	int	lines;		// height //
	int	min_depth;		// z_min //
	int	max_depth;		// z_max //
	int	***map;			// (x, y, z) //
}	t_map;

typedef struct s_cam
{
	int		zoom;		// zoom 									//
	double	x_ang;		// rotation angle x 						//
	double	y_ang;		// rotation angle y 						//
	double	z_ang;		// rotation angle z 						//
	int		x_offset;	// x -> pixels mov   						//
	int		y_offset;	// y -> pixels mov							//
	float	z_height;	// adjust the height						//
	int		iso;		// proyect mode (1)(0)						//
	int		prev_x;		// previous mouse position (interactions)	//
	int		prev_y;
}	t_cam;

typedef struct s_fdf
{
	mlx_t		*mlx;		// mlx conexion //
	mlx_image_t	*image;
	t_map		*map;
	t_cam		*cam;
	int			win_width;	//window width:   -	//
	int			win_height;	// window height: |	//
}	t_fdf;

typedef struct s_bresenham
{
	int dx;
	int dy;
	int sx;
	int sy;
	int err;
}	t_bresenham;


// CHECKERS && MANAGEMENT ERRORS //
int		ft_checker_args(int argc, char **argv);
void	ft_error(char *src);
void	ft_free_columns(char **columns);
void	free_map(t_map *map);
void free_fdf(t_fdf *fdf);

// MLX INIT //
void	init(t_fdf *pointer, const char *map_name);
t_fdf	*init_mlx(char *name);

// INIT MAP //
int	ft_columns_counter(char *line);
char	**split_lines_in_columns(char *line);
int	columns_to_map(t_map *map, char **columns, int row);
int	process_line(t_map *map, char *line, int row);
int create_map_row(t_map *map, int row);

int open_map_file(const char *map_name);
int read_lines(t_map *map, int fd);
t_map   *initialize_map(void);
void    update_depth(t_map *map, int z);
void    calculate_depth(t_map *map);

t_map   *init_map(const char *map_name);

// CAM //
void    init_cam(t_cam *cam, t_map *map);

// ISO && BRESENHAM //
void    iso_projection(int *x, int *y, int z, t_cam *cam);
void    put_pixel(mlx_image_t *image, int x, int y, uint32_t color);
void	init_bresenham(t_point start, t_point end, t_bresenham *bres);
void    put_line_pixels(t_fdf *fdf, t_point start, t_point end, t_bresenham *bres);
void    draw_line(t_fdf *fdf, t_point start, t_point end);

// MAP EVENTS //
void    move_map(t_fdf *fdf, mlx_key_data_t keydata);
void    zoom_map(t_fdf *fdf, mlx_key_data_t keydata);
void    rotate_map(t_fdf *fdf, mlx_key_data_t keydata);
void    handle_events(mlx_key_data_t keydata, void *param);

void	project_point(t_point *point, t_cam *cam);
void	draw_map_line(t_fdf *fdf, t_point start, t_point end);
void	draw_horizontal_lines(t_fdf *fdf, int y);
void	draw_vertical_lines(t_fdf *fdf, int x);
void	project_and_draw_map(t_fdf *fdf);

#endif