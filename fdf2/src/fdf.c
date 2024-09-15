/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 11:50:20 by marigome          #+#    #+#             */
/*   Updated: 2024/09/15 19:32:57 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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
	plot_map(fdf);
	mlx_loop(fdf->mlx);
	mlx_delete_image(fdf->mlx, fdf->image);
	mlx_terminate(fdf->mlx);
	free_map(map);
	free(fdf);
	return (0);
}
