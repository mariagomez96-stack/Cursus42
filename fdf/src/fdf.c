/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 11:50:20 by marigome          #+#    #+#             */
/*   Updated: 2024/09/17 14:37:33 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	*fdf;
	t_map	*map;

	ft_checker_args(argc, argv);
	fdf = init_mlx(argv[1]);
	map = init_map(argv[1]);
	fdf->map = map;
	ft_control_map(argv, fdf->map);
	fdf->cam = init_cam(fdf);
	manage_moves(fdf);
	ft_draw(fdf->map, fdf);
	mlx_loop(fdf->mlx);
	clean_fdf(fdf);
	return (0);
}
