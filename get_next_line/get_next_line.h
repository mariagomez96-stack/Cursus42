/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:32:24 by marigome          #+#    #+#             */
/*   Updated: 2024/05/28 11:46:39 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h> //readwrite
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/// @brief len (buffer + tmp) -> to join
/// @param src
/// @return len
size_t	ft_strlen(char *src);

/// @brief Inside of calloc to put zeros inside the buffer
/// @param ptr buffer
/// @param n size of buffer
void	ft_bzero(void *ptr, size_t n);

/// @brief To put n membs of byte size (1 char, 4 int)
/// @param nmemb size (len)
/// @param size bytes
/// @return void
void	*ft_calloc(size_t nmemb, size_t size);

/// @brief join s1 & s2 
/// @param s1 
/// @param s2 
/// @return buffer (1 & s2 joined)
char	*ft_strjoin(char *s1, char *s2);

/// @brief Looking for c (\n) inside tmp to break
/// @param s buffer
/// @param c character to look for
/// @return A pointer if c is found
char	*ft_strchr(char *s, int c);

char	*get_next_line(int fd);

#endif 
