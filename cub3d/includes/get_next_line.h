/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 07:07:14 by rdel-olm          #+#    #+#             */
/*   Updated: 2025/01/27 12:36:37 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>  //para typedef, malloc
# include <unistd.h> // para write()


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif


char	*get_next_line(int fd);
char	*ft_gnlstrchr(char *str, int c);
size_t	ft_len(char *str);
char	*ft_rline(char *line);
char	*ft_nline(char *str);
char	*ft_alloc(int fd, char *str);
char	*ft_gnlstrjoin(char *str1, char *str2);
#endif