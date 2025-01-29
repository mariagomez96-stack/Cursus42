/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:45:12 by marigome          #+#    #+#             */
/*   Updated: 2025/01/29 11:31:50 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;
    (void)argv;

	if (argc != 2 && ft_checker_extension(argv[1]))
		return (FAILURE);
	ft_init_info_game(&data);
	if (ft_parse(argv[1], &data))
    {
        printf("Mapa opened successfully!\n");
    }
    free_textures(&data.textures);
    free_mlx_textures(&data.textures);
    free_map(data.map.map);
    printf("Map loaded successfully!\n");
    return (0);
}