/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:50:27 by marigome          #+#    #+#             */
/*   Updated: 2024/05/13 15:40:56 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h> 





char	*ft_read_full_line(int fd, char *buffer)
{
	char	*tmp;
	int		i;
	int		number_digits;

	i = 0;
	number_digits = 1;
	tmp = calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!buffer)
		buffer = calloc(1, 1);
	while (number_digits > 0)
	{
		number_digits = read(fd, tmp, BUFFER_SIZE);
		if (number_digits == -1)
		{
			return (NULL);
			free (tmp);
			free (buffer);
		}
		tmp[number_digits] = '\0';
		buffer = 
}
