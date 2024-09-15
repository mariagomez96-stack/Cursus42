/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conf_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 08:10:10 by marigome          #+#    #+#             */
/*   Updated: 2024/09/15 17:29:03 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_press_scape(mlx_key_data_t keydata, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (fdf->mlx && keydata.action == MLX_PRESS \
		&& keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window((mlx_t *)param);
}

void	manage_moves(t_fdf *fdf)
{
	mlx_key_hook(fdf->mlx, &ft_press_scape, fdf->mlx);
}
