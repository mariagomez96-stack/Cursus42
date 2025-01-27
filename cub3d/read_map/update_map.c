/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:34:23 by marigome          #+#    #+#             */
/*   Updated: 2025/01/27 14:15:06 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_check_extra(char *map)
{
	int	i;

	i = 0;
	if (!map || !map[i] || map[i] == '\n')
	{
		printf(RED"The map is missing.\n"RESET);
		return (FAILURE);
	}
	while (map[i])
	{
		if (map[i] == '\n')
		{
			i++;
			while (map[i] != '\0' && map[i] == ' ')
				i++;
			if (map[i] == '\n')
			{
				printf(RED"Extra line in map.\n"RESET);
				return (FAILURE);
			}
		}
		if (map[i] != '\0')
			i++;
	}
	return (SUCCESS);
}

int	ft_split_map(t_data *info, char *map)
{
	if (!map)
		return (FAILURE);

	// 🔹 Verifica que el mapa no tenga líneas vacías antes de dividirlo
	if (ft_check_extra(map))
	{
		free(map);
		return (FAILURE);
	}

	// 🔹 Separa el mapa en líneas
	char **temp_map = ft_split(map, '\n');

	// 🔹 Si `ft_split` falla, limpiamos la memoria y retornamos error
	if (!temp_map)
	{
		printf(RED"Failed in ft_split at ft_split_map function.\n"RESET);
		free(map);
		return (FAILURE);
	}

	// 🔹 Guardamos el mapa procesado en `info->map.map`
	info->map.map = temp_map;
	info->map.map_line = ft_split_len(temp_map);

	// 🔹 Ya no necesitamos `map`, lo liberamos
	free(map);

	return (SUCCESS);
}


void	ft_trim_str_inline(char *s, char *set)
{
	size_t	len;
	size_t	n1;
	size_t	last;

	if (!s || !set)
		return;

	len = ft_strlen(s);
	n1 = 0;

	// 🔹 Mover el puntero al primer caracter que no esté en `set`
	while (n1 < len && ft_strchr(set, s[n1]) != NULL)
		n1++;

	last = len;
	// 🔹 Encontrar la última posición sin `set`
	while (last > n1 && ft_strchr(set, s[last - 1]) != NULL)
		last--;

	// 🔹 Sobreescribir la cadena original sin reasignar memoria
	ft_memmove(s, s + n1, last - n1);
	s[last - n1] = '\0';
}
void print_map(t_data *info)
{
    if (!info->map.map)
    {
        printf(RED"Error: El mapa no está cargado correctamente.\n"RESET);
        return;
    }

    printf(GREEN"Mapa cargado correctamente (%d líneas):\n"RESET, info->map.map_line);
    for (int i = 0; i < info->map.map_line; i++)
    {
        printf("%s\n", info->map.map[i]);
    }
}


int	ft_get_map(t_data *info, int fd)
{
	char	*line;
	char	*map;
	char	*temp;

	map = ft_strdup("");  // 🔹 Inicializar `map` con un string vacío para evitar NULL
	if (!map)
		return (FAILURE);
	while ((line = get_next_line(fd)))  // 🔹 Leer línea por línea
	{
		temp = map;  // Guardamos referencia a `map`
		map = ft_strjoin(map, line);  // 🔹 Concatenamos la nueva línea al mapa
		free(temp);  // 🔹 Liberamos la memoria anterior de `map`
        free(line);
		if (!map)  // 🔹 Si la concatenación falla, limpiar y salir
		{
			printf(RED"Failed in ft_strjoin.\n"RESET);
			return (FAILURE);
		}
	}
	// 🔹 Si `map` está vacío, fallar
	if (!*map)
		return (printf(RED"Failed reading map, empty content.\n"RESET), FAILURE);
	// 🔹 Eliminamos saltos de línea innecesarios sin reasignar memoria
	ft_trim_str_inline(map, "\n");
	if (ft_split_map(info, map))  // 🔹 Separa el mapa en `info->map`
        return (FAILURE);
	return (SUCCESS);
}
