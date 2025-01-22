/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:01:51 by marigome          #+#    #+#             */
/*   Updated: 2025/01/22 14:00:28 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

#include "cub3d.h"

int	ft_update_textures(t_data *info, int *res, int *fd)
{
	if (ft_get_walls(info, fd, res))
	{
		*res = 1;
		return (FAILURE);
	}
	return (SUCCESS);
}

/*
void	ft_add_text_path_2(t_data *info, char **c)
{
	if (c[0] && c[1] && !ft_strcmp(c[0], "C"))
	{
		info->textures.ceiling_color = ft_rgb_get(c);
		info->textures.color_flag = 1;
	}
	else if (c[0] && c[1] && !ft_strcmp(c[0], "F"))
	{
		info->textures.floor_color = ft_rgb_get(c);
		info->textures.floor_flag = 1;
	}
}

void	ft_add_text_path(t_data *info, char **c)
{
	if (c[0] && c[1] && !ft_strcmp(c[0], "NO"))
	{
		info->textures.no_path = ft_strdup(c[1]);
		info->textures.no_flag = 1;
	}
	else if (c[0] && c[1] && !ft_strcmp(c[0], "SO"))
	{
		info->textures.so_path = ft_strdup(c[1]);
		info->textures.so_flag = 1;
	}
	else if (c[0] && c[1] && !ft_strcmp(c[0], "EA"))
	{
		info->textures.ea_path = ft_strdup(c[1]);
		info->textures.ea_flag = 1;
	}
	else if (c[0] && c[1] && !ft_strcmp(c[0], "WE"))
	{
		info->textures.we_path = ft_strdup(c[1]);
		info->textures.we_flag = 1;
	}
	ft_add_text_path_2(info, c);
}*/
void	ft_init_texture_arrays(char **textures, char ***paths, int **flags, t_data *info)
{
	textures[0] = "NO";
	textures[1] = "SO";
	textures[2] = "WE";
	textures[3] = "EA";

	paths[0] = &info->textures.no_path;
	paths[1] = &info->textures.so_path;
	paths[2] = &info->textures.we_path;
	paths[3] = &info->textures.ea_path;

	flags[0] = &info->textures.no_flag;
	flags[1] = &info->textures.so_flag;
	flags[2] = &info->textures.we_flag;
	flags[3] = &info->textures.ea_flag;
}

void	ft_store_color(t_data *info, char **c)
{
	if (!c[0] || !c[1])
		return ;

	if (!ft_strcmp(c[0], "C"))
	{
		info->textures.ceiling_color = ft_rgb_get(c);
		info->textures.color_flag = 1;
	}
	else if (!ft_strcmp(c[0], "F"))
	{
		info->textures.floor_color = ft_rgb_get(c);
		info->textures.floor_flag = 1;
	}
}

void	ft_store_texture(t_data *info, char **c)
{
	int		i;
	char	*textures[4];
	char	**paths[4];
	int		*flags[4];

	ft_init_texture_arrays(textures, paths, flags, info);

	if (!c[0] || !c[1])
		return ;

	i = 0;
	while (i < 4)
	{
		if (!ft_strcmp(c[0], textures[i]))
		{
			*paths[i] = ft_strdup(c[1]);
			*flags[i] = 1;
			return ;
		}
		i++;
	}
	ft_store_color(info, c);
}

/* FT_GET_WALLS:
	- ft_process_line: Leemos la línea, eliminamos el salto de línea
		y cada palabra forma un token 
	- ft_check_text: */

int	ft_get_walls(t_data *info, int *fd, int *res)
{
	char	**split_line;
	int		i;
	int		j;

	split_line = NULL;
	i = 0;
	j = 0;
	while (i < 6)
	{
		if (ft_process_line(&split_line, *fd))
			return (FAILURE);
		j++;
		if (ft_check_text(info, split_line, &i, j))
			*res = 1;
	}
	ft_checker_textures(info, fd, i);
	return (SUCCESS);
}

