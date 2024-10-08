/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:50:11 by marigome          #+#    #+#             */
/*   Updated: 2024/09/17 10:12:39 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int32_t	ft_get_min(int32_t nbr1, int32_t nbr2)
{
	if (nbr1 < nbr2)
		return (nbr1);
	return (nbr2);
}

t_cam	*init_cam(t_fdf *fdf)
{
	t_cam	*cam;

	cam = (t_cam *)malloc(sizeof(t_cam));
	if (!cam)
	{
		ft_manage_err("Error cam\n");
		exit (EXIT_FAILURE);
	}
	cam->zoom = 40;
	cam->x_ang = -0.61547297;
	cam->y_ang = -0.523599;
	cam->z_ang = 0.61547297;
	cam->x_offset = fdf->win_width / 2;
	cam->y_offset = fdf->win_height / 2;
	cam->z_height = 1.0;
	cam->iso = 1;
	cam->prev_x = 0;
	cam->prev_y = 0;
	return (cam);
}
