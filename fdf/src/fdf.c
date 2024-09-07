/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 11:50:20 by marigome          #+#    #+#             */
/*   Updated: 2024/09/07 13:28:48 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	t_fdf	*fdf;





}










int main(int argc, char **argv)
{
	t_fdf *rol;
	t_map *map;

	ft_control_args(argc, argv);
	rol = ft_init(argv[1]);

	// Inicializa un mapa de prueba en lugar de leer desde un archivo
	map = ft_init_map(argv[1]);
	//ft_test_map(map);

	rol->map = map;  // Asigna el mapa de prueba al rol
	ft_control_map(argv, rol->map);
	rol->cam = ft_cam_init(rol);
	ft_manage_hook(rol);

	printf("Starting drawing process...\n");
	ft_draw(rol->map, rol);
	printf("Drawing completed.\n");

	mlx_loop(rol->mlx);
	mlx_terminate(rol->mlx);

	// Liberar la memoria del mapa después de su uso
	// ... Código para liberar map y otros recursos ...
	ft_free_map(map);
	ft_free_fdf(rol);

	return 0;
}