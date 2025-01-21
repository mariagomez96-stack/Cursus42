/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:17:26 by marigome          #+#    #+#             */
/*   Updated: 2025/01/21 20:38:46 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void ft_calculate_map_size(t_map *map)
{
    int i = 0;
    int j = 0;

    if (!map->map)
        return;
    while (map->map[i])
    {
        int len = ft_strlen(map->map[i]);
        if (len > j)
            j = len;
        i++;
    }
    map->map_size_x = j;
    map->map_size_y = i;
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*new;

	new = ft_strjoin(s1, s2);
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	return (new);
}

char	*ft_trim_str(char *s1, char *set)
{
	char	*new;

	new = ft_strtrim(s1, set);
	if (s1)
		free(s1);
	return (new);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	unsigned int	i;

	i = 0;
	if (!set || !s1)
		return (NULL);
	while (ft_strchr(set, *s1) && s1[i])
		s1++;
	i = ft_strlen((char *)s1);
	while (ft_strchr(set, s1[i]) && i != 0)
		i--;
	return (ft_substr((char *)s1, 0, i + 1));
}

int	ft_split_map(t_data *info, char *map)
{
	int	res;

	res = 0;
	if (ft_check_extra(map))
		res = 1;
	if (res == 1)
	{
		free(map);
		return (FAILURE);
	}
	info->map.map = ft_split(map, '\n');
	free(map);
	if (!info->map.map)
	{
		printf(RED"Failed in ft_split at ft_split_map function.\n"RESET);
		return (FAILURE);
	}
	info->map.map_line = ft_split_len(info->map.map);
	return (SUCCESS);
}