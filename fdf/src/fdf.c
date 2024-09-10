/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 11:50:20 by marigome          #+#    #+#             */
/*   Updated: 2024/09/10 16:08:22 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_fdf	*init_fdf(char *map_name)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (!fdf)
	{
		mlx_strerror(MLX_MEMFAIL);
		return (NULL);
	}
	fdf->map = init_map(map_name);
	if (!fdf->map)
	{
		free(fdf);
		return (NULL);
	}
	fdf->cam = (t_cam *)malloc(sizeof(t_cam));
	if (!fdf->cam)
	{
		free_map(fdf->map);
		free(fdf);
		return (NULL);
	}
	init_cam(fdf->cam, fdf->map);
	return (fdf);
}

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	// Verificar que el número de argumentos es correcto
	if (argc != 2)
	{
		ft_error("Usage: ./fdf <map_file>");
		return (EXIT_FAILURE);
	}

	// Inicializar la estructura fdf, cargar el mapa y la cámara
	fdf = init_fdf(argv[1]);
	if (!fdf)
		return (EXIT_FAILURE);

	// Inicializar MLX42 y crear la ventana
	fdf->mlx = mlx_init(WIDTH, HEIGHT, "FdF", true);
	if (!fdf->mlx)
	{
		ft_error("MLX initialization failed");
		free(fdf);
		return (EXIT_FAILURE);
	}
	// Crear la imagen donde dibujaremos
	fdf->image = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	// Proyectar y dibujar el mapa
	project_and_draw_map(fdf);

	// Mostrar la imagen en la ventana
	mlx_image_to_window(fdf->mlx, fdf->image, 0, 0);
	mlx_key_hook(fdf->mlx, handle_events, fdf);

	// Iniciar el loop principal de eventos de MLX
	mlx_loop(fdf->mlx);
	free_fdf(fdf);
	return (EXIT_SUCCESS);
}
