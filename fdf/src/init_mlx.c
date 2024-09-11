/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 13:08:23 by marigome          #+#    #+#             */
/*   Updated: 2024/09/11 14:31:40 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init(t_fdf *pointer, const char *map_name)
{
	pointer->win_height = DEF_HEIGHT;
	pointer->win_width = DEF_WIDTH;
	pointer->mlx = mlx_init(DEF_WIDTH, DEF_HEIGHT, map_name, true);
	if (!pointer->mlx)
	{
		ft_error(MLX_ERROR);
		exit(EXIT_FAILURE);
	}
	ft_printf(ORANGE "\nMLX " GREEN "initialized successfully...\n" RESET);
	pointer->image = mlx_new_image(pointer->mlx, DEF_WIDTH, DEF_HEIGHT);
	if (!pointer->image)
	{	
		mlx_strerror(MLX_INVIMG);
		mlx_terminate(pointer->mlx);
		exit(EXIT_FAILURE);
	}
	ft_printf(ORANGE "Image " GREEN "created successfully...\n" RESET);
	if (mlx_image_to_window(pointer->mlx, pointer->image, 0, 0) == -1)
	{
		mlx_close_window(pointer->mlx);
		mlx_strerror(MLX_INVIMG);
		exit(EXIT_FAILURE);
	}
	ft_printf(ORANGE "Image " GREEN "added to window successfully...\n" RESET);
}

t_fdf	*init_mlx(char *name)
{
	t_fdf	*fdf;
	char	*map_name;
	
	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (!fdf)
	{
		mlx_strerror(MLX_MEMFAIL);
		return (NULL);
	}
	map_name = ft_substr(name, 0, ft_strlen(name) - 4);
	if (!map_name)
	{	
		ft_error(RED MEMMORY_ERROR);
		free(fdf);
		return (NULL);
	}
	init(fdf, map_name);
	fdf->mouse = (t_mouse *)malloc(sizeof(t_mouse));
	if (!fdf->mouse)
	{
		ft_error("Error de ratón");
		exit (EXIT_FAILURE);
	}
	fdf->map = NULL;
	fdf->cam = NULL;
	free(map_name);

	return (fdf);
}