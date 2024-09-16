/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conf_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 08:10:10 by marigome          #+#    #+#             */
/*   Updated: 2024/09/16 11:15:48 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"


/*void	ft_press_scape(mlx_key_data_t keydata, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (fdf->mlx && keydata.action == MLX_PRESS \
		&& keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window((mlx_t *)param); 
}*/

static void	ft_move_zoom(mlx_key_data_t keydata, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	ft_printf("Tecla presionada: %d\n", keydata.key);
	if (keydata.action == MLX_PRESS && keydata.key == MLX_KEY_W)
		fdf->cam->zoom += 1;
	else if (keydata.action == MLX_PRESS && keydata.key == MLX_KEY_S \
	&& fdf->cam->zoom > 1)
		fdf->cam->zoom -= 1;		
}

static void	ft_reset(t_fdf *fdf)
{
	fdf->cam->x_offset = fdf->win_width / 2;
	fdf->cam->y_offset = fdf->win_height / 2;
	if (fdf->cam->iso)
	{
		fdf->cam->x_ang = -0.61547297;
		fdf->cam->y_ang = -0.523599;
		fdf->cam->z_ang = 0.61547297;
		fdf->cam->prev_x = 0;
		fdf->cam->prev_y = 0;
	}
	else
	{
		fdf->cam->x_ang = -0.523599;
		fdf->cam->y_ang = -0.261799;
		fdf->cam->z_ang = 0;
	}
	fdf->cam->z_height = 1.0;
	fdf->cam->zoom = ft_get_min(DEF_WIDTH / fdf->map->columns / 2,
			DEF_HEIGHT / fdf->map->lines / 2);
}

static void	ft_move_projection(t_fdf *fdf)
{
	if (fdf->cam->iso)
	{
		fdf->cam->x_ang = -0.523599;
		fdf->cam->y_ang = -0.261799;
		fdf->cam->z_ang = 0;
	}
	else
	{
		fdf->cam->x_ang = -0.615472907;
		fdf->cam->y_ang = -0.523599;
		fdf->cam->z_ang = 0.615472907;
	}
	fdf->cam->iso = !fdf->cam->iso;
}

static void	ft_move_height(int key, t_fdf *fdf)
{
	if (key == MLX_KEY_KP_SUBTRACT)
		fdf->cam->z_height -= 0.1;
	else if (key == MLX_KEY_KP_ADD)
		fdf->cam->z_height += 0.1;
	if (fdf->cam->z_height < 0.1)
		fdf->cam->z_height = 0.1;
	else if (fdf->cam->z_height > 10)
		fdf->cam->z_height = 10;
}

static void	ft_move_img(int key, t_fdf *fdf)
{
	if (key == MLX_KEY_LEFT)
		fdf->cam->x_offset -= 10;
	else if (key == MLX_KEY_RIGHT)
		fdf->cam->x_offset += 10;
	else if (key == MLX_KEY_DOWN)
		fdf->cam->y_offset += 10;
	else if (key == MLX_KEY_UP)
		fdf->cam->y_offset -= 10;
}

void	ft_key_hook(mlx_key_data_t keydata, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (fdf->mlx && keydata.action == MLX_PRESS && keydata.key == \
	MLX_KEY_ESCAPE)
		mlx_close_window(fdf->mlx);
	else if (fdf->mlx && keydata.action == MLX_PRESS && \
	(keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_LEFT \
	|| keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_UP))
		ft_move_img(keydata.key, fdf);
	else if (fdf->mlx && keydata.action == MLX_PRESS && \
	(keydata.key == MLX_KEY_KP_SUBTRACT || keydata.key == MLX_KEY_KP_ADD))
		ft_move_height(keydata.key, fdf);
	else if (fdf->mlx && keydata.action == MLX_PRESS && \
	keydata.key == MLX_KEY_SPACE)
		ft_move_projection(fdf);
	else if (fdf->mlx && keydata.action == MLX_PRESS && \
	keydata.key == MLX_KEY_R)
		ft_reset(fdf);
	else if (fdf->mlx && keydata.action == MLX_PRESS && \
	(keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_S))
		ft_move_zoom(keydata, fdf);
	ft_draw(fdf->map, fdf);
}


void	manage_moves(t_fdf *fdf)
{
	mlx_key_hook(fdf->mlx, &ft_key_hook, fdf);
}
