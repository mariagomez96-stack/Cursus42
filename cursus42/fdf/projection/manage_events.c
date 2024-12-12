/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:25:00 by marigome          #+#    #+#             */
/*   Updated: 2024/09/16 12:29:24 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_key_hook(mlx_key_data_t keydata, void *param)
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
