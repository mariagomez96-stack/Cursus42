/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 15:35:28 by marigome          #+#    #+#             */
/*   Updated: 2024/09/11 13:01:58 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_error(char *src)
{
	ft_printf("Error: %s\n", src);
	exit(EXIT_FAILURE);
}

void	ft_free_columns(char **columns)
{
	int	i;

	i = 0;
	while (columns[i])
		free(columns[i++]);
	free(columns);
}

void	ft_free_split(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		free(argv[i++]);
	free (argv);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (map->map)
	{
		while (i < map->lines)
			free(map->map[i++]);
		free(map->map);
	}
	free(map);
}

void free_fdf(t_fdf *fdf)
{
    int	i;

	i = 0;
	if (fdf)
    {
        // Libera la memoria de la imagen si existe
        if (fdf->image)
            mlx_delete_image(fdf->mlx, fdf->image);

        // Libera la memoria de la estructura del mapa si existe
        if (fdf->map)
        {
            while (i < fdf->map->lines)
                free(fdf->map->map[i++]);  // Suponiendo que `map` es una matriz
            free(fdf->map->map);
            free(fdf->map);
        }

        // Libera la estructura de la cámara si existe
        if (fdf->cam)
            free(fdf->cam);

        // Finalmente, libera la estructura principal de fdf
        free(fdf);
    }
}

