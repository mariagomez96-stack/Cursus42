/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 13:08:23 by marigome          #+#    #+#             */
/*   Updated: 2024/09/07 14:27:52 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init(t_fdf *pointer, const char *map_name)
{
	pointer->mlx = mlx_init(WIDTH, HEIGHT, map_name, true);
	if (!pointer->mlx)
	{
		ft_error(MLX_ERROR);
	}
	pointer->image = mlx_new_image(pointer->mlx, WIDTH, HEIGHT);
	if (!pointer->image)
	{
		mlx_strerror
	}

}

t_fdf	init_mlx(char *name)
{
	t_fdf	*fdf;
	char	*map_name;
	
	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	map_name = ft_substr(name, 0, ft_strlen(name) - 4);
	if (!map_name)
		ft_error(RED MEMMORY_ERROR);
	




}