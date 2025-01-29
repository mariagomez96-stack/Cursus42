/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:00:55 by marigome          #+#    #+#             */
/*   Updated: 2025/01/29 12:05:42 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	*ft_split_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

void free_textures(t_texture *textures)
{
    if (textures->no_path)
    {
        free(textures->no_path);
        textures->no_path = NULL;
    }
    if (textures->so_path)
    {
        free(textures->so_path);
        textures->so_path = NULL;
    }
    if (textures->we_path)
    {
        free(textures->we_path);
        textures->we_path = NULL;
    }
    if (textures->ea_path)
    {
        free(textures->ea_path);
        textures->ea_path = NULL;
    }
}

void free_mlx_textures(t_texture *textures)
{
    if (textures->no_texture)
        mlx_delete_texture(textures->no_texture);
    if (textures->so_texture)
        mlx_delete_texture(textures->so_texture);
    if (textures->we_texture)
        mlx_delete_texture(textures->we_texture);
    if (textures->ea_texture)
        mlx_delete_texture(textures->ea_texture);
}
void	free_map(char **map)
{
	int	i;

	if (!map)
		return;
	for (i = 0; map[i]; i++)
	{
		free(map[i]);  // 🔹 Liberar cada línea del mapa
		map[i] = NULL;
	}
	free(map);  // 🔹 Liberar el array de punteros
}


