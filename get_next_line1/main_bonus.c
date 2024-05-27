/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 12:56:07 by marigome          #+#    #+#             */
/*   Updated: 2024/05/27 13:13:52 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int main (void)
{
	int fd;
	char	*line;
	int	count;

	count = 0;

	fd = open("new.txt", O_RDONLY);
	printf("fd:%d\n", fd);
	if (fd == -1)
	{	
		printf("Error al abrir el archivo");
		return (0);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("%s", line);
		free(line);
	}
	close (fd);
	return (0);
}
