/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 11:50:20 by marigome          #+#    #+#             */
/*   Updated: 2024/09/12 15:53:23 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*t_fdf	*init_fdf(char *map_name)
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
}*/

/*int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	// Verificar que el número de argumentos es correcto
	ft_checker_args(argc, argv);
	ft_printf("Argumentos leídos");

	// Inicializar la estructura fdf, cargar el mapa y la cámara
	fdf = init_mlx(argv[1]);
	
	// Crear la imagen donde dibujaremos
	//fdf->image = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	// Proyectar y dibujar el mapa
	project_and_draw_map(fdf);

	// Mostrar la imagen en la ventana
	mlx_image_to_window(fdf->mlx, fdf->image, 0, 0);
	mlx_key_hook(fdf->mlx, handle_events, fdf);

	// Iniciar el loop principal de eventos de MLX
	mlx_loop(fdf->mlx);
	free_fdf(fdf);
	return (0);
} */

static void	ft_control_map(char **argv, t_map *map)
{
	(void) argv;
	if (!map || !map->map)
		ft_printf("Map or superarray is NULL\n");
	ft_printf(ORANGE "Map dimensions: " RESET GREEN "Width " RESET "%d, " \
	GREEN"Height " RESET "%d\n", map->columns, map->lines);
}

int	main(int argc, char **argv)
{
	t_fdf	*fdf;
	t_map	*map;

	ft_checker_args(argc, argv);
	fdf = init_mlx(argv[1]);
	map = init_map(argv[1]);
	fdf->map = map;
	ft_control_map(argv, map);
	fdf->cam = init_cam(fdf);
	manage_moves(fdf);
	ft_draw(fdf->map, fdf);
	mlx_loop(fdf->mlx);
	mlx_terminate(fdf->mlx);
	return (0);
}
