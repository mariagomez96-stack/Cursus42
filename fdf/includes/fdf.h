/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:27:05 by marigome          #+#    #+#             */
/*   Updated: 2024/09/06 15:08:45 by marigome         ###   ########.fr       */
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
# include "math.h"
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
	int	map_columns;	// width //
	int	map_lines;		// height //
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

#endif