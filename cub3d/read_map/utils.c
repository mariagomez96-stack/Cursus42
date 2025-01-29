/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:15:44 by marigome          #+#    #+#             */
/*   Updated: 2025/01/29 12:05:38 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_split_len(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

static char	*copy_realloc(char *new_ptr, char *ptr, int size)
{
	int	ptr_len;

	ptr_len = ft_strlen(ptr);
	if (ptr_len > size - 1)
		ptr_len = size - 1;
	ft_memcpy(new_ptr, ptr, ptr_len);
	new_ptr[ptr_len] = '\0';
	free(ptr);
	return (new_ptr);
}


char	*ft_realloc(char *ptr, int size)
{
	char	*new_ptr;

	new_ptr = NULL;
	if (size <= 0)
	{
		free(ptr);
		return (NULL);
	}
	if (!ptr)
	{
		new_ptr = malloc(sizeof(char) * size);
		return (new_ptr);
	}
	new_ptr = malloc(sizeof(char) * size + 1);
	if (!new_ptr)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = copy_realloc(new_ptr, ptr, size);
	return (new_ptr);
}

int ft_checker_extension(char *file)
{
    char *extension;

    if (!file)
        return (FAILURE);
    extension = ft_strrchr(file, '.');
    if (!extension || ft_strlen(extension) != 4 || ft_strcmp(extension, ".cub"))
    {
        printf(RED"Error: Invalid file extension. Expected '.cub'\n"RESET);
        return (FAILURE);
    }
    return (SUCCESS);
}
