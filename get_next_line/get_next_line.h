/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:51:04 by marigome          #+#    #+#             */
/*   Updated: 2024/05/14 12:19:43 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h> //write
# include <stdlib.h> //malloc
# include <stdio.h> //printf
# include <fcntl.h> //Para leer archivos

/// @brief Saco el tamaño de buffer y tmp para hacerles un join
/// @param src Array 
/// @return Tamaño de array
size_t	ft_strlen(char *src);

/// @brief Uno bf y tmp en un buffer tamaño bf y tmp
/// @param buffer en el que voy a ir guardando los bytes de tmp
/// @param buffer_tmp voy a ir leyendo buffer_size en read
/// Para ir pasándoselos luego a buffer
/// @return buffer_joined
char	*ft_join(char *buffer, char *buffer_tmp);

/// @brief Función para liberar contenido de puntero y retornar NULL
/// @param ptr Puntero a liberar
/// @return NULL
char	*ft_free_pointer(char *ptr);

/// @brief Sacamos la línea del buffer
/// @param buffer estático en el que buscamos \n
/// @return La línea
char	*check_line(char *buffer);

/// @brief En esta función leemos el archivo abierto
/// @param buffer estático donde vamos almacenando la info
/// @param fd parámetro resultante del open (En main)
/// @return buffer estático
char	*read_buff(char *buffer, int fd);

/// @brief En esta función renovamos el buffer con los
/// carácteres que haya después del '\n'
/// @param buffer buffer estático
/// @return el nuevo buffer
char	*new_buffer(char *buffer);

void	*ft_calloc(size_t nmemb, size_t size);

#endif 